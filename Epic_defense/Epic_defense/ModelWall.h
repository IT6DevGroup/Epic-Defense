#pragma once

#include "ModelTemplate.h"

class ModelWall: public ModelTemplate {
	static const GLint sizeX = 33;
	static const GLint sizeY = 80;
public:
	static GLfloat getHeight(){
		return ModelWall::sizeY;
	}
	static GLfloat getWidth(){
		return ModelWall::sizeX;
	}
	void initTextures(){
		TexturesNames.push_back("wall.tga");
	}
	void initGraphic(float posX, float posY){
		vcount = 6;
		initTextures();

		vertex v1 = { sizeX + posX, 0.0f + posY, -GAME_DEFAULT_GROUND_DISTANCE, 1.0f,  0.0f };
		this->vertices.info.push_back(v1);

		vertex v2 = { 0.0f + posX,  0.0f + posY, -GAME_DEFAULT_GROUND_DISTANCE, 0.0f, 0.0f };
		this->vertices.info.push_back(v2);

		vertex v3 = {0.0f + posX, sizeY + posY, -GAME_DEFAULT_GROUND_DISTANCE, 0.0f, 1.0f };
		this->vertices.info.push_back(v3);


		vertex v4 = {0.0f + posX, sizeY + posY, -GAME_DEFAULT_GROUND_DISTANCE, 0.0f, 1.0f};
		this->vertices.info.push_back(v4);

		vertex v5 = { sizeX + posX,  sizeY + posY, -GAME_DEFAULT_GROUND_DISTANCE, 1.0f, 1.0f };
		this->vertices.info.push_back(v5);

		vertex v6 = { sizeX + posX, 0.0f + posY, -GAME_DEFAULT_GROUND_DISTANCE, 1.0f, 0.0f };
		this->vertices.info.push_back(v6);	


	}

	std::string getTextureName(){
		return TexturesNames[0];
	}
};