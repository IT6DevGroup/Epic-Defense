#include "Threads.h"

CRITICAL_SECTION gameRequestCriticalSection;
CRITICAL_SECTION inSpawn1CriticalSection;
CRITICAL_SECTION inSpawn2CriticalSection;
CRITICAL_SECTION inSpawn3CriticalSection;
CRITICAL_SECTION crossroadsCriticalSection;
HANDLE hPath1Sem;
HANDLE hPath2Sem;
HANDLE hPath3Sem;

struct waveData{
	GLint spawnNum;
	std::vector <GLint> waveMobsIDs;
};

unsigned __stdcall MobThread(void* pArguments) {

	bool onSpawn = true; // Флаг, указывающий, находится ли моб близко к спауну. Становится false, когда моб перемещается дальше одной клетки дороги от спауна

	waveData *data = (waveData*) pArguments;

	GLint spawnNum = data->spawnNum;//(int) pArguments;
	POINT spawnP;

	GLint pathID;

	CRITICAL_SECTION *spawn_critical_section;
	//HANDLE path_semaphore;

	if (spawnNum == 1){ 
		spawnP = CGame::Instance().getSpawn1Coords();
		spawn_critical_section = &inSpawn1CriticalSection;
		pathID = CGame::Instance().getPath1FirstFragID();
		//path_semaphore = hPath1Sem;
	}
	if (spawnNum == 2){
		spawnP = CGame::Instance().getSpawn2Coords();
		spawn_critical_section = &inSpawn2CriticalSection;
		pathID = CGame::Instance().getPath2FirstFragID();
		//path_semaphore = hPath2Sem;
	}
	if (spawnNum == 3){ 
		spawnP = CGame::Instance().getSpawn3Coords();
		spawn_critical_section = &inSpawn3CriticalSection;
		pathID = CGame::Instance().getPath3FirstFragID();
		//path_semaphore = hPath3Sem;
	}

	EnterCriticalSection(spawn_critical_section);

	/*DWORD dwWaitResult = WaitForSingleObject(path_semaphore, INFINITE);
	switch (dwWaitResult) 
	{ 
	case WAIT_OBJECT_0:  // Моб вышел на дорогу   

	EnterCriticalSection(&gameRequestCriticalSection);

	CGlobalObject *goblin = new CGlobalObject(GAME_MODEL_GOBLIN, shader_program, spawnP.x, spawnP.y, 0, CGame::Instance().getPath1FirstFragID());
	CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, goblin);

	GLint globalID = CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) - 1;
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);

	LeaveCriticalSection(&gameRequestCriticalSection);
	bool leaved = false;

	while (onPath){
	if (graphicObject->getCoords().x > ModelPath::width && !leaved){
	LeaveCriticalSection(spawn_critical_section);
	leaved = true;
	}
	if (AIObject->getNextMobFragID() < 0){
	onPath = false;
	ReleaseSemaphore(path_semaphore, 1, NULL);   
	}
	}		    
	break; 
	}*/

	EnterCriticalSection(&gameRequestCriticalSection);

	CGlobalObject *goblin = new CGlobalObject(GAME_MODEL_GOBLIN, shader_program, spawnP.x, spawnP.y, CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN), 0, pathID);
	CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, goblin);

	GLint globalID = CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) - 1;
	CGraphicObject *graphicObject = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);
	CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
	data->waveMobsIDs.push_back(globalID);

	LeaveCriticalSection(&gameRequestCriticalSection);
	bool leaved = false;

	while (!leaved){
		if (graphicObject->getCoords().x > ModelPath::width){
			LeaveCriticalSection(spawn_critical_section);
			leaved = true;
		}
	}		    

	return 0;
}

unsigned __stdcall nextWaveThread(void* pArguments){

	bool onPath = true; // Флаг, указывающий, находится ли волна всё ещё на дороге. Если нет, то поток удаляется
	DWORD dwWaitResult;

	waveData *data = new waveData;

	data->spawnNum = (int) pArguments;

	GLint spawnNum = data->spawnNum;
	POINT spawnP;

	GLint pathID;

	CRITICAL_SECTION *spawn_critical_section;
	//HANDLE path_semaphore;

	if (spawnNum == 1){ 
		spawnP = CGame::Instance().getSpawn1Coords();
		//spawn_critical_section = &inSpawn1CriticalSection;
		pathID = CGame::Instance().getPath1FirstFragID();
		//path_semaphore = hPath1Sem;
	}
	if (spawnNum == 2){
		spawnP = CGame::Instance().getSpawn2Coords();
		//spawn_critical_section = &inSpawn2CriticalSection;
		pathID = CGame::Instance().getPath2FirstFragID();
		//path_semaphore = hPath2Sem;
	}
	if (spawnNum == 3){ 
		spawnP = CGame::Instance().getSpawn3Coords();
		//spawn_critical_section = &inSpawn3CriticalSection;
		pathID = CGame::Instance().getPath3FirstFragID();
		//path_semaphore = hPath3Sem;
	}

	switch(data->spawnNum){
	case 1:
		dwWaitResult = WaitForSingleObject(hPath1Sem, INFINITE);
		break;
	case 2:
		dwWaitResult = WaitForSingleObject(hPath2Sem, INFINITE);
		break;
	case 3:
		dwWaitResult = WaitForSingleObject(hPath3Sem, INFINITE);
		break;
	}
	EnterCriticalSection(&gameRequestCriticalSection);
	GLint crossroadsID = CGame::Instance().getCrossroadsID();
	CGraphicObject *crossroadsGrObj = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, crossroadsID);
	GLint waveNum = CGame::Instance().getWaveNum();
	LeaveCriticalSection(&gameRequestCriticalSection);

	CAIObject *firstMobAIobj;
	CGraphicObject *firstMobGrObj;
	bool entered = false; // Флаг, говорящий о том, что волна вошла на перекрёсток
	GLint crossroadsX = crossroadsGrObj->getCoords().x;
	GLint crossroadsY = crossroadsGrObj->getCoords().y;
	GLint offset = 20;
	switch (dwWaitResult) 
	{ 
	case WAIT_OBJECT_0:  
		for (int i = 0; i < waveNum; i++){
			HANDLE hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
			LARGE_INTEGER li;
			const int nTimerUnitsPerSecond = 10000000;
			li.QuadPart = -(0.5 * nTimerUnitsPerSecond);
			SetWaitableTimer(hTimer, &li, 0, NULL, NULL, FALSE);
			DWORD res = WaitForSingleObject(hTimer, INFINITE);
			switch(res){
			case WAIT_OBJECT_0:  
				EnterCriticalSection(&gameRequestCriticalSection);

				CGlobalObject *goblin = new CGlobalObject(GAME_MODEL_GOBLIN, shader_program, spawnP.x, spawnP.y, CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN), 0, pathID);
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, goblin);
				GLint globalID = CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) - 1;
				data->waveMobsIDs.push_back(globalID);

				if(i==0){
					firstMobAIobj = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
					firstMobGrObj = CGame::Instance().getGraphicObject(GAME_SCENE_MAIN, globalID);
				}

				if (!entered &&
					(firstMobGrObj->getCoords().x > crossroadsX-offset) &&
					(firstMobGrObj->getCoords().y < crossroadsY+offset*2 && firstMobGrObj->getCoords().y > crossroadsY-offset*2)){ // Если мобы входят в крит. секцию
						entered = true;

						EnterCriticalSection(&gameRequestCriticalSection);
						for (int i = 0; i < data->waveMobsIDs.size(); i++){  // Останавливаем всех мобов
							CAIObject *aiObj = CGame::Instance().getAIObject(GAME_SCENE_MAIN, data->waveMobsIDs[i]);
							aiObj->stopMoving();
						}
						LeaveCriticalSection(&gameRequestCriticalSection);

						EnterCriticalSection(&crossroadsCriticalSection);

						EnterCriticalSection(&gameRequestCriticalSection);
						for (int i = 0; i < data->waveMobsIDs.size(); i++){  // Есть доступ к перекрёстку - возобновляем движение
							CAIObject *aiObj = CGame::Instance().getAIObject(GAME_SCENE_MAIN, data->waveMobsIDs[i]);
							aiObj->continueMoving();
						}
						LeaveCriticalSection(&gameRequestCriticalSection);
				}

				LeaveCriticalSection(&gameRequestCriticalSection);
				break;
			}
		}

		EnterCriticalSection(&gameRequestCriticalSection);

		CAIObject *lastMobAIobj = CGame::Instance().getAIObject(GAME_SCENE_MAIN, data->waveMobsIDs[data->waveMobsIDs.size()-1]);
		CAIObject *firstMobAIobj = CGame::Instance().getAIObject(GAME_SCENE_MAIN, data->waveMobsIDs[0]);

		LeaveCriticalSection(&gameRequestCriticalSection);


		while (onPath){
			if (lastMobAIobj->getNextMobFragID() < 0){
				onPath = false;
				LeaveCriticalSection(&crossroadsCriticalSection);
				switch(data->spawnNum){
				case 1:
					ReleaseSemaphore(hPath1Sem, 1, NULL);  
					break;
				case 2:
					ReleaseSemaphore(hPath2Sem, 1, NULL);  
					break;
				case 3:
					ReleaseSemaphore(hPath3Sem, 1, NULL);  
					break;
				}
			}
			GLint firstMobX = firstMobGrObj->getCoords().x;
			GLint firstMobY = firstMobGrObj->getCoords().y;
			// Рассчитываем так, чтобы останоовиться за клетку до перекрёстка
			/*EnterCriticalSection(&gameRequestCriticalSection);
			CAIObject *nextPath = CGame::Instance().getAIObject(GAME_SCENE_MAIN, firstMobAIobj->getNextMobFragID()); 
			LeaveCriticalSection(&gameRequestCriticalSection);*/
			//if (/*firstMobAIobj->getNextMobFragID() == crossroadsID*/ (firstMobGrObj->getCoords().x > crossroadsGrObj->getCoords().x - 10) && (firstMobGrObj->getCoords().y > crossroadsGrObj->getCoords().y - 10)){
			if(!entered &&
				(firstMobX > crossroadsX-offset) &&
				(firstMobY < crossroadsY+offset*2 && firstMobY > crossroadsY-offset*2) ){ // Попали в область перекрёстка

					entered = true;
					EnterCriticalSection(&gameRequestCriticalSection);
					for (int i = 0; i < data->waveMobsIDs.size(); i++){  // Останавливаем всех мобов
						CAIObject *aiObj = CGame::Instance().getAIObject(GAME_SCENE_MAIN, data->waveMobsIDs[i]);
						aiObj->stopMoving();
					}
					LeaveCriticalSection(&gameRequestCriticalSection);

					EnterCriticalSection(&crossroadsCriticalSection);

					EnterCriticalSection(&gameRequestCriticalSection);
					for (int i = 0; i < data->waveMobsIDs.size(); i++){  // Есть доступ к перекрёстку - возобновляем движение
						CAIObject *aiObj = CGame::Instance().getAIObject(GAME_SCENE_MAIN, data->waveMobsIDs[i]);
						aiObj->continueMoving();
					}
					LeaveCriticalSection(&gameRequestCriticalSection);
			}
		}
		break; 
	}

	return 0;
}

void initializeCritSectionsAndSemaphores(){
	InitializeCriticalSection(&gameRequestCriticalSection);
	InitializeCriticalSection(&inSpawn1CriticalSection);
	InitializeCriticalSection(&inSpawn2CriticalSection);
	InitializeCriticalSection(&inSpawn3CriticalSection);
	InitializeCriticalSection(&crossroadsCriticalSection);

	hPath1Sem = CreateSemaphore(NULL, 2, 2, NULL);
	hPath2Sem = CreateSemaphore(NULL, 1, 1, NULL);
	hPath3Sem = CreateSemaphore(NULL, 2, 2, NULL);
}