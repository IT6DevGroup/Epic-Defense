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
	GLint heapCount =  9;//treesCount/14;//rand() % ((GLint)treesCount/2) + 1; // Генерируем количество кучек деревьев
	heap *heaps = new heap [heapCount]; // Создаём массив кучек
	GLint treesCountDec = treesCount; // Это число будет уменьшаться с добавлением деревьев в кучу
	GLint tr = 0;
	GLfloat spawnOffset = 200.0f;
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
		if (i != 5) // В шестом (но пятом от нуля) секторе у нас точка, куда идут мобы
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

void addWallAndSpawns(GLuint shaderProgram){
	GLint spawnNum = 4;
	GLint wallNum = GAME_DEFAULT_GROUND_SIZE / ModelWall::getHeight();
	GLint wallHeight = wallNum * ModelWall::getHeight() - spawnNum * ModelSpawn::getHeight();
	wallNum = wallHeight / ModelWall::getHeight();
	GLint objNum = wallNum + spawnNum ;//+ 1; // +1 чтобы учесть оставшийся отрезок
	for (int i = 0; i < objNum; i++){
		if ((i % spawnNum) == 0){
			CGlobalObject *spawn = new CGlobalObject(GAME_MODEL_SPAWN,shader_program,0.0f, i * ModelWall::getHeight());
			CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, spawn);
		} else {
			CGlobalObject *wall = new CGlobalObject(GAME_MODEL_WALL,shader_program,0.0f, i * ModelSpawn::getHeight());
			CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, wall);
		}
	}
}