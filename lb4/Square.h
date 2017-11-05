#pragma once
#include "Figure.h"
class Square : public Figure{
private:
	GLint _Length;
	bool _Draw();
public:
	bool Draw();
	bool Resize(char);
	void Coord(GLint[2]);
	Square(GLint pos[2], GLfloat color[3], GLint, GLint);
	Square();
	~Square();
};

