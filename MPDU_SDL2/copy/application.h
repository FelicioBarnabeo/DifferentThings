#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "texturemngr.h"


class Application
{
public:
    Application();
    ~Application();   
    void run();
    void createWindow(std::string title, int x, int y, int w, int h, WindowFlags flags=WindowFlags::SHOWN);
    void deleteWindow();
    void loadTexsture(std::string filename, std::string id);
    Window* window() const
    {
        return app_window;
    }
    bool quit = false;
    TTF_Font *m_font;

private:
    void init();
    void processInput();
    void rendering() const;
    TextureMngr* app_texstures = TextureMngr::Instance();
    Window *app_window; //On this time one app can contain only one window
};

#endif // APPLICATION_H
