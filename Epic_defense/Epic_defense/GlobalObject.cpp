#include "GlobalObject.h"


CGlobalObject::CGlobalObject(GLint model, GLuint shaderProgram, float posX, float posY, float zOffset)
{
	this->graphicObj = new CGraphicObject(model, shaderProgram, posX, posY, zOffset);
	this->physicObj = new CPhysicObject;
	this->gameObj = new CGameObject;
	this->soundObj = new CSoundObject;
	this->aiObj = new CAIObject;
}


CGlobalObject::~CGlobalObject(void)
{
}

CGraphicObject* CGlobalObject::getGraphicObject(){
	return this->graphicObj;
}
CGameObject* CGlobalObject::getGameObject(){
	return this->gameObj;
}
CPhysicObject* CGlobalObject::getPhysicObject(){
	return this->physicObj;
}
CSoundObject* CGlobalObject::getSoundObject(){
	return this->soundObj;
}
CAIObject* CGlobalObject::getAIObject(){
	return this->aiObj;
}