#pragma once
#include<QGraphicsScene>
#include<QPen>
    
class Turtle
{
    int x;
    int y;
    int dir;
    bool mark;
    QGraphicsScene* scene;
    QPen defaultPen;

	Turtle();
	Turtle(const Turtle&);
	Turtle&	operator=(const Turtle&);
public:
	static const double M_PI;
	~Turtle();
	static Turtle& GetInstance();
    void SetScene(QGraphicsScene* scene);
	void Move(int amount);
	void Rotate(int amount);
	void SetMark(bool mark);
	void Reset() ;
	void Clean();
	void Restart();
};

