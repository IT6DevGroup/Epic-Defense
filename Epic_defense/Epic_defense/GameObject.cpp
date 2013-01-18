#include "GameObject.h"


CGameObject::CGameObject(GLint model, GLint specialParam)
{
switch(model){
	case GAME_MODEL_TREE:
		{
			ModelTree *tree;
			tree = new ModelTree();

			delete tree;
		}
		break;
	case GAME_MODEL_SPAWN:
		{
			ModelSpawn *spawn;
			spawn = new ModelSpawn();

			delete spawn;
		}
		break;
	case GAME_MODEL_WALL:
		{
			ModelWall *wall;
			wall = new ModelWall();

			delete wall;
		}
		break;
	case GAME_MODEL_GOBLIN:
		{
			ModelGoblin *goblin;
			goblin = new ModelGoblin();

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
			//pathFragMesh.inCount = 0;
			//pathFragMesh.nextFragID = specialParam;

			delete path;
		}
		break;
	case GAME_MODEL_GROUND:
	default:
		break;
	}
}


CGameObject::~CGameObject(void)
{
}

/*
void CGameObject::increasePathFragInCount(){
	pathFragMesh.inCount++;
}*/