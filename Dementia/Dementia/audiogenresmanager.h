#ifndef FSDIRMANAGER_H
#define FSDIRMANAGER_H

#include <QObject>
#include <QDir>

class AudioGenresManager: public QObject
{
    Q_OBJECT
    QString m_rootPath;
    QString m_lang;

public:
    explicit AudioGenresManager(const QString &path, const QString &lang, QObject *parent = 0);

signals:
    void modelOutdated(void);

public slots:
    QStringList model(void) const;
    void setRootPath(const QString &path);
    void setLang(const QString &lang);
    QString absolutePath(void) const;
};

#endif // FSDIRMANAGER_H
