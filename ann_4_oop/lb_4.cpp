#include <iostream>
#include <random>
#include <cmath>
#include <GL/freeglut.h>
//#include "Shape.h"
#include "Circle.h"
#include "Square.h"

#define N 10

using namespace std;

Circle *c;
Square *s;
Shape **f;

random_device rd;
mt19937 gen(rd());

int W, H;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < N; i++) {
		f[i]->Draw();
	}
	glutSwapBuffers();
}

void reshape(int w, int h) {
	W = w;
	H = h;
	glViewport(0, 0, w, h);
	cout << w << "  " << h << endl;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static DWORD last_idle_time;

#define ANIM_INTERVAL 0.1

void animate() {
	double dt;
	DWORD time_now;
	time_now = GetTickCount();
	dt = (double)(time_now - last_idle_time) / 1000.0;
	if (dt >= ANIM_INTERVAL) {
		/*
		int X1, X2, Y1, Y2, S1, S2,PenetrationDepth;
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					X2 = f[j]->GetPosX();
					X1 = f[i]->GetPosX();
					Y2 = f[j]->GetPosY();
					Y1 = f[i]->GetPosY();
					S1 = f[i]->GetSize();
					S2 = f[j]->GetSize();
					if (typeid(*f[i]) == typeid(Circle) && typeid(*f[j]) == typeid(Circle)) {
					if (sqrt(powf((X2 - X1), 2) + powf((Y2 - Y1), 2)) <= (S2 + S1)) {
						PenetrationDepth = sqrt(powf((X2 - X1), 2) + powf((Y2 - Y1), 2)) - (S2 + S1);
						f[i]->Move(X1 + PenetrationDepth, Y1 + PenetrationDepth);
						f[j]->Move(X2 - PenetrationDepth, Y2 - PenetrationDepth);
						f[i]->SetSpeedX(-f[i]->GetSpeedX());
						f[j]->SetSpeedX(-f[j]->GetSpeedX());
						f[i]->Draw();
					}
					}
					if (typeid(*f[i]) == typeid(Square) && typeid(*f[j]) == typeid(Square)) {
						//r1.left <= r2.right and r2.left <= r1.right and r1.top <= r2.bottom and r2.top <= r1.bottom
						if (X1 - f[i]->GetSize() / 2 <= X2 + f[j]->GetSize() / 2 && X2 - f[j]->GetSize() / 2 <= X1 + f[i]->GetSize() / 2 && Y1 + f[i]->GetSize() / 2 <= Y2 - f[j]->GetSize() / 2 && Y2 + f[j]->GetSize() / 2 > Y1 - f[i]->GetSize() / 2) {
							f[i]->SetSpeedY(-f[i]->GetSpeedY());
							f[j]->SetSpeedY(-f[j]->GetSpeedY());
							f[i]->Draw();
						}
					}
				}
			}
			
		}
		*/
		for (int i = 0; i < N; i++) {
			if (typeid(*f[i]) == typeid(Circle)) {
				if ((f[i]->GetPosX() - f[i]->GetSize()) <= 0) {
					f[i]->SetSpeedX(-f[i]->GetSpeedX());
					f[i]->Move(f[i]->GetSize(), f[i]->GetPosY());
				}
				if ((f[i]->GetPosX() + f[i]->GetSize()) >= W) {
					f[i]->SetSpeedX(-f[i]->GetSpeedX());
					f[i]->Move(W - f[i]->GetSize(), f[i]->GetPosY());
				}
				if ((f[i]->GetPosY() - f[i]->GetSize()) <= 0) {
					f[i]->SetSpeedY(-f[i]->GetSpeedY());
					f[i]->Move(f[i]->GetPosX(), f[i]->GetSize());
				}
				if ((f[i]->GetPosY() + f[i]->GetSize()) >= H) {
					f[i]->SetSpeedY(-f[i]->GetSpeedY());
					f[i]->Move(f[i]->GetPosX(), H - f[i]->GetSize());
				}
			}
			if (typeid(*f[i]) == typeid(Square)) {
				if ((f[i]->GetPosX() - f[i]->GetSize()/2) <= 0) {
					f[i]->SetSpeedX(-f[i]->GetSpeedX());
					f[i]->Move(f[i]->GetSize()/2, f[i]->GetPosY());
				}
				if ((f[i]->GetPosX() + f[i]->GetSize() / 2) >= W) {
					f[i]->SetSpeedX(-f[i]->GetSpeedX());
					f[i]->Move(W-f[i]->GetSize() / 2, f[i]->GetPosY());
				}
				if ((f[i]->GetPosY() - f[i]->GetSize() / 2) <= 0) {
					f[i]->SetSpeedY(-f[i]->GetSpeedY());
					f[i]->Move(f[i]->GetPosX(), f[i]->GetSize() / 2);
				}
				if ((f[i]->GetPosY() + f[i]->GetSize() / 2) >= H) {
					f[i]->SetSpeedY(-f[i]->GetSpeedY());
					f[i]->Move(f[i]->GetPosX(), H - f[i]->GetSize()/2);
				}
			}
			f[i]->Draw();
		}
	
		last_idle_time = time_now;
		glutPostRedisplay();
	}
}

int main(int argc, char* argv[]) {
	uniform_real_distribution<> color_r(0, 1);
	uniform_int_distribution<> pos_r(0, 500);
	uniform_int_distribution<> rad_r(30, 60);
	uniform_int_distribution<> sp(-5, 5);

	f = new Shape *[N];
	int speed;
	GLfloat color1[3] = { color_r(gen),color_r(gen),color_r(gen) };
	GLfloat color2[3] = { color_r(gen),color_r(gen),color_r(gen) };
	for (int i = 0; i < N; i++) {
		GLint pos[2] = { pos_r(gen),pos_r(gen) };
		speed = sp(gen);
		if (!speed) {
			speed = 1;
		}
		if (i < N / 2) {
			f[i] = new Circle(rad_r(gen), pos[0],pos[1], color1[0], color1[1], color1[2]);
			
		} else {
			f[i] = new Square(rad_r(gen), pos[0], pos[1], color2[0], color2[1], color2[2]);
		}
		f[i]->SetSpeedX(speed);
		f[i]->SetSpeedY(speed);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutIdleFunc(animate);

	glutMainLoop();

	return 0;
}
