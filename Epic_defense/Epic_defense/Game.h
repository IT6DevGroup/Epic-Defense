#pragma once

#ifndef GAME_H
#define GAME_H

//#include "stdafx.h"
#include <map>
#include <string>

#include "texture_manager.h"

#include "Scene.h"


class CGame
{
	CGame(void);
	~CGame(void);
	std::map <std::string, CScene> scenes;
	//std::vector <CScene> scenes;

public:

	static CGame &Instance(){
		static CGame theSingleInstance;
		return theSingleInstance;
	};

	void addScene(CScene *sc, std::string name);
	void addObjectToScene(std::string sceneName, CGlobalObject *object);

	CScene getScene(std::string name);
	int getSceneCount();
	int getObjectsCountOnScene(std::string sceneName);

	// Version 2
	CGraphicObject* getGraphicObject(std::string sceneName, int globalObjectId);
	CGameObject* getGameObject(std::string sceneName, int globalObjectId);
	CPhysicObject* getPhysicObject(std::string sceneName, int globalObjectId);
	CSoundObject* getSoundObject(std::string sceneName, int globalObjectId);
	CAIObject* getAIObject(std::string sceneName, int globalObjectId);

	void LoadTextures();
	//void addScene(CScene *sc);
	//CScene getScene(int i);
};

#endif