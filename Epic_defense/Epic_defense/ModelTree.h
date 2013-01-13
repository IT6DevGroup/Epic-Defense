#pragma once

#include "ModelTemplate.h"

class ModelTree: public ModelTemplate {
	// Эту переменную следует заменить на новые width и height с соответствующими изменениями в addTrees()
	static const GLint TreeSize = 70;
public:
	void initTextures(){
		TexturesNames.push_back("tree.tga");
	}
	void initGraphic(float posX, float posY, float zOffset = 0.0f){
		vcount = 6;
		initTextures();

		GLfloat distance = GAME_DEFAULT_GROUND_DISTANCE;//- 1.0f;
		
		vertex v1 = { TreeSize + posX, 0.0f + posY, -distance - zOffset, 1.0f,  0.0f };
		this->vertices.info.push_back(v1);

		vertex v2 = { 0.0f + posX,  0.0f + posY, -distance - zOffset, 0.0f, 0.0f };
		this->vertices.info.push_back(v2);

		vertex v3 = {0.0f + posX, TreeSize + posY, -distance - zOffset, 0.0f, 1.0f };
		this->vertices.info.push_back(v3);	

		vertex v4 = {0.0f + posX, TreeSize + posY, -distance - zOffset, 0.0f, 1.0f};
		this->vertices.info.push_back(v4);

		vertex v5 = { TreeSize + posX,  TreeSize + posY, -distance - zOffset, 1.0f, 1.0f };
		this->vertices.info.push_back(v5);

		vertex v6 = { TreeSize + posX, 0.0f + posY, -distance - zOffset, 1.0f, 0.0f };
		this->vertices.info.push_back(v6);	

		
	}

	std::string getTextureName(){
		return TexturesNames[0];
	}

	static GLint getTreeSize(){
		return TreeSize;
	}
};