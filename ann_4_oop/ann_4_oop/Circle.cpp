#include "Circle.h"
using namespace std;

Circle::Circle(int rad, int nX, int nY, float r, float g, float b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
	x = nX;
	y = nY;
	radius = rad;
}

void Circle::set_radius(int rad) {
	radius = rad;
}

int Circle::get_radius() {
	return radius;
}

void Circle::Draw() {
	x += speedX;
	y += speedY;
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float angle = 2.0 * 3.1415926 * float(i) / 360;
		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);
		glVertex2f( x + dx, y + dy);
	}
	glEnd();
}

void Circle::Move(int nx, int ny) {
	x = nx;
	y = ny;

}

int Circle::GetSize() {
	return radius;
}

int Circle::GetPosX() {
	return x;
}

int Circle::GetPosY() {
	return y;
}

void Circle::SetSpeedX(int s) {
	speedX = s;
}

void Circle::SetSpeedY(int s) {
	speedY = s;
}