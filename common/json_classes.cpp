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
    header_ = object;
    tag_ = static_cast<MessageTag>(header_["tag"].toInt());
}

void JsonHeader::setTag(MessageTag tag) {
    tag_ = tag;
    header_.insert("tag", tag);
}

void JsonHeader::setObject(QJsonObject header) {
    header_ = header;
    ssid_ = header["ssid"].toVariant().toULongLong();
    tag_ = static_cast<MessageTag>(header_["tag"].toInt());
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

/* JsonResponse class */
/* --------------------------------------------*/

JsonResponse::JsonResponse() {
    error_ = ErrorCode::ERROR_UNKNOWN;
}

JsonResponse::JsonResponse(QJsonObject obj) {
    response_ = obj;
    error_ = static_cast<ErrorCode>(response_["error"].toInt());
    extra_ = response_["extra"].toObject();
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
    return response_;
}

void JsonResponse::setError(ErrorCode err) {
    error_ = err;
    response_.insert("error", error_);
}
void JsonResponse::setExtra(QJsonObject extra) {
    extra_ = extra;
    response_.insert("extra", extra);
}

QString JsonResponse::getString() {
    switch (error_) {
    case ERROR_OK:
        return "Success!";
    case ERROR_UNKNOWN:
        return "Unknown error";
    case ERROR_LOGIN_EXISTS:
        return "Login already exists.";
    default:
        return "WTF?!";
    }
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
