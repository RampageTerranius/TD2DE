///////////////////////////////
//Terranius Designs 2D Engine//
///////////////////////////////

/*
vc++ directorys requires the following
include directorys:
SDL2/include
SDL2_Image/include
SDL2_Mixer/include
SDL2_TTF/include

library directorys:
SDL2/lib/x84 (or x64)
SDL2_Image/lib/x84 (or x64)
SDL2_Mixer/lib/x84 (or x64)
SDL2_TTF/lib/x84 (or x64)

linker/input requires the following additional dependancys added
SDL2.lib
SDL2main.lib
SDL2_image.lib
SDL2_mixer.lib
SDL2_ttf.lib

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!MAKE SURE YOU USE SAME BIT VERSION FOR EACH PART!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
if you do not the project wil not build/wont start
*/

//check if TD2DE has already been loaded
#ifndef _TD2DE_
	#define _TD2DE_


	//dependancys
	#ifndef _STRING_
		#include <string>
		//name spaces
		using namespace std;
	#endif

	#ifndef _MAP_
		#include <map>
	#endif

	#ifndef _VECTOR_
		#include <vector>
	#endif

	#ifndef _FSTREAM_
		#include <fstream>
	#endif

	#ifndef _CTIME_
		#include <ctime>
	#endif

	//SDL
	#ifndef _SDL_H
		#include <SDL.h>
	#endif

	#ifndef _SDL_IMAGE_H
		#include <SDL_image.h>
	#endif

	#ifndef _SDL_MIXER_H_
		#include <SDL_mixer.h>
	#endif

	#ifndef _SDL_TTF_H_
		#include <SDL_ttf.h>
	#endif

	//version
	string TD2DE_Version = "0.11a";

	//classes
	#include "Debug.h"
	#include "TD2DE_Main.h"
	#include "Render_Class.h"
	#include "Texture_Class.h"
	#include "Object_Class.h"
	#include "Entity_Class.h"
	#include "Button_Class.h"
	#include "UI_Class.h"
	#include "TTF_Class.h"
	#include "Texture_Methods.h"
	#include "Keyboard_Class.h"
	#include "Mouse_Class.h"
	#include "Event_Handle.h"
	//#include "Sprite_Class.h"
	#include "Time_Class.h"
	#include "Audio_Class.h"
	#include "Engine_Class.h"
	//#include "CMD.h"

#endif