#include "Square.h"

Square::Square(int nA, int nX, int nY) {
	a = nA;
}

void Square::set_a(int nA) {
	a = nA;
}

int Square::get_a() {
	return a;
}

void Square::Draw(int r, int g, int b) {
	
}

void Square::Move(int nx, int ny) {
	x = nx;
	y = ny;
}