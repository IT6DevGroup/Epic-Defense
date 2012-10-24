#include <Windows.h>
//using namespace std;
#include <stdio.h>
#include <iostream>
#include <math.h>

#include <GL/glut.h>

#define WND_WIDTH 400.0
#define WND_HEIGHT 400.0

float angle = 0.0;

void drawP(int x, int y){
	glClear(GL_COLOR_BUFFER_BIT); // ������ ���
	glColor3f(1.0,1.0,1.0); // ���� �����
	// ������ ���������
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd(); // ����� ���������
	//glFlush(); // "��������� ��", ��� ������ ������
	glutSwapBuffers();
}

void draw(){ // ���������
	glClear(GL_COLOR_BUFFER_BIT); // ������ ���
	glColor3f(1.0,1.0,1.0); // ���� �����
	// ������ ���������

	/*glBegin(GL_POINTS); 
		glVertex2f(0.0,0.0); // ������ �����
		*/
	glPushMatrix();
	glRotatef(angle,0.0,0.0,1.0);
	glBegin(GL_LINES);
	for(float i = 0; i <= WND_WIDTH; i += 20.0){
		glVertex2f(i,0);
		glVertex2f(i, WND_HEIGHT);
	}
	for(float i = 0; i <= WND_HEIGHT; i += 20.0){
		glVertex2f(0,i);
		glVertex2f(WND_WIDTH,i);
	}
	glEnd(); // ����� ���������
	glPopMatrix();
	//glFlush(); // "��������� ��", ��� ������ ������
	glutSwapBuffers();
}

void timer(int){
	//++angle;
	//glutPostRedisplay(); // Draw();
	glutTimerFunc(50, timer, 0);
}

void mouseMove(int ax, int ay){

}

void mousePressed(int button, int state, int x, int y){
	switch(button){
	case GLUT_LEFT_BUTTON:
		break;
	case GLUT_RIGHT_BUTTON:
		break;
	case GLUT_MIDDLE_BUTTON:
		break;
	}
}

void mousePressedMove(int ax, int ay){

}

void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 'a':
		angle++;
		break;
	case 'd':
		angle--;
		break;
	}
}// ������ �����
void skeyboard(int key, int x, int y){

}// ������������� �������, ���� � �.�.

void init(){
	glClearColor(0.0, 0.0, 0.0, 1.0); // ���� ���� - ������ ��� ����� RGB, �������� - �����, ������������
	glMatrixMode(GL_PROJECTION); // ����� �������
	glLoadIdentity();
	glOrtho(0,WND_WIDTH,0,WND_HEIGHT, 0, 400.0); // ������ ��������� ����� � ������
	glMatrixMode(GL_MODELVIEW);
	//glTranslatef(50.0,0.0,0.0); // ������������
	//glScalef(0.9,1.0,1.0); // ���������������
	//glRotatef(15,0.0,0.0,1.0); // �������
}

int main(int argc, char** argv){

	// �������������
	glutInit(&argc,argv);
	//glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); // ���. ��� ������
	glutInitWindowSize(WND_WIDTH,WND_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Epic Defense");
	// �����������
	glutMotionFunc(mousePressedMove);
	glutPassiveMotionFunc(mouseMove);
	glutMouseFunc(mousePressed);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(skeyboard);
	glutDisplayFunc(draw);
	glutTimerFunc(50, timer, 0);
	init();

	glutMainLoop();
	return 0;
}