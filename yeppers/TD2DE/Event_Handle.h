#pragma once

void TD2DE_ButtonHandle();

//handle all events required. calls apon keyboard event for keyboard handle and uses button handle as well
void TD2DE_EventHandle()
{
	{
		if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
			TD2DE_DEBUG.LogError("EventHandle.h: EventHandle begin");
		//polling event que
		SDL_Event EventHandle;//used to handle all incoming key events
		while (SDL_PollEvent(&EventHandle))
			switch (EventHandle.type)
			{
			////////////////
			//mouse events//
			////////////////

			case SDL_MOUSEMOTION:
				int x, y;
				SDL_GetMouseState(&x, &y);
				TD2DE_MOUSE.SetX(x);
				TD2DE_MOUSE.SetY(y);
				TD2DE_ButtonHandle();
				break;

			case SDL_MOUSEBUTTONDOWN:
				switch (EventHandle.button.button)
				{
					case SDL_BUTTON_LEFT:
						TD2DE_MOUSE.SetLeftClick(true);
						TD2DE_ButtonHandle();
						break;

					case SDL_BUTTON_MIDDLE:
						TD2DE_MOUSE.SetMiddleClick(true);
						TD2DE_ButtonHandle();
						break;

					case SDL_BUTTON_RIGHT:
						TD2DE_MOUSE.SetRightClick(true);
						TD2DE_ButtonHandle();
						break;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				switch (EventHandle.button.button)
				{
				case SDL_BUTTON_LEFT:
					TD2DE_MOUSE.SetLeftClick(false);
					TD2DE_ButtonHandle();
					break;

				case SDL_BUTTON_MIDDLE:
					TD2DE_MOUSE.SetMiddleClick(false);
					TD2DE_ButtonHandle();
					break;

				case SDL_BUTTON_RIGHT:
					TD2DE_MOUSE.SetRightClick(false);
					TD2DE_ButtonHandle();
					break;
				}
				break;


			///////////////////
			//keyboard events//
			///////////////////

			//if keyboard press is detected
			case SDL_KEYDOWN:
				switch (EventHandle.key.keysym.sym)
				{
				//directional arrows
				case SDLK_UP:
					TD2DE_KEYBOARD.Up = true;
					break;
				case SDLK_DOWN:
					TD2DE_KEYBOARD.Down = true;
					break;
				case SDLK_LEFT:
					TD2DE_KEYBOARD.Left = true;
					break;
				case SDLK_RIGHT:
					TD2DE_KEYBOARD.Right = true;
					break;

					//other keys
				case SDLK_SPACE:
					TD2DE_KEYBOARD.Space = true;
					break;
				case SDLK_LALT:
					TD2DE_KEYBOARD.LAlt = true;
					break;
				case SDLK_RALT:
					TD2DE_KEYBOARD.RAlt = true;
					break;
				case SDLK_LCTRL:
					TD2DE_KEYBOARD.LCtrl = true;
					break;
				case SDLK_RCTRL:
					TD2DE_KEYBOARD.RCtrl = true;
					break;
				case SDLK_LSHIFT:
					TD2DE_KEYBOARD.LShift = true;
					break;
				case SDLK_RSHIFT:
					TD2DE_KEYBOARD.RShift = true;
					break;
				case SDLK_CAPSLOCK:
					TD2DE_KEYBOARD.CapsLock = true;
					break;
				case SDLK_RETURN:
					TD2DE_KEYBOARD.Enter = true;
					break;
				case SDLK_TAB:
					TD2DE_KEYBOARD.Tab = true;
					break;
				case SDLK_BACKSPACE:
					TD2DE_KEYBOARD.Backspace = true;
					break;
				case SDLK_ESCAPE:
					TD2DE_KEYBOARD.Esc = true;
					break;
				case SDLK_INSERT:
					TD2DE_KEYBOARD.Insert = true;
					break;
				case SDLK_DELETE:
					TD2DE_KEYBOARD.Delete = true;
					break;
				case SDLK_HOME:
					TD2DE_KEYBOARD.Home = true;
					break;
				case SDLK_END:
					TD2DE_KEYBOARD.End = true;
					break;
				case SDLK_PAGEUP:
					TD2DE_KEYBOARD.PageUp = true;
					break;
				case SDLK_PAGEDOWN:
					TD2DE_KEYBOARD.PageDown = true;
					break;
					//F(x) keys
				case SDLK_F1:
					TD2DE_KEYBOARD.F1 = true;
					break;
				case SDLK_F2:
					TD2DE_KEYBOARD.F2 = true;
					break;
				case SDLK_F3:
					TD2DE_KEYBOARD.F3 = true;
					break;
				case SDLK_F4:
					TD2DE_KEYBOARD.F4 = true;
					break;
				case SDLK_F5:
					TD2DE_KEYBOARD.F5 = true;
					break;
				case SDLK_F6:
					TD2DE_KEYBOARD.F6 = true;
					break;
				case SDLK_F7:
					TD2DE_KEYBOARD.F7 = true;
					break;
				case SDLK_F8:
					TD2DE_KEYBOARD.F8 = true;
					break;
				case SDLK_F9:
					TD2DE_KEYBOARD.F9 = true;
					break;
				case SDLK_F10:
					TD2DE_KEYBOARD.F10 = true;
					break;
				case SDLK_F11:
					TD2DE_KEYBOARD.F11 = true;
					break;
				case SDLK_F12:
					TD2DE_KEYBOARD.F12 = true;
					break;

					//standard keyboard numbers
				case SDLK_0:
					TD2DE_KEYBOARD.SK0 = true;
					break;
				case SDLK_1:
					TD2DE_KEYBOARD.SK1 = true;
					break;
				case SDLK_2:
					TD2DE_KEYBOARD.SK2 = true;
					break;
				case SDLK_3:
					TD2DE_KEYBOARD.SK3 = true;
					break;
				case SDLK_4:
					TD2DE_KEYBOARD.SK4 = true;
					break;
				case SDLK_5:
					TD2DE_KEYBOARD.SK5 = true;
					break;
				case SDLK_6:
					TD2DE_KEYBOARD.SK6 = true;
					break;
				case SDLK_7:
					TD2DE_KEYBOARD.SK7 = true;
					break;
				case SDLK_8:
					TD2DE_KEYBOARD.SK8 = true;
					break;
				case SDLK_9:
					TD2DE_KEYBOARD.SK9 = true;
					break;

					//letter presses
				case SDLK_a:
					TD2DE_KEYBOARD.A = true;
					break;
				case SDLK_b:
					TD2DE_KEYBOARD.B = true;
					break;
				case SDLK_c:
					TD2DE_KEYBOARD.C = true;
					break;
				case SDLK_d:
					TD2DE_KEYBOARD.D = true;
					break;
				case SDLK_e:
					TD2DE_KEYBOARD.E = true;
					break;
				case SDLK_f:
					TD2DE_KEYBOARD.F = true;
					break;
				case SDLK_g:
					TD2DE_KEYBOARD.G = true;
					break;
				case SDLK_h:
					TD2DE_KEYBOARD.H = true;
					break;
				case SDLK_i:
					TD2DE_KEYBOARD.I = true;
					break;
				case SDLK_j:
					TD2DE_KEYBOARD.J = true;
					break;
				case SDLK_k:
					TD2DE_KEYBOARD.K = true;
					break;
				case SDLK_l:
					TD2DE_KEYBOARD.L = true;
					break;
				case SDLK_m:
					TD2DE_KEYBOARD.M = true;
					break;
				case SDLK_n:
					TD2DE_KEYBOARD.N = true;
					break;
				case SDLK_o:
					TD2DE_KEYBOARD.O = true;
					break;
				case SDLK_p:
					TD2DE_KEYBOARD.P = true;
					break;
				case SDLK_q:
					TD2DE_KEYBOARD.Q = true;
					break;
				case SDLK_r:
					TD2DE_KEYBOARD.R = true;
					break;
				case SDLK_s:
					TD2DE_KEYBOARD.S = true;
					break;
				case SDLK_t:
					TD2DE_KEYBOARD.T = true;
					break;
				case SDLK_u:
					TD2DE_KEYBOARD.U = true;
					break;
				case SDLK_v:
					TD2DE_KEYBOARD.V = true;
					break;
				case SDLK_w:
					TD2DE_KEYBOARD.W = true;
					break;
				case SDLK_x:
					TD2DE_KEYBOARD.X = true;
					break;
				case SDLK_y:
					TD2DE_KEYBOARD.Y = true;
					break;
				case SDLK_z:
					TD2DE_KEYBOARD.Z = true;
					break;
				case SDLK_COMMA:
					TD2DE_KEYBOARD.Comma = true;
					break;
				case SDLK_STOP:
					TD2DE_KEYBOARD.Stop = true;
					break;
				case SDLK_SLASH:
					TD2DE_KEYBOARD.Slash = true;
					break;
				case SDLK_SEMICOLON:
					TD2DE_KEYBOARD.SemiColon = true;
					break;
				case SDLK_QUOTE:
					TD2DE_KEYBOARD.Quote = true;
					break;
				case SDLK_LEFTBRACKET:
					TD2DE_KEYBOARD.LeftBracket = true;
					break;
				case SDLK_RIGHTBRACKET:
					TD2DE_KEYBOARD.RightBracket = true;
					break;
				case SDLK_BACKSLASH:
					TD2DE_KEYBOARD.BackSlash = true;
					break;


					//if none of above apply
				default:
					if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
						TD2DE_DEBUG.LogError("Warning: EventHandle-PollEvent-SDL_KEYDOWN: Unknown keypress");
					break;
				}
				break;

			case SDL_KEYUP:
				switch (EventHandle.key.keysym.sym)
				{
					//directional arrows
				case SDLK_UP:
					TD2DE_KEYBOARD.Up = false;
					break;
				case SDLK_DOWN:
					TD2DE_KEYBOARD.Down = false;
					break;
				case SDLK_LEFT:
					TD2DE_KEYBOARD.Left = false;
					break;
				case SDLK_RIGHT:
					TD2DE_KEYBOARD.Right = false;
					break;

					//other keys
				case SDLK_SPACE:
					TD2DE_KEYBOARD.Space = false;
					break;
				case SDLK_LALT:
					TD2DE_KEYBOARD.LAlt = false;
					break;
				case SDLK_RALT:
					TD2DE_KEYBOARD.RAlt = false;
					break;
				case SDLK_LCTRL:
					TD2DE_KEYBOARD.LCtrl = false;
					break;
				case SDLK_RCTRL:
					TD2DE_KEYBOARD.RCtrl = false;
					break;
				case SDLK_LSHIFT:
					TD2DE_KEYBOARD.LShift = false;
					break;
				case SDLK_RSHIFT:
					TD2DE_KEYBOARD.RShift = false;
					break;
				case SDLK_CAPSLOCK:
					TD2DE_KEYBOARD.CapsLock = false;
					break;
				case SDLK_RETURN:
					TD2DE_KEYBOARD.Enter = false;
					break;
				case SDLK_TAB:
					TD2DE_KEYBOARD.Tab = false;
					break;
				case SDLK_BACKSPACE:
					TD2DE_KEYBOARD.Backspace = false;
					break;
				case SDLK_ESCAPE:
					TD2DE_KEYBOARD.Esc = false;
					break;
				case SDLK_INSERT:
					TD2DE_KEYBOARD.Insert = false;
					break;
				case SDLK_DELETE:
					TD2DE_KEYBOARD.Delete = false;
					break;
				case SDLK_HOME:
					TD2DE_KEYBOARD.Home = false;
					break;
				case SDLK_END:
					TD2DE_KEYBOARD.End = false;
					break;
				case SDLK_PAGEUP:
					TD2DE_KEYBOARD.PageUp = false;
					break;
				case SDLK_PAGEDOWN:
					TD2DE_KEYBOARD.PageDown = false;
					break;

					//F(x) keys
				case SDLK_F1:
					TD2DE_KEYBOARD.F1 = false;
					break;
				case SDLK_F2:
					TD2DE_KEYBOARD.F2 = false;
					break;
				case SDLK_F3:
					TD2DE_KEYBOARD.F3 = false;
					break;
				case SDLK_F4:
					TD2DE_KEYBOARD.F4 = false;
					break;
				case SDLK_F5:
					TD2DE_KEYBOARD.F5 = false;
					break;
				case SDLK_F6:
					TD2DE_KEYBOARD.F6 = false;
					break;
				case SDLK_F7:
					TD2DE_KEYBOARD.F7 = false;
					break;
				case SDLK_F8:
					TD2DE_KEYBOARD.F8 = false;
					break;
				case SDLK_F9:
					TD2DE_KEYBOARD.F9 = false;
					break;
				case SDLK_F10:
					TD2DE_KEYBOARD.F10 = false;
					break;
				case SDLK_F11:
					TD2DE_KEYBOARD.F11 = false;
					break;
				case SDLK_F12:
					TD2DE_KEYBOARD.F12 = false;
					break;

					//standard keyboard numbers
				case SDLK_0:
					TD2DE_KEYBOARD.SK0 = false;
					break;
				case SDLK_1:
					TD2DE_KEYBOARD.SK1 = false;
					break;
				case SDLK_2:
					TD2DE_KEYBOARD.SK2 = false;
					break;
				case SDLK_3:
					TD2DE_KEYBOARD.SK3 = false;
					break;
				case SDLK_4:
					TD2DE_KEYBOARD.SK4 = false;
					break;
				case SDLK_5:
					TD2DE_KEYBOARD.SK5 = false;
					break;
				case SDLK_6:
					TD2DE_KEYBOARD.SK6 = false;
					break;
				case SDLK_7:
					TD2DE_KEYBOARD.SK7 = false;
					break;
				case SDLK_8:
					TD2DE_KEYBOARD.SK8 = false;
					break;
				case SDLK_9:
					TD2DE_KEYBOARD.SK9 = false;
					break;

					//letter presses
				case SDLK_a:
					TD2DE_KEYBOARD.A = false;
					break;
				case SDLK_b:
					TD2DE_KEYBOARD.B = false;
					break;
				case SDLK_c:
					TD2DE_KEYBOARD.C = false;
					break;
				case SDLK_d:
					TD2DE_KEYBOARD.D = false;
					break;
				case SDLK_e:
					TD2DE_KEYBOARD.E = false;
					break;
				case SDLK_f:
					TD2DE_KEYBOARD.F = false;
					break;
				case SDLK_g:
					TD2DE_KEYBOARD.G = false;
					break;
				case SDLK_h:
					TD2DE_KEYBOARD.H = false;
					break;
				case SDLK_i:
					TD2DE_KEYBOARD.I = false;
					break;
				case SDLK_j:
					TD2DE_KEYBOARD.J = false;
					break;
				case SDLK_k:
					TD2DE_KEYBOARD.K = false;
					break;
				case SDLK_l:
					TD2DE_KEYBOARD.L = false;
					break;
				case SDLK_m:
					TD2DE_KEYBOARD.M = false;
					break;
				case SDLK_n:
					TD2DE_KEYBOARD.N = false;
					break;
				case SDLK_o:
					TD2DE_KEYBOARD.O = false;
					break;
				case SDLK_p:
					TD2DE_KEYBOARD.P = false;
					break;
				case SDLK_q:
					TD2DE_KEYBOARD.Q = false;
					break;
				case SDLK_r:
					TD2DE_KEYBOARD.R = false;
					break;
				case SDLK_s:
					TD2DE_KEYBOARD.S = false;
					break;
				case SDLK_t:
					TD2DE_KEYBOARD.T = false;
					break;
				case SDLK_u:
					TD2DE_KEYBOARD.U = false;
					break;
				case SDLK_v:
					TD2DE_KEYBOARD.V = false;
					break;
				case SDLK_w:
					TD2DE_KEYBOARD.W = false;
					break;
				case SDLK_x:
					TD2DE_KEYBOARD.X = false;
					break;
				case SDLK_y:
					TD2DE_KEYBOARD.Y = false;
					break;
				case SDLK_z:
					TD2DE_KEYBOARD.Z = false;
					break;
				case SDLK_COMMA:
					TD2DE_KEYBOARD.Comma = false;
					break;
				case SDLK_STOP:
					TD2DE_KEYBOARD.Stop = false;
					break;
				case SDLK_SLASH:
					TD2DE_KEYBOARD.Slash = false;
					break;
				case SDLK_SEMICOLON:
					TD2DE_KEYBOARD.SemiColon = false;
					break;
				case SDLK_QUOTE:
					TD2DE_KEYBOARD.Quote = false;
					break;
				case SDLK_LEFTBRACKET:
					TD2DE_KEYBOARD.LeftBracket = false;
					break;
				case SDLK_RIGHTBRACKET:
					TD2DE_KEYBOARD.RightBracket = false;
					break;
				case SDLK_BACKSLASH:
					TD2DE_KEYBOARD.BackSlash = false;
					break;
				}
				break;

				//if user pushes red x to quit program
			case SDL_QUIT:
				TD2DE.SetRunning(false);
				break;

				//if none of above apply
			default:
				if (TD2DE.GetDebugMode() >= DEBUG_MEDIUM)
					TD2DE_DEBUG.LogError("Warning: EventHandle-PollEvent: Unknown event type: " + to_string(EventHandle.type));
				break;
			}
		if (TD2DE.GetDebugMode() >= DEBUG_HIGH)
			TD2DE_DEBUG.LogError("EventHandle.h: EventHandle end", false);
	}
}

void TD2DE_ButtonHandle()
{
	for (int i = 0; i < TD2DE_BUTTON.size(); i++)
		if (TD2DE_MOUSE.GetX() >= TD2DE_BUTTON[i].GetX() && TD2DE_MOUSE.GetX() <= (TD2DE_BUTTON[i].GetX() + TD2DE_BUTTON[i].GetWidth()) && TD2DE_MOUSE.GetY() >= TD2DE_BUTTON[i].GetY() && TD2DE_MOUSE.GetY() <= (TD2DE_BUTTON[i].GetY() + TD2DE_BUTTON[i].GetHeight()))
		{
			if (!TD2DE_MOUSE.GetLeftClick() && !TD2DE_MOUSE.GetRightClick() && !TD2DE_MOUSE.GetMiddleClick())
				TD2DE_BUTTON[i].SetState(STATE_MOUSEOVER);
			else
				TD2DE_BUTTON[i].SetState(STATE_CLICKED);
		}
		else
			TD2DE_BUTTON[i].SetState(STATE_NONE);
}