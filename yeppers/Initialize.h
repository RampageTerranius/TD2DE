//header guard
#pragma once

void LoadSettings();
void CreateUI();
	
//initialization of program
bool Initialize()
{
	TD2DE_DEBUG.LogError(gProgramName + " Version " + gVersion);
	
	//loading settings file

	LoadSettings();
	TD2DE.SetWindowName(gProgramName + " " + gVersion);
	//TD2DE.SetBitRate(44100);
	TD2DE_ENGINE.Start();

	//create main window
	//get the name for the window
	



	//load images
	/*
	for (int lPlayer = 0; lPlayer < (gTotalPlayers+1); ++lPlayer)
		if ((Player[lPlayer].PlayerImage = (LoadPNG(gPlayerImageLocation))) == NULL)
		{
			LogError("Error: Initialize-SDL_Init-Load_Player_Images: Unable to load player images", false);
			return false;
		}
	*/

	//create player objects
	gPlayer1Object = CreateObject(OBJ_PLAYER1);
	gShotSound.Load("sounds/156895__halgrimm__a-shot.wav");
	//int TextID = TD2DE_CreateTTF("Xolonium-Regular.ttf", 28, "Random Text!", 255, 165, 0, 155);	
	//TD2DE_TEXTURE[TD2DE_TTF[TextID].GetTextureID()].SetCanRender(true);
	//TD2DE_TTF[TextID].SetX(100);
	//TD2DE_TTF[TextID].SetY(100);
	CreateUI();



	return true;
}

void CreateUI()
{
	//setting up shot timer
	int gUI_BulletTimer = TD2DE_CreateUI(INGAME);
	TD2DE_UI[gUI_BulletTimer].SetTextureID(LoadTexture(gShotTimerImageLocation, "ShotTimer"));
	TD2DE_UI[gUI_BulletTimer].SetX(20);
	TD2DE_UI[gUI_BulletTimer].SetY(20);
	TD2DE_TEXTURE.at(TD2DE_UI[gUI_BulletTimer].GetTextureID())->SetCanRender(true);
	TD2DE_TEXTURE.at(TD2DE_UI[gUI_BulletTimer].GetTextureID())->SetLayer(LAYER_BACK);
	
	int lTemp = TD2DE_CreateUI(INGAME);
	TD2DE_UI[lTemp].SetTextureID(LoadTexture(gShotTimerBorderImageLocation, "ShotTimerBorder"));
	TD2DE_UI[lTemp].SetX(19);
	TD2DE_UI[lTemp].SetY(19);
	TD2DE_TEXTURE.at(TD2DE_UI[lTemp].GetTextureID())->SetCanRender(true);
	TD2DE_TEXTURE.at(TD2DE_UI[lTemp].GetTextureID())->SetLayer(LAYER_BACK);
	LoadTexture("buttonup.png");
	LoadTexture("buttonover.png");
	LoadTexture("buttondown.png");
	TD2DE_TEXTURE.at("buttonup.png")->SetCanRender(true);
	TD2DE_TEXTURE.at("buttonup.png")->SetLayer(LAYER_FRONT);
	TD2DE_TEXTURE.at("buttonover.png")->SetCanRender(true);
	TD2DE_TEXTURE.at("buttonover.png")->SetLayer(LAYER_FRONT);
	TD2DE_TEXTURE.at("buttondown.png")->SetCanRender(true);
	TD2DE_TEXTURE.at("buttondown.png")->SetLayer(LAYER_FRONT);
	int bleh = TD2DE_CreateButton("buttonup.png", "buttonover.png", "buttondown.png");
	TD2DE_BUTTON[bleh].SetX(60);
	TD2DE_BUTTON[bleh].SetY(60);
	//TD2DE_BUTTON[bleh].
}

void LoadSettings()
{
	//loading settings

	//check if settings file exists
	fstream File(gSettingsLocation);
		
	if(File.good())
	{
		//clsoe the file since it exists
		File.close();
		CSimpleIniA lIni;
		lIni.LoadFile(gSettingsLocation.c_str());
		//load all settings required into variables
		stringstream s;//hold the data to be moved to strings/intergers/doubles

		//screen width
		int i;
		//double d;
		bool b;
		s << lIni.GetValue("General", "WinXSize", to_string(TD2DE.GetScreenWidth()).c_str(), false);
		s >> i;
		TD2DE.SetScreenWidth(i);
		s.clear();			
		//screen height
		s << lIni.GetValue("General", "WinYSize", to_string(TD2DE.GetScreenHeight()).c_str(), false);
		s >> i;
		TD2DE.SetScreenHeight(i);
		s.clear();			
		//if the app is fullscreen or not
		b = lIni.GetBoolValue("General", "Fullscreen", TD2DE.GetFullScreen(), false);
		TD2DE.SetFullScreen(b);
		//what framerate the engine is limited at
		s << lIni.GetValue("General", "FrameRateLimit", to_string(TD2DE.GetFrameRateLimit()).c_str(), false);
		s >> i; 
		TD2DE.SetFrameRateLimit(i);
		s.clear();
		//what type of aliasing to put on images, 0 = nearest 1 = linear 2 = anisotropic(wont be supported)
		s << lIni.GetValue("General", "RenderScaleQuality", gRenderScaleQuality.c_str(), false);
		s >> gRenderScaleQuality;
		s.clear();
		//the maximum velocity of a player
		s << lIni.GetValue("GameRelated", "MaxPlayerVelocity", to_string(gMaxPlayerVelocity).c_str(), false);
		s >> gMaxPlayerVelocity;
		s.clear();
		//increase in rotation and acceleration when sprinting
		s << lIni.GetValue("GameRelated", "SprintSpeedBoost", to_string(gSprintSpeedBoost).c_str(), false);
		s >> gSprintSpeedBoost;
		s.clear();
		//delay between shooting
		s << lIni.GetValue("GameRelated", "ShootingDelay", to_string(gShootingDelay).c_str(), false);
		s >> gShootingDelay;
		s.clear();
		//how long the bullet will live in engine ticks
		s << lIni.GetValue("GameRelated", "BulletLifeTime", to_string(gBulletLifeTime).c_str(), false);
		s >> gBulletLifeTime;
		s.clear();
		//how fast the palyer can accelerate
		s << lIni.GetValue("GameRelated", "VelocityIncreasePlayer", to_string(gVelocityIncreasePlayer).c_str(), false);
		s >> gVelocityIncreasePlayer;
		s.clear();
		//how fast the player will slow down via gravity
		s << lIni.GetValue("GameRelated", "VelocityDecreasePlayer", to_string(gVelocityDecreasePlayer).c_str(), false);
		s >> gVelocityDecreasePlayer;
		s.clear();
		//maximum speed a meteor can be moving
		s << lIni.GetValue("GameRelated", "MaxMeteorVelocity", to_string(gMaxMeteorVelocity).c_str(), false);
		s >> gMaxMeteorVelocity;
		s.clear();
		//how fast the meteor runs out of speed
		s << lIni.GetValue("GameRelated", "VelocityDecreaseMeteor", to_string(gVelocityDecreaseMeteor).c_str(), false);
		s >> gVelocityDecreaseMeteor;
		s.clear();
		//how fast teh palyer can rotate
		s << lIni.GetValue("GameRelated", "PlayerRotationSpeed", to_string(gPlayerRotationSpeed).c_str(), false);
		s >> gPlayerRotationSpeed;
		s.clear();

		//image loading
		//location of palyer 1 image
		s << lIni.GetValue("Images", "Player1", gPlayer1ImageLocation.c_str(), false);
		s >> gPlayer1ImageLocation;
		s.clear();
		//location on bullet image
		s << lIni.GetValue("Images", "Bullet", gBulletImageLocation.c_str(), false);
		s >> gBulletImageLocation;
		s.clear();

		s << lIni.GetValue("Images", "ShotTimer", gBulletImageLocation.c_str(), false);
		s >> gShotTimerImageLocation;
		s.clear();

		s << lIni.GetValue("Images", "ShotTimerBorder", gBulletImageLocation.c_str(), false);
		s >> gShotTimerBorderImageLocation;
		s.clear();
		lIni.Reset();
	}
	else
	{	
		File.close();
		File.open(gSettingsLocation, ios::out, ios::trunc);

		//create the file using default values
		File << "[General]\n"
			<< "WinXSize=" << TD2DE.GetScreenWidth() << "\n"
			<< "WinYSize=" << TD2DE.GetScreenHeight() << "\n"
			<< "Fullscreen=" << TD2DE.GetFullScreen() << "\n"
			<< "FrameRateLimit=" << TD2DE.GetFrameRateLimit() << "\n"
			<< "RenderScaleQuality=" << gRenderScaleQuality << "\n"
			<< "\n"
			<< "[GameRelated]\n"
			<< "MaxPlayerVelocity=" << gMaxPlayerVelocity << "\n"
			<< "SprintSpeedBoost=" << gSprintSpeedBoost << "\n"
			<< "ShootingDelay=" << gShootingDelay << "\n"
			<< "BulletLifeTime=" << gBulletLifeTime << "\n"
			<< "VelocityIncreasePlayer=" << gVelocityIncreasePlayer << "\n"
			<< "VelocityDecreasePlayer=" << gVelocityDecreasePlayer << "\n"
			<< "MaxMeteorVelocity=" << gMaxMeteorVelocity << "\n"
			<< "VelocityDecreaseMeteor=" << gVelocityDecreaseMeteor << "\n"
			<< "PlayerRotationSpeed=" << gPlayerRotationSpeed << "\n"
			<< "\n"
			<< "[Images]" << "\n"
			<< "Player1ImageLocation=" << gPlayer1ImageLocation << "\n"
			<< "BulletImageLocation=" << gBulletImageLocation << "\n"
			<< "ShotTimer=" << gShotTimerImageLocation << "\n"
			<< "ShotTimerBorder=" << gShotTimerBorderImageLocation;
		File.close();
	}
}