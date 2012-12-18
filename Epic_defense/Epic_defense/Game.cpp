#include "Game.h"

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::addScene(CScene *sc, std::string name){
	this->scenes[name] = *sc;
}

void CGame::addObjectToScene(std::string sceneName, CGlobalObject *object){
	this->scenes[sceneName].addObject(object);
}

CScene CGame::getScene(std::string name){
	return this->scenes[name];
}

int CGame::getSceneCount(){
	return this->scenes.size();
}

int CGame::getObjectsCountOnScene(std::string sceneName){
	return this->scenes[sceneName].getObjectCount();
}


// Version 2

CGraphicObject* CGame::getGraphicObject(std::string sceneName, int globalObjectId){
	return this->scenes[sceneName].getGraphicObject(globalObjectId);
}
CGameObject* CGame::getGameObject(std::string sceneName, int globalObjectId){
	return this->scenes[sceneName].getGameObject(globalObjectId);
}
CPhysicObject* CGame::getPhysicObject(std::string sceneName, int globalObjectId){
	return this->scenes[sceneName].getPhysicObject(globalObjectId);
}
CSoundObject* CGame::getSoundObject(std::string sceneName, int globalObjectId){
	return this->scenes[sceneName].getSoundObject(globalObjectId);
}
CAIObject* CGame::getAIObject(std::string sceneName, int globalObjectId){
	return this->scenes[sceneName].getAIObject(globalObjectId);
}

void CGame::LoadTextures(){
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("grass.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("tree.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("spawn.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("wall.tga");
	TEXTUREMANAGER::GetInstance().LoadTGATexture ("goblin.tga");

	GLuint textureSamplerLocation = glGetUniformLocation (shader_program, "diffuseTexture");
	glUniform1i (textureSamplerLocation, 0);
}


/*void CGame::addScene(CScene *sc){
this->scenes.push_back(*sc);
}

CScene CGame::getScene(int i){
return this->scenes[i];
}*/