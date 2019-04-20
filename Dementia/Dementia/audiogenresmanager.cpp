#include "audiogenresmanager.h"

AudioGenresManager::AudioGenresManager(const QString &path, const QString &lang, QObject *parent) :
    QObject(parent), m_rootPath(path), m_lang(lang)
{
    // nothing to do
}

QStringList AudioGenresManager::model(void) const
{
    QDir rootDir(this->absolutePath());
    if (!rootDir.exists()) return QStringList();

    QStringList tmpList = rootDir.entryList(QDir::NoDotAndDotDot|QDir::Dirs,
                                            QDir::Name);
    int i=0;
    while (i!=tmpList.count()) {
        QDir dir(this->absolutePath());
        dir.cd(tmpList.at(i));
        if (!dir.entryList(QStringList()<<"*.mp3",QDir::Files).isEmpty()) ++i;
        else tmpList.removeAt(i);
    }

    return (tmpList);
}

void AudioGenresManager::setRootPath(const QString &path)
{
    if (m_rootPath == path) return;
    m_rootPath = path;
    emit this->modelOutdated();
}

void AudioGenresManager::setLang(const QString &lang)
{
    if (m_lang == lang) return;
    m_lang = lang;
    emit this->modelOutdated();
}

QString AudioGenresManager::absolutePath(void) const
{
    return (m_rootPath + "/" + m_lang);
}



