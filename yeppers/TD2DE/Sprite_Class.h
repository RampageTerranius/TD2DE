//header guard
#pragma once

	//handler for sprites, using the texture engien to store each of the sprites images as needed
	class cSprite
	{
			
		private:
			string Name;//name of sprite
			vector <int> TextureID;//array storing all the ids of each texture 

			//extra data handling sprite animation
			int AnimationDelay;//how many ticks per animation change
			int CurrentTexture;//what texture is currently being shown
			int CurrentFrame;//how many frames sicne last change

		public:
			cSprite();
			void Delete();

			void SetTextureID(vector <int> NewTexID);
			vector <int> GetTextureID();
			void SetName(string NewName);
			string GetName();
			
	};
	vector <cSprite> TD2DE_SPRITE;

	//default constructor uses Delete() to clear data ahead of time
	cSprite::cSprite()
	{
		Delete();
	}

	//clearing function
	void cSprite::Delete()
	{
		Name = "Blank Sprite";
		TextureID.clear();
		AnimationDelay = 0;
		CurrentTexture = 0;
		CurrentFrame = 0;
	}

	void cSprite::SetTextureID(vector <int> NewTexID)
	{
		TextureID = NewTexID;
	}

	vector <int> cSprite::GetTextureID()
	{
		return TextureID;
	}

	void cSprite::SetName(string NewName)
	{
		Name = NewName;
	}

	string cSprite::GetName()
	{
		return Name;
	}

	//default sprite creation method
	int CreateSprite(string SpriteName, vector <int> NewTexID)
	{
		bool lLoop = true;
		while (lLoop)
		{
			int lTotalObjects = TD2DE_SPRITE.size();
			for (int i = 0; i < lTotalObjects; i++)
			{
				if (TD2DE_SPRITE[i].GetName() == "Blank Sprite")
				{
					//setup the new sprite
					cSprite NewSprite;

					//setup the name and ids for the textures
					NewSprite.SetTextureID(NewTexID);
					NewSprite.SetName(SpriteName);
	
					//assign the new sprite to the array
					TD2DE_SPRITE[i] = NewSprite;

					return i;
				}
			}
			//if it cant create an object increase the size of the array
			TD2DE_DEBUG.LogError("new value in SPRITE", false);
			TD2DE_DEBUG.LogError("before - c:" + to_string(TD2DE_SPRITE.capacity()) + " s:" + to_string(TD2DE_SPRITE.size()) + " ms:" + to_string(TD2DE_SPRITE.max_size()));
			cSprite Temp;
			Temp.Delete();//make sure its a blank object
			TD2DE_SPRITE.push_back(Temp);//push blank object to array
			TD2DE_DEBUG.LogError("after - c:" + to_string(TD2DE_SPRITE.capacity()) + " s:" + to_string(TD2DE_SPRITE.size()) + " ms:" + to_string(TD2DE_SPRITE.max_size()));
		}
		return -1;
	}

	//overload not requiring a name to be given (uses default name of "No Name")
	int CreateSprite(vector <int> NewTexID)
	{
		return CreateSprite("No Name", NewTexID);
	}

	//returns the first id it finds using the name specified
	int TD2DE_GetSpriteID(string Name)
	{
		//return the id of the sprite if found
		for (int i = 0; i < TD2DE_SPRITE.size(); i++)
			if (TD2DE_SPRITE[i].GetName() == Name)
				return i;

		//else return -1 to signify no sprite found
		return -1;
	}

	//returns the name of the sprite id specified
	string TD2DE_GetSpriteName(int Index)
	{
		if (Index < TD2DE_SPRITE.size())
		{
			return TD2DE_SPRITE[Index].GetName();
		}
		else
			if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
				TD2DE_DEBUG.LogError("Warning: TD2DE_GetSpriteName(): ID Searched for was out of range. " + to_string(Index) + " - " + to_string(TD2DE_SPRITE.size()));
		
		return "";
	}