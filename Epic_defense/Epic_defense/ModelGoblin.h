#pragma once

#include "ModelTemplate.h"

class ModelGoblin: public ModelTemplate {

public:

	static const GLint vcount = 6;

	static const GLint width = 13;
	static const GLint height = 23;

	static const bool moving = true;
	static const GLshort speed = 3; // —корость от 0 до 10

	static const GLint health = 100;

	void initTextures(){
		TexturesNames.push_back("goblin.tga");
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