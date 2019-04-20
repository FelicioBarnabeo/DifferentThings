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
protected:
    void setTextureid(string id)
    {
        textureid = id;
    }
public:
    explicit Element(int x, int y, int w, int h, string txtid);
    virtual ~Element();
    bool isIn(SDL_MouseButtonEvent event) const;
    virtual bool handle(SDL_Event *event);
    SDL_Rect getRect() const;    
    string getTextureid() const
    {
        return textureid;
    }
};

class Button : public Element
{
private:
    bool m_readyToClick;
    enum State{RELEASED,PRESSED}m_state;
    const string  imgoff;
    const string imgon;
    void setState(State st)
    {
        m_state = st;
    }
public:
    bool handle(SDL_Event *event);
    Button();
    explicit Button(int x, int y, int w, int h, string on, string off);
    ~Button();
    void setPressState();
    void setReleaseState();
    int getState() const
    {
        return m_state;
    }   
    void (*onClick)();
    bool readyToClick() const {return m_readyToClick;}
    void setReadyToClick(bool var){m_readyToClick = var;}

};

#endif // BUTTON_H
