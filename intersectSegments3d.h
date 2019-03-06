#pragma once

#include "vector3d.h"
#include "segment3d.h"
#include "context.h"

enum TypeOfIntersection {
	NotIntersected = 0,
	IntersectedInPoint = 1,
	IntersectedInSegment = 2,
};

struct Result {
	TypeOfIntersection type;
	Vector3D point;
	Segment3D lineSegment;

	void SetResult(TypeOfIntersection type_, const Vector3D& point_, const Segment3D& lineSegment_);
};

double Determinant(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3);

//CheckBoundingBox
//��������� ��� ��� ���������� v1 ������ ��� ����� ��������� v2
bool CheckBoundingBox(const Vector3D& v1, const Vector3D& v2);


//CheckCrossProducts
//��������� ��� ����� ��� ������� ������������ ���� �����:
//����� �� ������� ������� seg2 �� ���� ������� �� ������ ���������� ����� ������� seg1
//���������� true - ���� ����� �� ������ �������
//					��� ���� ���� �� ���� �� ������ ����� �� ����� ������
//���������� false - �����
bool CheckCrossProducts(const Segment3D& seg1, const Segment3D& seg2, const Context& context);

//Intersect
//������� ��������� ����������� ���� �������� seg1 � seg2
//oVector - ����� ����������� � ������ ���� ������� ������������ � �����
//oSegment - ������� ����������� � ������ ���� ������� ������������ �� �������
Result Intersect(const Segment3D& seg1, const Segment3D& seg2, const Context& context);
