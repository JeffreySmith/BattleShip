#include "SDL.h"
#include "timer.h"
Timer::Timer()
{
	startTicks=0;
	pausedTicks=0;
	paused=false;
	started=false;
}
void Timer::start()
{
	started=true;
	paused=false;
	
	startTicks=SDL_GetTicks();
}
void Timer::stop()
{
	started=false;
	paused=false;
}
int Timer::getTicks()
{
	if(started)
	{
		if(paused)
		{
			return pausedTicks;
		}
		else
		{
			return SDL_GetTicks()-startTicks;
		}
	}
	else
	{
		return 0;
	}
}
void Timer::pause()
{
	if(started && !paused)
	{
		paused=true;
		pausedTicks=SDL_GetTicks()-startTicks;
	}
}
void Timer::play()
{
	if(paused)
	{
		paused=false;
		startTicks=SDL_GetTicks()-pausedTicks;
		pausedTicks=0;
	}
}
bool Timer::isRunning()
{
	return started;
}
bool Timer::isPaused()
{
	return paused;
}