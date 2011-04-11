#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include <time.h>
#include "piece.h"
#include "snake.h"
#include "point.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_DEPTH 32

using namespace std;

SDL_Surface * loadbg(string name){
	SDL_Surface * oldimg = IMG_Load(name.c_str());
	if (oldimg == NULL){
		cout << "Error to load background : " << SDL_GetError()<<endl;
		return NULL;
	}
	SDL_Surface * bg = SDL_DisplayFormat(oldimg);
	SDL_FreeSurface(oldimg);
	return bg;
}

int main() {
	int px,py; 
	srand(time(NULL));
	
	SDL_Surface * screen = 0;
	bool running = true;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SDL_SWSURFACE | SDL_DOUBLEBUF);
	
	Snake * snk = new Snake();
	Point * punto = new Point("point.png");
	
	SDL_Surface * bg = loadbg("black_background.bmp");
	bool pointexist = true;
	
	SDL_Event * event = new SDL_Event();
     	while(!snk->getEnd()){
     		while(SDL_PollEvent(event)){
     			if(event->type == SDL_QUIT)
     				snk->setEnd(true);
     			else if(event->type == SDL_KEYDOWN){
     				if(event->key.keysym.sym == SDLK_UP)
     					snk->setDirection(UP);
     				if(event->key.keysym.sym == SDLK_DOWN)
     					snk->setDirection(DOWN);
     				if(event->key.keysym.sym == SDLK_LEFT)
     					snk->setDirection(LEFT);
     				if(event->key.keysym.sym == SDLK_RIGHT)
     					snk->setDirection(RIGHT);
     			}
     		}
     		SDL_BlitSurface(bg, NULL, screen, NULL);
     		snk->move();
     		snk->draw(screen);
     		
     		if(pointexist){
     			if( (snk->getTesta())->getPosX() == punto->getPosX() && (snk->getTesta())->getPosY() == punto->getPosY()){
     				snk->pushPiece();
     				snk->addPoint(punto->getPoint());
     				delete punto;
     				pointexist = false;
     			}
     			punto->draw(screen);
     		}else{
     			px = (rand() % 40) * 16;
			py = (rand() % 30) * 16;
			punto = new Point(px, py, "point.png");
     			while(snk->isThereOnAPoint(punto)){
     				delete punto;
     				px = (rand() % 40) * 16;
				py = (rand() % 30) * 16;
				punto = new Point(px, py, "point.png");
			}
     			pointexist = true;
     		}
     		
     		if(SDL_Flip(screen) == -1)
     			return 1;
     		SDL_Delay(100);
    	}
    	
    	cout << "Punteggio totale: "<<snk->getPoints()<<endl;
    	delete snk;
    	delete punto;
    	SDL_FreeSurface(screen);
    	SDL_FreeSurface(bg);
    	SDL_Quit();
    	return 0;
}
