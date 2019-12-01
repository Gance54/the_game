#include <QVariant>
#include <json_classes.h>

/* JsonHeader class */
/* --------------------------------------------*/

void Json::print() {
    QString str = QJsonDocument(object_).toJson(QJsonDocument::Indented);
    qDebug("Json dump:\n%s", qPrintable(str));
}

JsonHeader::JsonHeader() {
    setTag(MessageTag::TAG_UNKNOWN);
}

JsonHeader::JsonHeader(MessageTag tag) {
    setTag(tag);
}

JsonHeader::JsonHeader(QJsonObject object) {
    object_ = object;
    tag_ = static_cast<MessageTag>(object_["tag"].toInt());
}

void JsonHeader::setTag(MessageTag tag) {
    tag_ = tag;
    object_.insert("tag", tag);
}

void JsonHeader::setObject(QJsonObject header) {
    object_ = header;
    ssid_ = header["ssid"].toVariant().toULongLong();
    tag_ = static_cast<MessageTag>(object_["tag"].toInt());
}

void JsonHeader::setSsid(qulonglong ssid) {
    ssid_ = ssid;
    object_.insert("ssid", QJsonValue::fromVariant(QVariant::fromValue(ssid_)));
}
qulonglong JsonHeader::getSsid() {
    return ssid_;
}

MessageTag JsonHeader::getTag() {
    return tag_;
}

QJsonObject JsonHeader::object() {
    return object_;
}

/* JsonMessage class */
/* --------------------------------------------*/
JsonMessage::JsonMessage() {

}

JsonMessage::JsonMessage(QJsonDocument document) {
    object_ = document.object();
    header_.setObject(object_["header"].toObject());
    payload_ = object_["payload"].toObject();
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
    object_.insert("header", header_.object());
}
void JsonMessage::setPayload(QJsonObject payload) {
    payload_ = payload;
    object_.insert("payload", payload_);
}

JsonHeader JsonMessage::getHeader() {
    return header_;
}

QJsonObject JsonMessage::getPayload() {
    return payload_;
}

QJsonObject JsonMessage::object() {
    return object_;
}

/* JsonResponse class */
/* --------------------------------------------*/

JsonResponse::JsonResponse(QJsonObject obj) {
    object_ = obj;
    error_.setError(static_cast<ErrorCode::Code>(object_["error"].toInt()));
    extra_ = object_["extra"].toObject();
}

JsonResponse::JsonResponse(ErrorCode err) {
    setError(err);
}

JsonResponse::~JsonResponse() {}

ErrorCode JsonResponse::getError() {
    return error_;
}

QJsonObject JsonResponse::getExtra() {
    return extra_;
}

QJsonObject JsonResponse::object() {
    return object_;
}

void JsonResponse::setError(ErrorCode &err) {
    error_ = err;
    object_.insert("error", error_.getError());
}
void JsonResponse::setExtra(QJsonObject extra) {
    extra_ = extra;
    object_.insert("extra", extra);
}

/* JsonRegRequest class */
/* --------------------------------------------*/
JsonRegRequest::JsonRegRequest() {

}

JsonRegRequest::JsonRegRequest(QJsonObject obj) {
    object_ = obj;
    login_ = object_["login"].toString();
    password_ = object_["password"].toString();
    email_ = object_["email"].toString();
}

QString JsonRegRequest::getLogin() {
    return login_;
}

QString JsonRegRequest::getPassword() {
    return password_;
}

QString JsonRegRequest::getEmail() {
    return email_;
}

void JsonRegRequest::setLogin(QString login) {
    login_ = login;
    object_.insert("login", login_);
}
void JsonRegRequest::setPassword(QString password) {
    password_ = password;
    object_.insert("password", password_);
}
void JsonRegRequest::setEmail(QString email) {
    email_ = email;
    object_.insert("email", email_);
}

QJsonObject JsonRegRequest::object() {
    return object_;
}
