#pragma once

#include <vector>
#include <string>

#define GAME_MODEL_TRIANGLE 1
#define GAME_MODEL_GROUND 2
#define GAME_MODEL_TREE 3
#define GAME_MODEL_SPAWN 4
#define GAME_MODEL_WALL 5
#define GAME_MODEL_GOBLIN 6

#define GAME_DEFAULT_GROUND_DISTANCE 10.0f
#define GAME_DEFAULT_GROUND_SIZE 1125.0f

// Шаблон для создания VBO со всей необходимой информацией
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

class ModelTemplate {
protected:
	int vcount; // Кол-во вершин
	int icount; // Кол-во индексов
	std::vector <std::string> TexturesNames; // Текстур может быть несколько: например, если требуется учитывать поворот персонажа (в 2D)
	VBOdata <vertex> vertices; 
public:
	//std::vector <vertex> verts;

	ModelTemplate(){
		vertices.dataSize = sizeof(vertex);
	}

	void init();
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
	std::string getTextureName(/* Какие-либо условия */);
};