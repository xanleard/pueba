#include "NPC2.h"

NPC2::NPC2(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc2/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/down2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";


    //resien agragado

    rayo_texture = IMG_LoadTexture(renderer,"assets/rayo.png");
    SDL_QueryTexture(rayo_texture, NULL, NULL,
                        &this->rayo_rect.w,
                        &this->rayo_rect.h);

    //
}

NPC2::~NPC2()
{
    //dtor
}

void NPC2::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

    rectangulo.x;

    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo))
            //rectangulo=temp;
            personajes->erase(i);
    }
}
