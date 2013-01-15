#pragma once

#include <vector>
#include <algorithm>

#include "Game.h"

#define GAME_MIN_TREES 100
#define GAME_MAX_TREES 120

#define GAME_PATHS_OFFSET 200 // Отступ после спаунов, где будут дороги

void addTrees(GLuint shaderProgram);
void addWallSpawnsPath(GLuint shaderProgram);