#ifndef NPC4_H
#define NPC4_H

#include "Personaje.h"


class NPC4:public Personaje
{
    public:
        NPC4(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC4();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC4_H
