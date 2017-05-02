//print all images to the screen

//header guard
#pragma once

void PrintScreen()
{
	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("PrintScreen.h: PrintScreen begin", false);
	//clear screen before rendering
	TD2DE_RENDER.RenderClear();
		
	//handling different menus
	switch (gGameState)
	{
		//drawing the screen for when ingame
		case INGAME:
			TD2DE_RenderScene(true, true);
			break;
	}

	//Update screen
	TD2DE_RENDER.RenderPresent();

	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("PrintScreen.h: PrintScreen end", false);
}