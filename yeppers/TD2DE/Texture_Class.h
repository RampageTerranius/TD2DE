//header guard
#pragma once

SDL_Surface* gSurface = NULL;

//enums to do with layers (limitign the layers to 3)
enum eLayer
{
	LAYER_BACK,
	LAYER_MIDDLE,
	LAYER_FRONT
};

//class for handling textures and the like
class cTexture
{
	public:
	cTexture();
	~cTexture();

	void Delete();

	bool LoadFile(string File);
	//void Render(int X, int Y);//default render
	//void Render(int X, int Y, double Rotation);//image rotation enabled render
	
	eLayer GetLayer();
	void SetLayer(eLayer Layer);
	bool SetTexture(SDL_Texture* NewTexture, string NewName);//force the texture to be a specific image
	SDL_Texture* ReturnTexture();
	SDL_Rect GetRenderRect();
	void SetRenderRect(SDL_Rect NewRenderRect);
	bool Loaded();
	bool CanRender();
	void SetCanRender(bool CanRender);
	int GetWidth();
	int GetHeight();
	

	private:
	SDL_Rect RenderRect;//what areas of the texture to render
	SDL_Texture* Texture = NULL;
	int Width,
		Height;
	eLayer Layer;
	bool AllowRender;
};

map<string, cTexture*> TD2DE_TEXTURE;

//initializer
cTexture::cTexture()
{
	Delete();
}

//deconstructor
cTexture::~cTexture()
{
	//free all textures
	Delete();
}

void cTexture::Delete()
{
	if (Texture != NULL)
	{
		SDL_DestroyTexture(Texture);
		Texture = NULL;
	}
	else if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
		TD2DE_DEBUG.LogError("Warning: TextureClass-cTexture::FreeTexture: Texture is already NULL", false);

	RenderRect.h = 0;
	RenderRect.w = 0;
	RenderRect.x = 0;
	RenderRect.y = 0;
	Width = 0;
	Height = 0;
	Texture = NULL;
	Layer = LAYER_MIDDLE;
	AllowRender = false;
}

//force the texture with out loading
bool cTexture::SetTexture(SDL_Texture* NewTexture, string NewName)
{
	bool lReturn = false;

	//clear the texture ahead of time if needed
	if (Loaded())
		Delete();
	Texture = NewTexture;//set texture to given
	SDL_QueryTexture(Texture, NULL, NULL, &Width, &Height);//get the width and height of the texture
	AllowRender = true;

	if (Texture != NULL)
		lReturn = true;

	return lReturn;
}


SDL_Texture* cTexture::ReturnTexture()
{
	return Texture;
}

SDL_Rect cTexture::GetRenderRect()
{
	return RenderRect;
}

void cTexture::SetRenderRect(SDL_Rect NewRenderRect)
{
	RenderRect = NewRenderRect;
}

eLayer cTexture::GetLayer()
{
	return Layer;
}

void cTexture::SetLayer(eLayer fLayer)
{
	Layer = fLayer;
}

bool cTexture::Loaded()
{
	if (Texture == NULL)
		return false;
	else
		return true;
}

bool cTexture::CanRender()
{
	return AllowRender;
}

void cTexture::SetCanRender(bool CanRender)
{
	AllowRender = CanRender;
}

int cTexture::GetWidth()
{
	return Width;
}

int cTexture::GetHeight()
{
	return Height;
}

//prototype for use with load file
SDL_Surface* LoadPNG(string lFile);

//use LoadTexture for general use, LoadFile is for specifically forcing a file to load and is used by LoadTexture
bool cTexture::LoadFile(string File)
{
	bool lReturn = true;
	//clean up the texture ahead of time if needed
	if (Texture != NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
			TD2DE_DEBUG.LogError("Warning: TextureClass-cTexture-LoadFile: Texture deleted before loading", false);
		Delete();
	}

	SDL_Surface* lSurface;
	lSurface = LoadPNG(File);
	if (lSurface == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: TextureClass-cTexture-LoadFile-LoadPNG", true);
		lReturn = false;
	}
	else
	{
		SDL_SetColorKey(lSurface, true, SDL_MapRGB(lSurface->format, 255, 0, 255));
		Texture = SDL_CreateTextureFromSurface(TD2DE_RENDER.Renderer, lSurface);
	}

	if (Texture == NULL)
	{
		if (TD2DE.GetDebugMode() >= DEBUG_LOW)
			TD2DE_DEBUG.LogError("Error: TextureClass-cTexture-LoadFile-SDL_CreateTexture", true);
		lReturn = false;
	}

	Width = lSurface->w;
	Height = lSurface->h;
	AllowRender = true;
	SDL_FreeSurface(lSurface);

	return true;
}

/*

LEGACY CODE

//default render using RenderCopy, does not support rotation, supports specifying what parts of the texture to render
void cTexture::Render(int X, int Y)
{
	cTexture::Render(X, Y, 0);
}



//render using RenderCopyEx, enabled to allow rotation
void cTexture::Render(int X, int Y, double Rotation)
{
	SDL_Rect sRenderRect = RenderRect;
	SDL_Rect tRenderRect;

	if (sRenderRect.h == 0 && sRenderRect.w == 0 && sRenderRect.x == 0 && sRenderRect.y == 0)
	{
		sRenderRect.h = Height;
		sRenderRect.w = Width;
		sRenderRect.x = 0;
		sRenderRect.y = 0;
		tRenderRect.h = Height;
		tRenderRect.w = Width;
	}
	else
	{
		tRenderRect.h = sRenderRect.h;
		tRenderRect.w = sRenderRect.w;
	}
	tRenderRect.x = X;
	tRenderRect.y = Y;

	SDL_RenderCopyEx(TD2DE_RENDER.Renderer, Texture, &sRenderRect, &tRenderRect, Rotation, NULL, SDL_FLIP_NONE);
}
*/