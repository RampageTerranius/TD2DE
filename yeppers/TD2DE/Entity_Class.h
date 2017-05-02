#pragma once

class cEntity : public cObject
{
	private:
		int Health,//health under 0 (-1 or less) will consider the object invulnerable and not allow it to be destroyed
			LifeTime;			

		bool AffectedByVel,
			 AllowVelDrop,
			 AllowScreenWrap;

		double XVel,
			   YVel,
			   VelDrop,
			   VelInc,
			   MaxVel;

	public:
		cEntity();
		void Delete();

		int GetHealth();
		void SetHealth(int New);
		int GetLifeTime();
		void SetLifeTime(int New);

		bool GetAffectedByVel();
		void SetAffectedByVel(bool New);
		bool GetAllowVelDrop();
		void SetAllowVelDrop(bool New);
		bool GetAllowScreenWrap();
		void SetAllowScreenWrap(bool New);

		double GetXVel();
		void SetXVel(double New);
		double GetYVel();
		void SetYVel(double New);
		double GetVelDrop();
		void SetVelDrop(double New);
		double GetVelInc();
		void SetVelInc(double New);
		double GetMaxVel();
		void SetMaxVel(double New);
};
vector <cEntity> TD2DE_ENTITY;

cEntity::cEntity()
{
	Delete();
}

void cEntity::Delete()
{
	Health = LifeTime = 0;
	AffectedByVel = AllowVelDrop = AllowScreenWrap = false;
	XVel = YVel = VelDrop = VelInc = MaxVel = 0.0;
	cObject::Delete();
}

int cEntity::GetHealth()
{
	return Health;
}

void cEntity::SetHealth(int New)
{
	Health = New;
}

int cEntity::GetLifeTime()
{
	return LifeTime;
}

void cEntity::SetLifeTime(int New)
{
	LifeTime = New;
}

bool cEntity::GetAffectedByVel()
{
	return AffectedByVel;
}

void cEntity::SetAffectedByVel(bool New)
{
	AffectedByVel = New;
}

bool cEntity::GetAllowVelDrop()
{
	return AllowVelDrop;
}

void cEntity::SetAllowVelDrop(bool New)
{
	AllowVelDrop = New;
}

bool cEntity::GetAllowScreenWrap()
{
	return AllowScreenWrap;
}

void cEntity::SetAllowScreenWrap(bool New)
{
	AllowScreenWrap = New;
}

double cEntity::GetXVel()
{
	return XVel;
}

void cEntity::SetXVel(double New)
{
	XVel = New;
}

double cEntity::GetYVel()
{
	return YVel;
}

void cEntity::SetYVel(double New)
{
	YVel = New;
}

double cEntity::GetVelDrop()
{
	return VelDrop;
}

void cEntity::SetVelDrop(double New)
{
	VelDrop = New;
}

double cEntity::GetVelInc()
{
	return VelInc;
}

void cEntity::SetVelInc(double New)
{
	VelInc = New;
}

double cEntity::GetMaxVel()
{
	return MaxVel;
}

void cEntity::SetMaxVel(double New)
{
	MaxVel = New;
}

int TD2DE_CreateEntity(int lObjType)
{
	bool lLoop = true;
	while (lLoop)
	{
		int lTotalObjects = TD2DE_ENTITY.size();
		for (int i = 0; i < lTotalObjects; i++)
		{
			if (TD2DE_ENTITY[i].GetObjectID() == -1)
			{
				//set the object id then set its default values as per the object id
				TD2DE_ENTITY[i].SetObjectID(lObjType);

				AddObjectToList(i, TYPE_ENTITY);

				return i;
			}
		}
		//if it cant create an object increase the size of the array
		TD2DE_DEBUG.LogError("new value in Entity", false);
		TD2DE_DEBUG.LogError("before - c:" + to_string(TD2DE_ENTITY.capacity()) + " s:" + to_string(TD2DE_ENTITY.size()) + " ms:" + to_string(TD2DE_ENTITY.max_size()));
		cEntity Temp;
		Temp.Delete();//make sure its a blank object
		TD2DE_ENTITY.push_back(Temp);//push blank object to array
		TD2DE_DEBUG.LogError("after - c:" + to_string(TD2DE_ENTITY.capacity()) + " s:" + to_string(TD2DE_ENTITY.size()) + " ms:" + to_string(TD2DE_ENTITY.max_size()));
	}
	return -1;
}
