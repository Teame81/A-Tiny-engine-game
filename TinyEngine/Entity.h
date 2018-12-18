#pragma once
#include "Collision.h"
class World;

class Entity
{
public:
	Entity(float InX, float InY);

	virtual void Update();
	virtual void Draw();
	bool IsColliding;
	float X;
	float Y;
	engBoundingBox BoundingBox;
	World* MyWorld;
};

