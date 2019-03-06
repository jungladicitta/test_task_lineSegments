#pragma once

#include "test_runner.h"
#include "intersectSegments3d.h"
#include "vector3d.h"

void Test_simply_intersected() {
	auto context = Context(0.000001);
	auto result1 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0),    Vector3D(2.0,2.0,2.0),    context),
							 Segment3D(Vector3D(1.0,1.0,2.3456), Vector3D(2.0,2.0,1.9876), context),
							 context );
	auto result2 = Intersect(Segment3D(Vector3D(1.0,1.0,2.3456),Vector3D(2.0,2.0,1.9876), context),
							 Segment3D(Vector3D(1.0,1.0,1.0),   Vector3D(2.0,2.0,2.0),    context),
							 context );
	auto result3 = Intersect(Segment3D(Vector3D(1.0,1.0,2.3456),Vector3D(2.0,2.0,1.9876), context),
							 Segment3D(Vector3D(2.0,2.0,2.0),   Vector3D(1.0,1.0,1.0),    context),
							 context );
	ASSERT_EQUAL(result1.type, TypeOfIntersection::IntersectedInPoint);
	ASSERT_EQUAL(result2.type, TypeOfIntersection::IntersectedInPoint);
	ASSERT_EQUAL(result3.type, TypeOfIntersection::IntersectedInPoint);

	auto result4 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0),    Vector3D(3.0,3.0,3.0),    context),
			 	 	 	 	 Segment3D(Vector3D(2.0,1.0,2.0), 	 Vector3D(2.0,3.0,2.0),    context),
							 context );
	ASSERT_EQUAL(result4.point.GetX(),2.0);
	ASSERT_EQUAL(result4.point.GetY(),2.0);
	ASSERT_EQUAL(result4.point.GetZ(),2.0);
}

void Test_intersected_in_segment() {
	auto context = Context(0.000001);
	auto result1 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(0.1234,1.2345,2.3456), context),
							 Segment3D(Vector3D(0.1234,1.2345,2.3456), Vector3D(1.0,1.0,1.0), context),
							 context );
	auto result2 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(3.0,3.0,3.0), context),
							 Segment3D(Vector3D(2.0,2.0,2.0), Vector3D(3.0,3.0,3.0), context),
							 context );
	auto result3 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(3.0,3.0,3.0), context),
							 Segment3D(Vector3D(2.0,2.0,2.0), Vector3D(4.0,4.0,4.0), context),
							 context );
	ASSERT_EQUAL(result1.type, TypeOfIntersection::IntersectedInSegment);
	ASSERT_EQUAL(result2.type, TypeOfIntersection::IntersectedInSegment);
	ASSERT_EQUAL(result3.type, TypeOfIntersection::IntersectedInSegment);
}

void Test_intersected_in_vertex() {
	auto context = Context(0.000001);
	auto result1 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(0.1234,1.2345,2.3456), context),
							 Segment3D(Vector3D(0.1234,1.2345,2.3456), Vector3D(3.0,3.0,3.0), context),
							 context );
	auto result2 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(0.1234,1.2345,2.3456), context),
								 Segment3D(Vector3D(0.1234,1.2345,2.3456), Vector3D(3.0,4.0,5.0), context),
								 context );
	ASSERT_EQUAL(result1.point.GetX(), 0.1234);
	ASSERT_EQUAL(result1.point.GetY(), 1.2345);
	ASSERT_EQUAL(result1.point.GetZ(), 2.3456);

	ASSERT_EQUAL(result2.point.GetX(), 0.1234);
	ASSERT_EQUAL(result2.point.GetY(), 1.2345);
	ASSERT_EQUAL(result2.point.GetZ(), 2.3456);
}
void Test_all() {
	Test_simply_intersected();
	Test_intersected_in_segment();
	Test_intersected_in_vertex();
}
