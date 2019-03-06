#include "segment3d.h"
#include "vector3d.h"
#include "context.h"
#include <stdexcept>

Segment3D::Segment3D() {
	start = Vector3D();
	end = Vector3D();
}

Segment3D::Segment3D(Vector3D s, Vector3D e, Context context) {
	if ((s-e).GetLength() <= context.precision) throw invalid_argument("");
	else {
		start = s;
		end = e;
	}
}

ostream& operator<<(ostream& os, const Segment3D& seg) {
	os << "Start: " << seg.GetStart() << "; End: " << seg.GetEnd();
	return os;
}
