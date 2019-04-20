#ifndef GAMEFILESMANAGER_H
#define GAMEFILESMANAGER_H

#include <QObject>

class GameFilesManager : public QObject
{
    Q_OBJECT

    QString m_rootPath;
    QStringList m_model;
    QString m_lang;

public:
    explicit GameFilesManager(const QString &path, const QString &lang, QObject *parent = 0);

signals:
    void modelOutdated(void);

public slots:
    void setRootPath(const QString& path);
    void setLang(const QString& lang);
    QString absolutePath(void) const;
    QStringList model(void) const;
};

#endif // GAMEFILESMANAGER_H
