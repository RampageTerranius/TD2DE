//extra shit
#include "main.h"

int main(int argc, char **argv)
{
	//handling initialization of variables surfaces etc
	if (Initialize())
		TD2DE.SetRunning(true);
	else
		TD2DE.SetRunning(false);


	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("Main.CPP: While loop begin", false);

	//start timer for tracking frames per second
		

	//core gameplay loop
	while (TD2DE.GetRunning() == true)
	{
		//timer for time handling
		TD2DE_StartTimers(true, true);

		//keyboard prompts etc 
		TD2DE_EventHandle();



		//controlling ai and moving them
		//TODO
		//HandleAI();

		//handles the internal game play data. players, bullets, damage etc 
		GameDataHandle();

		//print screen and all subscreens
		PrintScreen();

		//handling framerate, engine speed etc
		TD2DE_TimeHandle();
	}
	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("Main.CPP: While loop end", false);

	//cleaning up all surfaces and sdl related objects
	Cleanup();
	return 0;
}