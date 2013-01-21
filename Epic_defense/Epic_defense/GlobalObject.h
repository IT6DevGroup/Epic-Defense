#pragma once

// Подключение остальных классов объектов содержится в AIObject.h
#include "AIObject.h"

// Глобальный объект - объединение в один всех объектов
class CGlobalObject
{
	CGraphicObject *graphicObj;
	CPhysicObject *physicObj;
	CGameObject *gameObj;
	CSoundObject *soundObj;
	CAIObject *aiObj;

	GLint globalID;

public:
	CGlobalObject(GLint model, GLuint shaderProgram, float posX, float posY, GLint globalObjID, float zOffset = 0.0f, GLint specialParam = 0);
	~CGlobalObject(void);

	CGraphicObject* getGraphicObject();
	CGameObject* getGameObject();
	CPhysicObject* getPhysicObject();
	CSoundObject* getSoundObject();
	CAIObject* getAIObject();

	GLint getGlobalID();
};

