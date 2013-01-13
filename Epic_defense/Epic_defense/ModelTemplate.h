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

// �������� VBO ����� ���� ���������. VBOdata - ������ ��� �������� VBO �� ���� ����������� �����������
template <class InfoType>
struct VBOdata {
	GLsizeiptr dataSize;
	std::vector <InfoType> info;
};

// � ����� ������ ���� ����� ������. ������ �������� ��������� ����� ������������� � ����� ������, ���� ����������
struct vertex
{
	float x, y, z; // �������
	float u, v; // ���������� ��������
	//float r, g ,b; // ����
};

// ModelTemplate ��������� ��� ������� ���������� ������� �� ���������, ����� ��� ��� ���� ��������������� ����� ��������
class ModelTemplate {
protected:
	int vcount; // ���-�� ������
	int icount; // ���-�� �������� (������ �� ������������)
	std::vector <std::string> TexturesNames; // ������� ����� ���� ���������: ��������, ���� ��������� ��������� ������� ��������� (� 2D)
	VBOdata <vertex> vertices; 

public:

	// �������� ��� ������� �� ���������

	// ������/������ �������� � ��������
	static const GLint width = 10;
	static const GLint height = 10;

	static const bool moving = false;
	// �������� �� 0 �� 10
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
	// ����� getTextureName ����� ��� ����������� ��������� ��������� ������� ��� �����-���� ������ ���������������
	std::string getTextureName(/* �����-���� ������� */);
};