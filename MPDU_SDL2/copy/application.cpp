#include "application.h"
#include <iostream>

Application::Application()
{
    init();
}

Application::~Application()
{
    TTF_CloseFont(m_font);
    //deleteWindow();
}

void Application::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    if(TTF_Init() == -1){
        std::cout<<" TTF_Init Error" << TTF_GetError() << std::endl;
        exit(1);
    }
    m_font = TTF_OpenFont("resources/fonts/Scada/Scada-Bold.ttf",15);
    if( m_font == nullptr)
    {
        std::cout << "TTF_OpenFont" << TTF_GetError() << std::endl;
        exit(1);
    }

    app_window = new Window();
}

void Application::createWindow(std::string title, int x, int y, int w, int h, WindowFlags flags)
{
    delete app_window;
    app_window = new Window(title, x, y, w, h, flags, RenderFlags::SOFTWARE);
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
    while(!quit)
    {
        processInput();
        rendering();
    }
}

void Application::rendering() const
{   
    app_window->draw(app_texstures);
    SDL_Surface *solid =  TTF_RenderText_Solid(m_font,"Mylabel",{0,0,0,0});
    SDL_Texture *txtsolid = SDL_CreateTextureFromSurface(app_window->render(),solid);
    SDL_Rect recttxt;
    SDL_QueryTexture(txtsolid,nullptr,nullptr,&recttxt.w,&recttxt.h);
    recttxt.x = 30;
    recttxt.y = -3;
    SDL_RenderCopy(app_window->render(),txtsolid,nullptr,&recttxt);
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

void Application::loadTexsture(std::string filename, std::string id)
{
     TextureMngr::Instance()->Load(app_window->render(),filename,id);
}

