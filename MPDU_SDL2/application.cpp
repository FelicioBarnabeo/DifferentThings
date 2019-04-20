#include "application.h"
#include <iostream>
#include <cstring>

Application::Application()
{
    init();
}

Application::~Application()
{
    //deleteWindow();
}

void Application::init()
{
    m_language = "russian"; //by default
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    app_window = new Window();
}

void Application::changeLanguage()
{
    if(m_language=="english")
        m_language = "russian";
    else if(m_language=="russian")
        m_language="english";
    app_texstures->setLanguage(m_language);
}

void Application::setLanguage(std::string lang)
{
    //nothing by default
}

void Application::createWindow(std::string title, int x, int y, int w, int h, Uint32 flags)
{
    delete app_window;
    app_window = new Window(title, x, y, w, h, flags, SOFTWARE);
}

void Application::deleteWindow()
{
    if(app_window != nullptr)
    {
        delete app_window;
        app_window = nullptr;
    }
}



void Application::run()
{
    while(true)
    {
        processInput();
        rendering();
    }
}

void Application::rendering() const
{
    app_window->draw(app_texstures);
    SDL_RenderPresent(app_window->render());
    SDL_Delay(1);
}

void Application::processInput()
{
    static SDL_Event event;
    while(SDL_PollEvent(&event) )
    {
        SDL_PumpEvents();
        app_window->handle(&event);
    }
}

void Application::loadTexsture(std::string language,std::string filename, std::string id)
{
     if (!(TextureMngr::Instance()->Load(language,app_window->render(),filename,id)))
     {
             cout<<"Warning"<<std::endl;
             cout<<"Not found file: "<< filename << std::endl;
    }
}

