#include "Mathematics.h"

POINT divisionStraightWithRatio(POINT A, POINT B, GLint distance){
	// �������, ��� AB - ����������, C - ����� � ������ �����
	GLfloat AC, BC;
	POINT M; // �����, ������� ��������� �����
	// ������� ������
	if (B.x > A.x){
		AC = B.x - A.x;
	} else {
		AC = A.x - B.x;
	}
	if (B.y > A.y) {
		BC = B.y - A.y;
	} else {
		BC = A.y - B.y;
	}
	GLfloat AB = sqrt(AC*AC + BC*BC);
	GLfloat AM = distance;
	GLfloat MB = AB - AM;
	GLfloat ratio = AM / MB;
	//float ratio = AM / MB;
	//float ratio = 0.038910;
	M.x = (A.x + ratio * B.x) / (1 + ratio); // ���� ����� �������
	M.y = (A.y + ratio * B.y) / (1 + ratio);

	if (AM < MB) // ���� ������ ���������� ������ ���������� �� B ������
		return M;
	else
		return B;
}