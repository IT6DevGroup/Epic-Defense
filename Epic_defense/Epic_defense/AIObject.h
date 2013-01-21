#pragma once

#include "GraphicObject.h"
#include "PhysicObject.h"
#include "GameObject.h"
#include "SoundObject.h"

#include "Models.h"

class CAIObject
{
	// MESH - особа€ структура дл€ хранени€ всех необходимых данных, полученных из модели
	struct AI_MESH {
		GLint model; 
		POINT p; //  оордината
		bool moving;
	};
		
	// ƒл€ куска дороги нужен особый меш, чтобы опредл€ть количество вход€щих дорог и следующий кусок
	struct PATH_FRAG_MESH {
		//  оличество указывающих на этот квадрат квадратов
		GLint inCount;
		// јйди следующего квадрата. ≈сли равен -1, то дорога заканчиваетс€
		GLint nextFragID;
	};

	// ” моба есть айдишник следующей дороги. ≈сли равен -1, то дороги нет
	struct MOB_MESH {
		GLint nextFragID;
		bool onPoint;
		POINT toPoint;
	};

	AI_MESH mesh;
	PATH_FRAG_MESH pathFragMesh;
	MOB_MESH mobMesh;

public:
	CAIObject(GLint model, GLfloat x, GLfloat y, GLint specialParam = 0);
	~CAIObject(void);

	void initPath();
	POINT action(POINT p, CGraphicObject *grObj);

	bool getMoving();
	bool getMobOnPoint();
	GLint getNextMobFragID();
	GLint getNextPathFragID();
	GLint getModelName();

	void setToPoint(POINT p);
	void setOnPointOn();
	void setOnPointOff();
	void setNextMobFragID(GLint globalID);
	void stopMoving();
	void continueMoving();
	// ”величивает количество вход€щих дорог у квадрата на единицу
	void increasePathFragInCount();

	void goToPoint();
};