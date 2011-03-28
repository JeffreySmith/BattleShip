#ifndef TIMER_H_
#define TIMER_H_


class Timer
{
	private:
		int startTicks,pausedTicks;
		bool paused,started;
		
	public:
		Timer();
		void start();
		void stop();
		void pause();
		void play();
		
		int getTicks();
		
		bool isRunning();
		bool isPaused();
};
#endif /*TIMER_H_*/