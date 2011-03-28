#include "sprite.h"
#include "SDL.h"
#include "SDL_image/SDL_image.h"
#include <cmath>

#define DEBUG 1

sprite::sprite()
{
	collisionControl=new struct area;
	
	image=NULL;
}
sprite::~sprite()
{
	
	if(image!=NULL)
	{
		SDL_FreeSurface(image);
	}
	delete collisionControl;
	
}

void sprite::draw(SDL_Surface *screen)
{
	SDL_Rect offset;
	offset.x=x;
	offset.y=y;
	
	SDL_BlitSurface(image,NULL,screen,&offset);
}
bool sprite::checkCollision(struct area *otherRect)
{
	if(collisionControl->x<=otherRect->x+otherRect->w && collisionControl->x+collisionControl->w>=otherRect->x)
	{
		if(collisionControl->y<=otherRect->y+otherRect->h && collisionControl->y+collisionControl->h>=otherRect->y)
		{
			return true;
		}
	}
	return false;
}
/*
  bool sprite::checkCircleCollision(struct area *otherRect)
  {
  if(distance(collisionControl->x,collisionControl->y,otherRect->x,otherRect->y)<collisionControl->r+otherRect->r)
  {
  return true;
  }
  else
  {
  return false;
  }
  }
  double distance(int x1,int y1,int x2,int y2)
  {
  return sqrt(pow(x2-x1,2) + pow (y2-y1,2));
  }
*/
int sprite::loadImage(char *filename)
{
	SDL_Surface* loadedImage = NULL;

	
	loadedImage = IMG_Load( filename);

	//check if the image loaded
	if( loadedImage != NULL )
	{
		//format the image to 32 bit
		image = SDL_DisplayFormat( loadedImage );

		//get rid of the old image
		SDL_FreeSurface( loadedImage );

		//make the background of the image transparent
		if(optimizedImage != NULL)
		{
			
			
			return 0;
			height=optimizedImage->h;
			width=optimizedImage->w;
			collisionControl->h=height;
			collisionControl->w=width;
		       
		}
	}
	return 1;
	
}
int sprite::loadImage(char *filename,SDL_Surface *imageStorage)
{
	SDL_Surface* loadedImage = NULL;

	
	loadedImage = IMG_Load( filename);

	//check if the image loaded
	if( loadedImage != NULL )
	{
		//format the image to 32 bit
		imageStorage = SDL_DisplayFormat( loadedImage );

		//get rid of the old image
		SDL_FreeSurface( loadedImage );

		//make the background of the image transparent
		if(optimizedImage != NULL)
		{
			 
			height=optimizedImage->h;
			width=optimizedImage->w;
			collisionControl->h=height;
			collisionControl->w=width;
			return 0;
		}
	       
	}
	return 1;
	
}
