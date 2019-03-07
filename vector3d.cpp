#include "vector3d.h"

double Vector3D::GetLength() const {
	return pow(X*X + Y*Y + Z*Z, 0.5);
};

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs) {
	return Vector3D(lhs.GetX()-rhs.GetX(), lhs.GetY()-rhs.GetY(), lhs.GetZ()-rhs.GetZ());
}

Vector3D operator*(double k, const Vector3D& v) {
	return Vector3D(v.GetX()*k, v.GetY()*k, v.GetZ()*k);
}

ostream& operator<<(ostream& os, const Vector3D& v) {
	os << '(' << v.GetX() << ',' << v.GetY() << ',' << v.GetZ() << ')';
	return os;
}

//Считает векторное произведение
Vector3D CrossProduct(const Vector3D& lhs, const Vector3D& rhs) {
	return Vector3D(lhs.GetY()*rhs.GetZ() - lhs.GetZ()*rhs.GetY(),
					-lhs.GetX()*rhs.GetZ() + lhs.GetZ()*rhs.GetX(),
					lhs.GetX()*rhs.GetY() - lhs.GetY()*rhs.GetX()
					);
}

//Считает скалярное произведение
double ScalarProduct(const Vector3D& lhs, const Vector3D& rhs) {
	return lhs.GetX()*rhs.GetX() + lhs.GetY()*rhs.GetY() + lhs.GetZ()*rhs.GetZ();
}
