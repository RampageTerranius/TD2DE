#pragma once

class cEngine
{
	public:
		bool Start();
		bool Stop();
} TD2DE_ENGINE;

bool cEngine::Start()
{
	//debug shit
	//wipe last debug file
	TD2DE_DEBUG.File.open(TD2DE.GetDebugFileName(), ios::out | ios::trunc);
	TD2DE_DEBUG.LogError("TD2DE - Terranius Designs 2D Engine v" + TD2DE.GetVersion());
	time_t T = time(0);
	string sT = ctime(&T);
	TD2DE_DEBUG.LogError("Time at launch: " + sT);

	//initialize SDL
	//video
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		if (SDL_GetError() != "")
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init_Video", true);
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: Video initialization success!");

	//standard audio
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		if (SDL_GetError() != "")
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init_Audio", true);
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: Audio initialization success!");

	//sdl_mixer
	if (Mix_OpenAudio(TD2DE.GetMHZ(), MIX_DEFAULT_FORMAT, TD2DE.GetChannels(), TD2DE.GetBitRate()) < 0)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init_Audio_Mixer", true);
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: Mixer sucessfully initialized at settings, " + to_string(TD2DE.GetMHZ()) + ", " + to_string(TD2DE.GetChannels()) + ", " + to_string(TD2DE.GetBitRate()));
	
	//timer
	if (SDL_Init(SDL_INIT_TIMER) != 0)
	{
		if (SDL_GetError() != "")
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init_Timer", true);
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: Timer initialization success!");

	//image loader
	int lFlags = IMG_INIT_PNG;
	int lInit = IMG_Init(lFlags);
	if (lInit != lFlags)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init-IMG_INIT: Unable to initialize image loader", true);
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: Image Loading engine initialization success!");

	//ttf loading
	if (TTF_Init() == -1)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init-TTF-INIT: Unable to initialize ttf engine", true);
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: TTF Engine initialization success!");

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, TD2DE_RENDER.GetRenderScaleQuality().c_str());
	
	if (TD2DE.GetFullScreen() == 1)
		lFlags = SDL_WINDOW_OPENGL && SDL_WINDOW_FULLSCREEN;
	else
		lFlags = SDL_WINDOW_OPENGL;
	//create the base window for the program
	TD2DE_RENDER.Window = SDL_CreateWindow
	(
		TD2DE.GetWindowName().c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		TD2DE.GetScreenWidth(),
		TD2DE.GetScreenHeight(),
		lFlags
	);

	if (TD2DE_RENDER.Window == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init-Initialize_Renderer: Unable to initialize primary window");
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: Primary Window creation success!");

	//create primary renderer (using hardware)
	if ((TD2DE_RENDER.Renderer = SDL_CreateRenderer(TD2DE_RENDER.Window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Initialize-SDL_Init-Initialize_Renderer: Unable to initialize renderer");
		return false;
	}
	else
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Info: Primary Renderer creation success!");

	SDL_SetRenderDrawBlendMode(TD2DE_RENDER.Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(TD2DE_RENDER.Renderer, 0x00, 0x00, 0x00, 0xFF);

	TD2DE.SetRunning(true);
	return true;
}

bool cEngine::Stop()
{
	//shutdown timers
	TD2DE_StopTimers(true, true);

	//clear the object for cObject
	for (unsigned int i = 0; i < TD2DE_ENTITY.size(); i++)
		TD2DE_ENTITY[i].Delete();
	TD2DE_ENTITY.clear();

	//delete each texture array before cleaning the array itself
	TD2DE_TEXTURE.clear();

	for (unsigned int i = 0; i < TD2DE_UI.size(); i++)
		TD2DE_UI[i].Delete();
	TD2DE_UI.clear();


	SDL_SetError("");
	SDL_DestroyRenderer(TD2DE_RENDER.Renderer);
	if (SDL_GetError() != "")
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Cleanup-DestroyRender", true);
	TD2DE_RENDER.Renderer = NULL;

	SDL_SetError("");
	SDL_DestroyWindow(TD2DE_RENDER.Window);
	if (SDL_GetError() != "")
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Cleanup-DestroyWindow", true);
	TD2DE_RENDER.Window = NULL;

	//close the debug file
	TD2DE_DEBUG.File.close();

	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();	

	time_t T = time(0);
	string sT = ctime(&T);
	TD2DE_DEBUG.LogError("Time at Shutdown: " + sT);

	return true;
}