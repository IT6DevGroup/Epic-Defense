#include "GlobalObject.h"


CGlobalObject::CGlobalObject(GLint model, GLuint shaderProgram, GLfloat posX, GLfloat posY, GLint globalObjID, GLfloat zOffset, GLint specialParam)
{
	this->graphicObj = new CGraphicObject(model, shaderProgram, posX, posY, zOffset);
	this->physicObj = new CPhysicObject(model);
	this->gameObj = new CGameObject(model);
	this->soundObj = new CSoundObject(model);
	this->aiObj = new CAIObject(model, posX, posY, specialParam);

	globalID = globalObjID;
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

GLint CGlobalObject::getGlobalID(){
	return globalID;
}