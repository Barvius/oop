#pragma once
#include <GL/freeglut.h>
class Figure{
protected:
	GLint _Pos[2];
	GLfloat _Color[3];
	GLint _CriticalSize;
public:
	virtual bool Draw() = 0;
	virtual bool Resize(char) = 0;
	virtual void Coord(GLint[2]) = 0;
	Figure(){
	}

	~Figure(){
	}
};

