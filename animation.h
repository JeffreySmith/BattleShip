#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "SDL.h"
#include "SDL_image/SDL_image.h"
#include <stdarg.h>
class animation
{
private:
	int numberOfAnimations;
	SDL_Surface *currentImage;
	SDL_Surface **images;
public:
	//Pass the number of images, then the path of each image
	animation(int,...);
	
	~animation();
};
