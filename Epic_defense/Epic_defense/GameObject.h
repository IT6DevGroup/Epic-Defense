#pragma once

#include "Models.h"

class CGameObject
{
	// MESH - ������ ��������� ��� �������� ���� ����������� ������, ���������� �� ������
	struct GAME_MESH {
		GLshort speed;
		GLint health;
	};

	GAME_MESH mesh;

public:
	// specialParam ����� ��� ������� ������ ������� ��������� �������
	CGameObject(GLint model, GLint specialParam = 0);
	~CGameObject(void);
};

