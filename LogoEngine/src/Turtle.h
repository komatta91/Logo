#pragma once
    
class Turtle
{
	int x = 0;
	int y = 0;
	int dir = 0;
	bool mark = true;

	Turtle();
	Turtle(const Turtle&);
	Turtle&	operator=(const Turtle&);
public:
	static const double M_PI;
	~Turtle();
	static Turtle& GetInstance();
	void Move(int amount);
	void Rotate(int amount);
	void SetMark(bool mark);
	void Reset() ;
	void Clean();
	void Restart();
};

