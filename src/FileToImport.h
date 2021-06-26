#ifndef FILETOIMPORT_H
#define FILETOIMPORT_H

#include <QObject>
#include <QDateTime>

class FileToImport
{
public:
    FileToImport(const QString &srcDir, const QString &fileName, const QString &tgtDir);

    QString srcName() const;
    QString tgtSubDir() const;
    QString tgtName() const;
    bool tgtExists() const;

private:
    QString m_srcName;
    QString m_tgtSubDir;
    QString m_tgtName;
    bool    m_tgtExists;
};


#endif // FILETOIMPORT_H
