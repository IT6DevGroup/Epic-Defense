#pragma once

#include "Models.h"

#include "texture_manager.h"
#include "matrix.h"

#include <vector>

class CGraphicObject
{
	struct MESH {
		GLint model;
		GLuint VAO;
		std::vector <GLuint> VBOVector;
		GLuint VBO;
		GLint vcount, icount;
	};
	MESH mesh;
	GLfloat	projectionMatrix[16];
	GLfloat	translateMatrix[16];
	GLfloat	textureMatrix[16];
public:
	CGraphicObject(GLint model, GLuint shaderProgram, float posX, float poxY, float zOffset = 0.0f);
	~CGraphicObject(void);

	void Move(float x, float y, float z = 0.0f/*,  GLuint shaderProgram*/);
	void DrawParamsSet(GLuint shaderProgram); // Установка параметров к прорисовке

	GLuint getVAO();
	std::vector <GLuint> getVBOVector();
	int getVerticesCount();
};

