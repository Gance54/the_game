#include <QVariant>
#include <json_classes.h>

/* JsonHeader class */
/* --------------------------------------------*/

static void printJson (QString header, QJsonObject object) {
    QString str = QJsonDocument(object).toJson(QJsonDocument::Indented);
    qDebug("%s:\n%s", qPrintable(header), qPrintable(str));
}

JsonHeader::JsonHeader() {
    setTag(MessageTag::TAG_UNKNOWN);
}

JsonHeader::JsonHeader(MessageTag tag) {
    setTag(tag);
}

JsonHeader::JsonHeader(QJsonObject object) {
    header_ = object;
    tag_ = static_cast<MessageTag>(header_.value("tag").toInt());
}

void JsonHeader::setTag(MessageTag tag) {
    tag_ = tag;
    header_.insert("tag", tag);
}

void JsonHeader::setObject(QJsonObject header) {
    header_ = header;
    ssid_ = header["ssid"].toVariant().toULongLong();
    tag_ = static_cast<MessageTag>(header_.value("tag").toInt());
}

void JsonHeader::setSsid(qulonglong ssid) {
    ssid_ = ssid;
    header_.insert("ssid", QJsonValue::fromVariant(QVariant::fromValue(ssid_)));
}
qulonglong JsonHeader::getSsid() {
    return ssid_;
}

MessageTag JsonHeader::getTag() {
    return tag_;
}

QJsonObject JsonHeader::object() {
    return header_;
}

void JsonHeader::print() {
    printJson("Header", header_);
}

/* JsonMessage class */
/* --------------------------------------------*/
JsonMessage::JsonMessage() {

}

JsonMessage::JsonMessage(QJsonDocument document) {
    message_ = document.object();
    header_.setObject(message_["header"].toObject());
    payload_ = message_["payload"].toObject();
}

JsonMessage::JsonMessage(JsonHeader header, QJsonObject payload) {
    setHeader(header);
    setPayload(payload);
}

JsonMessage::JsonMessage(MessageTag tag, QJsonObject payload) {
    JsonHeader header(tag);
    setHeader(header);
    setPayload(payload);
}

void JsonMessage::setHeader(JsonHeader header) {
    header_ = header;
    message_.insert("header", header_.object());
}
void JsonMessage::setPayload(QJsonObject payload) {
    payload_ = payload;
    message_.insert("payload", payload_);
}

JsonHeader JsonMessage::getHeader() {
    return header_;
}
QJsonObject JsonMessage::getPayload() {
    return payload_;
}
QJsonObject JsonMessage::object() {
    return message_;
}

void JsonMessage::print() {
   printJson("Message", message_);
}

/* JsonRegRequest class */
/* --------------------------------------------*/
JsonRegRequest::JsonRegRequest() {

}

JsonRegRequest::JsonRegRequest(QJsonObject obj) {
    request_ = obj;
    login_ = request_["login"].toString();
    password_ = request_["password"].toString();
    email_ = request_["email"].toString();
}

void JsonRegRequest::setLogin(QString login) {
    login_ = login;
    request_.insert("login", login_);
}
void JsonRegRequest::setPassword(QString password) {
    password_ = password;
    request_.insert("password", password_);
}
void JsonRegRequest::setEmail(QString email) {
    email_ = email;
    request_.insert("email", email_);
}

QJsonObject JsonRegRequest::object() {
    return request_;
}

void JsonRegRequest::print() {
   printJson("Registration request", request_);
}
