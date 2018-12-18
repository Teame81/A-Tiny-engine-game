#include "Entity.h"
#include "Troll.h"
#include "iDamage.h"
#include "World.h"
#include "TinyEngine.h"
#include "Player.h"

Troll::Troll(float InX, float InY) : Entity(InX, InY)
{
	RunSpeed = 100.f;
}

void Troll::Update()
{
	
	if (X < Target->X)
		X += RunSpeed * engDelta();
	if (X > Target->X)
		X -= RunSpeed * engDelta();
	if (Y < Target->Y)
		Y += RunSpeed * engDelta();
	if (Y > Target->Y)
		Y -= RunSpeed * engDelta();
	
	
	BoundingBox.X = X;
	BoundingBox.Y = Y;
	IsColliding = false;
}

void Troll::TakeDamage(int damage)
{
	MyWorld->DestroyEntity(this);

}

void Troll::Draw()
{
	engSetColor(0xffffffff);
	engDrawCircle(X, Y + 16, 32, true);
}

