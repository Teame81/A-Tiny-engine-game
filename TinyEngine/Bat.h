#pragma once
#include "Entity.h"
#include "iDamage.h"

class Bat : public Entity, public IDamage
{
public:
	float FlySpeed;
	Bat(float InX, float InY);
	void Update() override;
	void TakeDamage(int damage);
	void Draw() override;
private:
	void SetNewTarget();
	float TargetX, TargetY, WaitTimer = 3.f;
};