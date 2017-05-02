//header guard
#pragma once

class cTimer
{
	public:
	cTimer();

	void Start();
	void Stop();
	void Pause();
	void Unpause();
	bool IsStarted();
	bool IsPaused();

	Uint32 GetTicks();

	private:
	Uint32 PauseTick,
		   StartTick;

	bool Started,
	     Paused;

}TD2DE_FPSTIMER, TD2DE_CAPTIMER;

int TD2DE_CurrentFrame = 0,
	TD2DE_Fps = 0;

cTimer::cTimer()
{
	PauseTick = 0;
	StartTick = 0;
	Started = false;
	Paused = false;
}

Uint32 cTimer::GetTicks()
{
		
	if (Started)
	{
		if (Paused)
			return PauseTick;
		else
			return SDL_GetTicks() - StartTick;
	}
		
	return 0;
}

void cTimer::Start()
{
	StartTick = SDL_GetTicks();
	PauseTick = 0;
	Started = true;
	Paused = false;
}

void cTimer::Stop()
{
	StartTick = 0;
	PauseTick = 0;
	Started = false;
	Paused = false;
}

void cTimer::Pause()
{
		if (!Paused)
		{
			PauseTick = SDL_GetTicks() - StartTick;
			Paused = true;
		}
		else if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
			TD2DE_DEBUG.LogError("Warning: Attempting to unpause timer that is not started", false);
}

void cTimer::Unpause()
{
	if (Paused)
	{
		StartTick = SDL_GetTicks() - PauseTick;
		Paused = false;
	}
	else if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
		TD2DE_DEBUG.LogError("Warning: TimeClass Attempting to unpause Timer that is not paused", false);
}

bool cTimer::IsPaused()
{
	return Paused;
}

bool cTimer::IsStarted()
{
	return Started;
}

void TD2DE_TimeHandle()
{
	if (TD2DE.GetDebugMode())
		TD2DE_DEBUG.LogError("TimeHandle.h: TimeHandle begin", false);

	//limiting fps
	Uint32 lTicksPerFrame = (1000 / TD2DE.GetFrameRateLimit());

	Uint32 lFrameTicks = TD2DE_CAPTIMER.GetTicks();

	//getting fps
	if (TD2DE_FPSTIMER.GetTicks() < 1000)
	{
		TD2DE_CurrentFrame++;
	}
	else
	{
		TD2DE_FPSTIMER.Start();
		TD2DE_Fps = TD2DE_CurrentFrame;
		TD2DE_CurrentFrame = 0;
	}

	TD2DE_DEBUG.LogError("fps: " + to_string(TD2DE_Fps), false);

	//delaying to wait for next tiem to print frame
	if (lFrameTicks < lTicksPerFrame)
		SDL_Delay(lTicksPerFrame - lFrameTicks);

	if (TD2DE.GetDebugMode())
		TD2DE_DEBUG.LogError("TimeHandle.h: TimeHandle end", false);
}

//start the internal fps and cap timers (MUST be inside the main game loop to use the cap timer)
void TD2DE_StartTimers(bool Cap, bool Fps)
{
	//forcivly restart the cap tiemr every time as we need it to do so
	if (Cap == true)
		TD2DE_CAPTIMER.Start();
	//fps timer only needs to be activated once in its life and can determine the fps from there on
	if (Fps == true)
		if (TD2DE_FPSTIMER.IsStarted() == false)
			TD2DE_FPSTIMER.Start();
}

//shutdown fps and cap timers (this will automatically be called by the cleanup procedure so its not nessicary to use it yourself)
void TD2DE_StopTimers(bool Cap, bool Fps)
{
	if (Cap == true)
		if (TD2DE_CAPTIMER.IsStarted() == true)
			TD2DE_CAPTIMER.Stop();
	if (Fps == true)
		if (TD2DE_FPSTIMER.IsStarted() == true)
			TD2DE_FPSTIMER.Stop();
}