#include "videofilesmanager.h"

VideoFilesManager::VideoFilesManager(const QString &path, const QString &lang, QObject *parent)
    : QObject(parent), m_rootPath(path), m_lang(lang)
{
    // nothing to do
}

void VideoFilesManager::setRootPath(const QString &path)
{
    if (m_rootPath == path) return;
    m_rootPath = path;
    emit this->modelOutdated();
}

void VideoFilesManager::setLang(const QString &lang)
{
    if (m_lang == lang) return;
    m_lang = lang;
    emit this->modelOutdated();
}

QString VideoFilesManager::absolutePath(void) const
{
    return (m_rootPath + "/" + m_lang);
}

QStringList VideoFilesManager::model(void) const
{
    QDir rootDir(this->absolutePath());
    if (!rootDir.exists()) return (QStringList());
    QStringList tmpList;
    tmpList = rootDir.entryList(QDir::NoDotAndDotDot|QDir::Dirs, QDir::Name);

    return (tmpList);
}

QString VideoFilesManager::getDescOf(QString filename) const
{
    QString path = this->absolutePath() + "/" + filename + "/desc";
    QFile file(path);

    if (!file.exists())
        return (tr("Описание отсутствует."));

    if (!file.open(QIODevice::ReadOnly))
        return (tr("Описание отсутствует."));

    return (file.readAll());
}
