#pragma once
#include "Figure.h"
#include <math.h>
#include <GL/freeglut.h>
#include <iostream>

class Circle : public Figure{
private:
	GLint _Radius;
	bool _Draw();
public:
	bool Draw();
	bool Resize(char);
	void Coord(GLint[2]);
	Circle(GLint pos[2], GLfloat color[3], GLint, GLint);
	Circle();
	~Circle();
};

