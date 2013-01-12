#include "AIObject.h"


CAIObject::CAIObject(GLint model, GLfloat x, GLfloat y)
{

	mesh.model = model;
	mesh.p.x = x;
	mesh.p.y = y;
	mesh.moving = false; // по умолчанию

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

			delete goblin;
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

POINT CAIObject::nextStep(POINT p){
	POINT pOut = p;
	
	switch(mesh.model){

	case GAME_MODEL_GOBLIN:
		{
			ModelGoblin *goblin;
			goblin = new ModelGoblin();

			pOut.x = p.x + 1;
			pOut.y = p.y + 1;//10*sin(p.x);//p.y + 1;

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

	return pOut;
}

bool CAIObject::getMoving(){
	return mesh.moving;
}