#include "FileToImport.h"

#include <QFile>
#include <QDir>

#include <exiv2/exiv2.hpp>

FileToImport::FileToImport(const QString &srcDir, const QString &fileName, const QString &tgtDir)
    : m_srcName(fileName), m_tgtExists(false)
{
    QString file = QDir(srcDir).filePath(fileName);
    auto image = Exiv2::ImageFactory::open(file.toStdString());
    image->readMetadata();

    auto exifData = image->exifData();
    if (exifData.empty()) {
        return;
    }

    auto exifDateRaw = exifData["Exif.Photo.DateTimeOriginal"]; // Exif.Photo.DateTime ?
    auto exifDateString = QString::fromStdString(exifDateRaw.toString());
    auto exifDate = QDateTime::fromString(exifDateString, "yyyy:MM:dd HH:mm:ss");

    auto year = exifDate.toString("yyyy");
    auto day = exifDate.toString("yyyy-MM-dd");
    m_tgtSubDir = year + "/" + day;

    auto prefix = exifDate.toString("yyyyMMdd_HHmmss") + "_";
    if (m_srcName.startsWith(prefix)) {
        m_tgtName = m_srcName;
    } else {
        m_tgtName = prefix + m_srcName;
    }

    m_tgtExists = QFile::exists(tgtDir + "/" + m_tgtSubDir + "/" + m_tgtName);
}


QString FileToImport::srcName() const
{
    return m_srcName;
}

QString FileToImport::tgtSubDir() const
{
    return m_tgtSubDir;
}

QString FileToImport::tgtName() const
{
    return m_tgtName;
}

bool FileToImport::tgtExists() const
{
    return m_tgtExists;
}
