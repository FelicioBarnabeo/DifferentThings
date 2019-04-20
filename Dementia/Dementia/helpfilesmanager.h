#ifndef HELPMANAGER_H
#define HELPMANAGER_H

#include <QObject>

class HelpFilesManager : public QObject
{
    Q_OBJECT
    QString m_rootPath;
    QString m_lang;
    QStringList m_data;

public:
    explicit HelpFilesManager(const QString &path, const QString &lang, QObject *parent = 0);

signals:
    void modelOutdated(void);

public slots:
    QStringList contentsModel(void);
    QString text(int idx) const;
    QString absolutePath(void) const;
    void setRootPath(const QString &path);
    void setLang(const QString &lang);

};

#endif // HELPMANAGER_H
