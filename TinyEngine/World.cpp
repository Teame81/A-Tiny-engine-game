#include "World.h"
#include "Entity.h"
#include "Bat.h"
#include "TinyEngine.h"
#include "Box.h"
#include "Troll.h"
#include "Type.h"
#include <stdlib.h>
World::World()
{
for (int i = 0; i < MAX_ENTITIES; i++)
	ObjectList[i] = nullptr;
}

World::~World()
{
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (ObjectList[i] != nullptr)
		{
			delete ObjectList[i];
			ObjectList[i] = nullptr;
		}
	}
}



void World::Update()
{
	
	BatSpawnTimer -= engDelta();
	if (BatSpawnTimer <= 0.f) 
	{
		SpawnEntity(new Bat(rand() % 550 + 50, rand() % 650 + 50));
		SpawnEntity(new Box(rand() % 550 + 50, rand() % 650 + 50));
		SpawnEntity(new Box(rand() % 550 + 50, rand() % 650 + 50));
		SpawnEntity(new Box(rand() % 550 + 50, rand() % 650 + 50));
		SpawnEntity(new Box(rand() % 550 + 50, rand() % 650 + 50));
		SpawnEntity(new Box(rand() % 550 + 50, rand() % 650 + 50));
		BatSpawnTimer = 3.f;
	}
	int TrollCount = 0;
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		

		if (IsA<Troll>(ObjectList[i]))
		{
			TrollCount++;
		}
		if (ObjectList[i] == nullptr)
			continue;
		
		ObjectList[i]->Update();
	}
	if (TrollCount < 1)
	{
		Troll * TrollPtr = new Troll(rand() % 550 + 50, rand() % 650 + 50);
		TrollPtr->Target = PlayerPos;
		SpawnEntity(TrollPtr);
		
	}
}

void World::Draw()
{
	
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (ObjectList[i] == nullptr)
			continue;
		ObjectList[i]->Draw();
		engSetColor(0xffFFff00);
		engDrawStringFormat(600, 10, "Score: %d", TotScore);
	}
}

void World::SpawnEntity(Entity* InEntity)
{
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (ObjectList[i] == nullptr)
		{
			ObjectList[i] = InEntity;
			break;
		}
		ObjectList[i]->Draw();
	}
	InEntity->MyWorld = this;
}

void World::DestroyEntity(Entity* InEntity)
{
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (ObjectList[i] == InEntity)
		{
			ObjectList[i] = nullptr;
			delete InEntity;
			break;
		}
		
	}
	
}
