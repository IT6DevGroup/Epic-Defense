#ifndef TIMER_H
#define TIMER_H

#include <windows.h>

class GameTimer
{
public:
	GameTimer();

	void tick();
	void reset();
	void start();
	void stop();

	double getGameTime()	const;
	double getDeltaTime()	const;

protected:

private:
	double secondsPerCount;
	double deltaTime;

	bool ticking;

	__int64 baseTime;
	__int64 pausedTime;
	__int64 stopTime;
	__int64 previousTime;
	__int64 currentTime;

};

#endif