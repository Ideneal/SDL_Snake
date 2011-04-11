#include "point.h"

Point::Point(){
	this->posx = 0;
	this->posy = 0;
	this->img = NULL;
	this->point = 5;
}

Point::Point(string name){
	srand(time(NULL));
	int px = rand() % 40; // da 0 a 39
	int py = rand() % 30; // da 0 a 29
	this->posx = px * 16;
	this->posy = py * 16;
	
	this->point = 5;
	this->setImg(name);
}

Point::Point(float px, float py, string name){
	this->posx = px;
	this->posy = py;
	this->point = 5;
	this->setImg(name);
}

Point::~Point(){
	SDL_FreeSurface(this->img);
	this->img = NULL;
}

float Point::getPosX() const{
	return this->posx;
}

float Point::getPosY() const{
	return this->posy;
}

int Point::getPoint() const {
	return this->point;
}

void Point::setPosX(float px){
	this->posx = px;
}

void Point::setPosY(float py){
	this->posy = py;
}

void Point::setPoint(int n){
	this->point = n;
}

void Point::setImg(string name){
	SDL_Surface * oldimg = IMG_Load(name.c_str());
	if(oldimg == NULL){
		cout << "Errore caricamento immagine: "<<SDL_GetError()<<endl;
		return ;
	}
	this->img = SDL_DisplayFormat(oldimg);
	SDL_FreeSurface(oldimg);
	
	if(this->img == NULL)
		cout << "Errore aggiornamento immagine: "<<SDL_GetError()<<endl;
}

void Point::draw(SDL_Surface * screen){
	SDL_Rect * rect = new SDL_Rect();
	rect->x = this->posx;
	rect->y = this->posy;
	
	SDL_BlitSurface(this->img, NULL, screen, rect);
	delete rect;
}
	
