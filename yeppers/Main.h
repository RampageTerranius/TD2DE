//header guard
#pragma once
	
//Dependancys
#include "TD2DE/TD2DE.h"

//other
#include <Windows.h>
#include <WinBase.h>
#include <simpleini.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
	
//globals
//game states
enum eMenu
{
	MAINMENU,
	OPTIONS,
	INGAMEOPTIONS,
	INGAME
};

//variables
string gProgramName = "Crapsteroids";
string gVersion = "0.01";


int	gGameState = INGAME,
	gTotalPlayers = 1,
	gPlayer1Object = -1,
	gPlayer2Object = -1,
	gPlayer1ShotDelay = 0,
	gPlayer2ShotDelay = 0;

int gUI_BulletTimer = 0;
 
string gRenderScaleQuality = "0"; 
string gSettingsLocation = "Settings.ini";
string gPlayer1ImageLocation = "player.png";
string gBulletImageLocation = "bullet.png";
string gShotTimerImageLocation = "shottimer.png";
string gShotTimerBorderImageLocation = "shottimerborder.png";
double gSprintSpeedBoost = 2;//how much faster players can rotate and accelerate when using sprint
int gShootingDelay = 30;//how often the player can shoot, measured in engine ticks (60 = 1 second)
int gBulletLifeTime = 60;//how long a shot bullet will live for (measured in engine ticks)

//audio related
TD2DE_AUDIO_CHUNK gShotSound;


		//Velocity related
double gMaxPlayerVelocity = 10.0,
		gVelocityIncreasePlayer = 0.125,
		gVelocityDecreasePlayer = 0.1,				 
		gMaxMeteorVelocity = 8.0,				 
		gVelocityDecreaseMeteor = 0.025,
		gBulletVelocity = 12.0,//velocity increase off of ship
		gPlayerRotationSpeed = 5.0;

	//other
int lFrame = 0;

//enumeration for handling different object types with ease
enum eEntitys
{
	OBJ_NONE,
	OBJ_DEFAULT,
	OBJ_METEOR,
	OBJ_PLAYER1,
	OBJ_PLAYER2,
	OBJ_BULLET
};



//Extra source files (lower dependancy)
#include "Extrafunctions.h"
#include "Initialize.h"
#include "Cleanup.h"
#include "PrintScreen.h"
#include "GameDataHandle.h"