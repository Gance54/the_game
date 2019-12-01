#ifndef GAME_H
#define GAME_H
#include <qglobal.h>
#include <QString>

#define VERSION_MAJ 1
#define VERSION_MIN 0

class Version {
public:
    Version() {
        version_.version.maj = VERSION_MAJ;
        version_.version.min = VERSION_MIN;
    }

    quint64 getVersion() { return version_.version_full; }
    quint32 getVersionMin() { return version_.version.min; }
    quint32 getVersionMaj() { return version_.version.maj; }

    bool isVersionMatch (quint64 version) {
        return version == version_.version_full;
    }

    bool isVersionMatch(quint32 min, quint32 maj) {
        return min == version_.version.min &&
               maj == version_.version.maj;
    }

    QString getVersionString () {
        return QString::number(version_.version.maj) + "." +
               QString::number(version_.version.min);
    }

private:

    union u_version {
        quint64 version_full;
        struct s_version {
            quint32 min;
            quint32 maj;
        } version;
    } version_;

};

enum MessageTag {
    TAG_REGISTRATION  = 1,
    TAG_LOGIN,

    TAG_UNKNOWN
};

class ErrorCode {
public:
    enum Code {
        ERROR_OK = 0,
        ERROR_LOGIN_EXISTS = -100,
        ERROR_DB_INTERNAL_ERROR = 101,

        ERROR_UNKNOWN = -1000
    };

    ErrorCode() : error_(ERROR_UNKNOWN) {}
    ErrorCode(Code e) : error_(e) {}

    QString getErrorString() {
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

    Code getError() {
        return error_;
    }

    void setError(Code e) {
        error_ = e;
    }

private:
    Code error_;
};

#endif // GAME_H
