#include <cstdlib>
#include "TinyEngine.h"
#include "Bat.h"
#include "World.h"

Bat::Bat(float InX, float InY) : Entity(InX, InY)
{
	SetNewTarget();
	FlySpeed = (rand() % 50) + 50;
}

void Bat::Update()
{
	if (X < TargetX)
		X += FlySpeed * engDelta();
	if (X > TargetX)
		X -= FlySpeed * engDelta();
	if (Y < TargetY)
		Y += FlySpeed * engDelta();
	if (Y > TargetY)
		Y -= FlySpeed * engDelta();
	float XDistance = TargetX - X;
	float YDistance = TargetY - Y;
	BoundingBox.X = X;
	BoundingBox.Y = Y;
	IsColliding = false;
	if (abs(XDistance) < 1.0f && abs(YDistance) < 1.0f)
	{
		WaitTimer -= engDelta();
		if (WaitTimer <= 0.f)
		{
			SetNewTarget();
			WaitTimer = 3.f;
		}

	}
}

void Bat::TakeDamage(int damage)
{
 	MyWorld->TotScore += 50;
	MyWorld->DestroyEntity(this);
}

void Bat::Draw()
{
	if (IsColliding)
		engSetColor(0xff00ff00);
	else
		engSetColor(0x0000ff00);

	engDrawRect(X, Y, 32, 32);
	engSetColor(0xFF000000);
	engDrawRect(X + 8, Y + 8, 16, 16);
	
}

void Bat::SetNewTarget()
{
	engBoundingBox ScreenBox(0, 0, 800, 600);
	engBoundingBox BatBox = BoundingBox;
	do 
	{
	TargetX = X + (rand() % 400) - 200;
	TargetY = Y + (rand() % 400) - 200;
	BatBox.X = TargetX;
	BatBox.Y = TargetY;

	} while (!ScreenBox.Contains(BatBox));
}

