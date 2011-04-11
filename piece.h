#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

//direction
#define UP 	1
#define RIGHT	2
#define DOWN	3
#define LEFT	4

class piece{
	private:
		float posx;
		float posy;
		SDL_Surface * img;
		int direction;
		bool die;
	public:
		piece();
		piece(string);
		piece(float,float,string);
		piece(float,float,int,string);
		~piece();
		
		float getPosX() const;
		float getPosY() const;
		SDL_Surface * getImg() const;
		int getDirection() const;
		bool getDie() const;
		
		void setDie(bool);
		void setPosX(float);
		void setPosY(float);
		void setImg(string);
		void setImg(SDL_Surface *);
		void setDirection(int);
		
		void move();
		void draw(SDL_Surface *);
};
#endif
