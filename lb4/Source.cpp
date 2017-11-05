// Lab4Gl.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <random>
#include <GL/freeglut.h>

#include"Circle.h"
#include"Square.h"

#define N 5

using namespace std;

Circle *c;
Square *s;

random_device rd;
mt19937 gen(rd());

int W, H;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	/* � ����� ������ - �������� ��������� ��� ���� �������� */
	/* ��������������, ���������� ��������� � ���� ������� ������ ������������ OpenGL*/
	/* ... */
	for (int i = 0; i < N; i++) {
		c[i].Draw();
		s[i].Draw();
	}






	glutSwapBuffers();
}

void reshape(int w, int h){
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


void kb(int key, int x, int y) {
	/************************************************************************/
	/* � ����� ������������ ������� ������� ����. ������, ��� �����.        */
	/************************************************************************/








	glutPostRedisplay();
}

static DWORD last_idle_time;

/* ����� ������� ������ ������ ����� */
#define ANIM_INTERVAL 0.05

void animate() {
	double dt;
	DWORD time_now;
	time_now = GetTickCount();  // ����� ����������� � ������� ������ �������.
	dt = (double)(time_now - last_idle_time) / 1000.0;	// ����� ������ � ������� ��������� ��������
	if (dt >= ANIM_INTERVAL) {
		/***********************************************************************************************/
		/* � ����� ������ ��, ��� ���������. ��������, ������� ������ �� ������, ������ ������� � �.�. */
		/***********************************************************************************************/
		uniform_int_distribution<> x(100, W - 100);
		uniform_int_distribution<> y(100, H - 100);
		for (int i = 0; i < N; i++) {
			if (!c[i].Resize('H')) {

				
				GLint pos[2] = { x(gen),y(gen) };
				c[i].Coord(pos);

			}
			if (!s[i].Resize('H')) {
				GLint pos[2] = { x(gen),y(gen) };
				s[i].Coord(pos);

			}
		}
		







		last_idle_time = time_now;
		glutPostRedisplay();
	}
}

int main(int argc, char* argv[]){
	/************************************************************************/
	/* ��� ��� ������� �� ���������� �������� ���� ������ �������� �������� */
	/************************************************************************/
	uniform_real_distribution<> color_r(0, 1);
	uniform_int_distribution<> pos_r(0, 800);
	uniform_int_distribution<> rad_r(0, 60);

	c = new Circle[N];
	s = new Square[N];

	for (int i = 0; i < N; i++){
		GLint pos[2] = { pos_r(gen),pos_r(gen) };
		GLfloat color[3] = { color_r(gen),color_r(gen),color_r(gen) };
		c[i] = Circle(pos, color, rad_r(gen),100);
		//GLint pos[2] = { pos_r(gen),pos_r(gen) };
		s[i] = Square(pos, color, rad_r(gen), 100);
	}
	
	







	/* ����� - �������������� OpenGL � ��������� ������� ���� */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	/* ����� ������������� idle function ��� �������� */
	/* � ������������� special function ��� ��������� ������� ����������: ������� �������, PgUp, PgDn, Home, End, Ins, F1-F12 */

	//glutSpecialFunc(kb);  //<---- � ���� ������� ��������� ���������� �������. ��������: void kb(int key, int x, int y); key - ��� ������� �������, ��������, GLUT_KEY_UP (��. ������������)
	glutIdleFunc(animate); //<---- ��� ������� ���������� ��������� � ����������� ��������. � ��� ���� �������� ��������� ����� � �������� ������� � ���-�� ������������. �.�. ������� �������� �� �������

	glutMainLoop();

	return 0;
}
