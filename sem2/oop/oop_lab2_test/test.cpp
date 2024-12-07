#include <cfloat>
#include <cmath>
#include "pch.h"
#include "../oop_lab2_prog/lab2.h"

// dC * dRatio / dW

TEST(OperationTimeCalculation, TestValidInput) {
	double result = GetTimeOfOperationInHours(1.0, 1.0, 0.5);
	EXPECT_DOUBLE_EQ(result, 0.5) << "Doesn't work properly with simple imput.";

	result = GetTimeOfOperationInHours(50.0, 100.0, 0.9);
	EXPECT_DOUBLE_EQ(result, 1.8) << "Doesn't work properly with bigger input.";

	result = GetTimeOfOperationInHours(1.0, 5.0, 0.1);
	EXPECT_DOUBLE_EQ(result, 0.5) << "Doesn't work properly with small ratio.";
	
	result = GetTimeOfOperationInHours(0.1, 0.00001, 0.75);
	EXPECT_DOUBLE_EQ(result, 0.000075) << "Doesn't work properly with very small numbers.";
	
	result = GetTimeOfOperationInHours(6.0, 150.0, 0.25);
	EXPECT_DOUBLE_EQ(result, 6.25) << "Doesn't work properly with bigger input.";
}

TEST(OperationTimeCalculation, TestInvalidInput) {
	double result = GetTimeOfOperationInHours(1.0, 1.0, 1.5);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work with ratio > 1.";

	result = GetTimeOfOperationInHours(-0.0, 0.0, 0.0);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work with zeros.";

	result = GetTimeOfOperationInHours(199.0, -1.0, 0.5);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work with negative energy.";

	result = GetTimeOfOperationInHours(-18.0, 5.0, 0.75);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work with negative wattage.";

	result = GetTimeOfOperationInHours(50.0, 100.0, 1.0);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work with ratio = 1. Infinite engine is impossible :)";

	result = GetTimeOfOperationInHours(DBL_MAX, DBL_MAX, 0.5);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work with DBL_MAX as it is out of range.";

	result = GetTimeOfOperationInHours(DBL_MAX, 50.0, 0.6);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work with DBL_MAX as it is out of range.";

	result = GetTimeOfOperationInHours(34765869822.87867, 50.0, 0.6);
	EXPECT_TRUE(isnan(result)) << "Shouldn't work as such high capacity is not possible.";
}

TEST(OperationTimeCalculation, TestInfinityInput) {
	double result = GetTimeOfOperationInHours(INFINITY, 30.0, 0.4);
	EXPECT_TRUE(isnan(result)) << "Doesn't handle the case when wattage is infinity.";

	result = GetTimeOfOperationInHours(1.0, -INFINITY, 0.05);
	EXPECT_TRUE(isnan(result)) << "Doesn't handle the case when capacity is infinity.";
}

TEST(OperationTimeCalculation, TestNANInput) {
	double result = GetTimeOfOperationInHours(1.0, 3.5, NAN);
	EXPECT_TRUE(isnan(result)) << "Doesn't handle the case when coefficient is NAN value.";

	result = GetTimeOfOperationInHours(-NAN, 0.5, 0.5);
	EXPECT_TRUE(isnan(result)) << "Doesn't handle the case when wattage is NAN value.";

	result = GetTimeOfOperationInHours(0.1, NAN, 0.25);
	EXPECT_TRUE(isnan(result)) << "Doesn't handle the case when capacity is NAN value.";
}