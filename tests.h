//набор тестов

#pragma once

#include "test_runner.h"
#include "intersectSegments3d.h"
#include "vector3d.h"

void Test_simply_intersected() {

	auto result1 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0),    Vector3D(2.0,2.0,2.0)),
							 Segment3D(Vector3D(1.0,1.0,2.3456), Vector3D(2.0,2.0,1.9876))
							 );
	auto result2 = Intersect(Segment3D(Vector3D(1.0,1.0,2.3456),Vector3D(2.0,2.0,1.9876)),
							 Segment3D(Vector3D(1.0,1.0,1.0),   Vector3D(2.0,2.0,2.0))
							 );
	auto result3 = Intersect(Segment3D(Vector3D(1.0,1.0,2.3456),Vector3D(2.0,2.0,1.9876)),
							 Segment3D(Vector3D(2.0,2.0,2.0),   Vector3D(1.0,1.0,1.0))
							 );
	ASSERT_EQUAL(result1.type, TypeOfIntersection::IntersectedInPoint);
	ASSERT_EQUAL(result2.type, TypeOfIntersection::IntersectedInPoint);
	ASSERT_EQUAL(result3.type, TypeOfIntersection::IntersectedInPoint);

	auto result4 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0),    Vector3D(3.0,3.0,3.0)),
			 	 	 	 	 Segment3D(Vector3D(2.0,1.0,2.0), 	 Vector3D(2.0,3.0,2.0))
							 );
	ASSERT_EQUAL(result4.point.GetX(),2.0);
	ASSERT_EQUAL(result4.point.GetY(),2.0);
	ASSERT_EQUAL(result4.point.GetZ(),2.0);
}

void Test_intersected_in_segment() {

	auto result1 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(0.1234,1.2345,2.3456)),
							 Segment3D(Vector3D(0.1234,1.2345,2.3456), Vector3D(1.0,1.0,1.0))
							 );
	auto result2 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(3.0,3.0,3.0)),
							 Segment3D(Vector3D(2.0,2.0,2.0), Vector3D(3.0,3.0,3.0))
							 );
	auto result3 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(3.0,3.0,3.0)),
							 Segment3D(Vector3D(2.0,2.0,2.0), Vector3D(4.0,4.0,4.0))
							 );
	ASSERT_EQUAL(result1.type, TypeOfIntersection::IntersectedInSegment);
	ASSERT_EQUAL(result2.type, TypeOfIntersection::IntersectedInSegment);
	ASSERT_EQUAL(result3.type, TypeOfIntersection::IntersectedInSegment);
}

void Test_intersected_in_vertex() {

	auto result1 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(0.1234,1.2345,2.3456)),
							 Segment3D(Vector3D(0.1234,1.2345,2.3456), Vector3D(3.0,3.0,3.0))
							 );
	auto result2 = Intersect(Segment3D(Vector3D(1.0,1.0,1.0), Vector3D(0.1234,1.2345,2.3456)),
							 Segment3D(Vector3D(0.1234,1.2345,2.3456), Vector3D(3.0,4.0,5.0))
							 );
	ASSERT_EQUAL(result1.point.GetX(), 0.1234);
	ASSERT_EQUAL(result1.point.GetY(), 1.2345);
	ASSERT_EQUAL(result1.point.GetZ(), 2.3456);

	ASSERT_EQUAL(result2.point.GetX(), 0.1234);
	ASSERT_EQUAL(result2.point.GetY(), 1.2345);
	ASSERT_EQUAL(result2.point.GetZ(), 2.3456);
}

void Test_not_intersected() {

	auto result1 = Intersect(Segment3D(Vector3D(-1.0,-1.0,-1.0), Vector3D(-2.0,-2.0,-2.0)),
							 Segment3D(Vector3D(-0.9,-0.9,-0.9), Vector3D(-2.0,-2.0,-1.9))
							 );
	ASSERT_EQUAL(result1.type, TypeOfIntersection::NotIntersected);
}

void Test_all() {
	Test_simply_intersected();
	Test_intersected_in_segment();
	Test_intersected_in_vertex();
	Test_not_intersected();
}
