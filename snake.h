#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "piece.h"
#include "point.h"

using namespace std;

class Snake{
	private:
		vector< piece * > snake;
		int points;
		bool end;
		
		void init();
	public:
		Snake();
		~Snake();
		
		int getPoints() const;
		piece * getTesta() const;
		/* direction: 1-up  2-right  3-down  4-left */
		int getDirection()const;
		bool getEnd() const;
		bool isThereOnAPoint(Point *) const;
		
		void setEnd(bool);
		void setPoints(int);
		void addPoint();
		void addPoint(int);
		void setDirection(int);
		
		void pushPiece();
		void move();
		void draw(SDL_Surface *);
};
#endif		
