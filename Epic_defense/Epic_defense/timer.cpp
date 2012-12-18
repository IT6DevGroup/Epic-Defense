#include "timer.h"

GameTimer::GameTimer()
{
	ticking			= true;

	secondsPerCount	= 0.0;
	deltaTime		= -1.0;

	baseTime		= 0;
	pausedTime		= 0;
	previousTime	= 0;
	currentTime		= 0;

	__int64 countsPerSecond;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSecond);

	secondsPerCount	= 1.0 / (double)countsPerSecond;
}

void GameTimer::tick()
{
	if(!ticking)
		deltaTime = 0.0;
	else
	{
		__int64 currentTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		this->currentTime = currentTime;
		deltaTime = (this->currentTime - this->previousTime) * secondsPerCount;

		if(deltaTime < 0.0)
			deltaTime = 0.0;

		previousTime = this->currentTime;
	}
}

void GameTimer::reset()
{
	ticking			= true;
	stopTime		= 0;

	__int64 currentTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

	baseTime		= currentTime;
	previousTime	= currentTime;
}
void GameTimer::start()
{
	if(!ticking)
	{
		__int64 startTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

		pausedTime		+= (startTime - stopTime);

		previousTime	= startTime;
		stopTime		= 0;
		ticking			= true;
	}
}
void GameTimer::stop()
{
	if(ticking)
	{
		__int64 currentTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

		stopTime		= currentTime;
		ticking			= false;
	}
}

double GameTimer::getGameTime() const
{
	double runTime = -1.0;

	if(!ticking)
		runTime = (stopTime - baseTime) * secondsPerCount;
	else
		runTime = ((currentTime - pausedTime) - baseTime) * secondsPerCount;

	return runTime;
}
double GameTimer::getDeltaTime() const
{
	return deltaTime;
}