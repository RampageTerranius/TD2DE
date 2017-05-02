#pragma once
//sends data across to the texture engine to load and manage ttf textures

class cTTF : public cObject
{
};

vector <cTTF> TD2DE_TTF;
/*
//returns the id to the texture of the created ttf texture
int cTTF::Create(string TTFFile, int FontSize, string Message, int R, int G, int B, int A)
{
	int lReturn = -1;

	SDL_Color Temp {R, G, B, A};
	TTF_Font *Font;
	Font = TTF_OpenFont(TTFFile.c_str(), FontSize);//loading the font file to be used
	if (Font == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: TTF-Create: Unable to load ttf file : " + TTFFile);
		return lReturn;
	}
	
	SDL_Surface *TTFSurface = NULL;
	TTFSurface = TTF_RenderText_Solid(Font, Message.c_str(), Temp);
	TTF_CloseFont(Font);
	if (TTFSurface == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: TTF-Create: Surface was empty: " + TTFFile);
		SDL_FreeSurface(TTFSurface);
		return lReturn;
	}

	SDL_Texture *TTFTexture = NULL;
	TTFTexture = SDL_CreateTextureFromSurface(TD2DE_RENDER.Renderer, TTFSurface);
	if (TTFTexture == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: TTF-Create: Texture was empty: " + TTFFile);
		SDL_FreeSurface(TTFSurface);
			SDL_DestroyTexture(TTFTexture);
		return lReturn;
	}		

	int SaveTexture(SDL_Texture *Texture, string NewName);
	lReturn = SaveTexture(TTFTexture, "TTF-" + Message);

	//clean the surface and texture
	SDL_DestroyTexture(TTFTexture);
	SDL_FreeSurface(TTFSurface);
	Delete();//clear the data after use

	return lReturn;
}*/

string TD2DE_CreateTTFTexture(string TTFFile, int FontSize, string Message, int R, int G, int B, int A)
{
	SDL_Surface *TTFSurface = NULL;

	TTF_Font *Font = TTF_OpenFont(TTFFile.c_str(), FontSize);//loading the font file to be used
	if (Font == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: TTF-Create: Unable to load ttf file : " + TTFFile);
		return "";
	}

	SDL_Color Temp{ R, G, B, A };

	TTFSurface = TTF_RenderText_Solid(Font, Message.c_str(), Temp);
	TTF_CloseFont(Font);

	if (TTFSurface == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: TTF-Create: Surface was empty: " + TTFFile);
		SDL_FreeSurface(TTFSurface);
		return "";
	}

	SDL_Texture *TTFTexture = NULL;

	TTFTexture = SDL_CreateTextureFromSurface(TD2DE_RENDER.Renderer, TTFSurface);

	string SaveTexture(SDL_Texture *Texture, string Name);//needed for saving ahead
	return SaveTexture(TTFTexture, Message);
}

int TD2DE_CreateTTF(string TTFFile, int FontSize, string Message, int R, int G, int B, int A)
{
	bool lLoop = true;
	while (lLoop)
	{
		int lTotalObjects = TD2DE_TTF.size();
		for (int i = 0; i < lTotalObjects; i++)
		{
			if (TD2DE_TTF[i].GetObjectID() == -1)
			{
				TD2DE_TTF[i].SetTextureID(TD2DE_CreateTTFTexture(TTFFile, FontSize, Message, R, G, B, A));
				TD2DE_TTF[i].SetObjectID(0);

				if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
					TD2DE_DEBUG.LogError("Info: TD2DE_CreateTFF: sucessfully created ttf: " + TTFFile + ", '" + Message + "'");

				AddObjectToList(i, TYPE_TTF);

				return i;
			}
		}
		//if it cant create an object increase the size of the array
		TD2DE_DEBUG.LogError("new value in TTF", false);
		TD2DE_DEBUG.LogError("before - c:" + to_string(TD2DE_ENTITY.capacity()) + " s:" + to_string(TD2DE_ENTITY.size()) + " ms:" + to_string(TD2DE_ENTITY.max_size()));
		cTTF Temp;
		Temp.Delete();//make sure its a blank object
		TD2DE_TTF.push_back(Temp);//push blank object to array
		TD2DE_DEBUG.LogError("after - c:" + to_string(TD2DE_ENTITY.capacity()) + " s:" + to_string(TD2DE_ENTITY.size()) + " ms:" + to_string(TD2DE_ENTITY.max_size()));
	}
	return -1;
}