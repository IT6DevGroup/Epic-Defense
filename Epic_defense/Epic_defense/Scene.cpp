#include "Scene.h"


bool comp(CGlobalObject a, CGlobalObject b){
	CGraphicObject *grA = a.getGraphicObject();
	CGraphicObject *grB = b.getGraphicObject();
	return (grA->getCoords().y>grB->getCoords().y);
}

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

CGraphicObject* CScene::getGraphicObject(int globalObjectId, bool isVectorID){
	if(!isVectorID)
		for (int i = 0; i < this->objects.size(); i++){
			if(this->objects[i].getGlobalID() == globalObjectId)
				return this->objects[i].getGraphicObject();
		}
	else
		return this->objects[globalObjectId].getGraphicObject();
}
CGameObject* CScene::getGameObject(int globalObjectId, bool isVectorID){
	if(!isVectorID)
		for (int i = 0; i < this->objects.size(); i++){
			if(this->objects[i].getGlobalID() == globalObjectId)
				return this->objects[i].getGameObject();
		}
	else
		return this->objects[globalObjectId].getGameObject();
}
CPhysicObject* CScene::getPhysicObject(int globalObjectId, bool isVectorID){
	if(!isVectorID)
		for (int i = 0; i < this->objects.size(); i++){
			if(this->objects[i].getGlobalID() == globalObjectId)
				return this->objects[i].getPhysicObject();
		}
	else
		return this->objects[globalObjectId].getPhysicObject();
}
CSoundObject* CScene::getSoundObject(int globalObjectId, bool isVectorID){
	if(!isVectorID)
		for (int i = 0; i < this->objects.size(); i++){
			if(this->objects[i].getGlobalID() == globalObjectId)
				return this->objects[i].getSoundObject();
		}
	else
		return this->objects[globalObjectId].getSoundObject();
}
CAIObject* CScene::getAIObject(int globalObjectId, bool isVectorID){
	if(!isVectorID)
		for (int i = 0; i < this->objects.size(); i++){
			if(this->objects[i].getGlobalID() == globalObjectId)
				return this->objects[i].getAIObject();
		}
	else
		return this->objects[globalObjectId].getAIObject();
}


CGlobalObject* CScene::getGlobalObject(int vectorID){
	return &this->objects[vectorID];
}


void CScene::sortObjects(GLint from){
	std::sort(objects.begin(), objects.end(), comp);
}
