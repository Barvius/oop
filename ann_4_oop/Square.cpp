#include "Square.h"

Square::Square(int l, int nX, int nY, float r, float g, float b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
	x = nX;
	y = nY;
	a = l;
}

void Square::set_a(int nA) {
	a = nA;
}

int Square::get_a() {
	return a;
}

void Square::Draw() {

	glColor3f(color[0], color[1], color[2]);
	glRectf(x - (a / 2), y + (a / 2), x + (a / 2), y - (a / 2));
	x += speedX;
	y += speedY;
}

void Square::Move(int nx, int ny) {
	x = nx;
	y = ny;

}

int Square::GetSize() {
	return a;
}

int Square::GetPosX() {
	return x;
}

int Square::GetPosY() {
	return y;
}

void Square::SetSpeedX(int s) {
	speedX = s;
}

void Square::SetSpeedY(int s) {
	speedY = s;
}