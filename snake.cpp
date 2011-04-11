#include "snake.h"

void Snake::init(){
	//head
	piece * head = new piece(16*25, 16*20, RIGHT, "head.png");
	this->snake.push_back(head);
	//body
	for(int i=24; i>20; i--){
		piece * body = new piece(16*i, 16*20, RIGHT, "piece.png");
		this->snake.push_back(body);
	}
}

Snake::Snake(){
	this->init();
	this->points = 0;
	this->end = false;
}

Snake::~Snake(){
	for(int i=0; i< (int) this->snake.size(); i++)
		delete snake[i];
}

int Snake::getPoints() const{
	return this->points;
}

piece * Snake::getTesta() const{
	return this->snake[0];
}

int Snake::getDirection() const{
	return (this->snake[0])->getDirection();
}

bool Snake::getEnd() const{
	return this->end;
}

bool Snake::isThereOnAPoint(Point * asd) const{
	bool sovrapposizione = false;
	for(int i=0; i<(int)this->snake.size(); i++){
		if (asd->getPosX() == (this->snake[i])->getPosX() && asd->getPosY() == (this->snake[i])->getPosY())
			sovrapposizione = true;
	}
	
	return sovrapposizione;
}

void Snake::setEnd(bool e){
	this->end = e;
}

void Snake::setPoints(int n){
	this->points = n;
}

void Snake::addPoint(){
	this->points++;
}

void Snake::addPoint(int n){
	this->points += n;
}

void Snake::setDirection(int d){
	(this->snake[0])->setDirection(d);
}

void Snake::pushPiece(){
	int px,py,dir;
	px = (this->snake[ (int)this->snake.size() - 1 ] )->getPosX();
	py = (this->snake[ (int)this->snake.size() - 1 ] )->getPosY();
	dir = (this->snake[ (int)this->snake.size() - 1 ] )->getDirection();
	
	piece * coda = NULL;
	
	switch(dir){
		case UP:
			coda = new piece(px,py+16,dir,"piece.png");
			break;
		case DOWN:
			coda = new piece(px,py-16,dir,"piece.png");
			break;
		case RIGHT:
			coda = new piece(px-16,py,dir,"piece.png");
			break;
		case LEFT:
			coda = new piece(px+16,py,dir,"piece.png");
			break;
	}
	
	this->snake.push_back(coda);
}

void Snake::move(){
	for(int i = 0; i<(int)this->snake.size(); i++)
		(this->snake[i])->move();
	for(int i = (int)this->snake.size() - 1 ; i>0 ; i--)
		(this->snake[i])->setDirection( (this->snake[i-1])->getDirection() );
	
	for(int i = 0; i<(int)this->snake.size(); i++)
		if((this->snake[i])->getDie())
			this->end = true;
	
	int px,py;
	px = (this->snake[0])->getPosX();
	py = (this->snake[0])->getPosY();
	for(int i = 1; i<(int)this->snake.size(); i++)
		if((this->snake[i])->getPosX() == px && (this->snake[i])->getPosY() == py)
			this->end = true;
}

void Snake::draw(SDL_Surface * screen){
	for(int i = 0; i<(int)this->snake.size(); i++)
		(this->snake[i])->draw(screen);
}
