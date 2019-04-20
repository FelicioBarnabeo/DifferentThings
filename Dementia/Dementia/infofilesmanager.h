#ifndef INFOMANAGER_H
#define INFOMANAGER_H

#include <QObject>
#include <QDir>

class InfoFilesManager : public QObject
{
    Q_OBJECT
    QString m_rootPath;
    QString m_lang;

public:
    explicit InfoFilesManager(const QString &path, const QString &lang, QObject *parent = 0);

signals:
    void modelOutdated(void);

public slots:
    QStringList dataModel(void) const;
    QStringList contentsModel(void) const;
    QString absolutePath(void) const;
    void setLang(const QString &lang);
    void setRootPath(const QString &path);
};

#endif // INFOMANAGER_H
