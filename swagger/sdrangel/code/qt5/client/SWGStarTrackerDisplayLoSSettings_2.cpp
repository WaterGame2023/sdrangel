/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGStarTrackerDisplayLoSSettings_2.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGStarTrackerDisplayLoSSettings_2::SWGStarTrackerDisplayLoSSettings_2(QString* json) {
    init();
    this->fromJson(*json);
}

SWGStarTrackerDisplayLoSSettings_2::SWGStarTrackerDisplayLoSSettings_2() {
    name = nullptr;
    m_name_isSet = false;
    b = 0.0f;
    m_b_isSet = false;
    l = 0.0f;
    m_l_isSet = false;
    d = 0.0f;
    m_d_isSet = false;
}

SWGStarTrackerDisplayLoSSettings_2::~SWGStarTrackerDisplayLoSSettings_2() {
    this->cleanup();
}

void
SWGStarTrackerDisplayLoSSettings_2::init() {
    name = new QString("");
    m_name_isSet = false;
    b = 0.0f;
    m_b_isSet = false;
    l = 0.0f;
    m_l_isSet = false;
    d = 0.0f;
    m_d_isSet = false;
}

void
SWGStarTrackerDisplayLoSSettings_2::cleanup() {
    if(name != nullptr) { 
        delete name;
    }



}

SWGStarTrackerDisplayLoSSettings_2*
SWGStarTrackerDisplayLoSSettings_2::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGStarTrackerDisplayLoSSettings_2::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&name, pJson["name"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&b, pJson["b"], "float", "");
    
    ::SWGSDRangel::setValue(&l, pJson["l"], "float", "");
    
    ::SWGSDRangel::setValue(&d, pJson["d"], "float", "");
    
}

QString
SWGStarTrackerDisplayLoSSettings_2::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGStarTrackerDisplayLoSSettings_2::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(name != nullptr && *name != QString("")){
        toJsonValue(QString("name"), name, obj, QString("QString"));
    }
    if(m_b_isSet){
        obj->insert("b", QJsonValue(b));
    }
    if(m_l_isSet){
        obj->insert("l", QJsonValue(l));
    }
    if(m_d_isSet){
        obj->insert("d", QJsonValue(d));
    }

    return obj;
}

QString*
SWGStarTrackerDisplayLoSSettings_2::getName() {
    return name;
}
void
SWGStarTrackerDisplayLoSSettings_2::setName(QString* name) {
    this->name = name;
    this->m_name_isSet = true;
}

float
SWGStarTrackerDisplayLoSSettings_2::getB() {
    return b;
}
void
SWGStarTrackerDisplayLoSSettings_2::setB(float b) {
    this->b = b;
    this->m_b_isSet = true;
}

float
SWGStarTrackerDisplayLoSSettings_2::getL() {
    return l;
}
void
SWGStarTrackerDisplayLoSSettings_2::setL(float l) {
    this->l = l;
    this->m_l_isSet = true;
}

float
SWGStarTrackerDisplayLoSSettings_2::getD() {
    return d;
}
void
SWGStarTrackerDisplayLoSSettings_2::setD(float d) {
    this->d = d;
    this->m_d_isSet = true;
}


bool
SWGStarTrackerDisplayLoSSettings_2::isSet(){
    bool isObjectUpdated = false;
    do{
        if(name && *name != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_b_isSet){
            isObjectUpdated = true; break;
        }
        if(m_l_isSet){
            isObjectUpdated = true; break;
        }
        if(m_d_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

