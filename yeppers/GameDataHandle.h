//handling internal game data. bullet velocity, player velocity, moving players, etc 


//header guard
#pragma once

//prototypes
void PlayerMovementHandle();
void MomentumHandle();
void DeleteTimedOut();

int TextID = -1;

//functions
void GameDataHandle()
{
	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("GameDataHandle.h : GameDataHandle begin", false);

	//if the player has pressed esc quit the program
	if (TD2DE_KEYBOARD.Esc == true)
		TD2DE.SetRunning(false);

	//handling player momentum increase
	PlayerMovementHandle();

	if (TextID != -1)
	{
		TD2DE_TTF[TextID].Delete();
		TD2DE_TEXTURE.erase(TD2DE_TTF[TextID].GetTextureID());
	}		
	
	TextID = TD2DE_CreateTTF("Xolonium-Regular.ttf", 28, to_string(TD2DE_Fps), 255, 165, 0, 155);
	TD2DE_TTF[TextID].SetX(TD2DE.GetScreenWidth() - 50);
	TD2DE_TTF[TextID].SetY(TD2DE.GetScreenHeight() - 50);

	//player shot handle
	if (TD2DE_KEYBOARD.Space && gPlayer1ShotDelay == 0)
	{
		CreateObject(OBJ_BULLET);
		gShotSound.Play();
		gPlayer1ShotDelay = gShootingDelay;		
	}

	//check if shoot delay needs to be reduced
	if (gPlayer1ShotDelay > 0)
		gPlayer1ShotDelay--;

	//immediately after handling shotdelay update the ui showing how long till next shot
	SDL_Rect TempRect;
	TempRect.h = 10;
	if (gPlayer1ShotDelay == 0)
		TempRect.w = TD2DE_TEXTURE.at(TD2DE_UI[gUI_BulletTimer].GetTextureID())->GetWidth();
	else
		TempRect.w = (int)round(((double)TD2DE_TEXTURE.at(TD2DE_UI[gUI_BulletTimer].GetTextureID())->GetWidth()) * (abs((double)gShootingDelay - (double)gPlayer1ShotDelay) / (double)gShootingDelay));

	TempRect.x = 0;
	TempRect.y = 0;
	TD2DE_TEXTURE.at(TD2DE_UI[gUI_BulletTimer].GetTextureID())->SetRenderRect(TempRect);

	//handling momentum
	MomentumHandle();

	//deleting objects that have run out of time (must of had tiem to begin with)
	DeleteTimedOut();

	if (TD2DE_BUTTON[0].GetState() == STATE_CLICKED)
		TD2DE.SetRunning(false);

	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("GameDataHandle.h : GameDataHandle end", false);
}

//delete any objects whos time has run out (wont count objects that defaulted at 0 time)
void DeleteTimedOut()
{
	//check entire array
	for(size_t i = 0; i < TD2DE_ENTITY.size(); i++)
		//if it already has more then 0 time (stops it from deleting objects that defaulted at 0 time)
		if (TD2DE_ENTITY[i].GetLifeTime() > 0)
		{
			//drop its time by 1 and check if it needs to be deleted
			TD2DE_ENTITY[i].SetLifeTime(TD2DE_ENTITY[i].GetLifeTime() - 1);
			if (TD2DE_ENTITY[i].GetLifeTime() == 0)
			{
				TD2DE_ENTITY[i].Delete();
				RemoveObjectFromList(i, 0);
			}				
		}
}

void CalculatePlayerMomentum(bool MoveForward)
{
	if (MoveForward)
	{
		//checking if using speed boost
		double i = 1;
		if (TD2DE_KEYBOARD.LShift)
			i = gSprintSpeedBoost;
		TD2DE_ENTITY[gPlayer1Object].SetXVel(TD2DE_ENTITY[gPlayer1Object].GetXVel() + (sin((TD2DE_ENTITY[gPlayer1Object].GetDirPointing() * (M_PI / 180))) * TD2DE_ENTITY[gPlayer1Object].GetVelInc()) * i);
		TD2DE_ENTITY[gPlayer1Object].SetYVel(TD2DE_ENTITY[gPlayer1Object].GetYVel() - (cos((TD2DE_ENTITY[gPlayer1Object].GetDirPointing() * (M_PI / 180))) * TD2DE_ENTITY[gPlayer1Object].GetVelInc()) * i);
	}
	else
	{
		//checking if using speed boost
		double i = 1;
		if (TD2DE_KEYBOARD.LShift)
			i = gSprintSpeedBoost;
		TD2DE_ENTITY[gPlayer1Object].SetXVel(TD2DE_ENTITY[gPlayer1Object].GetXVel() - (sin((TD2DE_ENTITY[gPlayer1Object].GetDirPointing() * (M_PI / 180))) * TD2DE_ENTITY[gPlayer1Object].GetVelInc()) * i);
		TD2DE_ENTITY[gPlayer1Object].SetYVel(TD2DE_ENTITY[gPlayer1Object].GetYVel() + (cos((TD2DE_ENTITY[gPlayer1Object].GetDirPointing() * (M_PI / 180))) * TD2DE_ENTITY[gPlayer1Object].GetVelInc()) * i);
	}
}

void PlayerMovementHandle()
{
	//allow velocity to drop down
	TD2DE_ENTITY[gPlayer1Object].SetAllowVelDrop(true);
	//checking if need to change velocity and if so stop velocity drop				
	if (TD2DE_KEYBOARD.Up == true)
	{
		TD2DE_ENTITY[gPlayer1Object].SetAllowVelDrop(false);

		//calculate the players velocity
		CalculatePlayerMomentum(true);
			
		//checkign if over maximum velocity
		if (TD2DE_ENTITY[gPlayer1Object].GetYVel() < -TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetYVel(-TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
		if (TD2DE_ENTITY[gPlayer1Object].GetYVel() > TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetYVel(TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
		if (TD2DE_ENTITY[gPlayer1Object].GetXVel() < -TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetXVel(-TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
		if (TD2DE_ENTITY[gPlayer1Object].GetXVel() > TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetXVel(TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
	}

	if (TD2DE_KEYBOARD.Down == true)
	{
		TD2DE_ENTITY[gPlayer1Object].SetAllowVelDrop(false);
		CalculatePlayerMomentum(false);
		if (TD2DE_ENTITY[gPlayer1Object].GetYVel() < -TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetYVel(-TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
		if (TD2DE_ENTITY[gPlayer1Object].GetYVel() > TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetYVel(TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
		if (TD2DE_ENTITY[gPlayer1Object].GetXVel() < -TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetXVel(-TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
		if (TD2DE_ENTITY[gPlayer1Object].GetXVel() > TD2DE_ENTITY[gPlayer1Object].GetMaxVel())
			TD2DE_ENTITY[gPlayer1Object].SetXVel(TD2DE_ENTITY[gPlayer1Object].GetMaxVel());
	}

	if (TD2DE_KEYBOARD.Left == true)
	{
		//checking if using speed boost
		double i = 1;
		if (TD2DE_KEYBOARD.LShift)
			i = gSprintSpeedBoost;

		//TD2DE_ENTITY[gPlayer1Object].AllowVelDrop = false;
		TD2DE_ENTITY[gPlayer1Object].SetDirPointing(TD2DE_ENTITY[gPlayer1Object].GetDirPointing() - gPlayerRotationSpeed * i);
		if (TD2DE_ENTITY[gPlayer1Object].GetDirPointing() < 1.0)
			TD2DE_ENTITY[gPlayer1Object].SetDirPointing(360.0);
	}

	if (TD2DE_KEYBOARD.Right == true)
	{
		//checking if using speed boost
		double i = 1;
		if (TD2DE_KEYBOARD.LShift)
			i = gSprintSpeedBoost;
		//TD2DE_ENTITY[gPlayer1Object].AllowVelDrop = false;
		TD2DE_ENTITY[gPlayer1Object].SetDirPointing(TD2DE_ENTITY[gPlayer1Object].GetDirPointing() + gPlayerRotationSpeed * i);
		if (TD2DE_ENTITY[gPlayer1Object].GetDirPointing() > 360.0)
			TD2DE_ENTITY[gPlayer1Object].SetDirPointing(1.0);
	}
}


void MomentumHandle()
{
	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("GameDataHandle.h : MomentumHandle begin", false);

	for (size_t i = 0; i < TD2DE_ENTITY.size(); i++)
	{			
		//LogError("1: " + to_string(i), false);
		//LogError("c:" + to_string(TD2DE_ENTITY.capacity()) + " s:" + to_string(TD2DE_ENTITY.size()) + " ms:" + to_string(TD2DE_ENTITY.max_size()));
		if (TD2DE_ENTITY[i].GetObjectID() != OBJ_NONE && TD2DE_ENTITY[i].GetAffectedByVel() == true)
		{
			cTexture* lTEX = TD2DE_TEXTURE.at(TD2DE_ENTITY[i].GetTextureID());
			//moving the object depending on momentum
			TD2DE_ENTITY[i].SetX(TD2DE_ENTITY[i].GetX() + int(round(TD2DE_ENTITY[i].GetXVel())));
			TD2DE_ENTITY[i].SetY(TD2DE_ENTITY[i].GetY() + int(round(TD2DE_ENTITY[i].GetYVel())));

			//if allowing screen wrap move user across to other side of screen
			if (TD2DE_ENTITY[i].GetAllowScreenWrap() == true)
			{

				if (TD2DE_ENTITY[i].GetX() < 0)
					TD2DE_ENTITY[i].SetX(TD2DE.GetScreenWidth() - lTEX->GetWidth());
					

				if (TD2DE_ENTITY[i].GetX() > TD2DE.GetScreenWidth())
					TD2DE_ENTITY[i].SetX(0);

				if (TD2DE_ENTITY[i].GetY() < 0)
					TD2DE_ENTITY[i].SetY(TD2DE.GetScreenHeight() - lTEX->GetHeight());

				if (TD2DE_ENTITY[i].GetY() > TD2DE.GetScreenHeight())
					TD2DE_ENTITY[i].SetY(0);
			}
			else
				//stopping movement when hitting objects/walls etc
			{
				if (TD2DE_ENTITY[i].GetY() < 0)
				{
					TD2DE_ENTITY[i].SetY(0);
					TD2DE_ENTITY[i].SetYVel(0);
				}

				if (TD2DE_ENTITY[i].GetY() > TD2DE.GetScreenHeight() - lTEX->GetHeight())
				{
					TD2DE_ENTITY[i].SetY(TD2DE.GetScreenHeight() - lTEX->GetHeight());
					TD2DE_ENTITY[i].SetYVel(0);
				}

				if (TD2DE_ENTITY[i].GetX() < 0)
				{
					TD2DE_ENTITY[i].SetX(0);
					TD2DE_ENTITY[i].SetXVel(0);
				}

				if (TD2DE_ENTITY[i].GetX() > TD2DE.GetScreenWidth() - lTEX->GetWidth())
				{
					TD2DE_ENTITY[i].SetX(TD2DE.GetScreenWidth() - lTEX->GetWidth());
					TD2DE_ENTITY[i].SetXVel(0);
				}
			}

			//velocity reduction over time
			if (TD2DE_ENTITY[i].GetAllowVelDrop() == true)
			{				
				if (TD2DE_ENTITY[i].GetXVel() != 0)
				{
					if (TD2DE_ENTITY[i].GetXVel() < 0)
					{
						if (TD2DE_ENTITY[i].GetVelDrop() != 0)
							TD2DE_ENTITY[i].SetXVel(TD2DE_ENTITY[i].GetXVel() + TD2DE_ENTITY[i].GetVelDrop());
						if (TD2DE_ENTITY[i].GetXVel() > 0)
							TD2DE_ENTITY[i].SetXVel(0);
					}
					else if (TD2DE_ENTITY[i].GetXVel() > 0)
					{
						if (TD2DE_ENTITY[i].GetVelDrop() != 0)
							TD2DE_ENTITY[i].SetXVel(TD2DE_ENTITY[i].GetXVel() - TD2DE_ENTITY[i].GetVelDrop());
						if (TD2DE_ENTITY[i].GetXVel() < 0)
							TD2DE_ENTITY[i].SetXVel(0);
					}
				}

				if (TD2DE_ENTITY[i].GetYVel() != 0)
				{
					if (TD2DE_ENTITY[i].GetYVel() < 0)
					{
						if (TD2DE_ENTITY[i].GetVelDrop() != 0)
							TD2DE_ENTITY[i].SetYVel(TD2DE_ENTITY[i].GetYVel() + TD2DE_ENTITY[i].GetVelDrop());
						if (TD2DE_ENTITY[i].GetYVel() > 0)
							TD2DE_ENTITY[i].SetYVel(0);
					}
					else if (TD2DE_ENTITY[i].GetYVel() > 0)
					{
						if (TD2DE_ENTITY[i].GetVelDrop() != 0)
							TD2DE_ENTITY[i].SetYVel(TD2DE_ENTITY[i].GetYVel() - TD2DE_ENTITY[i].GetVelDrop());
						if (TD2DE_ENTITY[i].GetYVel() < 0)
							TD2DE_ENTITY[i].SetYVel(0);
					}
				}
			}
		}
	}
	if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		TD2DE_DEBUG.LogError("GameDataHandle.h : MomentumHandle end", false);
}