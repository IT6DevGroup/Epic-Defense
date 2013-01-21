#pragma once

#ifndef THREADS_H
#define THREADS_H
#endif


#include <windows.h>
#include <process.h>

#include "Game.h"

// ������� ��� ������ ����
unsigned __stdcall MobThread(void* pArguments);	
// ������� ��� ������ �����
unsigned __stdcall nextWaveThread(void* pArguments);	
void initializeCritSectionsAndSemaphores();

/*
// ������� ��� ������ ����
unsigned __stdcall MobThread(void* pArguments) {
	
	EnterCriticalSection(&gameRequestCriticalSection);

	CGlobalObject *goblin = new CGlobalObject(GAME_MODEL_GOBLIN, shader_program, 0.0f, 0.0f, 0, CGame::Instance().getPath1FirstFragID());
	CGame::Instance().addObjectToScene(GAME_SCENE_MAIN, goblin);

	LeaveCriticalSection(&gameRequestCriticalSection);
	return 0;
}

void initializeCriticalSections(){
	InitializeCriticalSection(&gameRequestCriticalSection);
	InitializeCriticalSection(&inSpawnCriticalSection);
}*/