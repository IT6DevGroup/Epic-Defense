#pragma once

#include "Models.h"

class CGameObject
{
	// MESH - особая структура для хранения всех необходимых данных, полученных из модели
	struct GAME_MESH {

	};

	GAME_MESH mesh;

public:
	// specialParam нужен для задания особых условий некоторым моделям
	CGameObject(GLint model, GLint specialParam = 0);
	~CGameObject(void);
};

