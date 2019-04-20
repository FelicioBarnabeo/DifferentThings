#ifndef BUTTON_H
#define BUTTON_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

using namespace std;

class Element
{
    const int x, y;
    const int w, h;
    string textureid;
public:
    explicit Element(int x, int y, int w, int h, string txtid);
    virtual ~Element();
    bool isIn(SDL_MouseButtonEvent event) const;
    virtual bool handle(SDL_Event *event);
    SDL_Rect getRect() const;
    void setTextureid(string id)
    {
        textureid = id;
    }
    string getTextureid() const
    {
        return textureid;
    }
};

class Button : public Element
{
private:
    const string text;
    const string  imgoff;
    const string imgon;
    bool m_readyToClick;
    enum State{RELEASED,PRESSED};
    State m_state;
public:
    bool handle(SDL_Event *event);
    Button();
    explicit Button(int x, int y, int w, int h, string on, string off);
    explicit Button(int x, int y, int w, int h, string name);
    ~Button();
    void setPressState();
    void setReleaseState();
    int getState() const
    {
        return m_state;
    }
    void setState(State st)
    {
        m_state = st;
    }
    void (*onClick)();
    bool readyToClick() const {return m_readyToClick;}
    void setReadyToClick(bool var){m_readyToClick = var;}
};

#endif // BUTTON_H
