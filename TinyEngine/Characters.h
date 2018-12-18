#pragma once

class Entity
{
private:
	unsigned int Color = 0xFFffFFff;
public:
	float X = 20.f;
	float Y = 20.f;
	int Type = 0; 
	//Entity(){}
	Entity(float InX, float InY, unsigned int InColor) //Constructor(Same name as class)
	{
		X = InX;
		Y = InY;
		Color = InColor;
		Type = 0;
	}
	void Draw()  //Method
	{
		engSetColor(Color);
		engDrawRect(X, Y, 32, 32);
	}

};//Always Semicolon after Structs, Classes

class Player : public Entity
{
	public:
	int Health = 100;
	Player(float InX, float InY) : Entity(InX, InY, 0x00FF00FF) 
	{
		Type = 1;
	}

};

class Enemy : public Entity
{
	public:
	float speed = 20.f;

	Enemy(float InX, float InY) : Entity(InX, InY, 0xFF0000FF)
	{
		Type = 2;
	}
};



//void OutOfField
//{
//private:
//public:
//	if (Player.X)
//	{
//	}
//
//};
