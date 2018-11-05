///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QtGlobal>
#include "util/simpleserializer.h"

#include "soapysdroutputsettings.h"

SoapySDROutputSettings::SoapySDROutputSettings()
{
    resetToDefaults();
}

void SoapySDROutputSettings::resetToDefaults()
{
    m_centerFrequency = 435000*1000;
    m_LOppmTenths = 0;
    m_devSampleRate = 1024000;
    m_log2Interp = 0;
    m_transverterMode = false;
    m_transverterDeltaFrequency = 0;
    m_antenna = "NONE";
}

QByteArray SoapySDROutputSettings::serialize() const
{
    SimpleSerializer s(1);

    s.writeS32(1, m_devSampleRate);
    s.writeS32(2, m_LOppmTenths);
    s.writeU32(3, m_log2Interp);
    s.writeBool(4, m_transverterMode);
    s.writeS64(5, m_transverterDeltaFrequency);
    s.writeString(6, m_antenna);

    return s.final();
}

bool SoapySDROutputSettings::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if (!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if (d.getVersion() == 1)
    {
        d.readS32(1, &m_devSampleRate);
        d.readS32(2, &m_LOppmTenths);
        d.readU32(3, &m_log2Interp);
        d.readBool(4, &m_transverterMode, false);
        d.readS64(5, &m_transverterDeltaFrequency, 0);
        d.readString(6, &m_antenna, "NONE");

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}
