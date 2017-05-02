#pragma once

//automatically render the scene using layers and if the image is allowed to be rendered


void TD2DE_RenderScene(bool UseLayers, bool UseCanRender)
{
	for each(cObjList e in ObjList)
	{
		switch (e.Type)//0 entity - 1 button - 2 ttf - 3 ui
		{
		case TYPE_ENTITY:
			TD2DE_ENTITY[e.ID].Render();
			break;
		case TYPE_BUTTON:
			TD2DE_BUTTON[e.ID].Render();
			break;
		case TYPE_TTF:
			TD2DE_TTF[e.ID].Render();
			break;
		case TYPE_UI:
			TD2DE_UI[e.ID].Render();
			break;
		}
	}
}


	/*bool lReturn = true;
	cObject* lObjArray = new cObject[TD2DE_ENTITY.size() + TD2DE_TTF.size() + TD2DE_UI.size() + TD2DE_BUTTON.size()];
	int lLength = 0;

	//preparing the array for use
	for each(cEntity e in TD2DE_ENTITY)
	{
		lObjArray[lLength] = (cEntity)e;
		lLength++;
	}
	for each(cTTF e in TD2DE_TTF)
	{
		lObjArray[lLength] = (cTTF)e;
		lLength++;
	}
	for each(cUI e in TD2DE_UI)
	{
		lObjArray[lLength] = (cUI)e;
		lLength++;
	}
	for each(cButton e in TD2DE_BUTTON)
	{
		lObjArray[lLength] = (cButton)e;
		lLength++;
	}


	//attempt to render the scene
	try
	{
		TD2DE_DEBUG.LogError("size: " + to_string(TD2DE_TEXTURE.size()));

		//checking how many layers to use
		//if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
		//	TD2DE_DEBUG.LogError("texture layer max: " + to_string(gTextureMaxLayer));

		//looping for each layer
		for (int i = 0; i <= TD2DE.GetMaxLayer(); i++)
		{
			//looping for each object
			for (int n = 0; n < lLength; n++)
			{
				//get the objects texture id and check if its blank or not
				cObject lObj = lObjArray[n];
				string lID = lObj.GetTextureID();

				if (lID != "")
				{
					//make sure the texture actually exists that were trying to print
					if (TD2DE_TEXTURE.count(lID) > 0)
					{
						cTexture* lTex = TD2DE_TEXTURE.at(lID);

						//check if were at same layer as texture or if we arent using layers
						if (lTex->GetLayer() == i || UseLayers == false)
						{
							//if were not going to use layers then force this to be the only loop that activates
							if (UseLayers == false)
								i = TD2DE.GetMaxLayer();

							//check if the object is allowed to render or it we dont care if it can or cant 
							if (lTex->CanRender() || UseCanRender == false)
								lObjArray[n].Render();
						}
					}
					else
						if (TD2DE.GetDebugMode() >= DEBUG_LOW)
							TD2DE_DEBUG.LogError("Error: RenderScene: attmept to load a texture that has not been created under id: " + lID);
				}
			}
		}
	}
	catch (int i)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Texture_Class-RenderScene: An error occured while attempting to render the scene. the render has been canceled. error code :" + to_string(i));
		lReturn = false;
	}*/


	
	//LEGACY CODE
	
	//attempt to render the scene
	/*try
	{
		//TD2DE_DEBUG.LogError("size: " + TD2DE_TEXTURE.size());
		for (int n = 0; n <= TD2DE.GetMaxLayer(); n++)
		{
			//start rendering entitys
			//loop for entire entity array
			for (size_t i = 0; i < TD2DE_ENTITY.size(); i++)
			{
				
				if (TD2DE_ENTITY[i].GetTextureID() != "")
				{
					cTexture* lTEX = TD2DE_TEXTURE.at(TD2DE_ENTITY[i].GetTextureID());
					//check if at same layer as loop or if we wont be using layers
					if (TD2DE_TEXTURE.at(TD2DE_ENTITY[i].GetTextureID())->GetLayer() == n || UseLayers == false)
					{
						//if were not going to use layers then force this to be the only loop that activates
						if (UseLayers == false)
							n = TD2DE.GetMaxLayer();

						//check if the object is allowed to render or it we dont care if it can or cant 
						if (TD2DE_TEXTURE.at(TD2DE_ENTITY[i].GetTextureID())->CanRender() || UseCanRender == false)
						{
							//check if we will bother dealing with rotation
							TD2DE_ENTITY[i].Render();
						}
					}
				}
			}
		}

		//render any text
		for (int n = 0; n < TD2DE_TTF.size(); n++)
		{
			if (TD2DE_TTF[n].GetTextureID() != "")
			{
				TD2DE_TTF[n].Render();
			}
		}

		//render buttons (not taking into account layering)
		for (int n = 0; n < TD2DE_BUTTON.size(); n++)
		{
			TD2DE_BUTTON[n].Render();
		}

		//start rendering UI (render after entitys as we want it to ALWAYS be on top)
		for (int n = 0; n <= TD2DE.GetMaxLayer(); n++)
		{
			for (size_t i = 0; i < TD2DE_UI.size(); i++)
			{
				if (TD2DE_UI[i].GetTextureID() != "")
				{

					TD2DE_DEBUG.LogError("ui:"+to_string(i)+"h:" + to_string(TD2DE_TEXTURE.at(TD2DE_UI[i].GetTextureID())->GetRenderRect().h) + "w:" + to_string(TD2DE_TEXTURE.at(TD2DE_UI[i].GetTextureID())->GetRenderRect().w) + "x:" + to_string(TD2DE_TEXTURE.at(TD2DE_UI[i].GetTextureID())->GetRenderRect().x) + "y:" + to_string(TD2DE_TEXTURE.at(TD2DE_UI[i].GetTextureID())->GetRenderRect().y));
					if (TD2DE_TEXTURE.at(TD2DE_UI[i].GetTextureID())->GetLayer() == n || UseLayers == false)
					{
						if (UseLayers == false)
							n = TD2DE.GetMaxLayer();

						if (TD2DE_TEXTURE.at(TD2DE_UI[i].GetTextureID())->CanRender() || UseCanRender == false)
						{
								TD2DE_UI[i].Render();
						}
					}
				}
			}
		}

		
	}catch (int i)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: Texture_Class-RenderScene: An error occured while attempting to render the scene. the render has been canceled. error code :" + to_string(i));
		lReturn = false;
	}*/
	//delete lObjArray;

SDL_Surface* LoadPNG(string lFile)
{
	SDL_Surface* lImage;
	lImage = IMG_Load(lFile.c_str());
	if (!lImage && TD2DE.GetDebugMode() >= DEBUG_LOW)
		TD2DE_DEBUG.LogError("Error: Misc-LoadPNG: Image Loading Error");

	return lImage;
}

string LoadTexture(string lFile, string lName)
{
	//checking if a texture of the same name already exists
	if (TD2DE_TEXTURE.count(lName) == 1)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
			TD2DE_DEBUG.LogError("Info: LoadTexture(): Image (" + lFile + ") with same name (" + lName + ") is already loaded");

		return lName;
	}
	else
	{
		//else we will create the texture in memory
		cTexture* Tex = new cTexture();
		Tex->LoadFile(lFile);

		TD2DE_TEXTURE.insert(std::pair<string, cTexture*>(lName, Tex));

		if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
			TD2DE_DEBUG.LogError("Info: LoadTexture(): Image loaded under the name: " + lName);
		return lName;
	}

	//this shouldnt call but just incase
	if (TD2DE.GetDebugMode() >= DEBUG_LOW)
		TD2DE_DEBUG.LogError("Error: LoadTexture(): Unknown Error", false);

	return "";
}

//in the case that the user does not wish to specify a name for the loaded texture autoamtically revert to using the file location as its name
string LoadTexture(string lFile)
{
	return LoadTexture(lFile, lFile);
}

string SaveTexture(SDL_Texture *Texture, string Name)
{
	if (TD2DE_TEXTURE.count(Name) == 1)
	{
		cTexture* lTEX = new cTexture();
		if (lTEX->SetTexture(Texture, Name))
		{
			TD2DE_TEXTURE.at(Name) = lTEX;

			if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
				TD2DE_DEBUG.LogError("Info: TextureClass-SaveTexture: texture " + Name + " successfully saved under name '" + Name);
		}
		else
		{
			delete lTEX;
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogError("Error: TextureClass-SaveTexture: SetTexture() has failed returning false");
			return "";
		}
		
	}
	else
	{
		cTexture* lTEX = new cTexture();
		if (lTEX->SetTexture(Texture, Name))
		{
			TD2DE_TEXTURE.insert(std::pair<string, cTexture*>(Name, lTEX));

			if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
				TD2DE_DEBUG.LogError("Info: TextureClass-SaveTexture: texture " + Name + " successfully Created under name '" + Name);
		}
		else
		{
			delete lTEX;
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogError("Error: TextureClass-SaveTexture: SetTexture() has failed to create returning false");
			return "";
		}
	}

	return Name;
}

//LEGACY CODE
/*
//loads an image into the texture array checking to see if a texture with the same name already exists and returning that texture if it does isntead
int LoadTexture(string lFile, string lName)
{
	int lReturn = -1;
	//working with a static vector here, presuming there will be no corruption of pointers

	//check for same text first
	//if a texture with same name is found return that textures id instead
	for (size_t i = 0; i < TD2DE_TEXTURE.size(); i++)
		if (TD2DE_TEXTURE[i].GetName() == lName)
		{
			if (lReturn != -1 && TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
				TD2DE_DEBUG.LogError("Info: ExtraFunctions-LoadImage: a texture with the name '" + lName + "' with texture id: " + to_string(lReturn) + " was found, id returned and new texture not created");
			return i;
		}
			

	//same texture name not found so now check for blank array
	for (size_t i = 0; i < TD2DE_TEXTURE.size(); i++)
	{
		if (!TD2DE_TEXTURE[i].Loaded())
		{
			//if blank array is found load image into it and name the array, check to see if an error happens when loading
			if (TD2DE_TEXTURE[i].LoadFile(lFile) == true)
			{
				TD2DE_TEXTURE[i].SetName(lName);
				if (lReturn != -1 && TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
					TD2DE_DEBUG.LogError("Info: TextureClass-LoadTexture: texture " + lFile + " successfully loaded under name '" + lName + "' with texture id: " + to_string(lReturn));
				return i;
			}
			if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
				TD2DE_DEBUG.LogError("Error: TextureClass-LoadTexture: LoadFile() has failed returning false");
			return -1;
		}
	}

	//return -1 if all else has failed and image load was not successful (the array was full etc)
	if (TD2DE.GetDebugMode() >= DEBUG_LOW)
		TD2DE_DEBUG.LogError("Warning: TextureClass-LoadTexture: texture array is full, can not load texture");

	return lReturn;
}
*/

/*
int SaveTexture(SDL_Texture *Texture, string Name)
{
	int lReturn = -1;

	//save a basic texture directly to the array
	for (size_t i = 0; i < TD2DE_TEXTURE.size(); i++)
	{
		if (!TD2DE_TEXTURE[i].Loaded())
		{
			//if blank array is found save texture into it and name the array, check to see if an error happens when loading
			if (TD2DE_TEXTURE[i].SetTexture(Texture, Name) == true)
			{
				if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
					TD2DE_DEBUG.LogError("Info: TextureClass-SaveTexture: texture " + Name + " successfully saved under name '" + Name + "' with texture id: " + to_string(i));
				return i;
			}
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogError("Error: TextureClass-SaveTexture: SetTexture() has failed returning false");
			return -1;
		}
	}

	//return -1 if all else has failed and texture save was not successful (the array was full etc)
	if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
		TD2DE_DEBUG.LogError("Warning: TextureClass-SaveTexture: texture array is full, can not save texture");

	return lReturn;
}
*/