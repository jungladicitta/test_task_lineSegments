#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Vector3D {
public:
	Vector3D() : X(0.0), Y(0.0), Z(0.0) {
	}
	Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {
	}

	double GetX() const {
		return X;
	}
	double GetY() const {
		return Y;
		}
	double GetZ() const {
		return Z;
	}

	//Длина вектора
	double GetLength() const;

private:
	double X;
	double Y;
	double Z;
};

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);

Vector3D operator*(double k, const Vector3D& v);

ostream& operator<<(ostream& os, const Vector3D& v);

//Считает векторное произведение
Vector3D CrossProduct(const Vector3D& lhs, const Vector3D& rhs);

//Считает скалярное произведение
double ScalarProduct(const Vector3D& lhs, const Vector3D& rhs);
