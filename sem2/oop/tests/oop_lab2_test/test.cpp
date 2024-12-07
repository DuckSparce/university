#include "pch.h"
#include "C:\Users\USER\source\repos\university\sem2\OOP\tests\test_project1\lab2.h"

TEST(ShiftRight, TestCornerCases) {
	//zero input number and shift amount
	unsigned int uiResult = ShiftRight(0, 0);
	EXPECT_EQ(uiResult, 0);
	//max input, min shift
	uiResult = ShiftRight(0xFFFFFFFFU, 0);
	EXPECT_EQ(uiResult, 0xFFFFFFFFU);
	//max input, max shift
	uiResult = ShiftRight(0xABCDEF24U, 32);
	EXPECT_EQ(uiResult, 0xABCDEF24U);
	//min input, random shift
	uiResult = ShiftRight(0, 10);
	EXPECT_EQ(uiResult, 0);
	//random input, max shift
	uiResult = ShiftRight(0xABCD9876U, 32);
	EXPECT_EQ(uiResult, 0xABCD9876);
}


TEST(ShiftRight, TestRandom) {

	unsigned int uiResult = ShiftRight(0b00000000'00000000'00000000'01001011U, 1);
	EXPECT_EQ(uiResult, 0b10000000'00000000'00000000'00100101U);

	uiResult = ShiftRight(4, 1);
	EXPECT_EQ(uiResult, 2);

	uiResult = ShiftRight(0b0101'0101'0101'0101'0101U, 8);
	EXPECT_EQ(uiResult, 0b0101'0101'0000'0000'0000'0101'0101'0101);

	uiResult = ShiftRight(0xDDDDBB77U, 13);
	EXPECT_EQ(uiResult, 0b1111'1111'1111'1110'1110'1110'1110'1101);
}