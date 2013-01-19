#include "AIObject.h"


CAIObject::CAIObject(GLint model, GLfloat x, GLfloat y, GLint specialParam)
{

	mesh.model = model;
	mesh.p.x = x;
	mesh.p.y = y;
	mesh.moving = false; // �� ���������

	switch(model){
	case GAME_MODEL_TREE:
		{
			ModelTree *tree;
			tree = new ModelTree();

			mesh.moving = ModelTree::moving;

			delete tree;
		}
		break;
	case GAME_MODEL_SPAWN:
		{
			ModelSpawn *spawn;
			spawn = new ModelSpawn();

			mesh.moving = ModelSpawn::moving;

			delete spawn;
		}
		break;
	case GAME_MODEL_WALL:
		{
			ModelWall *wall;
			wall = new ModelWall();

			mesh.moving = ModelWall::moving;

			delete wall;
		}
		break;
	case GAME_MODEL_GOBLIN:
		{
			ModelGoblin *goblin;
			goblin = new ModelGoblin();

			mesh.moving = ModelGoblin::moving;

			if (specialParam == 0) specialParam = -1;

			mobMesh.nextFragID = specialParam;
			mobMesh.onPoint = false;

			delete goblin;
		}
		break;
	case GAME_MODEL_PATH:
		{
			ModelPath *path;
			path = new ModelPath();

			// � ������ specialParam - ���� ���������� ��������, � ���� ������ �������������, ���� ����� -1. 
			// ���� specialParam ����� ����, �� �������, ��� ������ �������������, �.�. 0 - ��� �����
			if (specialParam == 0) specialParam = -1;

			// ��� �������� �������� �������, ��� ���������� ����������� �� ���� ��������� ����� ����
			pathFragMesh.inCount = 0;
			pathFragMesh.nextFragID = specialParam;

			delete path;
		}
		break;
	case GAME_MODEL_GROUND:
	default:
		break;
	}
}

CAIObject::~CAIObject(void)
{
}

void CAIObject::initPath(){

}

// ����� ������� ��� ��������� ���� ��������, ������� ����� ��������� ������. ���������� � ������� ������� ����� �����������
POINT CAIObject::action(POINT p, CGraphicObject *grObj){
	POINT pOut = p;

	if (mesh.moving) {
		switch(mesh.model){

		case GAME_MODEL_GOBLIN:
			{
				ModelGoblin *goblin;
				goblin = new ModelGoblin();

				pOut.x = p.x + 1;
				pOut.y = p.y + 1;//10*sin(p.x);//p.y + 1;

				grObj->Move(pOut.x, pOut.y);

				delete goblin;
			}
			break;
		case GAME_MODEL_TREE:
		case GAME_MODEL_SPAWN:
		case GAME_MODEL_WALL:
		case GAME_MODEL_GROUND:
		default:
			break;
		}
	}

	return pOut;
}

bool CAIObject::getMoving(){
	return mesh.moving;
}

bool CAIObject::getMobOnPoint(){
	return mobMesh.onPoint;
}

GLint CAIObject::getNextMobFragID(){
	return mobMesh.nextFragID;
}

GLint CAIObject::getNextPathFragID(){
	return pathFragMesh.nextFragID;
}

void CAIObject::setToPoint(POINT p){
	mobMesh.toPoint = p;
}

void CAIObject::setOnPointOn(){
	mobMesh.onPoint = true;
}

void CAIObject::setOnPointOff(){
	mobMesh.onPoint = false;
}

void CAIObject::setNextMobFragID(GLint globalID){
	mobMesh.nextFragID = globalID;
}

void CAIObject::increasePathFragInCount(){
	pathFragMesh.inCount++;
}

void CAIObject::goToPoint(){
	if (mobMesh.onPoint){ // ���� ������ � �����, �� ��� � ���������

	} else { // ���� ��� �� ������ � �����, �� ��� �� ��������� ����
		if (mobMesh.nextFragID!=-1){ // ���� � ���� ������ ���� �����, � ������� ���������
			//CGraphicObject *grObj = CGame::Instance().
			//POINT to = 
		} else { // ����� ���� ���� � �������� �����

		}
	}
}