#ifndef MATRIX_H
#define MATRIX_H

#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/gl.h>

#include <math.h>

#include "defines.h"

void	GetIdentityMatrix (GLfloat *matrix);
void	GetPerspectiveProjectionMatrix (float fovAngle, float aspect, float nearPlane, float farPlane, GLfloat *matrix);
void	GetOrthogonalProjectionMatrix (float left, float right, float top, float bottom, float nearPlane, float farPlane, GLfloat *matrix);


#endif