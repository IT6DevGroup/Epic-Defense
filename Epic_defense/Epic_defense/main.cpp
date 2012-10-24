#include <Windows.h>
//using namespace std;
#include <stdio.h>
#include <iostream>

#include <GL/glut.h>

#define WND_WIDTH 400
#define WND_HEIGHT 400

void draw(){ // ���������
	glClear(GL_COLOR_BUFFER_BIT); // ������ ���
	glColor3f(0.0,150.0,110.0); // ���� �����
	glBegin(GL_POINTS); // ������ ���������
		glVertex2f(0.0,0.0); // ������ �����
	glEnd(); // ����� ���������
	glFlush(); // "��������� ��"
}

void init(){
	glClearColor(100.0, 100.0, 0.2, 1.0); // ���� ���� - ������ ��� ����� RGB, �������� - �����, ������������
	glMatrixMode(GL_PROJECTION); // ����� �������
	glLoadIdentity();
	glOrtho(-200,200.0,-200,200.0, -5.0, 5.0); // ������ ��������� �����
}

int main(int argc, char** argv){

	// �������������
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WND_WIDTH,WND_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Epic Defense");
	// �����������
	glutDisplayFunc(draw);
	init();

	glutMainLoop();
	return 0;
}