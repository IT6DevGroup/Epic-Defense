#pragma once

#include "Models.h"

#include "texture_manager.h"
#include "matrix.h"

#include <vector>

class CGraphicObject
{
	// MESH - ������ ��������� ��� �������� ���� ����������� ������, ���������� �� ������
	struct MESH {
		GLint model;
		GLuint VAO;
		std::vector <GLuint> VBOVector;
		GLuint VBO;
		GLint vcount, icount;
		POINT p;
	};
	MESH mesh;
	GLfloat	projectionMatrix[16];
	GLfloat	translateMatrix[16];
	GLfloat	textureMatrix[16];
public:
	CGraphicObject(GLint model, GLuint shaderProgram, float posX, float poxY, float zOffset = 0.0f);
	~CGraphicObject(void);

	void Move(float x, float y, float z = 0.0f);
	// ��������� ���������� � ���������� (����������� ����� ����� �������� ���������� OpenGL)
	void DrawParamsSet(GLuint shaderProgram); 

	GLuint getVAO();
	std::vector <GLuint> getVBOVector();
	GLint getVerticesCount();
	POINT getCoords();
};

