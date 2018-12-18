#include "TinyEngine.h"
#include "Player.h"
#include "Collision.h"
#include "World.h"
#include "Bullet.h"
#include "Type.h"
#include "Bat.h"
#include "Box.h"
#include "Troll.h"
#define PRINT(inString, ...) engDrawStringFormat(10, 10, inString, __VA_ARGS__); engWaitKey();


Player::Player(float InX, float InY) : Entity(InX, InY)
{
	
}

void Player::Update()
{
	int Score = 0;
	engBoundingBox ScreenBox(0, 0, 800, 600);
	float XDelta = 0.f;
	float YDelta = 0.f;
	XDirection = 0;
	YDirection = 0;

	if (engGetKey(Key::Right))
	{
		XDelta += 250.f * engDelta();
		XDirection++;
	}
	if (engGetKey(Key::Left))
	{
		XDelta -= 250.f * engDelta();
		XDirection--;
	}
	if (engGetKey(Key::Up))
	{
		YDelta -= 250.f * engDelta();
		YDirection--;
	}
	if (engGetKey(Key::Down))
	{
		YDelta += 250.f * engDelta();
		YDirection++;
	}
	if (XDirection == 0 && YDirection == 0)
	{
		XDirection = 1;
	}
	
	if (engGetKeyDown(Key::Tab))
	{
		CurrentWeapon = (WeaponType)(((int)CurrentWeapon + 1) % (int)WeaponType::MAX);
	}

	//Do collisions check with Screen
	{
		engBoundingBox DeltaBox = BoundingBox;
		DeltaBox.X = X + XDelta;
		if (ScreenBox.Contains(DeltaBox))
		{
			X += XDelta;
		}
	}
	{
		engBoundingBox DeltaBox = BoundingBox;
		DeltaBox.Y = Y + YDelta;
		if (ScreenBox.Contains(DeltaBox))
		{
			Y += YDelta;
		}	
	}
	WeaponCooldown -= engDelta();
		
	switch (CurrentWeapon)
	{
	case WeaponType::Pistol:
	{	if (engGetKeyDown(Key::Space))
	{
		MyWorld->SpawnEntity(new Bullet(X + 40 * XDirection + 40, Y + 40 * YDirection, XDirection, YDirection));
	}
	}	break;
	case WeaponType::MachineGun:
	{	if (engGetKey(Key::Space)&& WeaponCooldown<= 0.f)
	{
		MyWorld->SpawnEntity(new Bullet(X + 40 * XDirection + 40, Y + 40 * YDirection, XDirection, YDirection));
		WeaponCooldown = 0.1f;
		

	}
	}	break;
	case WeaponType::SlowMachingGun:
		if (engGetKey(Key::Space) && WeaponCooldown<= 0.f)
		{
			MyWorld->SpawnEntity(new Bullet(X + 40 * XDirection + 40, Y + 40 * YDirection, XDirection, YDirection));
			WeaponCooldown = 0.3f;
		}
	default:
		break;
	}
	 


	BoundingBox.X = X;
	BoundingBox.Y = Y;
	IsColliding = false;
	/*for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (MyWorld->ObjectList[i] == nullptr || MyWorld->ObjectList[i] == this)
			continue;

		if (BoundingBox.CollidesWith(MyWorld->ObjectList[i]->BoundingBox))
		{
			IsColliding = true;
			if (IsA<Bat>(MyWorld->ObjectList[i]))
			{
				MyWorld->PlayerHasDied = true;
			}
		}
	}*/
	Bat* BatCollision = MyWorld->GetCollision<Bat>(BoundingBox);
	if (BatCollision != nullptr)
	{
		IsColliding = true;
		MyWorld->PlayerHasDied = true;
	}
	Box* BoxCollosion = MyWorld->GetCollision<Box>(BoundingBox);
	if (BoxCollosion != nullptr)
	{
		IsColliding = true;
		MyWorld->TotScore--;
	}
	Troll* TrollCollosion = MyWorld->GetCollision<Troll>(BoundingBox);
	if (TrollCollosion != nullptr)
	{
		IsColliding = true;
		MyWorld->TotScore--;
	}
}

void Player::Draw()
{
	if (IsColliding)
		engSetColor(0xffff0000);
	else
		engSetColor(0x0000ff00);

	engDrawRect(X, Y, 32, 32);
	engSetColor(0xFFffFFff);
	engDrawRect(X + 8, Y + 8, 16, 16);
	engDrawLine(X + 16, Y + 16, X + XDirection * 32 + 16 , Y + YDirection * 32 + 16); //gun

}

