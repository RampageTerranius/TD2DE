#pragma once
class cTD2DE
{
	private:
		eDebug	DebugMode;//accepts DEBUG_NONE, DEBUG_LOW, DEBUG_MEDIUM, DEBUG_HIGH. none = no debug info, low = only errors, medium = errors + warnings, high = errors + warnings + extra stuff like reporting variables or loop section etc
		string	DebugFileName,
				WindowName,
				Version;

		int		ScreenWidth,
				ScreenHeight,
				FrameRateLimit,//engine fps is combined with engine ticks
				//following are for audio
				MHZ,//the speaker frequency to work with, defaulted to 22050
				Channels,//how many channels the audio will run on (basically how many speakers there is)
				BitRate;//defaulted to 2048kb, more = higher quality but laggier
		int		MaxLayers;

		bool	Running,
				FullScreen,
				CMD;//command console

	public:
		//constructor
		cTD2DE();

		//variable mutators and accessors
		eDebug GetDebugMode();
		void SetDebugMode(eDebug NewDebugMode);
		string GetDebugFileName();
		void SetDebugFileName(string NewDebugFileName);
		string GetWindowName();
		void SetWindowName(string NewWindowName);
		string GetVersion();
		int GetScreenWidth();
		void SetScreenWidth(int NewScreenWidth);
		int GetScreenHeight();
		void SetScreenHeight(int NewScreenHeight);
		int GetFrameRateLimit();
		void SetFrameRateLimit(int NewFrameRateLimit);
		bool GetRunning();
		void SetRunning(bool NewRunning);
		bool GetFullScreen();
		void SetFullScreen(bool NewFullScreen);
		int GetMaxLayer();
		void SetMaxLayer(int Layer);
		bool GetCMD();
		void SetCMD(bool NewCMD);

		//audio related
		int GetMHZ();
		void SetMHZ(int NewMHZ);
		int GetChannels();
		void SetChannels(int NewwChannels);
		int GetBitRate();
		void SetBitRate(int NewBitRate);
} TD2DE;

//constructor
cTD2DE::cTD2DE()
{
	DebugMode = DEBUG_HIGH;
	DebugFileName = "TD2DE.txt";
	Version = TD2DE_Version;
	ScreenWidth = 640;
	ScreenHeight = 480;
	FrameRateLimit = 60;
	Running = false;
	FullScreen = 0;
	MaxLayers = 2;

	//audio related
	MHZ = 22050;
	Channels = 2;
	BitRate = 2048;
}

//acessors and mutators
eDebug cTD2DE::GetDebugMode()
{
	return DebugMode;
}

void cTD2DE::SetDebugMode(eDebug NewDebugMode)
{
	DebugMode = NewDebugMode;
}

string cTD2DE::GetDebugFileName()
{
	return DebugFileName;
}

void cTD2DE::SetDebugFileName(string NewDebugFileName)
{
	DebugFileName = NewDebugFileName;
}

string cTD2DE::GetWindowName()
{
	return WindowName;
}

void cTD2DE::SetWindowName(string NewWindowName)
{
	WindowName = NewWindowName;
}

string cTD2DE::GetVersion()
{
	return Version;
}

int cTD2DE::GetScreenWidth()
{
	return ScreenWidth;
}

void cTD2DE::SetScreenWidth(int NewScreenWidth)
{
	ScreenWidth = NewScreenWidth;
}

int cTD2DE::GetScreenHeight()
{
	return ScreenHeight;
}

void cTD2DE::SetScreenHeight(int NewScreenHeight)
{
	ScreenHeight = NewScreenHeight;
}

int cTD2DE::GetFrameRateLimit()
{
	return FrameRateLimit;
}

void cTD2DE::SetFrameRateLimit(int NewFrameRateLimit)
{
	FrameRateLimit = NewFrameRateLimit;
}

bool cTD2DE::GetRunning()
{
	return Running;
}

void cTD2DE::SetRunning(bool NewRunning)
{
	Running = NewRunning;
}

bool cTD2DE::GetFullScreen()
{
	return FullScreen;
}

void cTD2DE::SetFullScreen(bool NewFullScreen)
{
	FullScreen = NewFullScreen;
}

int cTD2DE::GetMaxLayer()
{
	return MaxLayers;
}

void cTD2DE::SetMaxLayer(int Layer)
{
	MaxLayers = Layer;
}

bool cTD2DE::GetCMD()
{
	return CMD;
}

void cTD2DE::SetCMD(bool NewCMD)
{
	CMD = NewCMD;
}

int cTD2DE::GetMHZ()
{
	return MHZ;
}

void cTD2DE::SetMHZ(int NewMHZ)
{
	MHZ = NewMHZ;
}

int cTD2DE::GetChannels()
{
	return Channels;
}

void cTD2DE::SetChannels(int NewwChannels)
{
	Channels = NewwChannels;
}

int cTD2DE::GetBitRate()
{
	return BitRate;
}

void cTD2DE::SetBitRate(int NewBitRate)
{
	BitRate = NewBitRate;
}