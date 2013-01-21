#pragma once

#ifndef GAME_H
#define GAME_H

// Каждое это количество кадров будет появляться новая волна
#define GAME_WAVE_PER_FRAME 400
// Максимальное количество мобов в волне. Когда мобов становится столько, наступает следующая глобальная волна
#define GAME_MAX_MOBS_ON_WAVE 10 

//#include "stdafx.h"
#include <map>
#include <string>
#include <process.h>

#include "texture_manager.h"

#include "Scene.h"

class CGame
{
	CGame(void);
	~CGame(void);
	std::map <std::string, CScene> scenes;
	//std::vector <CScene> scenes;

	bool paths;
	// Айдишники первых кусков дорог
	GLint path1FirstFragID;
	GLint path2FirstFragID;
	GLint path3FirstFragID;
	GLint crossroadsID;

	// Координаты спаунов
	POINT spawn1p;
	POINT spawn2p;
	POINT spawn3p;

	GLint globalWave;
	GLint wave;
	bool isNextWave;
	bool isNextGlobalWave;

	GLint sortFrom; // Сортировать главную сцену нужно без учёта земли, дорог и спаунов

	POINT castleCoords;

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
	bool getPathsExistence();
	GLint getPath1FirstFragID();
	GLint getPath2FirstFragID();
	GLint getPath3FirstFragID();
	POINT getSpawn1Coords();
	POINT getSpawn2Coords();
	POINT getSpawn3Coords();
	bool getIsNextWave();
	bool getIsNextGlobalWave();
	GLint getCrossroadsID();
	GLint getWaveNum();
	GLint getGlobalWaveNum();
	GLint getSortFrom();
	POINT getCastleCoords();

	void setPathsFirstFragIDs(GLint path1, GLint path2, GLint path3);
	void setSpawnsCoords(POINT spawn1, POINT spawn2, POINT spawn3);
	void nextWave();
	void setIsNextWaveOff();
	void nextGlobalWave();
	void setIsNextGlobalWaveOff();
	void setCrossroadsID(GLint globalID);
	void setSortFrom(GLint from);
	void setCastleCoords(POINT coords);

	// Version 2
	CGraphicObject* getGraphicObject(std::string sceneName, int globalObjectId, bool isVectorID = false);
	CGameObject* getGameObject(std::string sceneName, int globalObjectId, bool isVectorID = false);
	CPhysicObject* getPhysicObject(std::string sceneName, int globalObjectId, bool isVectorID = false);
	CSoundObject* getSoundObject(std::string sceneName, int globalObjectId, bool isVectorID = false);
	CAIObject* getAIObject(std::string sceneName, int globalObjectId, bool isVectorID = false);

	CGlobalObject* getGlobalObject(std::string sceneName, GLint vectorID);

	void sortObjectsOnScene(std::string sceneName);

	void LoadTextures();
	void DisablePaths();
	//void addScene(CScene *sc);
	//CScene getScene(int i);
};

#endif