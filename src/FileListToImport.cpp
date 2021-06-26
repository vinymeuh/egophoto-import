#include "FileListToImport.h"

#include <QDir>
#include <QList>


FileListToImport::FileListToImport(QObject *parent)
    : QAbstractListModel(parent)
{
}


int FileListToImport::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_files.count();
}


QVariant FileListToImport::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_files.count())
        return QVariant();

    const FileToImport &file = m_files[index.row()];
    if (role == FileName)
        return file.srcName();
    if (role == TargetDir)
        return file.tgtSubDir();
    if (role == TargetName)
        return file.tgtName();

    return QVariant();
}


QHash<int, QByteArray> FileListToImport::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FileName] = "filename";
    roles[TargetDir] = "targetdir";
    roles[TargetName] = "targetname";
    return roles;
}


void FileListToImport::prepareImport(const QString srcDir, const QString tgtDir)
{
    m_srcDir = srcDir;
    m_tgtDir = tgtDir;

    QDir pathDir(m_srcDir);
    QStringList imageFileExtensions = { "*.jpg", "*.JPG", "*.NEF" };
    QStringList imageFiles = pathDir.entryList(imageFileExtensions, QDir::Files);

    beginResetModel();
    m_files.clear();
    foreach(QString imgFile, imageFiles) {
        m_files.append(FileToImport(m_srcDir, imgFile, m_tgtDir));
    }
    endResetModel();
}

void FileListToImport::import()
{
    foreach(FileToImport f2i, m_files) {
        if (f2i.tgtExists())
            continue;

        qDebug() << f2i.srcName() + " -> " + f2i.tgtSubDir() + "/" + f2i.tgtName();
        QDir().mkpath(m_tgtDir + "/" + f2i.tgtSubDir());    // TODO: return code
        QFile::copy(
            m_srcDir + "/" + f2i.srcName(),
            m_tgtDir + "/" + f2i.tgtSubDir() + "/" + f2i.tgtName()
        );
    }
}
