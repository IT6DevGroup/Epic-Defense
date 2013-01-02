#pragma once

#include "Models.h"

class CAIObject
{
	struct AIMESH {
		GLint model;
		POINT p;
		bool moving;
	};
	AIMESH mesh;
public:
	CAIObject(GLint model, GLfloat x, GLfloat y);
	~CAIObject(void);

	void initPath();
	POINT nextStep(POINT p);

	bool getMoving();
};