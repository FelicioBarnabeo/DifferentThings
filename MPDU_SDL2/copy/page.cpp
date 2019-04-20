#include "page.h"
#include "texturemngr.h"
#include <iostream>

Page::Page(std::string name): m_name(name)
{
    m_parent = name;
    m_pressedButton = nullptr;
}

Page::Page(std::string name,std::string parent): m_name(name)
{
    m_parent = parent;
    m_pressedButton = nullptr;
}

Page::~Page()
{
    for(auto var : m_elementArray)
    {
        delete var;
    }
}

void Page::addElement(Element *elem)
{
    m_elementArray.push_back(elem);
}

void Page::setParent(std::string parent)
{
    m_parent = parent;
}

void Page::unsetPressedButton()
{
    //Сушествует ли зажатая кнопка
    if(pressedButton())
    {
        m_pressedButton->setReleaseState();
        m_pressedButton = nullptr;
    }
}

void Page::setPressedButton(Button *btn)
{
    m_pressedButton = btn;
    btn->setPressState(); //Избыточно, уже установлено состояние
}


