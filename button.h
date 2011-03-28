#ifndef BUTTON_H_
#define BUTTON_H_
#include "SDL.h"
#include "sprite.h"
class button: public sprite
{
private:
	SDL_Surface *mouseOver;
	SDL_Surface *mouseDown;
	SDL_Surface *displayedImage;
public:
	//Sets the position
	button(int,int);
	//Set the position and takes three image paths
	//1:Regularily displayed image 2: mouse down image 3: MouseOver image
	button(int,int,char*,char*,char*);
	//Checks to see if the mouse is down. Make sure to pass it the sdl_event every frame!
	//Returns true if the mouse is down.
	bool MOUSEDOWN(SDL_Event *);
	//Same goes for this, except it checks to see if the mouse is over.
	bool MOUSEOVER(SDL_Event *);
	~button();
		
};
#endif /*BUTTON_H_*/
