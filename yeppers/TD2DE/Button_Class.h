#pragma once

enum eState
{
	STATE_NONE,
	STATE_MOUSEOVER,
	STATE_CLICKED
};

//handling ui buttons and the like (play game, main menu all that shitola)
//it is HIGHLY recomended to make the textures used by the different button states the same width/height as you may only specify a single location for the buttons event handling (mouse over clicknig etc)
class cButton : public cObject
{
	private:
		vector <string> TextureStorageID = vector <string> (3);//override of inherited TextureID from cObject. 0 is default image,1 is mouse over image, 2 is clicked image

		int Width,
			Height;

		eState State;

		bool AllowLeftClick,
			 AllowRightClick,
			 AllowMiddleClick;

	public:
		cButton();
		~cButton();
		void Delete();

		//void Render();
		string GetName();
		void SetName(string lName);
		string GetTextureStorageID(int Index);
		string GetTextureStorageID();
		void SetTextureStorageID(int Index, string NewTextureID);
		eState GetState();
		void SetState(eState NewState);
		int GetWidth();
		void SetWidth(int NewWidth);
		int GetHeight();
		void SetHeight(int NewHeight);
};
vector <cButton> TD2DE_BUTTON;

//constructor
cButton::cButton()
{
	Delete();
}

//deconstructor
cButton::~cButton()
{
	Delete();
}

void cButton::Delete()
{
	TextureStorageID[0] = -1;
	TextureStorageID[1] = -1;
	TextureStorageID[2] = -1;
	Width = Height = 0;
	AllowLeftClick = AllowRightClick = AllowMiddleClick = false;
	cObject::Delete();
}

/*void cButton::Render()
{
	int ID = -1;
	switch (State)
	{
		case STATE_NONE:
			ID = 0;
			break;

		case STATE_MOUSEOVER:
			ID = 1;
			break;

		case STATE_CLICKED:
			ID = 2;
			break;
	}

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
}*/

string cButton::GetTextureStorageID(int Index)
{
	
	if (Index >= 0 && Index <= 3)
		return TextureStorageID[Index];
	else
	{		
		TD2DE_DEBUG.LogError("Warning: cButton::GetTextureID: index is out of range using value " + to_string(Index) + ", index will only support 0, 1, 2,");
		return "";
	}
}

string cButton::GetTextureStorageID()
{
	return GetTextureStorageID(State);
}

void cButton::SetTextureStorageID(int Index, string NewTextureID)
{
	if (Index >= 0 && Index < TextureStorageID.size())
		TextureStorageID[Index] = NewTextureID;
	else
		TD2DE_DEBUG.LogError("Warning: cButton::SetTextureID: index is out of range using value " + to_string(Index) + ", index will only support 0, 1, 2,");
}

eState cButton::GetState()
{
	return State;
}

void cButton::SetState(eState NewState)
{
	if (State != NewState)
	{
		State = NewState;
		TextureID = TextureStorageID[State];
	}
}

int cButton::GetWidth()
{
	return Width;
}

void cButton::SetWidth(int NewWidth)
{
	Width = NewWidth;
}

int cButton::GetHeight()
{
	return Height;
}

void cButton::SetHeight(int NewHeight)
{
	Height = NewHeight;
}

int TD2DE_CreateButton(string Tex1 = "", string Tex2 = "", string Tex3 = "")
{
	bool lLoop = true;
	while (lLoop)
	{
		int lTotalObjects = TD2DE_BUTTON.size();
		for (int i = 0; i < lTotalObjects; i++)
		{
			if (TD2DE_BUTTON[i].GetObjectID() == -1)
			{
				//load the textures (defaulted to -1 if not given)
				TD2DE_BUTTON[i].SetTextureStorageID(0, Tex1);
				TD2DE_BUTTON[i].SetTextureStorageID(1, Tex2);
				TD2DE_BUTTON[i].SetTextureStorageID(2, Tex3);
				TD2DE_BUTTON[i].SetObjectID(0);

				//set the default width and height to texture 1's width and height
				TD2DE_BUTTON[i].SetWidth(TD2DE_TEXTURE.at(Tex1)->GetWidth());
				TD2DE_BUTTON[i].SetHeight(TD2DE_TEXTURE.at(Tex1)->GetHeight());

				AddObjectToList(i, TYPE_BUTTON);

				return i;				
			}
		}
		//if it cant create an object increase the size of the array
		TD2DE_DEBUG.LogError("new value in BUTTON", false);
		TD2DE_DEBUG.LogError("before - c:" + to_string(TD2DE_BUTTON.capacity()) + " s:" + to_string(TD2DE_BUTTON.size()) + " ms:" + to_string(TD2DE_BUTTON.max_size()));
		cButton Temp;
		Temp.Delete();//make sure its a blank object
		TD2DE_BUTTON.push_back(Temp);//push blank object to array
		TD2DE_DEBUG.LogError("after - c:" + to_string(TD2DE_BUTTON.capacity()) + " s:" + to_string(TD2DE_BUTTON.size()) + " ms:" + to_string(TD2DE_BUTTON.max_size()));		
	}
	return -1;
}