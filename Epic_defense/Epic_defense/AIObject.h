#pragma once

#include "GraphicObject.h"
#include "PhysicObject.h"
#include "GameObject.h"
#include "SoundObject.h"

#include "Models.h"

class CAIObject
{
	// MESH - ������ ��������� ��� �������� ���� ����������� ������, ���������� �� ������
	struct AI_MESH {
		GLint model; 
		POINT p; // ����������
		bool moving;
	};
		
	// ��� ����� ������ ����� ������ ���, ����� ��������� ���������� �������� ����� � ��������� �����
	struct PATH_FRAG_MESH {
		// ���������� ����������� �� ���� ������� ���������
		GLint inCount;
		// ���� ���������� ��������. ���� ����� -1, �� ������ �������������
		GLint nextFragID;
	};

	// � ���� ���� �������� ��������� ������. ���� ����� -1, �� ������ ���
	struct MOB_MESH {
		GLint nextFragID;
		bool onPoint;
		POINT toPoint;
	};

	AI_MESH mesh;
	PATH_FRAG_MESH pathFragMesh;
	MOB_MESH mobMesh;

public:
	CAIObject(GLint model, GLfloat x, GLfloat y, GLint specialParam = 0);
	~CAIObject(void);

	void initPath();
	POINT action(POINT p, CGraphicObject *grObj);

	bool getMoving();
	bool getMobOnPoint();
	GLint getNextFragID();

	void setToPoint(POINT p);

	// ����������� ���������� �������� ����� � �������� �� �������
	void increasePathFragInCount();

	void goToPoint();
};