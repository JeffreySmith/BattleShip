#include "button.h"
#include "SDL.h"
	
button::button(int xPos,int yPos)
{
	x=xPos;
	y=yPos;
	mouseOver=NULL;
	mouseDown=NULL;
}
button::button(int xPos,int yPos,char *regularImage,char *mouseDownImage,char *mouseOverImage)
{
	x=xPos;
	y=yPos;
	loadImage(regularImage,displayedImage);
	loadImage(mouseDownImage,mouseDown);
	loadImage(mouseOverImage,mouseOver);
}
button::~button()
{
	if(mouseOver!=NULL)
	{
		SDL_FreeSurface(mouseOver);
	}
	if(mouseDown!=NULL)
	{
		SDL_FreeSurface(mouseDown);
	}
	if(displayedImage!=NULL)
	{
		SDL_FreeSurface(displayedImage);
	}

	  
	bool button::MOUSEOVER(SDL_Event *event)
	{
		int mouseX=event->motion.x;
		int mouseY=event->motion.y;
		if(event->type==SDL_MOUSEMOTION)
		{
			if( (mouseX>x && mouseX < x+width) && (mouseY >y && mouseY<y+height))
			{
				this->setImage(mouseOver);
				return true;
			}
		}
		return false;
	}
	bool button::MOUSEDOWN(SDL_Event *event)
	{
		int mouseX=event->motion.x;
		int mouseY=event->motion.y;
		if(MOUSEOVER(event))
		{
			if(event->type==SDL_MOUSEBUTTONDOWN)
			{
				this->setImage(mouseDown);
				return true;
			}
		
		}
		return false;
	}
