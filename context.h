#pragma once
#include <cmath>

struct Context {
	double precision;
	Context(double precision_) : precision(precision_) {}
	bool EqualToZero(double x) const {
		return fabs(x) <= precision;
	}
};
