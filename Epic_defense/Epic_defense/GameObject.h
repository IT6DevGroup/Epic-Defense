#pragma once

#include "Models.h"

class CGameObject
{
	// MESH - ������ ��������� ��� �������� ���� ����������� ������, ���������� �� ������
	struct GAME_MESH {

	};

	GAME_MESH mesh;

public:
	// specialParam ����� ��� ������� ������ ������� ��������� �������
	CGameObject(GLint model, GLint specialParam = 0);
	~CGameObject(void);
};

