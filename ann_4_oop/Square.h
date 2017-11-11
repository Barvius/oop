#pragma once
#include "Shape.h"
#include <GL/freeglut.h>
class Square : public Shape {
private:
	int a;
public:
	Square(int, int, int, float, float, float);
	~Square() {};
	void set_a(int nA);
	int get_a();
	void Move(int, int);
	void Draw();
	int GetSize();
	int GetPosX();
	int GetPosY();
	void SetSpeedX(int);
	void SetSpeedY(int);
	int GetSpeedX() { return speedX; };
	int GetSpeedY() { return speedY; };
};
