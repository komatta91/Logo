#include "Turtle.h"
#include <math.h>
#include <QDebug>
#include <QCoreApplication>

const double Turtle::M_PI = 3.14159265358979323846;

Turtle::Turtle() : mark(true), x(0), y(0), dir(180)
{
    //defaultPen.setWidth(1);
}


Turtle::~Turtle()
{
}


Turtle& Turtle::GetInstance()
{
	static Turtle instance;
	return instance;
}

void Turtle::SetScene(QGraphicsScene* scene)
{
    this->scene = scene;
    x = scene->sceneRect().center().toPoint().x();
    y = scene->sceneRect().center().toPoint().y();
}

void Turtle::Move(int amount)
{

	double radiany = (dir * M_PI) / 180.0f;
	double sin_ = sin(radiany);
    double cos_ = cos(radiany);
    int prevX = x;
    int prevY = y;
    x += (amount * sin_ + 0.5);
    y += (amount * cos_ + 0.5);
    if (mark)
    {
        qDebug() << "Rysowanie.";
        QPen pen;
        pen.setWidth(1);
        scene->addLine(prevX,prevY, x, y, pen);
        scene->update();
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void Turtle::Rotate(int amount)
{
    dir -= amount;
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
    //x = 0;
    //y = 0;
    dir = 180;
	mark = true;
    x = scene->sceneRect().center().toPoint().x();
    y = scene->sceneRect().center().toPoint().y();
}

void Turtle::Clean()
{
    scene->clear();
}

void Turtle::Restart()
{
	Reset();
	Clean();
}


