#include "Circle.h"
using namespace std;
Circle::Circle(GLint pos[2], GLfloat color[3], GLint radius,GLint criticalsize){
	memcpy(_Pos, pos, 2 * sizeof(GLint));
	memcpy(_Color, color, 3 * sizeof(GLfloat));
	_Radius = radius;
	_CriticalSize = criticalsize;
}

Circle::Circle() {

}

Circle::~Circle(){

}

bool Circle::_Draw() {
	glColor3f(_Color[0], _Color[1], _Color[2]);

	if (abs(_Radius) > _CriticalSize) {
		return false;
	}
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++){
		float angle = 2.0 * 3.1415926 * float(i) / 360;
		float dx = _Radius * cosf(angle);
		float dy = _Radius * sinf(angle);
		glVertex2f(_Pos[0] + dx, _Pos[1] + dy);
	}
	glEnd();
	return true;
}

bool Circle::Draw() {
	return _Draw();
}

bool Circle::Resize(char size) {
	switch (size){
	case 'H':
		_Radius++;
		break;
	case 'L':
		_Radius--;
		break;
	default:
		break;
	}
	return _Draw();

}

void Circle::Coord(GLint pos[2]) {
	_Radius = 0;
	memcpy(_Pos, pos, 2 * sizeof(GLint));
}