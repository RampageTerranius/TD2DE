#pragma once

class cCMD
{
	private: 
	SDL_Texture* Tex;
	int Width,
		Height;

	public:
		cCMD();
		~cCMD();

		int GetWidth();
		int GetHeight();
		bool CreateCommandConsoleTexture();
		void DrawCommandConsole();

};

cCMD::cCMD()
{
	Tex = NULL;
}

cCMD::~cCMD()
{
	if (Tex != NULL)
	{
		SDL_DestroyTexture(Tex);
		Tex = NULL;
	}
}

int cCMD::GetWidth()
{
	return Width;
}

int cCMD::GetHeight()
{
	return Height;
}

bool cCMD::CreateCommandConsoleTexture()
{
	if (Width != GetWidth() || Height != GetHeight())
	{
		SDL_Surface* Temp = SDL_CreateRGBSurface(0, TD2DE.GetScreenWidth(), TD2DE.GetScreenHeight() / 2, 8, 0, 0, 0, 155);

	}

	return 0;
}

void cCMD::DrawCommandConsole()
{
	if (TD2DE.GetCMD())
	{
		if (Tex == NULL)
		{
			if ()
				if (!CreateCommandConsoleTexture())
				{
					if (TD2DE.GetDebugMode() >= DEBUG_LOW)
						TD2DE_DEBUG.LogError("Erorr: DrawCommandConsole: unable to create command console texture");
				}
		}
	}
}