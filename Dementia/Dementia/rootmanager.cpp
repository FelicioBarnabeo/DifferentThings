#include "rootmanager.h"

RootManager::RootManager(QObject *parent) : QObject(parent)
{
    setProgress(0);
}

QString RootManager::status() const
{
    return m_status;
}

int RootManager::progress() const
{
    return m_progress;
}

void RootManager::updateFirmwareFromUSB()
{
    setProgress(0);
    setStatus("Updating firmware from USB");
    setProgress(1);
    setStatus("Searching fw.tar.gz in /media/usb0/");
    setProgress(2);
    setStatus("Firmware now is up to date");
    setProgress(100);
}

void RootManager::updateFirmwareFromServer()
{
    setProgress(0);
    setStatus("Updating firmware from Server");
    setProgress(1);
    setStatus("Request fw.tar.gz");
    setProgress(2);
    setStatus("Firmware now is up to date");
    setProgress(100);
}

void RootManager::updateFirmwareFromSSD()
{
    setProgress(0);
    setStatus("Updating firmware from SSD");
    setProgress(1);
    setStatus("Searching fw.tar.gz in /media/data");
    setProgress(2);
    setStatus("Firmware now is up to date");
    setProgress(100);
}

void RootManager::updateMediaFromUSB()
{
    setProgress(0);
    setStatus("Updating media from USB");
    setProgress(1);
    setStatus("Searching media.tar.gz in /media/usb0/");
    setProgress(2);
    setStatus("Media now is up to date");
    setProgress(100);
}

void RootManager::updateMediaFromServer()
{
    setStatus("Updating media from SSD");
    setProgress(1);
    setStatus("Searching media.tar.gz in /media/data");
    setProgress(2);
    setStatus("Media now is up to date");
    setProgress(100);
}

void RootManager::updateMediaFromSSD()
{
    setProgress(0);
    setStatus("Updating media from SSD");
    setProgress(1);
    setStatus("Searching media.tar.gz in /media/data");
    setProgress(2);
    setStatus("Media now is up to date");
    setProgress(100);
}

void RootManager::reboot()
{
    setProgress(0);
    setStatus("Rebooting...");
    setProgress(80);
}

void RootManager::halt()
{
    setProgress(0);
    setStatus("Halting...");
    setProgress(80);
}

void RootManager::setStatus(QString status)
{
    if (m_status == status) return;

    m_status = status;
    emit statusChanged(status);
}

void RootManager::setProgress(int progress)
{
    if (m_progress == progress) return;

    m_progress = progress;
    emit progressChanged(progress);
}
