#pragma once
#include "Entity.h"

enum class WeaponType : unsigned char
{
	Pistol,
	MachineGun,
	SlowMachingGun,
	MAX
};
class Player : public Entity 
{
public:
	Player(float InX, float InY);
	void Update() override;
	void Draw() override;
	
	int XDirection = 0;
	int YDirection = 0;
	
	int InventorySpace;

	WeaponType CurrentWeapon = WeaponType::Pistol;
private:
	float WeaponCooldown=0.f;
};