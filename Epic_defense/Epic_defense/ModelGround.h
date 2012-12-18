#pragma once

#include "ModelTemplate.h"

class ModelGround: public ModelTemplate {
public:
	void initTextures(){
		ModelGround::TexturesNames.push_back("grass.tga");
	}
	void init(float posX, float posY){
		vcount = 150;
		initTextures();
		
		/*vertex v1 = {0.0f + posX, -100.0f + posY, -5.0f, 1.0f, 0.0f};
		this->vertices.info.push_back(v1);

		vertex v2 = { 100.0f + posX,  -100.0f + posY, -5.0f, 0.0f, 0.0f };
		this->vertices.info.push_back(v2);

		vertex v3 = { 100.0f + posX, 0.0f + posY, -5.0f, 0.0f, 1.0f };
		this->vertices.info.push_back(v3);	


		vertex v4 = { 100.0f + posX, 0.0f + posY, -5.0f, 0.0f,  1.0f };
		this->vertices.info.push_back(v4);

		vertex v5 = { 0.0f + posX,  0.0f + posY, -5.0f, 1.0f, 1.0f };
		this->vertices.info.push_back(v5);

		vertex v6 = {0.0f + posX, -100.0f + posY, -5.0f, 1.0f, 0.0f };
		this->vertices.info.push_back(v6);	
		*/

		float scale = GAME_DEFAULT_GROUND_SIZE / 5; // По пять квадратов
		
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				// верхний треугольник
				vertex	a = {(x + 1) * scale, y * scale, -GAME_DEFAULT_GROUND_DISTANCE, 1.0, 0.0};
				this->vertices.info.push_back (a);

				vertex	b = {x * scale, y * scale, -GAME_DEFAULT_GROUND_DISTANCE, 0.0, 0.0 };
				this->vertices.info.push_back (b);

				vertex	c = {x * scale, (y + 1) * scale, -GAME_DEFAULT_GROUND_DISTANCE, 0.0, 1.0};
				this->vertices.info.push_back (c);

				// нижний треугольник
				vertex	a1 = {x * scale, (y + 1) * scale, -GAME_DEFAULT_GROUND_DISTANCE, 0.0, 1.0};
				this->vertices.info.push_back (a1);

				vertex	b1 = {(x + 1) * scale, (y + 1) * scale, -GAME_DEFAULT_GROUND_DISTANCE, 1.0, 1.0};
				this->vertices.info.push_back (b1);

				vertex	c1 =  {(x + 1) * scale, y * scale, -GAME_DEFAULT_GROUND_DISTANCE, 1.0, 0.0 };
				this->vertices.info.push_back (c1);
			}
		}
	}
	// Получаем имя текстуры в зависимости от каких-либо возможных условий
	std::string getTextureName(/* Какие-либо условия */){
		return TexturesNames[0];
	}
};