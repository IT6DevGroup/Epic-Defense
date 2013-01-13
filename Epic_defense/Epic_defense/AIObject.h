#pragma once

#include "GraphicObject.h"
#include "PhysicObject.h"
#include "GameObject.h"
#include "SoundObject.h"

#include "Models.h"

class CAIObject
{
	// MESH - ������ ��������� ��� �������� ���� ����������� ������, ���������� �� ������
	struct AIMESH {
		GLint model;
		POINT p;
		bool moving;
	};
	AIMESH mesh;
public:
	CAIObject(GLint model, GLfloat x, GLfloat y);
	~CAIObject(void);

	void initPath();
	POINT action(POINT p, CGraphicObject *grObj);

	bool getMoving();
};