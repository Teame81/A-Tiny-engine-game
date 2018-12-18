#include "TinyEngine.h"
#include "Entity.h"
#include <cstdlib>
#include "Collision.h"
#include <time.h>
#include "Player.h"
#include "Bat.h"
#include "World.h"
#include "Troll.h"


void main()
{
	engInit();
	
	Entity test;
	
	srand(time(NULL));
	
	while (engIsOpen())
	{
	int TotScore = 0;
	//World GameWorld; // Statisk deklarering // Skapar Världen mappar upp 250 "Entitys" och nollar dem
	World* GameWorld = new World;
	Player *PlayerPtr = new Player(100, 200);
	Troll * TrollPtr = new Troll(450, 450);
	TrollPtr->Target = PlayerPtr;
	GameWorld->SpawnEntity(PlayerPtr);
	GameWorld->SpawnEntity(TrollPtr);
	GameWorld->SpawnEntity(new Bat(300, 300));
	GameWorld->SpawnEntity(new Bat(400, 400));
	GameWorld->SpawnEntity(new Bat(500, 500));
	GameWorld->SpawnEntity(new Bat(500, 200));
	GameWorld->PlayerPos = PlayerPtr;
		
		while (engIsOpen())
		{
					

			if (engGetKey(Key::Escape))
			{
				engClose();
			}

			GameWorld->Update();
			GameWorld->Draw();

			if (GameWorld->PlayerHasDied)
			{
				engDelay(2000);
				break;
			}
			engUpdate();
		}
	
		

	}



	
	engDestroy();
	
}

