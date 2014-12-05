#include "NPC4.h"

NPC4::NPC4(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc2/arbol1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/arbol2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";
}

NPC4::~NPC4()
{
    //dtor
}

void NPC4::logic(Uint8* teclas_presionadas)
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
            rectangulo=temp;
            //personajes->erase(i);
    }
}
