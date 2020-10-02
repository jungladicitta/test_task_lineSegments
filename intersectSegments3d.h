#pragma once

#include "vector3d.h"
#include "segment3d.h"

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
//Проверяет что все координаты v1 больше или равны координат v2
bool CheckBoundingBox(const Vector3D& v1, const Vector3D& v2);


//CheckCrossProducts
//Проверяет как лежат два отрезка относительно друг друга:
//лежат ли вершины отрезка seg2 по одну сторону от прямой проходящей через отрезок seg1
//возвращает true - если лежат по разные стороны
//					или если хотя бы одна из вершин лежит на самой прямой
//возвращает false - иначе
bool CheckCrossProducts(const Segment3D& seg1, const Segment3D& seg2);

//Intersect
//Функция находящая пересечение двух отрезков seg1 и seg2
//oVector - точка пересечения в случае если отрезки пересекаются в точке
//oSegment - отрезок пересечения в случае если отрезки пересекаются по отрезку
Result Intersect(const Segment3D& seg1, const Segment3D& seg2);
