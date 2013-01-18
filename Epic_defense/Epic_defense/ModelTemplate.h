#pragma once

#include <vector>
#include <string>

#define GAME_MODEL_TRIANGLE 1
#define GAME_MODEL_GROUND 2
#define GAME_MODEL_TREE 3
#define GAME_MODEL_SPAWN 4
#define GAME_MODEL_WALL 5
#define GAME_MODEL_GOBLIN 6
#define GAME_MODEL_PATH 7

#define GAME_DEFAULT_GROUND_DISTANCE 10.0f
#define GAME_DEFAULT_GROUND_SIZE 1120.0f

/*
КАК ДОБАВИТЬ МОДЕЛЬ

В файле ModelTemplate создаём макрос с условным именем модели. То есть, например, GAME_MODEL_GROUND
Далее нужно создать класс модели (с приставкой Model), унаследованный от ModelTemplate.
Проставив в нём нужные данные, необходимо добавить в конструкторе CGraphicObject в switch(model) новый case с добавленным макросом
и выполнить в нём все нужны функции. Сейчас можно просто скопировать любой другой case и поменять названия классов и переменных.

Далее в функции класса CGraphicObject DrawParamsSet() добавляем такой же case, как в конструкторе, содержимое которого тоже будет таким же,
как у других кейзов этой функции, только с другими названиями (см. DrawParamsSet())

Текстуру обязательно надо добавить в фунцкции CGame::LoadTextures()

Всё, можно писать addObjectToScene нового объекта в main.cpp

Этот процесс распространяется и на другие файлы объектов. Такие же свитчи находятся в конструкторах GraphicObject, AIObject, GameObject. Остальные пока не используются.
*/

// Буфферов VBO может быть несколько. VBOdata - шаблон для создания VBO со всей необходимой информацией
template <class InfoType>
struct VBOdata {
	GLsizeiptr dataSize;
	std::vector <InfoType> info;
};

// У любой модели есть набор вершин. Другие подобные структуры могут опеределяться в самой модели, если необходимо
struct vertex
{
	float x, y, z; // позиция
	float u, v; // координаты текстуры
	//float r, g ,b; // цвет
};

// ModelTemplate необходим для задания параметров моделей по умолчанию, чтобы все они были разновидностями одной сущности
class ModelTemplate {
protected:
	int vcount; // Кол-во вершин
	int icount; // Кол-во индексов (сейчас не используется)
	std::vector <std::string> TexturesNames; // Текстур может быть несколько: например, если требуется учитывать поворот персонажа (в 2D)
	VBOdata <vertex> vertices; 

public:

	// Значения для моделей по умолчанию

	// Ширина/высота картинки в пикселях
	static const GLint width = 10;
	static const GLint height = 10;

	static const bool moving = false;
	// Скорость от 0 до 10
	static const GLint speed = 1;

	static const GLint health = 100;

	ModelTemplate(){
		vertices.dataSize = sizeof(vertex);
	}

	void initGraphic();
	void initTextures();

	std::vector <vertex> getVerticesList(){
		return vertices.info;
	}

	GLsizeiptr getVertexSize(){
		return sizeof(vertex);
	}
	int getVerticesCount(){
		return vcount;
	}

	// Метод getTextureName нужен для возможности получения различных текстур при каких-либо особых обстоятельствах
	std::string getTextureName(/* Какие-либо условия */);
};