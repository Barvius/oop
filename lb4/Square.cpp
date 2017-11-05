#include "Square.h"

Square::Square(GLint pos[2], GLfloat color[3], GLint lenght, GLint criticalsize) {
	memcpy(_Pos, pos, 2 * sizeof(GLint));
	memcpy(_Color, color, 3 * sizeof(GLfloat));
	_Length = lenght;
	_CriticalSize = criticalsize;
}

Square::Square() {

}

Square::~Square() {

}

bool Square::_Draw() {
	glColor3f(_Color[0], _Color[1], _Color[2]);
	if (_Length > _CriticalSize) {
		return false;
	}
	glRectf(_Pos[0] - (_Length / 2), _Pos[1] + (_Length / 2), _Pos[0] + (_Length / 2), _Pos[1] - (_Length / 2));
	return true;
}

bool Square::Draw() {
	return _Draw();
}

bool Square::Resize(char size) {
	switch (size) {
	case 'H':
		_Length++;
		break;
	case 'L':
		_Length--;
		break;
	default:
		break;
	}
	return _Draw();

}

void Square::Coord(GLint pos[2]) {
	_Length = 0;
	memcpy(_Pos, pos, 2 * sizeof(GLint));
}