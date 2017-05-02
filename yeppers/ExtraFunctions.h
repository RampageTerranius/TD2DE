#pragma once
int CreateObject(int lObjType)
{
	//set the object id then set its default values as per the object id
	int i = TD2DE_CreateEntity(lObjType);
	switch (TD2DE_ENTITY[i].GetObjectID())
	{
		//prepare a clean object
		case OBJ_PLAYER1:
		case OBJ_PLAYER2:
			TD2DE_ENTITY[i].SetTextureID(LoadTexture(gPlayer1ImageLocation, "player"));
			TD2DE_ENTITY[i].SetAffectedByVel(true);
			//TD2DE_ENTITY[i].AllowVelDrop = false;//OBSOLETE CODE - keyboard calls handle this for us
			TD2DE_ENTITY[i].SetMaxVel(gMaxPlayerVelocity);
			TD2DE_ENTITY[i].SetVelDrop(gVelocityDecreasePlayer);
			TD2DE_ENTITY[i].SetVelInc(gVelocityIncreasePlayer);
			TD2DE_ENTITY[i].SetAllowScreenWrap(true);
			TD2DE_TEXTURE.at(TD2DE_ENTITY[i].GetTextureID())->SetLayer(LAYER_MIDDLE);
			break;

		case OBJ_METEOR:
			TD2DE_ENTITY[i].SetAffectedByVel(true);
			TD2DE_ENTITY[i].SetAllowVelDrop(true);
			TD2DE_ENTITY[i].SetMaxVel(gMaxMeteorVelocity);
			TD2DE_ENTITY[i].SetVelDrop(gVelocityDecreaseMeteor);
			TD2DE_TEXTURE.at(TD2DE_ENTITY[i].GetTextureID())->SetLayer(LAYER_MIDDLE);
			break;
			
		case OBJ_BULLET:
			TD2DE_ENTITY[i].SetAffectedByVel(true);
			TD2DE_ENTITY[i].SetHealth(-1);
			TD2DE_ENTITY[i].SetXVel(+sin((TD2DE_ENTITY[gPlayer1Object].GetDirPointing() * (M_PI / 180))) * gBulletVelocity);
			TD2DE_ENTITY[i].SetYVel(-cos((TD2DE_ENTITY[gPlayer1Object].GetDirPointing() * (M_PI / 180))) * gBulletVelocity);
			/*
			if (TD2DE_ENTITY[gPlayer1Object].XVel > 0)
			TD2DE_ENTITY[i].XVel = TD2DE_ENTITY[gPlayer1Object].XVel + gBulletVelocity;
			else if (TD2DE_ENTITY[gPlayer1Object].XVel < 0)
			TD2DE_ENTITY[i].XVel = TD2DE_ENTITY[gPlayer1Object].XVel - gBulletVelocity;
			if (TD2DE_ENTITY[gPlayer1Object].YVel > 0)
			TD2DE_ENTITY[i].YVel = TD2DE_ENTITY[gPlayer1Object].YVel + gBulletVelocity;
			else if (TD2DE_ENTITY[gPlayer1Object].YVel < 0)
			TD2DE_ENTITY[i].YVel = TD2DE_ENTITY[gPlayer1Object].YVel - gBulletVelocity;
			*/
			//TD2DE_ENTITY[i].ObjectImage.SetTexture(gBulletImage.ReturnTexture());//return the already loaded texture
			TD2DE_ENTITY[i].SetTextureID(LoadTexture(gBulletImageLocation, "bullet"));
			TD2DE_ENTITY[i].SetAllowScreenWrap(true);
			TD2DE_ENTITY[i].SetX(TD2DE_ENTITY[gPlayer1Object].GetX() + (TD2DE_TEXTURE.at(TD2DE_ENTITY[gPlayer1Object].GetTextureID())->GetWidth() / 2));
			TD2DE_ENTITY[i].SetY(TD2DE_ENTITY[gPlayer1Object].GetY() + (TD2DE_TEXTURE.at(TD2DE_ENTITY[gPlayer1Object].GetTextureID())->GetHeight() / 2));
			TD2DE_ENTITY[i].SetLifeTime(gBulletLifeTime);
			TD2DE_TEXTURE.at(TD2DE_ENTITY[i].GetTextureID())->SetLayer(LAYER_BACK);
			break;
	}
	return i;
}



//get the distance between two different points
double GetDistance(double X, double Y, double X2, double Y2)
{
	double lXTemp = (X + Y) / 2;
	double lYTemp = (X2 + Y2) / 2;

	return abs(lXTemp - lYTemp);
}