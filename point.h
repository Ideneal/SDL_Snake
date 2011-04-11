#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>

using namespace std;

class Point{
	private:
		float posx;
		float posy;
		int point;
		SDL_Surface * img;
	public:
		Point();
		Point(string);
		Point(float, float, string);
		~Point();
		
		float getPosX() const;
		float getPosY() const;
		int getPoint() const;
		
		void setPosX(float);
		void setPosY(float);
		void setPoint(int);
		void setImg(string);
		
		void draw(SDL_Surface *);
};
#endif
