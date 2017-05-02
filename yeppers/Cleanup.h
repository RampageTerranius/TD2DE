//header guard
#pragma once
	
//cleaning up files and surfaces at end of program

void Cleanup()
{
	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("Cleanup.h: Cleanup begin");

	TD2DE_ENGINE.Stop();

	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("Cleanup.h: Cleanup end");
}