#pragma once


#include "ModelTemplate.h"

class ModelSpawn: public ModelTemplate {
	static const GLint sizeX = 33;
	static const GLint sizeY = 80;
public:
	static const GLint vcount = 6;

	static GLfloat getHeight(){
		return ModelSpawn::sizeY;
	}
	void initTextures(){
		TexturesNames.push_back("spawn.tga");
	}
	void initGraphic(float posX, float posY){
		initTextures();

		/*vertex v1 = {0.0f + posX, -sizeY + posY, -5.0f, 1.0f, 0.0f};
		this->vertices.info.push_back(v1);

		vertex v2 = { sizeX + posX,  -sizeY + posY, -5.0f, 0.0f, 0.0f };
		this->vertices.info.push_back(v2);

		vertex v3 = { sizeX + posX, 0.0f + posY, -5.0f, 0.0f, 1.0f };
		this->vertices.info.push_back(v3);	


		vertex v4 = { sizeX + posX, 0.0f + posY, -5.0f, 0.0f,  1.0f };
		this->vertices.info.push_back(v4);

		vertex v5 = { 0.0f + posX,  0.0f + posY, -5.0f, 1.0f, 1.0f };
		this->vertices.info.push_back(v5);

		vertex v6 = {0.0f + posX, -sizeY + posY, -5.0f, 1.0f, 0.0f };
		this->vertices.info.push_back(v6);	*/

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