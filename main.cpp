#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#include "vector3d.h"
#include "segment3d.h"
#include "intersectSegments3d.h"
#include "context.h"
#include "test_runner.h"
#include "tests.h"

using namespace std;

int main() {
	TestRunner tr;
	RUN_TEST(tr, Test_all);


	return 0;
}
