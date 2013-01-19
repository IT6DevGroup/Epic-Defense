#pragma once

/*
	AIHandler нужен для ИИ, т.к. из класса CAIObject мы не можем пользоваться функциями CGame
	CAIObject подключён к CGlobalObject, а тот к CScene, и CScene подключён к CGame,
	и, таким образом, CAIObject не знает о существовании CGame, а функции эти необходимы,
	т.к. AI манипулирует globalID (айдишником объекта в векторе объектов сцены)
*/

#include "Game.h"
#include "Mathematics.h"

void AIAction(GLint globalID);