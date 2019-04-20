#include <QDebug>
#include <QDir>
#include "airshowfilesmanager.h"

namespace AirshowConsts {
const QString NamesFile = "names.cfg";
const QString ArchFile = "map.tar";
const int BufferSize = 100000;
const QChar MagicChar = '[';
const int TimeoutMs = 1000;
}

AirshowFilesManager::AirshowFilesManager(QString path, QString lang, QObject *parent)
    : QObject(parent), m_path(path), m_lang(lang), m_counter(0), m_isBusy(false),
      m_isUnpackFinished(true), m_isErrorOccured(false), m_fileSize(0)
{
    m_unpackProc = new QProcess(this);
    m_clientSocket = new QTcpSocket(this);
    m_timeoutTmr = new QTimer(this);
    m_buffer = new char[AirshowConsts::BufferSize];

    m_file.setFileName(m_path + "/" + AirshowConsts::ArchFile);

    readFilesNames();

    typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
    connect(m_clientSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error),
            this, &AirshowFilesManager::connectionError);
    connect(m_clientSocket, &QAbstractSocket::connected, m_timeoutTmr, &QTimer::stop);

    connect(m_timeoutTmr,&QTimer::timeout,this,&AirshowFilesManager::connectionTimeout);

    connect(m_clientSocket, &QTcpSocket::readyRead, this, &AirshowFilesManager::dataRead);
    connect(m_unpackProc,static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
            this, &AirshowFilesManager::unpackFinished);
}

AirshowFilesManager::~AirshowFilesManager()
{
    delete[] m_buffer;
}

void AirshowFilesManager::readFilesNames()
{
    QString curDBName;

    QFile file(m_path + "/" + AirshowConsts::NamesFile);
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        while (!file.atEnd() && !file.error()) {
            QString line = file.readLine().simplified();
            if (line.at(0) == AirshowConsts::MagicChar)
                curDBName = line.mid(1,line.length()-2);
            else
                m_filesNames[curDBName].append(m_path + "/" + line);
        }
    } else {
        m_isErrorOccured = true;
    }
}

QUrl AirshowFilesManager::nextImage(void)
{
    qDebug()<<"Request to switch";
    QUrl url;

    if (!m_filesNames.size()) return (url);

    int tries = 0;
    while(tries != m_filesNames[m_lang].count()) {
        if (m_counter == m_filesNames[m_lang].count()) m_counter=0;

        QFile curFile(m_filesNames[m_lang][m_counter]);
        if (curFile.exists())
            return (QUrl::fromLocalFile(m_filesNames[m_lang][m_counter++]));

        ++tries;
        ++m_counter;
    }

    return (url);
}

bool AirshowFilesManager::updateImages(QString serverIP, int port)
{
    if (m_isErrorOccured) return (false);

    m_clientSocket->abort();
    m_isBusy = false;
    m_file.close();
    m_fileSize = 0;

    if (m_file.open(QIODevice::WriteOnly)) {
        //m_timeoutTmr->start(AirshowConsts::TimeoutMs);
        m_clientSocket->connectToHost(serverIP,port);
        if (m_clientSocket->waitForConnected(100)) return (true);
        m_clientSocket->abort();
        return (false);
    } else {
        return (false);
    }
}

void AirshowFilesManager::dataRead(void)
{
    if (!m_isBusy) {
        if (m_clientSocket->bytesAvailable()<(qint64)sizeof(quint64)) return;
        m_isBusy = true;
        m_clientSocket->read((char*)&m_fileSize,sizeof(quint64));
        qDebug()<<"File size: "<<m_fileSize;
    }

    qint64 readedBytes;
    while (m_clientSocket->bytesAvailable()) {
        if (m_fileSize) {
            readedBytes = m_clientSocket->read(m_buffer,AirshowConsts::BufferSize);
            m_file.write(m_buffer,readedBytes);
            m_fileSize -= readedBytes;
        }
    }

    if (!m_fileSize) {
        qDebug()<<"File ready. Disconnect";
        m_isBusy = false;
        m_file.close();
        m_clientSocket->disconnectFromHost();
        this->unpack();
    }
}

void AirshowFilesManager::connectionError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"Connection error";

    //m_timeoutTmr->stop();
    m_clientSocket->disconnectFromHost();
    //m_clientSocket->abort();
    emit networkErrorOccured();

    qDebug()<<"\tsocket error ="<<socketError;
    qDebug()<<"\tsocket state ="<<m_clientSocket->state();
}

void AirshowFilesManager::connectionTimeout()
{
    qDebug()<<"Timeout";
    this->connectionError(QAbstractSocket::SocketTimeoutError);
}

void AirshowFilesManager::unpack(void)
{
    qDebug()<<"Unpack started";
    QStringList args;
    args<<"-xf"<<AirshowConsts::ArchFile<<"--strip-components=1";
    m_unpackProc->setWorkingDirectory(m_path);
    m_unpackProc->start("truetar",args);
}

void AirshowFilesManager::unpackFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug()<<"Unpack finished";
    emit imagesReady();
    qDebug()<<"\tunpack exit code ="<<exitCode;
    qDebug()<<"\tunpack exit status"<<exitStatus;
}

void AirshowFilesManager::resetToDefault()
{
    m_unpackProc->kill();
    //m_timeoutTmr->stop();
    m_clientSocket->abort();
    m_isBusy = false;
    m_file.close();
    m_fileSize = 0;
    m_counter = 0;
}

void AirshowFilesManager::setLang(QString lang)
{
    m_lang = lang;
}
