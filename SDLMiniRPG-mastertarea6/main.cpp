
#include <SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<fstream>
#include "PersonajeJugador.h"
#include "NPC.h"
#include "NPC2.h"
#include "NPC3.h"
#include "NPC4.h"


#include <stdlib.h>

   /* srand, rand */

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character,*game_over;
SDL_Rect rect_background,rect_character;

class Tile
{
public:
    int fuente_x;
    int fuente_y;
    int destino_x;
    int destino_y;
    Tile(int fuente_x, int fuente_y, int destino_x, int destino_y)
    {
        this->fuente_x=fuente_x;
        this->fuente_y=fuente_y;
        this->destino_x=destino_x;
        this->destino_y=destino_y;
    }
};

vector<Tile*> cargarTiles(string nombre_archivo)
{
    vector<Tile*> tiles;
    ifstream archivo(nombre_archivo.c_str());
    for(int destino_y=0; destino_y<10; destino_y++)
    {
        for(int destino_x=0; destino_x<10; destino_x++)
        {
            int fuente_x;
            int fuente_y;
            archivo>>fuente_x;
            archivo>>fuente_y;
            tiles.push_back(new Tile(fuente_x,fuente_y,destino_x,destino_y));
        }
    }
    archivo.close();
    return tiles;
}


void dibujarTile(SDL_Texture *tileset_texture, SDL_Renderer* renderer,
        int fuente_x, int fuente_y, int destino_x, int destino_y)
{
    SDL_Rect fuente,destino;
    fuente.x = 32*fuente_x;
    fuente.y = 32*fuente_y;
    fuente.w = 32;
    fuente.h = 32;

    destino.x = 32*destino_x;
    destino.y = 32*destino_y;
    destino.w = 32;
    destino.h = 32;


    SDL_RenderCopy(renderer,tileset_texture,&fuente,&destino);
}

void loopGameover(){
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_c ){

                        //loopMenu();
                }
            }
        }

        SDL_RenderCopy(renderer, game_over, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

int main( int argc, char* args[] )
{
    cargarTiles("assets/tile.map");
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 500/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;
game_over=IMG_LoadTexture(renderer,"game_over.png");
    character = IMG_LoadTexture(renderer, "assets/personaje/down.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;


    list<Personaje*>personajes;
    personajes.push_back(new PersonajeJugador (425,100,renderer,&personajes));
    //personajes.push_back(new NPC (50,100,renderer,&personajes));
//casas
    personajes.push_back(new NPC3 (100,0,renderer,&personajes));
    personajes.push_back(new NPC3 (0,200,renderer,&personajes));
    personajes.push_back(new NPC3 (0,260,renderer,&personajes));

 //arboles
 personajes.push_back(new NPC4 (100,300,renderer,&personajes));
    personajes.push_back(new NPC4 (160,300,renderer,&personajes));
    personajes.push_back(new NPC4 (220,300,renderer,&personajes));


    SDL_Texture* tileset_texture = IMG_LoadTexture(renderer, "assets/tileset.png");
    vector<Tile*>tiles=cargarTiles("assets/tile.map");

    //Main Loop
    int frame=0;
    int conts=0;
    int frame2=0;
    int conts2=0;

    while(true)
    {


            //para los npc 1
            frame++;
            if(frame%100==0 && conts<3){
//                personajes.push_back(new NPC (50,rand() % 50,renderer,&personajes));
                    personajes.push_back(new NPC (50,100,renderer,&personajes));
                conts++;
            }

            //para el dragon


             frame2++;
            if(frame2%400==0 && conts2<3){
//                personajes.push_back(new NPC (50,rand() % 50,renderer,&personajes));
                    personajes.push_back(new NPC2 (400,350,renderer,&personajes));
                conts2++;
            }else if(conts2==5){

                loopGameover();
            }

        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
//        for(int i=0;i<tiles.size();i++)
//        {
//            dibujarTile(tileset_texture,renderer,
//                    tiles[i]->fuente_x,tiles[i]->fuente_y,
//                    tiles[i]->destino_x,tiles[i]->destino_y);
//        }
//
//        dibujarTile(tileset_texture,renderer,
//                    0,6,
//                    5,4);

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);
    }

	return 0;
}
