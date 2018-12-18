#include "TinyEngine.h"
#include "Entity.h"

Entity::Entity(float InX, float InY) : X(InX), Y(InY), BoundingBox(InX, InY, 32, 32) 
{

}
void Entity::Update()
{

}
void Entity::Draw()
{
	engSetColor(0xffffffff);
	engDrawRect(X, Y, 32, 32);
}