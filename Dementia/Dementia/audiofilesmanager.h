#ifndef FSFILEMANAGER_H
#define FSFILEMANAGER_H

#include <QObject>
#include <QDir>

class AudioFilesManager : public QObject
{
    Q_OBJECT
    QString m_rootPath;
    QString m_extPath;
    QString m_lang;

public:
    explicit AudioFilesManager(const QString &path, const QString &lang, QObject *parent = 0);

signals:
    void modelOutdated(void);

public slots:
    void setExtPath(const QString &extPath);
    void setRootPath(const QString &absolutePath);
    void setLang(const QString &lang);

    QString absolutePath(void) const;
    QStringList model(void) const;
};

#endif // FSFILEMANAGER_H
