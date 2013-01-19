#include "EpicDefense.h"

#include <time.h>


struct tree {
	GLfloat x, y;
};
bool comp(tree a, tree b){
	return (a.y>b.y);
}
void addTrees(GLuint shaderProgram){
	struct heap{
		GLint treesCount;
		GLfloat sizeX, sizeY, x, y;
		tree *trees;
	};

	srand ( time(NULL) );
	// rand() % 10 + 1;
	GLint treesCount = rand() % (GAME_MAX_TREES - GAME_MIN_TREES) + GAME_MIN_TREES; // Генерируем количество деревьев
	GLint heapCount =  9;//treesCount/14;//rand() % ((GLint)treesCount/2) + 1; // Количество кучек деревьев
	heap *heaps = new heap [heapCount]; // Создаём массив кучек
	GLint treesCountDec = treesCount; // Это число будет уменьшаться с добавлением деревьев в кучу
	GLint tr = 0;
	GLfloat spawnOffset = GAME_PATHS_OFFSET;
	for (GLint i = 0; i < 3; i++){ // Располагаем кучки
		for (int j = 0; j < 3; j++){
			heaps[tr].sizeX = (GAME_DEFAULT_GROUND_SIZE - spawnOffset)/3;
			heaps[tr].sizeY = GAME_DEFAULT_GROUND_SIZE/3;
			heaps[tr].x = j * heaps[i].sizeX + spawnOffset;
			heaps[tr].y = i * heaps[i].sizeY;
			tr++;
		}
	}
	std::vector <GLint> heapIndexes;
	for (GLint i = 0; i < heapCount; i++){
		if (i != 5 && i != 3) // В шестом (но пятом от нуля) секторе у нас точка, куда идут мобы, а четвёртов (но третьем от нуля) у нас выход с перекрёстка
			heapIndexes.push_back(i);
	}
	while (heapIndexes.size()>0){
		GLint i, iVector;
		if (heapIndexes.size()>1)
			iVector = rand() % (heapIndexes.size() - 1);
		else 
			iVector = 0;

		i = heapIndexes[iVector];
		if (heapIndexes.size() > heapIndexes.size()/2)
			heaps[i].treesCount = rand() % treesCountDec/2;
		else
			heaps[i].treesCount = rand() % treesCountDec;
		if(heaps[i].treesCount > 0){
			treesCountDec -= heaps[i].treesCount;
			heaps[i].trees = new tree [heaps[i].treesCount]; // Массив с деревьями
			if (heaps[i].treesCount>1){
				std::vector <tree> treesVector;
				for (GLint k = 0; k < heaps[i].treesCount; k++){ // Назначили координаты
					heaps[i].trees[k].x = rand() % (GLint)(heaps[i].sizeX - ModelTree::getTreeSize()) + heaps[i].x;//heaps[i].x + c * ModelTree::getTreeSize();
					heaps[i].trees[k].y = rand() % (GLint)(heaps[i].sizeY - ModelTree::getTreeSize()) + heaps[i].y;//heaps[i].y + k * ModelTree::getTreeSize();
					treesVector.push_back(heaps[i].trees[k]);
				}
				std::sort(treesVector.begin(), treesVector.end(), comp);
				for (GLint k = 0; k < heaps[i].treesCount; k++){ // Рисуем сверху вниз
					CGlobalObject *treeAdd = new CGlobalObject(GAME_MODEL_TREE, shaderProgram, treesVector[k].x, treesVector[k].y);
					CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, treeAdd);
				}
			}
			else {
				heaps[i].trees[0].x = heaps[i].x + 10.0f;
				heaps[i].trees[0].y = heaps[i].y + 10.0f;
			}
		}

		GLint temp = heapIndexes[heapIndexes.size() - 1];
		heapIndexes[heapIndexes.size() - 1] = heapIndexes[iVector];
		heapIndexes[iVector] = temp;
		heapIndexes.pop_back();
	}
	/*for (GLint i = 0; i < heapCount; i++){
	if (treesCountDec > 0 && i!=5){ // В шестом (но пятом от нуля) секторе у нас точка, куда идут мобы
	if(i<4)
	heaps[i].treesCount = rand() % treesCountDec/2; // Берётся рандомной значение среди кол-ва деревьев
	else 
	heaps[i].treesCount = rand() % treesCountDec;
	if(heaps[i].treesCount > 0){
	treesCountDec -= heaps[i].treesCount;
	heaps[i].trees = new tree [heaps[i].treesCount]; // Массив с деревьями
	if (heaps[i].treesCount>1){
	std::vector <tree> treesVector;
	for (GLint k = 0; k < heaps[i].treesCount; k++){ // Назначили координаты
	heaps[i].trees[k].x = rand() % (GLint)(heaps[i].sizeX - ModelTree::getTreeSize()) + heaps[i].x;//heaps[i].x + c * ModelTree::getTreeSize();
	heaps[i].trees[k].y = rand() % (GLint)(heaps[i].sizeY - ModelTree::getTreeSize()) + heaps[i].y;//heaps[i].y + k * ModelTree::getTreeSize();
	treesVector.push_back(heaps[i].trees[k]);
	}
	std::sort(treesVector.begin(), treesVector.end(), comp);
	for (GLint k = 0; k < heaps[i].treesCount; k++){ // Рисуем сверху вниз
	CGlobalObject *treeAdd = new CGlobalObject(GAME_MODEL_TREE, shaderProgram, treesVector[k].x, treesVector[k].y);
	CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, treeAdd);
	}
	}
	else {
	heaps[i].trees[0].x = heaps[i].x + 10.0f;
	heaps[i].trees[0].y = heaps[i].y + 10.0f;
	}
	}
	}
	}*/
}

void addWallSpawnsPath(GLuint shaderProgram){
	struct pathFrag{
		GLint x, y;
		GLint nextID;
	};

	GLint spawnNum = 3; 
	GLint wallNum = GAME_DEFAULT_GROUND_SIZE / ModelWall::getHeight();
	GLint wallHeight = wallNum * ModelWall::getHeight() - spawnNum * ModelSpawn::getHeight();
	wallNum = wallHeight / ModelWall::getHeight();
	GLint objNum = wallNum + spawnNum; //+ 1; // +1 чтобы учесть оставшийся отрезок
	GLint oneWallPlot = objNum / spawnNum; // Длина одного участка стены

	if(spawnNum == 3){ // Дорожки могут быть только если у нас три спауна

		GLint pathNum = 1; // Номер по порядку той дороги, что сейчас добавляем. У второй дороги нет поворота, её конец - семафор
		GLint pathFragCount = GAME_PATHS_OFFSET / ModelPath::width; // Количество помещающихся дорог
		GLfloat correctingY = 25.0f; // Дороги нужно немного приподнять вверх, чтобы они были прямо напротив выхода спауна

		std::vector <pathFrag> path1;
		std::vector <pathFrag> path2;
		std::vector <pathFrag> path3;

		GLfloat firstSpawnY = 3 * ModelWall::getHeight();
		GLfloat secondSpawnY = 7 * ModelWall::getHeight();
		GLfloat thirdSpawnY = 11 * ModelWall::getHeight();
		for (int i = 0; i < objNum; i++){
			if (((i+1) % oneWallPlot) == 0){ // спаун
				CGlobalObject *spawn = new CGlobalObject(GAME_MODEL_SPAWN,shader_program,0.0f, i * ModelWall::getHeight());
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, spawn);
				if (pathNum != 2){ // Крайние дороги
					if (pathNum == 1){ // Первая дорога
						GLint fragFromBotCount =  (secondSpawnY - (firstSpawnY + ModelSpawn::height)) / ModelPath::height; // Количество дорог между спаунами, то есть кол-во дорог после поворота
						for (int p = 0; p < pathFragCount; p++){
							pathFrag frag;
							frag.x = ModelWall::getWidth() + p * ModelPath::width;
							frag.y = correctingY + i * ModelWall::getHeight(); // Координата Y текущего (в цикле) спауна
							path1.push_back(frag);
						}
						// Теперь дорога после поворота
						for (int p = 0; p < fragFromBotCount + 1; p++){ // +1  т.к. последняя дорога нефункционирующая, для красоты, чтобы не было зазора
							pathFrag frag;
							frag.x = ModelWall::getWidth() +  (pathFragCount - 1) * ModelPath::width; // Теперь у всех дорог одинаковый Х
							frag.y = correctingY + i * ModelWall::getHeight() + ModelPath::height + p * ModelPath::height; // Координата Y текущего (в цикле) спауна + высота уже имеющейся дороги + меняющийся Y
							path1.push_back(frag);
						}
						pathNum++;
					}
					else { // Вторая дорога
						GLint fragFromTopCount =  (thirdSpawnY - (secondSpawnY + ModelSpawn::height)) / ModelPath::height; // Количество дорог между спаунами, то есть кол-во дорог после поворота
						for (int p = 0; p < pathFragCount; p++){
							pathFrag frag;
							frag.x = ModelWall::getWidth() + p * ModelPath::width;
							frag.y = correctingY + i * ModelWall::getHeight(); // Координата Y (в цикле) спауна
							path3.push_back(frag);
						}
						// Теперь дорога после поворота
						for (int p = 0; p < fragFromTopCount + 1; p++){ // +1  т.к. последняя дорога нефункционирующая, для красоты, чтобы не было зазора
							pathFrag frag;
							frag.x = ModelWall::getWidth() +  (pathFragCount - 1) * ModelPath::width; // Теперь у всех дорог одинаковый Х
							frag.y = correctingY + i * ModelWall::getHeight() - ModelPath::height - p * ModelPath::height; // Координата Y текущего (в цикле) спауна МИНУС меняющийся Y
							path3.push_back(frag);
						}
						pathNum++;
					}
				} else { // Средняя дорога
					for (int p = 0; p < pathFragCount + 1; p++){ // +1  т.к. последняя дорога нефункционирующая, для красоты, чтобы был перекрёсток
						pathFrag frag;
						frag.x = ModelWall::getWidth() + p * ModelPath::width;
						frag.y = correctingY + i * ModelWall::getHeight(); // Координата Y (в цикле) спауна
						path2.push_back(frag);
					}
					pathNum++;
				}
				
			} else {
				CGlobalObject *wall = new CGlobalObject(GAME_MODEL_WALL,shader_program,0.0f, i * ModelSpawn::getHeight());
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, wall);
			}
		}
		// Вектора дорог готовы

		// Общее количество кусков дорог
		GLint totalPathsNum = path1.size() + path2.size() + path3.size();
		// Айди семафора
		GLint semaphoreID = CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) + (path1.size() - 1) + (path2.size() - 1);
		for (int i = 0; i < path1.size(); i++){
			if (i < path1.size()-1){
				CGlobalObject *pathFrag = new CGlobalObject(GAME_MODEL_PATH,shader_program,path1[i].x, path1[i].y, 0, CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) + 1); // Указывает на следующий квадрат
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, pathFrag);
			} else { // Последний кусок дорожки указывает на семафор
				CGlobalObject *pathFrag = new CGlobalObject(GAME_MODEL_PATH,shader_program,path1[i].x, path1[i].y, 0, semaphoreID); // Указывает на семафор
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, pathFrag);
			}
		}
		for (int i = 0; i < path2.size(); i++){
			if (i < path2.size()-1){
				CGlobalObject *pathFrag = new CGlobalObject(GAME_MODEL_PATH,shader_program,path2[i].x, path2[i].y, 0, CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) + 1);
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, pathFrag);
			} else { // Последний кусок дороги ни на что не указывает
				CGlobalObject *pathFrag = new CGlobalObject(GAME_MODEL_PATH,shader_program,path2[i].x, path2[i].y, 0, -1);
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, pathFrag);
			}
		}
		for (int i = 0; i < path3.size(); i++){
			if (i < path3.size()-1){ // До последнего куска дорожки
				CGlobalObject *pathFrag = new CGlobalObject(GAME_MODEL_PATH,shader_program,path3[i].x, path3[i].y, 0, CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) + 1); // Указывает на следующий квадрат
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, pathFrag);
			} else { // Последний кусок дорожки указывает на семафор
				CGlobalObject *pathFrag = new CGlobalObject(GAME_MODEL_PATH,shader_program,path3[i].x, path3[i].y, 0, semaphoreID); // Указывает на семафор
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, pathFrag);
			}
		}
		// Теперь увеличим значение входящих дорог у квадратов
		GLint c = CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN);
		for (int i = 0; i < totalPathsNum; i++){
			GLint globalID = CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) - 1 - totalPathsNum + i + 1; // -3 т.к. totalPathsNum = size() + size() + size()
			if (globalID != semaphoreID){ // Не семафор
				CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
				AIObject->increasePathFragInCount();
			} else { // Семафор
				CAIObject *AIObject = CGame::Instance().getAIObject(GAME_SCENE_MAIN, globalID);
				AIObject->increasePathFragInCount();
				AIObject->increasePathFragInCount();
				AIObject->increasePathFragInCount();
			}
		}
		GLint c2 = CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) - 1 - totalPathsNum + 1;
		CGlobalObject *goblin = new CGlobalObject(GAME_MODEL_GOBLIN, shader_program, 0.0f, 0.0f, 0, CGame::Instance().getObjectsCountOnScene(GAME_SCENE_MAIN) - 1 - totalPathsNum + 1);
		CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, goblin);
	} else { // Если указано больше трёх спаунов, дорог не будет
		CGame::Instance().DisablePaths();
		for (int i = 0; i < objNum; i++){
			if (((i+1) % oneWallPlot) == 0){ // Спаун
				CGlobalObject *spawn = new CGlobalObject(GAME_MODEL_SPAWN,shader_program,0.0f, i * ModelWall::getHeight());
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, spawn);
			} else { // Стена
				CGlobalObject *wall = new CGlobalObject(GAME_MODEL_WALL,shader_program,0.0f, i * ModelSpawn::getHeight());
				CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, wall);
			}
		}
	}
}

