#include <iostream>
#include <random>
#include <cmath>
#include <GL/freeglut.h>
//#include "Shape.h"
#include "Circle.h"
#include "Square.h"

#define N 5

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
		uniform_int_distribution<> x(100, W - 100);
		uniform_int_distribution<> y(100, H - 100);
		uniform_int_distribution<> sp(-5, 5);
		for (int i = 0; i < N; i++) {
			//int x = f[i]->GetPosX();
			//int y = f[i]->GetPosY();
			//f[i]->Move(x+c(gen), y+ c(gen));
			f[i]->Draw();
		}
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (sqrt(powf((f[j]->GetPosX() - f[i]->GetPosX()), 2) + powf((f[j]->GetPosY() - f[i]->GetPosY()), 2)) - (f[j]->GetSize() + f[i]->GetSize())<=0) {
					f[i]->SetSpeedX(-f[i]->GetSpeedX());
					f[i]->SetSpeedY(-f[i]->GetSpeedY());
				}
				f[i]->Draw();
			}
		}
		//system("pause");
		for (int i = 0; i < N; i++) {
			//if (!sqrt(powf((f[i]->GetPosX() - H), 2) + powf((f[i]->GetPosY() - W), 2)) - f[i]->GetSize()) {
			//	f[i]->Move(f[i]->GetPosX() + c(gen), f[i]->GetPosY() + c(gen));
			//}
			if ((f[i]->GetPosX() - f[i]->GetSize()) < 0 || (f[i]->GetPosX() + f[i]->GetSize()) > W) {
				f[i]->SetSpeedX(-f[i]->GetSpeedX());
			}
			if ((f[i]->GetPosY() - f[i]->GetSize()) < 0 || (f[i]->GetPosY() + f[i]->GetSize()) > H) {
				f[i]->SetSpeedY(-f[i]->GetSpeedY());
			}
		}
		/*
		for (int i = 0; i < N; i++){
			if (arr <= 10) spis = -spis; // Если координата Х <= 10 то меняем направление движения по оси Х на противоположное
			if (arr >= pictureBox3.Width - 10) spis = -spis;// меняется направление
			if (arr[i + 1] <= 10) spis[i + 1] = -spis[i + 1]; // Если координата У <= 10 то меняем направление движения по оси У на противоположное
			if (arr[i + 1] >= pictureBox3.Height - 10) spis[i + 1] = -spis[i + 1];

			arr += spis; // координаты точки , которая будет удаляться от полюса + текущее смещение шара по оси Х
			arr[i + 1] += spis[i + 1]; // По оси У
			pictureBox3.Invalidate();  // Перерисовка pictureBox-a
		}
		*/
		
		
			
			//if (!f[i]->Resize('H')) {
			//	GLint pos[2] = { x(gen),y(gen) };
			//	f[i]->Coord(pos);
			//}
		///}
		last_idle_time = time_now;
		glutPostRedisplay();
	}
}

int main(int argc, char* argv[]) {
	uniform_real_distribution<> color_r(0, 1);
	uniform_int_distribution<> pos_r(0, 500);
	uniform_int_distribution<> rad_r(30, 60);
	uniform_int_distribution<> sp(-5, 5);
	//c = new Circle[N];
	//s = new Square[N];
	f = new Shape *[N];
	int speed;
	for (int i = 0; i < N; i++) {
		GLint pos[2] = { pos_r(gen),pos_r(gen) };
		GLfloat color[3] = { color_r(gen),color_r(gen),color_r(gen) };
		//if (i < N / 2) {
			f[i] = new Circle(rad_r(gen), pos[0],pos[1], color[0], color[1], color[2]);
			speed = sp(gen);
			if (!speed) {
				speed = 1;
			}
			f[i]->SetSpeedX(speed);
			f[i]->SetSpeedY(speed);
		//}
		//else {
			//f[i] = new Square(pos, color, rad_r(gen), 100);
		//}

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
