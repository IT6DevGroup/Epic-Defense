#pragma once

#include "ModelTemplate.h"

class ModelCastle: public ModelTemplate {

public:

	static const GLint vcount = 6;

	static const GLint width = 159;
	static const GLint height = 142;

	static const GLint health = 1000;

	void initTextures(){
		TexturesNames.push_back("castle.tga");
	}
	void initGraphic(float posX, float posY, float zOffset = 0.0f){
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

	std::string getTextureName(){
		return TexturesNames[0];
	}

};