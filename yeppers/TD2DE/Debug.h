#pragma once
//debug enums
enum eDebug
{
	DEBUG_NONE,
	DEBUG_LOW,
	DEBUG_MEDIUM,	
	DEBUG_HIGH
};

class cDebug
{
	public:
		fstream File;

		void LogError(string lError, bool lGetError);
		void LogError(string lError);
}TD2DE_DEBUG;

void cDebug::LogError(string lError, bool lGetError)
{
	if (lGetError)
	{
		File << lError.data() << ":" << SDL_GetError() << "\n";
		SDL_ClearError();
	}
	else
		File << lError.data() << "\n";
	File.sync();
}

void cDebug::LogError(string lError)
{
	File << lError.data() << "\n";
	File.sync();
}

