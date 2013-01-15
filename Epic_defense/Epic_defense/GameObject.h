#pragma once

#include "Models.h"

class CGameObject
{
	// MESH - ������ ��������� ��� �������� ���� ����������� ������, ���������� �� ������
	struct GAME_MESH {

	};

	// ��� ����� ������ ����� ������ ���, ����� ��������� ���������� �������� ����� � ��������� �����
	struct PATH_FRAG_MESH{
		GLint inCount, nextFragID;
	};

	GAME_MESH mesh;
	PATH_FRAG_MESH pathFragMesh;

public:
	// specialParam ����� ��� ������� ������ ������� ��������� �������
	CGameObject(GLint model, GLint specialParam = 0);
	~CGameObject(void);

	// ����������� ���������� �������� ����� � �������� � �������
	void increasePathFragInCount(GLint globalID);
};

