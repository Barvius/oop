#pragma once
#include "Shape.h"

class Square : public Shape {
private:
	int a;
public:
	Square(int nA, int nX, int nY);
	~Square() {};
	void set_a(int nA);
	int get_a();
	void Draw(int r, int g, int b);
	void Move(int nx, int ny);
};
