#ifndef NPC3_H
#define NPC3_H

#include "Personaje.h"

class NPC3:public Personaje
{
    public:
        NPC3(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC3();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC3_H
