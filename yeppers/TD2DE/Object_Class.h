#pragma once

enum eObjectType
{
	TYPE_ENTITY,
	TYPE_BUTTON,
	TYPE_TTF,
	TYPE_UI
};

class cObject
{
	protected:
		//variables		
		int ObjectID;

		string TextureID;//name of the texture used in map<string, cTexture> TD2DE_TEXTURE			
			
		double X,//left right
			   Y,//up down
			   DirPointing;

	//functions
	public:
		//constructor
		cObject();
		void Delete();//deletes the entire objects stored variables setting them back to default
		
		string GetTextureID();
		void SetTextureID(string New);
		int GetObjectID();
		void SetObjectID(int NewObjectID);
		void Render();
		double GetX();
		void SetX(double New);
		double GetY();
		void SetY(double New);
		double GetDirPointing();
		void SetDirPointing(double New);
};

cObject::cObject()
{
	Delete();
}

void cObject::Delete()
{
	TextureID = "";
	ObjectID = -1;//loops to create new objects etc will look for a -1 id
	X = Y = 0.0;
	DirPointing = 0.0;
}

void cObject::Render()
{
	cTexture* lTEX = TD2DE_TEXTURE.at(TextureID);
	SDL_Rect sRenderRect = lTEX->GetRenderRect();
	SDL_Rect tRenderRect;

	if (sRenderRect.h == 0 && sRenderRect.w == 0 && sRenderRect.x == 0 && sRenderRect.y == 0)
	{
		sRenderRect.h = lTEX->GetHeight();
		sRenderRect.w = lTEX->GetWidth();
		sRenderRect.x = 0;
		sRenderRect.y = 0;
		tRenderRect.h = lTEX->GetHeight();
		tRenderRect.w = lTEX->GetWidth();
	}
	else
	{
		tRenderRect.h = sRenderRect.h;
		tRenderRect.w = sRenderRect.w;
	}
	tRenderRect.x = X;
	tRenderRect.y = Y;

	SDL_RenderCopyEx(TD2DE_RENDER.Renderer, lTEX->ReturnTexture(), &sRenderRect, &tRenderRect, DirPointing, NULL, SDL_FLIP_NONE);
}

string cObject::GetTextureID()
{
	return TextureID;
}

void cObject::SetTextureID(string New)
{
	TextureID = New;
}

int cObject::GetObjectID()
{
	return ObjectID;
}

void cObject::SetObjectID(int NewObjectID)
{
	ObjectID = NewObjectID;
}

double cObject::GetX()
{
	return X;
}

void cObject::SetX(double New)
{
	X = New;
}

double cObject::GetY()
{
	return Y;
}

void cObject::SetY(double New)
{
	Y = New;
}

double cObject::GetDirPointing()
{
	return DirPointing;
}

void cObject::SetDirPointing(double New)
{
	DirPointing = New;
}

list <int, eObjectType> ObjList;

int FindSpotInObjectList(cObjList)
{
	int lReturn = 0;

	//find the spot we need to insert the new object into
	for each (cObjList e in ObjList)
	{
		bool lFound = false;

		//TODO: add a way to figure out where we need to add the new object

		if (lFound)
			return lReturn;
		else
			lReturn++;
	}

	//in the case it needs to be added to the end
	return lReturn;
}

void AddObjectToList(int ID, eObjectType Type)
{
	if (ObjList.size > 0)
	{
		//check for clones of the object first
		for each (cObjList e in ObjList)
		{
			//found a copy of the current object
			if (e.ID == ID && e.Type == Type)
			{
				if (TD2DE.GetDebugMode() >= DEBUG_LOW)
					TD2DE_DEBUG.LogError("Object_Class: AddObjectToList - already exists in list");
				return;
			}
		}
	}

	//create temp object and push it to the vector
	cObjList temp;
	temp.ID = ID;
	temp.Type = Type;

	//TODO exra code here to figure out WHERE in the list it needs to be entered
	int lLocation = FindSpotInObjectList(temp);
	if (lLocation != ObjList.size)
		ObjList.insert(ObjList.begin() + lLocation, temp);
	else
		ObjList.push_back(temp);
}

void RemoveObjectFromList(int ID, int Type)
{
	if (ObjList.size > 0)
	{
		//check for clones of the object first
		for (int i = 0; i < ObjList.size; i++)
		{
			//found a copy of the current object, wipe it
			if (ObjList[i].ID == ID && ObjList[i].Type == Type)
			{
				if (TD2DE.GetDebugMode() >= DEBUG_LOW)
					TD2DE_DEBUG.LogError("Object_Class: DeleteObjectFromList - Object Deleted");
				ObjList.erase(ObjList.begin() + i);
			}
		}
	}
}