#include "audiofilesmanager.h"

AudioFilesManager::AudioFilesManager(const QString &path, const QString &lang, QObject *parent) :
    QObject(parent), m_rootPath(path), m_lang(lang)
{
    // nothing to do
}

QStringList AudioFilesManager::model(void) const
{
    QDir rootDir(this->absolutePath());

    if (!rootDir.exists()) return (QStringList());
    QStringList tmpList;
    tmpList = rootDir.entryList(QStringList()<<"*.mp3",
                                QDir::NoDotAndDotDot|QDir::Files,
                                QDir::Name);
    return (tmpList);
}

void AudioFilesManager::setExtPath(const QString &path)
{
    if (m_extPath == path) return;
    m_extPath = path;
    emit this->modelOutdated();
}

void AudioFilesManager::setRootPath(const QString &path)
{
    if (m_rootPath == path) return;
    m_rootPath = path;
    emit this->modelOutdated();
}

void AudioFilesManager::setLang(const QString &lang)
{
    if (m_lang == lang) return;
    m_lang = lang;
    emit this->modelOutdated();
}

QString AudioFilesManager::absolutePath(void) const
{
    return (m_rootPath + "/" + m_lang + "/" + m_extPath);
}
