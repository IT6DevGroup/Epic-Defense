#pragma once

#include "GraphicObject.h"
#include "PhysicObject.h"
#include "GameObject.h"
#include "SoundObject.h"

#include "Models.h"

class CAIObject
{
	// MESH - особая структура для хранения всех необходимых данных, полученных из модели
	struct AI_MESH {
		GLint model;
		POINT p;
		bool moving;
	};
	AI_MESH mesh;
public:
	CAIObject(GLint model, GLfloat x, GLfloat y);
	~CAIObject(void);

	void initPath();
	POINT action(POINT p, CGraphicObject *grObj);

	bool getMoving();
};