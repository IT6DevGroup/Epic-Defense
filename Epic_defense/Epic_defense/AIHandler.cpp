#include "AIHandler.h"

void AIAction(GLint globalID){
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);

	if (AIObject->getMoving()){
		if (AIObject->getMobOnPoint()){ // ���� ������ � �����, �� ��� � ���������

		} else { // ���� ��� �� ������ � �����, �� ��� �� ��������� ����
			if (AIObject->getNextFragID()!=-1){ // ���� � ���� ������ ���� �����, � ������� ���������
				CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextFragID());
				POINT to = grObjPath->getCoords();
				graphicObject->Move(to.x, to.y); // ��������, ������ ���� ������� �������� � ����� � �������� ���������
			} else { // ����� ���� ���� � �������� �����

			}
		}
	}
}