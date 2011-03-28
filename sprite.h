#ifndef SPRITE_H_
#define SPRITE_H_
#include "SDL.h"

class sprite
{
private:
	SDL_Surface *optimizedImage;	
	SDL_Surface *image;
        
public:
	struct area
	{
		int x;
		int y;
		int h;
		int w;
		//Used only if the object is a circle, or we want circular collision detection
		int r;
	};
		
		
	sprite();
	//Should be set in your constructor, unless you want your sprite to be at 0,0.
	int x,y;
		
	//These are retrieved when you load an image, don't worry about them.
	int width,height;
		
	//Gets the distance between two points
	double distance(int,int,int,int);
	
	//Loads an image
	int loadImage(char *);
	//This loads an image into a specific SDL_Surface
	int loadImage(char*,SDL_Surface*);
		
	//The argument passed to draw MUST be the screen
	//If you don't, there will be strange artifacts on the screen.
	void draw(SDL_Surface *);
		
	//This compares two structs. The callers struct is implied
	bool checkCollision(struct area*);
		
	//Circular collision
	bool checkCircleCollision(struct area*);
	//Actual decleration of the collision struct
	struct area *collisionControl;
		
		
	~sprite();
		
};
#endif /*SPRITE_H_*/
