#pragma once

typedef struct POINT
{ 
	int x; 
	int y; 
};

class CGameObject
{
public:
	CGameObject(void);
	~CGameObject(void);
protected:
	int size;
	int hp;
	bool passable;
	int speed;
	POINT pos;
};