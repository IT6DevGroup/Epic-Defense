#include "AIHandler.h"

void AIAction(GLint globalID){
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);

	if (AIObject->getMoving()){
		if (AIObject->getMobOnPoint()){ // ���� ������ � �����, �� ��� � ���������
			//CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextFragID());
			GLint id = AIObject->getNextMobFragID();
			CAIObject *AIObjectPath = CGame::Instance().getAIObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
			GLint nextFragID = AIObjectPath->getNextPathFragID();
			AIObject->setNextMobFragID(nextFragID);
			AIObject->setOnPointOff();
		} else { // ���� ��� �� ������ � �����, �� ��� �� ��������� ����
			if (AIObject->getNextMobFragID()!=-1){ // ���� � ���� ������ ���� �����, � ������� ���������
				CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
				POINT to = grObjPath->getCoords(); // �������� �����
				POINT now = graphicObject->getCoords(); // ������� �����
				POINT nextPoint = divisionStraightWithRatio(now, to, 5);
				graphicObject->Move(nextPoint.x, nextPoint.y); // ��������, ������ ���� ������� �������� � ����� � �������� ���������
				GLint x = nextPoint.x;
				GLint y = nextPoint.y;
				if ( (nextPoint.x == to.x) && (nextPoint.y == to.y) )
					AIObject->setOnPointOn();
			} else { // ����� ���� ���� � �������� �����

			}
		}
	}
}