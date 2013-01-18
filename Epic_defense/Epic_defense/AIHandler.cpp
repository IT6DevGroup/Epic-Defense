#include "AIHandler.h"

void AIAction(GLint globalID){
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);

	if (AIObject->getMoving()){
		if (AIObject->getMobOnPoint()){ // Если пришёл в точку, то идём в следующую

		} else { // Если ещё не пришёл в точку, то идём со скоростью моба
			if (AIObject->getNextFragID()!=-1){ // Если у моба вообще есть точка, к которой двигаться
				CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextFragID());
				POINT to = grObjPath->getCoords();
				graphicObject->Move(to.x, to.y); // Работает, теперь надо сделать движение к точке с заданной скоростью
			} else { // Иначе ищем путь к конечной точке

			}
		}
	}
}