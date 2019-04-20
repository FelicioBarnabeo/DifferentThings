#ifndef VIDEOFILESMANAGER_H
#define VIDEOFILESMANAGER_H

#include <QObject>
#include <QDir>

class VideoFilesManager : public QObject
{
    Q_OBJECT

    QString m_rootPath;
    QString m_lang;
    QStringList m_model;

public:
    explicit VideoFilesManager(const QString &path, const QString &lang, QObject *parent = 0);

signals:
    void modelOutdated(void);

public slots:
    void setRootPath(const QString& path);
    void setLang(const QString& lang);
    QString absolutePath(void) const;
    QStringList model(void) const;
    QString getDescOf(QString filename) const;
};

#endif // VIDEOFILESMANAGER_H
