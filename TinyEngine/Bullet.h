#pragma once
#include "Entity.h"
#include "iDamage.h"

class Bullet :public Entity
{
public:
	Bullet(int InX, int InY, int DirX, int DirY);
	void Update() override;
	void Draw() override;
private:
	int DirectionX;
	int DirectionY;
	float LifeTime = 5.f;
};

