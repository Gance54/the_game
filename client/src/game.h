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


#endif // GAME_H
