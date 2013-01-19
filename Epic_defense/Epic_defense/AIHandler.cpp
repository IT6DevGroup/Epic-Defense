#include "AIHandler.h"

void AIAction(GLint globalID){
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);

	if (AIObject->getMoving()){
		if (AIObject->getMobOnPoint()){ // Если пришёл в точку, то идём в следующую
			//CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextFragID());
			GLint id = AIObject->getNextMobFragID();
			CAIObject *AIObjectPath = CGame::Instance().getAIObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
			GLint nextFragID = AIObjectPath->getNextPathFragID();
			AIObject->setNextMobFragID(nextFragID);
			AIObject->setOnPointOff();
		} else { // Если ещё не пришёл в точку, то идём со скоростью моба
			if (AIObject->getNextMobFragID()!=-1){ // Если у моба вообще есть точка, к которой двигаться
				CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
				POINT to = grObjPath->getCoords(); // Конечная точка
				POINT now = graphicObject->getCoords(); // Текущая точка
				POINT nextPoint = divisionStraightWithRatio(now, to, 5);
				graphicObject->Move(nextPoint.x, nextPoint.y); // Работает, теперь надо сделать движение к точке с заданной скоростью
				GLint x = nextPoint.x;
				GLint y = nextPoint.y;
				if ( (nextPoint.x == to.x) && (nextPoint.y == to.y) )
					AIObject->setOnPointOn();
			} else { // Иначе ищем путь к конечной точке

			}
		}
	}
}