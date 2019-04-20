#include "window.h"
#include <iostream>

Window::Window(std::string title, int x , int y, int w, int h, Uint32 flags,RenderFlags renflags)
{
    m_window = nullptr;
    m_ren = nullptr;
    createWindow(title, x, y, w, h, flags);
    createRenderer(renflags, -1);
    m_currentPage = nullptr;
}

Window::Window()
{
    m_window = nullptr;
    m_ren = nullptr;
    createWindow("Application", 0, 0, 500, 500, SHOWN);
    createRenderer(SOFTWARE, -1);
    m_currentPage = nullptr;
}

void Window::destroyWindow()
{
    if(m_window != nullptr && (m_ren != nullptr))
    {
        for(auto it = m_pagesBuffer.begin(); it!=m_pagesBuffer.end();it++)
        {
            delete (*it).second;
        }
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_ren);
    }
}

Window::~Window()
{

    destroyWindow();
}

Window* Window::createWindow(std::string title, int x, int y, int w, int h, Uint32 flags)
{
//    if(m_window != nullptr)
//    {
//        destroyWindow();
//    }
    m_window = SDL_CreateWindow(title.c_str(), x, y, w, h, static_cast<Uint32>(flags)); /*FULLSCREEN_DESKTOP | BORDERLESS*/
    if(m_window == nullptr)
    {
        std::cout<< "CreateWindow Error: "<< SDL_GetError() << std::endl;
        exit(1);
    }
    return this;
}

void Window::createRenderer(RenderFlags flags, int driverIndex)
{
//    if(m_ren != nullptr)
//    {
//        SDL_DestroyRenderer(m_ren);
//    }
    m_ren = SDL_CreateRenderer(m_window, driverIndex, static_cast<Uint32>(flags));
    if(m_ren == nullptr){
        std::cout << "CreateRendere Error" << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Window::addPage(Page &page)
{
    std::string name = page.id();
    m_pagesBuffer[name] = &page;
}

void Window::toPage(std::string name)
{
    currentPage().unsetPressedButton();
    setCurrentPage(name);
}

void Window::toParrent()
{
    setCurrentPage(currentPage().parent());
}


void Window::draw(TextureMngr *manager)
{
    SDL_RenderClear(m_ren);
    for(auto var : currentPage().elements())
    {
        //std::cout<< var->getTextureid()<<std::endl;
        manager->Draw(var,m_ren);
    }
}

void Window::handle(SDL_Event *evnt)
{
    //std::cout<< "Handle event" << evnt->type << std::endl;

    //Если есть зажатая кнопка
    if(currentPage().pressedButton() != nullptr)
    {
        std::cout<<"id:"<<currentPage().id()<<"  texture id: ";
        std::cout<<currentPage().pressedButton()->getTextureid()<<std::endl;
        //Если событие произошло в пределах кнопки(движение мыши или отпуск)
        if(currentPage().pressedButton()->isIn(evnt->button))
        {
            currentPage().pressedButton()->handle(evnt);
            return;
        }
        //Иначе отжать кнопку и не обрабатывать
        else
        {
            currentPage().unsetPressedButton();
            return;
        }
    }
    //Иначе по циклу проверить по событию какой элемент нужно обработать
    else
    {
        //std::cout<<"current press button NOT ready"<<std::endl;
        for(auto var : currentPage().elements())
        {
            if(var->isIn(evnt->button))
            {
                //Если событие это нажатие кнопки, то установить зажатую кнопку
                //И подготовить к обработке нажатия
                if(var->handle(evnt))
                {
                    currentPage().setPressedButton(dynamic_cast<Button*>(var));
                    return;
                }
            }
        }
    }
}

void Window::setCurrentPage(std::string name)
{
    if(m_pagesBuffer.find(name) != m_pagesBuffer.end())
        m_currentPage = m_pagesBuffer[name];
}

std::unordered_map<std::string, Page*> Window::pagesBuffer() const
{
    return m_pagesBuffer;
}
