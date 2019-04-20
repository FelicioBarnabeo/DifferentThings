#include "gamefilesmanager.h"
#include <QDir>

GameFilesManager::GameFilesManager(const QString &path, const QString &lang, QObject *parent)
    : QObject(parent), m_rootPath(path), m_lang(lang)
{
    // nothing to do
}

void GameFilesManager::setRootPath(const QString &path)
{
    if (m_rootPath == path) return;
    m_rootPath = path;
    emit this->modelOutdated();
}

QString GameFilesManager::absolutePath(void) const
{
    return (m_rootPath + "/" + m_lang);
}

QStringList GameFilesManager::model(void) const
{
    QDir rootDir(this->absolutePath());
    if (!rootDir.exists()) return (QStringList());
    QStringList tmpList;
    tmpList = rootDir.entryList(QDir::NoDotAndDotDot|QDir::Dirs, QDir::Name);

    return (tmpList);
}

void GameFilesManager::setLang(const QString &lang)
{
    if (m_lang == lang) return;
    m_lang = lang;
    emit this->modelOutdated();
}

