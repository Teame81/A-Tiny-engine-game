#include "Bullet.h"
#include "TinyEngine.h"
#include "Entity.h"
#include "World.h"
#include "Type.h"
#include "Bat.h"


Bullet::Bullet(int InX, int InY, int DirX, int DirY) : Entity(InX, InY), DirectionX(DirX), DirectionY(DirY)
{

}

void Bullet::Update()
{
	X += 400 * engDelta()* DirectionX;
	Y += 400 * engDelta()* DirectionY;
	BoundingBox.X = X-26;
	BoundingBox.Y = Y;

	IDamage *HitDamage = MyWorld->GetCollision<IDamage>(BoundingBox);
	
	if (HitDamage != nullptr)
	{
		HitDamage->TakeDamage(50);
		MyWorld->DestroyEntity(this);
		return;
	}
	LifeTime -= engDelta();
	if (LifeTime <=0.f)
	{
		MyWorld->DestroyEntity(this);
		return;
	}

	/*for (int i = 0; i < MAX_ENTITIES; i++)
	{
		Entity* EntityPtr = MyWorld->ObjectList[i];
		

		if (EntityPtr == nullptr || EntityPtr == this)
			continue;

		if (IsA<Bat>(EntityPtr))
		{
			if (BoundingBox.CollidesWith(EntityPtr->BoundingBox))
			{
				MyWorld->DestroyEntity(EntityPtr);
				MyWorld->DestroyEntity(this);

				return;
			}
		}
	}*/
	//Bat* BatCollision = MyWorld->GetCollision<Bat>(BoundingBox);
	//if (BatCollision != nullptr)
	//{
	//	IsColliding = true;
	//	MyWorld->DestroyEntity(BatCollision);
	//	MyWorld->DestroyEntity(this);
	//	return;
	//}
}

void Bullet::Draw()
{
	engSetColor(0xffffffff);
	engDrawCircle(X, Y + 16, 6, true);
}
