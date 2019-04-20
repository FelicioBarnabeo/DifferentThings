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
    //контейнер текстур где пара: ключ - язык, значение - контенер:
    // ключ- id  текстуры значение - сама текстура
    std::map<string, std::map<string, SDL_Texture *>> textureMap;
    TextureMngr();
    TextureMngr(const TextureMngr&) = delete;
    TextureMngr & operator=(const TextureMngr&) = delete;
    //SDL_Renderer *m_ren;
    std::string m_language;
public:
    ~TextureMngr();
    static TextureMngr* Instance();
    void setLanguage(std::string lang){m_language = lang;}
    std::string currentLanguage() const {return m_language;}
    bool Load(std::string language, SDL_Renderer *ren, string filename, string id);
    void Draw(Element *elem, SDL_Renderer *ren, SDL_Rect *clip = nullptr);
};

#endif // TEXTUREMNGR_H
