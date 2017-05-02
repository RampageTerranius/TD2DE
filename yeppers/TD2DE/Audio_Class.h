#pragma once
//base audio class, is inherited by audio music and overwritten
class TD2DE_AUDIO_CHUNK
{
	private:
		Mix_Chunk *Sound;
		int Channels;//defaulting to -1 (-1 is all channels)

	protected:				
		int Loops;//how many times the sound will loop

	public:
		TD2DE_AUDIO_CHUNK();
		~TD2DE_AUDIO_CHUNK();
		void Delete();
		void Play();
		void Load(string lName);
		void SetChannels(int NewChannels);
		void SetLoops(int NewLoops);
};

TD2DE_AUDIO_CHUNK::TD2DE_AUDIO_CHUNK()
{
	Channels = -1;
	Loops = 0;
	Sound = NULL;
}

TD2DE_AUDIO_CHUNK::~TD2DE_AUDIO_CHUNK()
{
	Delete();
}

void TD2DE_AUDIO_CHUNK::Delete()
{
	if (Sound != NULL)
		Mix_FreeChunk(Sound);
}

void TD2DE_AUDIO_CHUNK::Play()
{
	Mix_PlayChannel(Channels, Sound, Loops);
}

void TD2DE_AUDIO_CHUNK::Load(string lName)
{
	Sound = Mix_LoadWAV(lName.c_str());
	if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
	{
		if (Sound != NULL)
			TD2DE_DEBUG.LogError("Audio chunk file successfully loaded: " + lName);
		else
		{
			string Temp(Mix_GetError());
			TD2DE_DEBUG.LogError("Audio chunk file was not loaded: " + Temp);
		}			
	}
}

void TD2DE_AUDIO_CHUNK::SetChannels(int NewChannels)
{
	Channels = NewChannels;
}

void TD2DE_AUDIO_CHUNK::SetLoops(int NewLoops)
{
	Loops = NewLoops;
}

//used for music specifically overwrites play and sound from base class
class TD2DE_AUDIO_MUSIC : public TD2DE_AUDIO_CHUNK
{
	private:
		Mix_Music *Sound;
		bool Paused;

	public:
		TD2DE_AUDIO_MUSIC();
		~TD2DE_AUDIO_MUSIC();
		void Load(string lName);
		void Delete();
		void Pause();
		void Play();
} TD2DE_AUDIO_MUSIC;

TD2DE_AUDIO_MUSIC::TD2DE_AUDIO_MUSIC()
{
	TD2DE_AUDIO_CHUNK::TD2DE_AUDIO_CHUNK();
	Paused = false;
}

TD2DE_AUDIO_MUSIC::~TD2DE_AUDIO_MUSIC()
{
	Delete();
}

void TD2DE_AUDIO_MUSIC::Delete()
{
	Paused = false;	
	if (Sound != NULL)
		Mix_FreeMusic(Sound);
}

void TD2DE_AUDIO_MUSIC::Load(string lName)
{
	Sound = Mix_LoadMUS(lName.c_str());
	if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
	{
		if (Sound != NULL)
			TD2DE_DEBUG.LogError("Audio music file successfully loaded: " + lName);
		else
		{
			string Temp(Mix_GetError());
			TD2DE_DEBUG.LogError("Audio music file was not loaded: " + Temp);
		}
	}
}

void TD2DE_AUDIO_MUSIC::Pause()
{
	if (!Mix_PausedMusic())
		Mix_PauseMusic();
	else
		Mix_ResumeMusic();
}

void TD2DE_AUDIO_MUSIC::Play()
{
	if (!Paused)
		Mix_PlayMusic(Sound, Loops);
	else
		if (Mix_PausedMusic())
			Mix_ResumeMusic();
}