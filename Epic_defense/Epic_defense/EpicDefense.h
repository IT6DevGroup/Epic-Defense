#pragma once

#include <vector>
#include <algorithm>

#include "Game.h"

#define GAME_MIN_TREES 100
#define GAME_MAX_TREES 120

void addTrees(GLuint shaderProgram);
void addWallSpawnsPath(GLuint shaderProgram);