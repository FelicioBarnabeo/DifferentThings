#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texturemngr.h"
#include <string>


class Application
{
public:
    Application();
    ~Application();   
    void run();
    void createWindow(std::string title, int x, int y, int w, int h, Uint32 flags);
    void deleteWindow();
    void loadTexsture(std::string language, std::string filename, std::string id);
    Window* window() const
    {
        return app_window;
    }
    bool quit = false;
    void changeLanguage();
    void setLanguage(std::string lang);
    std::string getLanguage() const{return m_language;}
private:
    std::string m_language;
    void init();
    void processInput();
    void rendering() const;
    TextureMngr* app_texstures = TextureMngr::Instance();
    Window *app_window; //On this time one app can contain only one window
};

#endif // APPLICATION_H
