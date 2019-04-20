#ifndef TEXTUREMNGR_H
#define TEXTUREMNGR_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <map>
#include "button.h"
#include "page.h"

using namespace std;

class TextureMngr
{
    static TextureMngr* m_Instance;
    std::map<string, SDL_Texture *> textureMap;
    TextureMngr();
    TextureMngr(const TextureMngr&) = delete;
    TextureMngr & operator=(const TextureMngr&) = delete;
    SDL_Renderer *ren;
public:
    ~TextureMngr();
    static TextureMngr* Instance();
    bool Load(SDL_Renderer *ren, string filename, string id);
    void Draw(Element *elem, SDL_Renderer *ren, SDL_Rect *clip = nullptr);
};

#endif // TEXTUREMNGR_H
