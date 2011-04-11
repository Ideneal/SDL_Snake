#include "piece.h"

piece::piece(){
	this->posx = 0;
	this->posy = 0;
	this->img = NULL;
	this->direction = 1;
	this->die = false;
}

piece::piece(string name){
	this->posx = 0;
	this->posy = 0;
	this->setImg(name);
	this->direction = 1;
	this->die = false;
}

piece::piece(float px, float py, string name){
	this->posx = px;
	this->posy = py;
	this->setImg(name);
	this->direction = 1;
	this->die = false;
}

piece::piece(float px, float py, int d, string name){
	this->posx = px;
	this->posy = py;
	this->setImg(name);
	if(d>0 && d<5)
		this->direction = d;
	else 
		this->direction = 1;
	this->die = false;
}

piece::~piece(){
	SDL_FreeSurface(this->img);
}

float piece::getPosX() const{
	return this->posx;
}

float piece::getPosY() const{
	return this->posy;
}

SDL_Surface * piece::getImg() const{
	return this->img;
}

int piece::getDirection() const {
	return this->direction;
}

bool piece::getDie() const{
	return this->die;
}

void piece::setDie(bool d){
	this->die = d;
}

void piece::setPosX(float px){
	this->posx = px;
}

void piece::setPosY(float py){
	this->posy = py;
}

void piece::setImg(string name){
	SDL_Surface * oldimg = IMG_Load(name.c_str());
	if(oldimg == NULL){
		cout << "Errore caricamento immagine : "<<SDL_GetError()<<endl;
	}else{
		this->img = SDL_DisplayFormat(oldimg);
		SDL_FreeSurface(oldimg);
		if(this->img == NULL)
			cout << "Errore aggiornamento immagine : "<<SDL_GetError()<<endl;
	}
}

void piece::setImg(SDL_Surface * sdlimg){
	this->img = sdlimg;
}

void piece::setDirection(int d){
	if(d>0 && d<5 && this->direction != d){
		if( ( (this->direction % 2) == 0 && (d%2)!=0) || ( (this->direction%2) != 0 && (d%2) == 0))
			this->direction = d;
	}
}

void piece::move(){
	switch (this->direction){
		case UP:
			this->posy -= 16;
			break;
		case DOWN:
			this->posy += 16;
			break;
		case RIGHT:
			this->posx += 16;
			break;
		case LEFT:
			this->posx -= 16;
			break;
	}
	
	if((this->getPosX() < 0 || this->getPosX() > 640-16) || (this->getPosY() < 0 || this->getPosY() > 480-16))
		this->die = true;
}

void piece::draw(SDL_Surface * screen){
	SDL_Rect * rect = new SDL_Rect();
	rect->x = this->posx;
	rect->y = this->posy;
	
	SDL_BlitSurface(this->img, NULL, screen, rect);
	delete rect;
	SDL_Flip(this->img);
}
