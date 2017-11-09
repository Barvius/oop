#pragma once
#include <iostream>
#include "Shape.h"
#include <math.h>
#include <GL/freeglut.h>

class Circle : public Shape {
private:
	int radius;
public:
	Circle(int,int,int,float,float,float);
	~Circle() {};
	void set_radius(int rad);
	int get_radius();
	void Draw();
	void Move(int nx, int ny);
	int GetSize();
	int GetPosX();
	int GetPosY();
	void SetSpeedX(int);
	void SetSpeedY(int);
	int GetSpeedX() { return speedX; };
	int GetSpeedY() { return speedY; };
};
