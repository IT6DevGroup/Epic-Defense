#pragma once

/*
	AIHandler ����� ��� ��, �.�. �� ������ CAIObject �� �� ����� ������������ ��������� CGame:
	CAIObject ��������� � CGlobalObject, � ��� � CScene, � CScene ��������� � CGame,
	�, ����� �������, CAIObject �� ����� � ������������� CGame, � ������� ��� ����������,
	�.�. AI ������������ globalID (���������� ������� � ������� �������� �����)
*/

#include "Game.h"
#include "Mathematics.h"
#include "Threads.h"

void AIAction(GLint globalID);