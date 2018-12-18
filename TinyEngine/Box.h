#pragma once
#include "Entity.h"
#include "iDamage.h"
#include "World.h"

class Box : public Entity, public IDamage
{
public:
	
		Box(int X, int Y) : Entity(X, Y) {}
	
		void Update() override {}
		void TakeDamage(int Damage) override;
		void Draw() override;
};