#include "matrix.h"

// Возвращает единичную матрицу
void	GetIdentityMatrix (GLfloat *matrix)
{
	matrix[0]	= 1.0f;
	matrix[1]	= 0.0f;
	matrix[2]	= 0.0f;
	matrix[3]	= 0.0f;

	matrix[4]	= 0.0f;
	matrix[5]	= 1.0f;
	matrix[6]	= 0.0f;
	matrix[7]	= 0.0f;

	matrix[8]	= 0.0f;
	matrix[9]	= 0.0f;
	matrix[10]	= 1.0f;
	matrix[11]	= 0.0f;

	matrix[12]	= 0.0f;
	matrix[13]	= 0.0f;
	matrix[14]	= 0.0f;
	matrix[15]	= 1.0f;
}

// Возвращает матрицу перспективной проекции
void	GetPerspectiveProjectionMatrix (float fovAngle, float aspect, float nearPlane, float farPlane, GLfloat *matrix)
{
	float	top		= nearPlane * tanf (DEG2RAD(fovAngle / 2.0f));
	float	right	= top * aspect;
	float	bottom	= - top;
	float	left	= - right;

	matrix[0]	= 2 * nearPlane / (right - left);
	matrix[1]	= 0.0f;
	matrix[2]	= (right + left) / (right - left);
	matrix[3]	= 0.0f;

	matrix[4]	= 0.0f;
	matrix[5]	= 2 * nearPlane / (top - bottom);
	matrix[6]	= (top + bottom) / (top - bottom);
	matrix[7]	= 0.0f;

	matrix[8]	= 0.0f;
	matrix[9]	= 0.0f;
	matrix[10]	= -(farPlane + nearPlane) / (farPlane - nearPlane);
	matrix[11]	= -2 * (farPlane * nearPlane) / (farPlane - nearPlane);

	matrix[12]	= 0.0f;
	matrix[13]	= 0.0f;
	matrix[14]	= -1.0f;
	matrix[15]	= 0.0f;
}

// Возвращает матрицу ортографической проекции
void	GetOrthogonalProjectionMatrix (float left, float right, float top, float bottom, float nearPlane, float farPlane, GLfloat *matrix)
{
	matrix[0]	= 2 / (right - left);
	matrix[1]	= 0.0f;
	matrix[2]	= 0.0f;
	matrix[3]	= (right + left) / (right - left);

	matrix[4]	= 0.0f;
	matrix[5]	= 2 / (top - bottom);
	matrix[6]	= 0.0f;
	matrix[7]	= (top + bottom) / (top - bottom);

	matrix[8]	= 0.0f;
	matrix[9]	= 0.0f;
	matrix[10]	= -2 / (farPlane - nearPlane);
	matrix[11]	= -(farPlane + nearPlane) / (farPlane - nearPlane);

	matrix[12]	= 0.0f;
	matrix[13]	= 0.0f;
	matrix[14]	= 0.0f;
	matrix[15]	= 1.0f;
}	