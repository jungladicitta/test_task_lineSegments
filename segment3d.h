#pragma once

#include "vector3d.h"
#include "context.h"

using namespace std;

class Segment3D {
public:
	Segment3D();
	Segment3D(Vector3D s, Vector3D e, Context context);

	const Vector3D& GetStart() const {
		return start;
	}
	const Vector3D& GetEnd() const {
		return end;
	}

private:
	Vector3D start;
	Vector3D end;
};

ostream& operator<<(ostream& os, const Segment3D& seg);
