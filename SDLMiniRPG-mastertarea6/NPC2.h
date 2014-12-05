#ifndef NPC2_H
#define NPC2_H

#include "Personaje.h"

class NPC2: public Personaje
{
     public:
         SDL_Texture *rayo_texture;
        SDL_Rect rayo_rect;
        bool rayo_activado;
        int rayo_cooldown;
        int rayo_frame_actual;
        string rayo_orientacion;
        NPC2(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC2();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC2_H
