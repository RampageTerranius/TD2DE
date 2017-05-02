//!!!!!!!!!!
//!OBSOLETE!
//!!!!!!!!!!
//modified into object class
//no longer compiled

//header guard
#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H


	class Player
	{
		public:
			Object cObject;

			Player();
			void HandleMomentum();
			void CloseImage();


		int 
			Health,
			Weapon,
			Ammo;

		bool
			Sprinting,
			Debug;

		cKeyboard cPlayerKeyboard;
	} Player[2];

	Player::Player()
	{
		Health = 0;
		Weapon = 0;
		Ammo = 0;

		Sprinting = false;
		Debug = false;
		//loading image for player class
		//PlayerImage.LoadFile(gPlayer1ImageLocation);
	}





	void Player::HandleMomentum()
	{
		//checking if need to change velocity
		if (cPlayerKeyboard.Up == true)
		{
			YVelocity -= gVelocityIncrease;
			if (YVelocity < (-gMaxPlayerVelocity))
				YVelocity = -gMaxPlayerVelocity;
		}

		if (cPlayerKeyboard.Down == true)
		{
			YVelocity += gVelocityIncrease;
			if (YVelocity > (gMaxPlayerVelocity))
				YVelocity = gMaxPlayerVelocity;
		}

		if (cPlayerKeyboard.Left == true)
		{
			XVelocity -= gVelocityIncrease;
			if (XVelocity < (-gMaxPlayerVelocity))
				XVelocity = -gMaxPlayerVelocity;
		}

		if (cPlayerKeyboard.Right == true)
		{
			XVelocity += gVelocityIncrease;
			if (XVelocity > (gMaxPlayerVelocity))
				XVelocity = gMaxPlayerVelocity;
		}

			
		//handling player data
		//moving players with velocity
		Y += round(YVelocity);
		X += round(XVelocity);


		//stopping movement when hitting objects/walls etc
		if (Y < 0)
		{
			Y = 0;
			YVelocity = 0;
		}

		if (Y > gScreenHeight)
		{
			Y = gScreenHeight;
			YVelocity = 0;
		}

		if (X < 0)
		{
			X = 0;
			XVelocity = 0;
		}

		if (X > gScreenWidth)
		{
			X = gScreenWidth;
			XVelocity = 0;
		}



		if (cPlayerKeyboard.Up == false && cPlayerKeyboard.Down == false && cPlayerKeyboard.Left == false && cPlayerKeyboard.Right == false)
		{
			
			//velocity reduction over time
			if (XVelocity != 0)
			{
				if (Debug)
					LogError("1",false);
				if (XVelocity < 0)
				{
					if (Debug)
						LogError("2",false);
					XVelocity += gVelocityDecrease;
					if (XVelocity > 0)
					{
						if (Debug)
							LogError("3",false);
						XVelocity = 0;
					}
				}

					
				if (XVelocity > 0)
				{
					if (Debug)
						LogError("4",false);
					XVelocity -= gVelocityDecrease;
					if (XVelocity < 0)
					{
						if (Debug)
							LogError("5",false);
						XVelocity = 0;
					}
				}

			}
			
			if (YVelocity != 0)
			{
				if (Debug)
					LogError("6",false);
				if (YVelocity < 0)
				{
					if (Debug)
						LogError("7",false);
					YVelocity += gVelocityDecrease;
					if (YVelocity > 0)
					{
						if (Debug)
							LogError("8",false);
						YVelocity = 0;
					}
				}

					
				if (YVelocity > 0)
				{
					if (Debug)
						LogError("9",false);
					YVelocity -= gVelocityDecrease;
					if (YVelocity < 0)
					{
						if (Debug)
							LogError("10",false);
						YVelocity = 0;
					}
				}
			}
		}
	}


//end of header guard
#endif