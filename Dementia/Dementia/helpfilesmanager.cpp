#include "helpfilesmanager.h"
#include <QDir>
#include <QDebug>

HelpFilesManager::HelpFilesManager(const QString &path, const QString &lang, QObject *parent)
    : QObject(parent), m_rootPath(path), m_lang(lang)
{
    // nothing to do
}

QStringList HelpFilesManager::contentsModel(void)
{
    QDir rootDir(this->absolutePath());
    if (!rootDir.exists()) return QStringList();

    QStringList tmpList = rootDir.entryList(QStringList()<<"*.htm",
                                            QDir::NoDotAndDotDot|QDir::Files,
                                            QDir::Name);
    m_data = tmpList;
    for (QStringList::iterator it=tmpList.begin(); it!=tmpList.end(); ++it) {
        *it = (*it).mid(5).simplified();
        (*it).chop(4);
    }
    return (tmpList);
}

QString HelpFilesManager::text(int idx) const
{
    if (idx<0 || idx==m_data.size()) return QString();
    QFile file(this->absolutePath() + "/" + m_data.at(idx));
    if (!file.exists()) return QString();
    if (!file.open(QIODevice::ReadOnly)) return QString();
    return QString(file.readAll());
}

void HelpFilesManager::setRootPath(const QString &path)
{
    if (m_rootPath == path) return;
    m_rootPath = path;
    emit this->modelOutdated();
}

void HelpFilesManager::setLang(const QString &lang)
{
    if (m_lang == lang) return;
    m_lang = lang;
    emit this->modelOutdated();
}

QString HelpFilesManager::absolutePath() const
{
    return (m_rootPath + "/" + m_lang);
}
