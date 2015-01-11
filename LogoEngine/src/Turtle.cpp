#include "Turtle.h"
#include <math.h>


const double Turtle::M_PI = 3.14159265358979323846;

Turtle::Turtle()
{
}


Turtle::~Turtle()
{
}


Turtle& Turtle::GetInstance()
{
	static Turtle instance;
	return instance;
}

void Turtle::Move(int amount)
{

	double radiany = (dir * M_PI) / 180.0f;
	double sin_ = sin(radiany);
	double cos_ = cos(radiany);
	
	x += (amount * sin_ + 0.5);
	y += (amount * cos_ + 0.5);
}

void Turtle::Rotate(int amount)
{
	dir += amount;
	if (dir < 0)
	{
		dir = 360 + dir;
	}
}

void Turtle::SetMark(bool mark)
{
	this->mark = mark;
}

void Turtle::Reset()
{
	x = 0;
	y = 0;
	dir = 0;
	mark = true;
}

void Turtle::Clean()
{
	
}

void Turtle::Restart()
{
	Reset();
	Clean();
}
