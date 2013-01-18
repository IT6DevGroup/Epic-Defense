#pragma once

// ����������� ��������� ������� �������� ���������� � AIObject.h
#include "AIObject.h"

// ���������� ������ - ����������� � ���� ���� ��������
class CGlobalObject
{
	CGraphicObject *graphicObj;
	CPhysicObject *physicObj;
	CGameObject *gameObj;
	CSoundObject *soundObj;
	CAIObject *aiObj;

public:
	CGlobalObject(GLint model, GLuint shaderProgram, float posX, float posY, float zOffset = 0.0f, GLint specialParam = 0);
	~CGlobalObject(void);

	CGraphicObject* getGraphicObject();
	CGameObject* getGameObject();
	CPhysicObject* getPhysicObject();
	CSoundObject* getSoundObject();
	CAIObject* getAIObject();
};

