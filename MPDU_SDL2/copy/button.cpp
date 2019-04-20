#include "button.h"
#include <iostream>




Element::Element(int x, int y, int w, int h, string txtid):
    x(x),y(y),w(w),h(h),textureid(txtid)
{

}

Element::~Element(){

}

SDL_Rect Element::getRect() const
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;
    return rect;
}

bool Element::isIn(SDL_MouseButtonEvent event) const
{
    return ((event.x >= x) && (event.x <= x + w) &&
            (event.y >= y) && (event.y <= y + h));
}

bool Element::handle(SDL_Event *event)
{
    return false;
}


//Для кнопки есть 2 текстуры в отличие от класса элемент
//Поэтому по умолчанию texstureid устанавливается в текстуру "отключенную-off"
Button::Button(int x, int y, int w, int h, string off, string on)
    :Element(x,y,w,h,off),imgoff(off),imgon(on)
{
    onClick = [](){};
    m_state = State::RELEASED;
    m_readyToClick = false;
}

Button::~Button()
{

}

bool Button::handle(SDL_Event *event)
{
    switch(event->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        setPressState();
        return true;
    case SDL_MOUSEBUTTONUP:
        setTextureid(imgoff);
        if(m_readyToClick)
            onClick();
        return false;
    case SDL_MOUSEMOTION:
        return false;
    default:
        return false;
    }
}

void Button::setPressState()
{
    m_readyToClick = true;
    setTextureid(imgon);
}

void Button::setReleaseState()
{
    m_readyToClick = false;
    setTextureid(imgoff);
}



