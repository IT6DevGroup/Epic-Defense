#include "AIHandler.h"

GLint spawned = 0; // Сколько спаунов в волне уже заспаунило мобов (обнуляется с каждой волной)

void AIAction(GLint globalID){
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);


	// Обработка передвижения
	if (AIObject->getMoving()){ 
		if (AIObject->getMobOnPoint()){ // Если пришёл в точку, то идём в следующую
			//CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextFragID());
			GLint id = AIObject->getNextMobFragID();
			CAIObject *AIObjectPath = CGame::Instance().getAIObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
			GLint nextFragID = AIObjectPath->getNextPathFragID();
			AIObject->setNextMobFragID(nextFragID);
			AIObject->setOnPointOff();
		} else { // Если ещё не пришёл в точку, то идём со скоростью моба
			if (AIObject->getNextMobFragID()>-1){ // Если у моба вообще есть точка, к которой двигаться
				CGraphicObject *grObjPath = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, AIObject->getNextMobFragID());
				POINT to = grObjPath->getCoords(); // Конечная точка
				POINT now = graphicObject->getCoords(); // Текущая точка
				POINT nextPoint = divisionStraightWithRatio(now, to, ModelGoblin::speed);
				graphicObject->Move(nextPoint.x, nextPoint.y); // Работает, теперь надо сделать движение к точке с заданной скоростью
				GLint x = nextPoint.x;
				GLint y = nextPoint.y;
				if ( (nextPoint.x == to.x) && (nextPoint.y == to.y) )
					AIObject->setOnPointOn();
			} else { // Если у моба нет следующей точки, то ищем путь к конечной 
				POINT to = CGame::Instance().getCastleCoords(); // Конечная точка
				POINT now = graphicObject->getCoords(); // Текущая точка
				POINT nextPoint = divisionStraightWithRatio(now, to, ModelGoblin::speed);
				graphicObject->Move(nextPoint.x, nextPoint.y);
			}
		}
	}

	// Обработка спауна
	/*
	Возможны две версии:
	1) Спаун выпускает гоблинов через каждое определёное количество времени
	2) Спаун просто сразу создаёт много потоков мобов в зависимости от волны, а они уже разбираются сами
	с использованием семафоров и крит. секций

	Используется вторая
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