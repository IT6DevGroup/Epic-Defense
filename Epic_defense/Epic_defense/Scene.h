#pragma once
#include <vector>

#include "GlobalObject.h"

#define GAME_SCENE_MAIN "main"
#define GAME_SCENE_MENU "menu"

class CScene
{

public:
	CScene(void);
	~CScene(void);

	std::vector<CGlobalObject> objects;

	void addObject(CGlobalObject *obj);

	CGlobalObject getObject(int i);
	int getObjectCount();

	CGraphicObject* getGraphicObject(int globalObjectId);
	CGameObject* getGameObject(int globalObjectId);
	CPhysicObject* getPhysicObject(int globalObjectId);
	CSoundObject* getSoundObject(int globalObjectId);
	CAIObject* getAIObject(int globalObjectId);
};

