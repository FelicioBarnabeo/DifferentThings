#include "texturemngr.h"


TextureMngr* TextureMngr::m_Instance = 0;

TextureMngr::TextureMngr()
{
    for(auto var : textureMap)
    {
        SDL_DestroyTexture(var.second);
    }
}

TextureMngr* TextureMngr::Instance()
{   
    if(m_Instance == nullptr)
    {
        m_Instance = new TextureMngr();
        return m_Instance;
    }
    return m_Instance;
}

TextureMngr::~TextureMngr()
{
    for(auto var : textureMap) {
        SDL_DestroyTexture(var.second);
    }
}

bool TextureMngr::Load(SDL_Renderer *ren,string filename, string id )
{
    SDL_Texture *tex = IMG_LoadTexture(ren,filename.c_str());
    if(tex == nullptr)
        return false;
    else{
        textureMap[id] = tex;
        return true;
    }
    return false; //something wrong
}

void TextureMngr::Draw(Element *elem, SDL_Renderer *ren, SDL_Rect *clip)
{
    SDL_Rect rect = elem->getRect();
    SDL_RenderCopy(ren,textureMap[elem->getTextureid()],clip,&rect);
}
