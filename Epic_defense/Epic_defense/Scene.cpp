#include "Scene.h"


CScene::CScene(void)
{
}


CScene::~CScene(void)
{
}

void CScene::addObject(CGlobalObject *obj){
	this->objects.push_back(*obj);
}

CGlobalObject CScene::getObject(int i){
	return this->objects[i];
}

int CScene::getObjectCount(){
	return this->objects.size();
}

CGraphicObject* CScene::getGraphicObject(int globalObjectId){
	return this->objects[globalObjectId].getGraphicObject();
}
CGameObject* CScene::getGameObject(int globalObjectId){
	return this->objects[globalObjectId].getGameObject();
}
CPhysicObject* CScene::getPhysicObject(int globalObjectId){
	return this->objects[globalObjectId].getPhysicObject();
}
CSoundObject* CScene::getSoundObject(int globalObjectId){
	return this->objects[globalObjectId].getSoundObject();
}
CAIObject* CScene::getAIObject(int globalObjectId){
	return this->objects[globalObjectId].getAIObject();
}
