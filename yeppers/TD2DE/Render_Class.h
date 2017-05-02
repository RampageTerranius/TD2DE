#pragma once

class cRender
{
	private:
	string RenderScaleQuality;

	public:
	//sdl window and renderer build
	SDL_Window* Window = NULL;
	SDL_Renderer* Renderer = NULL;

	void RenderClear();
	void RenderPresent();

	string GetRenderScaleQuality();
	void SetRenderScaleQuality(string NewRenderScaleQuality);	
}TD2DE_RENDER;

void cRender::RenderClear()
{
	SDL_RenderClear(Renderer);
}

void cRender::RenderPresent()
{
	SDL_RenderPresent(Renderer);
}

string cRender::GetRenderScaleQuality()
{
	return RenderScaleQuality;
}

void cRender::SetRenderScaleQuality(string NewRenderScaleQuality)
{
	RenderScaleQuality = NewRenderScaleQuality;
}