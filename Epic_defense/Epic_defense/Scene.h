#pragma once
#include <vector>
#include <algorithm>

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

	CGraphicObject* getGraphicObject(int globalObjectId, bool isVectorID = false);
	CGameObject* getGameObject(int globalObjectId, bool isVectorID = false);
	CPhysicObject* getPhysicObject(int globalObjectId, bool isVectorID = false);
	CSoundObject* getSoundObject(int globalObjectId, bool isVectorID = false);
	CAIObject* getAIObject(int globalObjectId, bool isVectorID = false);

	CGlobalObject* getGlobalObject(int vectorID);

	void sortObjects(GLint from);
};

