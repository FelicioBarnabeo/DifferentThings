#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "settings.h"
#include "audiogenresmanager.h"
#include "audiofilesmanager.h"
#include "airshowfilesmanager.h"
#include "videofilesmanager.h"
#include "infofilesmanager.h"
#include "specfilesmanager.h"
#include "gamefilesmanager.h"
#include "helpfilesmanager.h"
#include "rootmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SettingsManager settings;
    AudioGenresManager audioGenresManager(settings.audioRootPath(),settings.language());
    AudioFilesManager audioFilesManager(settings.audioRootPath(),settings.language());
    AirshowFilesManager airshowFilesManager(settings.airshowRootPath(),settings.language());
    VideoFilesManager videoFilesManager(settings.videoRootPath(),settings.language());
    InfoFilesManager infoFilesManager(settings.infoRootPath(),settings.language());
    SpecFilesManager specFilesManager(settings.specRootPath(),settings.language(),settings.specServerPort());
    GameFilesManager gameFilesManager(settings.gameRootPath(),settings.language());
    HelpFilesManager helpFilesManager(settings.helpRootPath(),settings.language());

    RootManager rootManager;

    QObject::connect(&settings, &SettingsManager::languageChanged,
                     &audioGenresManager, &AudioGenresManager::setLang);

    QObject::connect(&settings, &SettingsManager::languageChanged,
                     &audioFilesManager, &AudioFilesManager::setLang);

    QObject::connect(&settings, &SettingsManager::languageChanged,
                     &videoFilesManager, &VideoFilesManager::setLang);

    QObject::connect(&settings, &SettingsManager::languageChanged,
                     &infoFilesManager, &InfoFilesManager::setLang);

    QObject::connect(&settings,&SettingsManager::languageChanged,
                     &specFilesManager,&SpecFilesManager::setLang);

    QObject::connect(&settings, &SettingsManager::languageChanged,
                     &gameFilesManager, &GameFilesManager::setLang);

    QObject::connect(&settings, &SettingsManager::languageChanged,
                     &helpFilesManager, &HelpFilesManager::setLang);

    QObject::connect(&settings, &SettingsManager::languageChanged,
                     &airshowFilesManager, &AirshowFilesManager::setLang);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("SettingsManager", &settings);
    engine.rootContext()->setContextProperty("AudioFilesManager", &audioFilesManager);
    engine.rootContext()->setContextProperty("AudioGenresManager", &audioGenresManager);
    engine.rootContext()->setContextProperty("AirshowFilesManager", &airshowFilesManager);
    engine.rootContext()->setContextProperty("VideoFilesManager", &videoFilesManager);
    engine.rootContext()->setContextProperty("InfoFilesManager", &infoFilesManager);
    engine.rootContext()->setContextProperty("SpecFilesManager", &specFilesManager);
    engine.rootContext()->setContextProperty("GameFilesManager", &gameFilesManager);
    engine.rootContext()->setContextProperty("HelpFilesManager", &helpFilesManager);
    engine.rootContext()->setContextProperty("RootManager", &rootManager);
    engine.load(QUrl(QStringLiteral("qrc:/qml/app.qml")));

    return app.exec();
}
