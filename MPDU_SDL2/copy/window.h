#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <unordered_map>
#include "page.h"
#include "texturemngr.h"

enum class WindowFlags
{
    FULLSCREEN         = SDL_WINDOW_FULLSCREEN,
    FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP, //fullscreen window at the current desktop resolution
    OPENGL             = SDL_WINDOW_OPENGL,        //window usable with OpenGL context
    SHOWN              = SDL_WINDOW_SHOWN,         //window is visible
    HIDDEN             = SDL_WINDOW_HIDDEN,        //window is not visible
    BORDERLESS         = SDL_WINDOW_BORDERLESS,    //no window decoration
    RESIZABLE          = SDL_WINDOW_RESIZABLE,     //window can be resized
    MINIMIZED          = SDL_WINDOW_MINIMIZED,     //window is minimized
    MAXIMIZED          = SDL_WINDOW_MAXIMIZED,     //window is maximized
    INPUT_GRABBED      = SDL_WINDOW_INPUT_GRABBED, //window has grabbed input focus
    INPUT_FOCUS        = SDL_WINDOW_INPUT_FOCUS,   //window has input focus
    MOUSE_FOCUS        = SDL_WINDOW_MOUSE_FOCUS,   //window has mouse focus
    FOREIGN            = SDL_WINDOW_FOREIGN,       //window not created by SDL
    HIGHDPI            = SDL_WINDOW_ALLOW_HIGHDPI, //window should be created in high-DPI mode if supported (>= SDL 2.0.1)
    //MOUSE_CAPTURE      = SDL_WINDOW_MOUSE_CAPTURE  //window has mouse captured (unrelated to INPUT_GRABBED, >= SDL 2.0.4)
};

enum class RenderFlags
{
    SOFTWARE      = SDL_RENDERER_SOFTWARE,      //the renderer is a software fallback
    ACCELERATED   = SDL_RENDERER_ACCELERATED,   //the renderer uses hardware acceleration
    PRESENTVSYNC  = SDL_RENDERER_PRESENTVSYNC,  //present is synchronized with the refresh rate
    TARGETTEXTURE = SDL_RENDERER_TARGETTEXTURE, //the renderer supports rendering to texture
};

class Window
{
public:
    Window();
    explicit Window(std::string title , int x , int y, int w, int h, WindowFlags flags, RenderFlags renflags);
    ~Window();
    Window* createWindow(std::string title, int x, int y, int w, int h, WindowFlags flags);
    void destroyWindow();
    void createRenderer(RenderFlags flags , int driverIndex );
    void addPage(Page &page);
    SDL_Renderer * render() const
    {
        return m_ren;
    }
    void draw(TextureMngr *manager);
    void handle(SDL_Event* evnt);
    Page& currentPage() const
    {
        return *m_currentPage;
    }
    void toPage(std::string name);
    void setCurrentPage(std::string name);
    void lock(){m_lock = true;}
    void unlock(){m_lock = false;}
    int getlock(){return m_lock;}
private:
    static bool m_lock;
    Page* m_currentPage;
    SDL_Renderer *m_ren; //This is main render for window, whithout this cant drawing
    SDL_Window *m_window;
    std::unordered_map<std::string, Page *> pagesBuffer;

};

#endif // WINDOW_H
