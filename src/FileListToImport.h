#ifndef FILELISTTOIMPORT_H
#define FILELISTTOIMPORT_H

#include <QObject>
#include <QAbstractListModel>

#include "FileToImport.h"

class FileListToImport : public QAbstractListModel
{
    Q_OBJECT

public:
    enum FileListToImportRoles {
        FileName = Qt::UserRole + 1,
        TargetDir,
        TargetName,
    };

    FileListToImport(QObject *parent=0);

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void prepareImport(const QString srcDir, const QString tgtDir);
    Q_INVOKABLE void import();

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<FileToImport> m_files;
    QString m_srcDir;
    QString m_tgtDir;
};

#endif // FILELISTTOIMPORT_H
