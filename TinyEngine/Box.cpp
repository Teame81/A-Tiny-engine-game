#include "Box.h"
#include "TinyEngine.h"
#include "World.h"

void Box::TakeDamage(int Damage)
{
	MyWorld->TotScore += 1;
	MyWorld->DestroyEntity(this);
}

void Box::Draw()
{
	engSetColor(0xff00ff00);
	engDrawRect(X, Y, 32, 32);
}
//	MyWorld->DestroyEntity(this);
//{
//}

