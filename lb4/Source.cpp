// Lab4Gl.cpp: определяет точку входа для консольного приложения.
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

	/* А здесь рисуем - вызываем отрисовку для всех объектов */
	/* Соответственно, реализация отрисовки у всех классов должна использовать OpenGL*/
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
	/* А здесь обрабатываем события нажатий спец. клавиш, как хотим.        */
	/************************************************************************/








	glutPostRedisplay();
}

static DWORD last_idle_time;

/* Через сколько секунд менять сцену */
#define ANIM_INTERVAL 0.05

void animate() {
	double dt;
	DWORD time_now;
	time_now = GetTickCount();  // Число миллисекунд с момента старта системы.
	dt = (double)(time_now - last_idle_time) / 1000.0;	// Число секунд с прошлой отрисовки анимации
	if (dt >= ANIM_INTERVAL) {
		/***********************************************************************************************/
		/* А здесь меняем то, что требуется. Например, двигаем фигуры на экране, меняем размеры и т.п. */
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
	/* Вот тут неплохо бы обеспечить создание всех нужных объектов иерархии */
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
	
	







	/* Далее - инициализируем OpenGL и запускаем главный цикл */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	/* Здесь устанавливаем idle function для анимации */
	/* и устанавливаем special function для обработки нажатий спецклавиш: стрелки курсора, PgUp, PgDn, Home, End, Ins, F1-F12 */

	//glutSpecialFunc(kb);  //<---- в этой функции требуется обработать события. Прототип: void kb(int key, int x, int y); key - код нажатой клавиши, например, GLUT_KEY_UP (см. документацию)
	glutIdleFunc(animate); //<---- эта функция вызывается постоянно с неизвестной частотой. В ней надо измерить прошедшее время с прошлого запуска и что-то перерисовать. Т.е. сделать анимацию по заданию

	glutMainLoop();

	return 0;
}
