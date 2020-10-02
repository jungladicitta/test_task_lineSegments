#include "segment3d.h"
#include "vector3d.h"
#include <stdexcept>

Segment3D::Segment3D() {
	start = Vector3D();
	end = Vector3D();
}

Segment3D::Segment3D(Vector3D s, Vector3D e) {
	if ((s-e).GetLength() <= 0.0) throw invalid_argument("");
	else {
		start = s;
		end = e;
	}
}

ostream& operator<<(ostream& os, const Segment3D& seg) {
	os << "Start: " << seg.GetStart() << "; End: " << seg.GetEnd();
	return os;
}
