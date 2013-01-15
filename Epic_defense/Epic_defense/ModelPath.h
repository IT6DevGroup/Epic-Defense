#pragma once

#include "ModelTemplate.h"

/*	��� ���� �� �����, �.�. ����� ������ - ������ �������

// ���� ������� ������ ��������������� ������� ���������� ���� ������� � TexturesNames � initTextures()
#define GAME_PATH_LR 0
#define GAME_PATH_BT 1
#define GAME_PATH_CROSS 2
#define GAME_PATH_TURN_BL 3
#define GAME_PATH_TURN_LT 4
*/

/*
������ �������� ��������� �������:
� ������� �������� ������ ���� ������������� (���������� ���� � ������� �������� �����) ���������� �� ��� ��������.
����� �������, ���� �������� �� ������ �������� � �������.
���� � ������� ������ ����� ��� ����� (���� �� ���� ��������� ����� ��� ������ ���������), �� ����� ��������� - �������
*/

class ModelPath: public ModelTemplate {
public:

	/*
	static const GLint width = 50;
	static const GLint height = 50;
	*/

	static const GLint width = 26;
	static const GLint height = 26;

	void initTextures(){
		/*
		TexturesNames.push_back("path_lr.tga");
		TexturesNames.push_back("path_bt.tga");
		TexturesNames.push_back("path_cross.tga");
		TexturesNames.push_back("path_turn_bl.tga");
		TexturesNames.push_back("path_turn_lt.tga");
		*/
		TexturesNames.push_back("path.tga");
	}
	void initGraphic(float posX, float posY, float zOffset = 0.0f){
		vcount = 6;
		initTextures();

		vertex v1 = {0.0f + posX, height + posY, -GAME_DEFAULT_GROUND_DISTANCE, 0.0f,  1.0f };
		this->vertices.info.push_back(v1);

		vertex v2 = { 0.0f + posX,  0.0f + posY, -GAME_DEFAULT_GROUND_DISTANCE, 0.0f, 0.0f };
		this->vertices.info.push_back(v2);

		vertex v3 = {width + posX, 0.0f + posY, -GAME_DEFAULT_GROUND_DISTANCE, 1.0f, 0.0f };
		this->vertices.info.push_back(v3);

		vertex v4 = {width + posX, 0.0f + posY, -GAME_DEFAULT_GROUND_DISTANCE, 1.0f, 0.0f};
		this->vertices.info.push_back(v4);

		vertex v5 = { width + posX,  height + posY, -GAME_DEFAULT_GROUND_DISTANCE, 1.0f, 1.0f };
		this->vertices.info.push_back(v5);

		vertex v6 = { 0.0f + posX, height + posY, -GAME_DEFAULT_GROUND_DISTANCE, 0.0f, 1.0f };
		this->vertices.info.push_back(v6);	
	}

	std::string getTextureName(/*GLint pathType*/){
		/*return TexturesNames[pathType];*/
		return TexturesNames[0];
	}

};