#pragma once
#include "Entity.h"
#include "iDamage.h"

class Troll : public Entity, public IDamage
{
public:
	Entity * Target = nullptr;
	float RunSpeed;	
	Troll(float InX, float InY);
	void Update() override;
	void TakeDamage(int damage);
	void Draw() override;
private:
	float TargetX, TargetY;

};