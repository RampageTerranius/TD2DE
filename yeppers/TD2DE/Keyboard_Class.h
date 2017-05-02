//header guard
#pragma once

//determines if a key is currently pushed down or not	
class cKeyboard
{
	public:
	cKeyboard();

	//directions
	bool	Up,
			Down,
			Left,
			Right;

	//other
	bool	Space,
			LAlt,
			RAlt,
			LCtrl,
			RCtrl,
			LShift,
			RShift,
			CapsLock,
			Enter,
			Tab,
			Backspace,
			Esc,
			Insert,
			Delete,
			Home,
			End,
			PageUp,
			PageDown;

	//f(x) keys
	bool	F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12;

	//standard keyboard numbers
	bool    SK0,
			SK1,
			SK2,
			SK3,
			SK4,
			SK5,
			SK6,
			SK7,
			SK8,
			SK9;

	//letters
	bool	A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			Comma,
			Stop,
			Slash,
			SemiColon,
			Quote,
			LeftBracket,
			RightBracket,
			BackSlash;
}TD2DE_KEYBOARD;

cKeyboard::cKeyboard()
{
	bool
		Up =
		Down =
		Left =
		Right =
		Space =
		LAlt =
		RAlt =
		LCtrl =
		RCtrl =
		LShift =
		RShift =
		CapsLock =
		Enter =
		Tab =
		Backspace =
		Esc =
		Insert =
		Delete =
		Home =
		End =
		PageUp =
		PageDown =
		F1 =
		F2 =
		F3 =
		F4 =
		F5 =
		F6 =
		F7 =
		F8 =
		F9 =
		F10 =
		F11 =
		F12 =
		SK0 =
		SK1 =
		SK2 =
		SK3 =
		SK4 =
		SK5 =
		SK6 =
		SK7 =
		SK8 =
		SK9 =
		A =
		B =
		C =
		D =
		E =
		F =
		G =
		H =
		I =
		J =
		K =
		L =
		M =
		N =
		O =
		P =
		Q =
		R =
		S =
		T =
		U =
		V =
		W =
		X =
		Y =
		Z =
		Comma =
		Stop =
		Slash =
		SemiColon =
		Quote =
		LeftBracket =
		RightBracket =
		BackSlash = false;
}