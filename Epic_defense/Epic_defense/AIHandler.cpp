#include "AIHandler.h"

GLint spawned = 0; // ������� ������� � ����� ��� ���������� ����� (���������� � ������ ������)

void AIAction(GLint globalID){
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);


	// ��������� ������������
	if (AIObject->getMoving()){ 
		if (AIObject->getMobOnPoint()){ // ���� ������ � �����, �� ��� � ���������
			//CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextFragID());
			GLint id = AIObject->getNextMobFragID();
			CAIObject *AIObjectPath = CGame::Instance().getAIObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
			GLint nextFragID = AIObjectPath->getNextPathFragID();
			AIObject->setNextMobFragID(nextFragID);
			AIObject->setOnPointOff();
		} else { // ���� ��� �� ������ � �����, �� ��� �� ��������� ����
			if (AIObject->getNextMobFragID()>-1){ // ���� � ���� ������ ���� �����, � ������� ���������
				CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
				POINT to = grObjPath->getCoords(); // �������� �����
				POINT now = graphicObject->getCoords(); // ������� �����
				POINT nextPoint = divisionStraightWithRatio(now, to, ModelGoblin::speed);
				graphicObject->Move(nextPoint.x, nextPoint.y); // ��������, ������ ���� ������� �������� � ����� � �������� ���������
				GLint x = nextPoint.x;
				GLint y = nextPoint.y;
				if ( (nextPoint.x == to.x) && (nextPoint.y == to.y) )
					AIObject->setOnPointOn();
			} else { // ���� � ���� ��� ��������� �����, �� ���� ���� � �������� 
				POINT to = CGame::Instance().getCastleCoords(); // �������� �����
				POINT now = graphicObject->getCoords(); // ������� �����
				POINT nextPoint = divisionStraightWithRatio(now, to, ModelGoblin::speed);
				graphicObject->Move(nextPoint.x, nextPoint.y);
			}
		}
	}

	// ��������� ������
	/*
	�������� ��� ������:
	1) ����� ��������� �������� ����� ������ ���������� ���������� �������
	2) ����� ������ ����� ������ ����� ������� ����� � ����������� �� �����, � ��� ��� ����������� ����
	� �������������� ��������� � ����. ������

	������������ ������
	*/
	if (AIObject->getModelName() == GAME_MODEL_SPAWN){
		//if(!c){
		if(CGame::Instance().getIsNextWave()){
			GLint spawnNum = 0;
			POINT now = graphicObject->getCoords();
			if (now.x == CGame::Instance().getSpawn1Coords().x && now.y == CGame::Instance().getSpawn1Coords().y) spawnNum = 1;
			if (now.x == CGame::Instance().getSpawn2Coords().x && now.y == CGame::Instance().getSpawn2Coords().y) spawnNum = 2;
			if (now.x == CGame::Instance().getSpawn3Coords().x && now.y == CGame::Instance().getSpawn3Coords().y) spawnNum = 3;

			_beginthreadex(NULL, 0, nextWaveThread, (void*) spawnNum, 0, NULL);
			/*_beginthreadex(NULL, 0, MobThread, (void*) spawnNum, 0, NULL);			
			_beginthreadex(NULL, 0, MobThread, (void*) spawnNum, 0, NULL);
			_beginthreadex(NULL, 0, MobThread, (void*) spawnNum, 0, NULL);
			_beginthreadex(NULL, 0, MobThread, (void*) spawnNum, 0, NULL);*/

			spawned++;

			if (spawned == 3){
				CGame::Instance().setIsNextWaveOff();
				spawned = 0;
			}
		}
	}
}