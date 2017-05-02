#pragma once

class cMouse
{
	private:
		bool LeftClick,
			 RightClick,
			 MiddleClick;
		int X,
			Y;
		

	public:
		cMouse();

		bool GetLeftClick();
		void SetLeftClick(bool NewLeftClick);
		bool GetRightClick();
		void SetRightClick(bool NewRightClick);
		bool GetMiddleClick();
		void SetMiddleClick(bool NewMiddleClick);
		int GetX();
		void SetX(int NewX);
		int GetY();
		void SetY(int NewY);

		void Delete();

} TD2DE_MOUSE;

cMouse::cMouse()
{
	
	Delete();
}

void cMouse::Delete()
{
	LeftClick = RightClick = MiddleClick = false;
	X = Y = 0;
}

bool cMouse::GetLeftClick()
{
	return LeftClick;
}

void cMouse::SetLeftClick(bool NewLeftClick)
{
	LeftClick = NewLeftClick;
}

bool cMouse::GetRightClick()
{
	return RightClick;
}

void cMouse::SetRightClick(bool NewRightClick)
{
	RightClick = NewRightClick;
}

bool cMouse::GetMiddleClick()
{
	return MiddleClick;
}

void cMouse::SetMiddleClick(bool NewMiddleClick)
{
	MiddleClick = NewMiddleClick;
}

int cMouse::GetX()
{
	return X;
}

void cMouse::SetX(int NewX)
{
	X = NewX;
}

int cMouse::GetY()
{
	return Y;
}

void cMouse::SetY(int NewY)
{
	Y = NewY;
}