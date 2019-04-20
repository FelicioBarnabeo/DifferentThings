#include "infofilesmanager.h"

InfoFilesManager::InfoFilesManager(const QString &path, const QString &lang, QObject *parent):
    QObject(parent), m_rootPath(path), m_lang(lang)
{
    // nothing to do
}

QStringList InfoFilesManager::dataModel(void) const
{
    QDir rootDir(this->absolutePath());
    if (!rootDir.exists()) return QStringList();

    QStringList tmpList = rootDir.entryList(QStringList()<<"*.jpg",
                                            QDir::NoDotAndDotDot|QDir::Files,
                                            QDir::Name);
    for (QStringList::iterator it=tmpList.begin(); it!=tmpList.end(); ++it)
        *it = "file:" + this->absolutePath() + "/" + *it;

    return (tmpList);
}

QStringList InfoFilesManager::contentsModel(void) const
{
    QDir rootDir(this->absolutePath());
    if (!rootDir.exists()) return QStringList();

    QStringList tmpList = rootDir.entryList(QStringList()<<"*.jpg",
                                            QDir::NoDotAndDotDot|QDir::Files,
                                            QDir::Name);
    for (QStringList::iterator it=tmpList.begin(); it!=tmpList.end(); ++it) {
        *it = (*it).mid(5).simplified();
        (*it).chop(4);
    }
    return (tmpList);
}

QString InfoFilesManager::absolutePath(void) const
{
    return (m_rootPath + "/" + m_lang);
}

void InfoFilesManager::setLang(const QString &lang)
{
    if (m_lang == lang) return;
    m_lang = lang;
    emit this->modelOutdated();
}

void InfoFilesManager::setRootPath(const QString &path)
{
    if (m_rootPath == path) return;
    m_rootPath = path;
    emit this->modelOutdated();
}
