#pragma once

#include "ModelTemplate.h"

class TriangleModel: public ModelTemplate {	
public:
	void init(float posX, float posY){
		vcount = 3;

		//VBOdata <vertex> vertices;

		//vertex v1 = {/* положение */ -1.0f + posX, -1.0f + posY, -2.0f,/* цвет */ 1.0f, 0.0f, 0.0f };
		//this->vertices.info.push_back(v1);

		//vertex v2 = { 0.0f + posX,  2.0f + posY, -2.0f, 0.0f, 1.0f, 0.0f };
		//this->vertices.info.push_back(v2);

		//vertex v3 = { 1.0f + posX, -1.0f + posY, -2.0f, 0.0f, 0.0f, 1.0f };
		//this->vertices.info.push_back(v3);	

		// Этот класс с этим конструктором в любом случае нужен, т.к. он будет расширен для назначения текстур и прочего
	}
};



// индексы
/*
const uint32_t indices[icount] = {
	 0, 3, 1,  1, 3, 2, // front
	 4, 7, 5,  5, 7, 6, // back
	 8,11, 9,  9,11,10, // top
	12,15,13, 13,15,14, // bottom
	16,19,17, 17,19,18, // left
	20,23,21, 21,23,22  // right
};
*/