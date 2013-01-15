#pragma once

#include "Models.h"

class CGameObject
{
	// MESH - особая структура для хранения всех необходимых данных, полученных из модели
	struct GAME_MESH {

	};

	// Для куска дороги нужен особый меш, чтобы опредлять количество входящих дорог и следующий кусок
	struct PATH_FRAG_MESH{
		GLint inCount, nextFragID;
	};

	GAME_MESH mesh;
	PATH_FRAG_MESH pathFragMesh;

public:
	// specialParam нужен для задания особых условий некоторым моделям
	CGameObject(GLint model, GLint specialParam = 0);
	~CGameObject(void);

	// Увеличивает количество входящих дорог у квадрата в единицу
	void increasePathFragInCount(GLint globalID);
};

