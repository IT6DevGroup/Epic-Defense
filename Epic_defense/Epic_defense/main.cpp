#include <Windows.h>
//using namespace std;
#include <stdio.h>
#include <iostream>

#include <GL/glut.h>

#define WND_WIDTH 400
#define WND_HEIGHT 400

void draw(){ // Рисование
	glClear(GL_COLOR_BUFFER_BIT); // Рисуем фон
	glColor3f(0.0,150.0,110.0); // Цвет точки
	glBegin(GL_POINTS); // Начало рисования
		glVertex2f(0.0,0.0); // Рисуем точку
	glEnd(); // Конец рисования
	glFlush(); // "выполнить всё"
}

void init(){
	glClearColor(100.0, 100.0, 0.2, 1.0); // Цвет фона - первые три цифры RGB, четвёртая - альфа, прозрачность
	glMatrixMode(GL_PROJECTION); // Выбор матрицы
	glLoadIdentity();
	glOrtho(-200,200.0,-200,200.0, -5.0, 5.0); // Строим декартову сетку
}

int main(int argc, char** argv){

	// Инициализация
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WND_WIDTH,WND_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Epic Defense");
	// Регистрация
	glutDisplayFunc(draw);
	init();

	glutMainLoop();
	return 0;
}