#ifndef PAGE_H
#define PAGE_H

#include "button.h"
#include <vector>
#include <string>

class Page
{
public:
    explicit Page(std::string name);
    explicit Page(std::string name, std::string parent);
    ~Page();
    Page(const Page &rhs);
    Page& operator =(const Page &rhs);
    //void draw(TextureMngr *manager);
    std::string id() const
    {
        return m_name;
    }
    std::vector<Element *> elements() const
    {
        return m_elementArray;
    }
    void addElement(Element *elem);
    void setParent(std::string);
    std::string parent() const
    {
        return m_parent;
    }
    void setPressedButton(Button *btn);
    void unsetPressedButton();
    Button* pressedButton() const {return m_pressedButton;}
private:
    Button *m_pressedButton;
    std::string m_parent;
    std::string m_name;
    std::vector<Element *> m_elementArray;

};

#endif // PAGE_H
