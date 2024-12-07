#include "pch.h"

#include "../oop_lab8_prog/classes.h"

#include <vector>
#include <string>
#include <gtest/gtest.h>

unsigned char get_position(unsigned char row, unsigned char col) {
	if (row > 7 || col > 7) {
		// Exception
		return 0;
	}

	return col * 8 + row;
}

TEST(CChessman, OveralTest) {
	CKnight knight1(false, get_position(6, 4));
	CKnight knight2(true, get_position(0, 7));
	CRook rook1(false, get_position(5, 1));
	CQueen queen1(false, get_position(0, 6));
	
	CChessman* array[4] = {
		dynamic_cast<CChessman*>(&knight1),
		dynamic_cast<CChessman*>(&knight2),
		dynamic_cast<CChessman*>(&rook1),
		dynamic_cast<CChessman*>(&queen1)
	};

	// 1
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 2), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(7, 2), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(4, 3), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(4, 5) + 128, array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 6), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(7, 6) + 64, array, 4));
	// 2
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(1, 5), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(2, 6), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 0) + 64, array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 3), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 7), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(4, 1), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(2, 1), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(7, 1) + 128, array, 4));
	// 3
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 0) + 64, array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 3), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(5, 7), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(4, 1), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(2, 1), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(7, 1) + 128, array, 4));
	// 4
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(0, 7) + 64, array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(0, 0), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(0, 2), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(0, 5), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(3, 6), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(4, 6) + 128, array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(1, 7), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(2, 4), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(1, 5), array, 4));
	EXPECT_TRUE(CanAnyoneCapturePosition(get_position(6, 0), array, 4));

	EXPECT_FALSE(CanAnyoneCapturePosition(get_position(0, 6), array, 4));
	EXPECT_FALSE(CanAnyoneCapturePosition(get_position(1, 3), array, 4));
	EXPECT_FALSE(CanAnyoneCapturePosition(get_position(2, 0), array, 4));
	EXPECT_FALSE(CanAnyoneCapturePosition(get_position(3, 2), array, 4));
	EXPECT_FALSE(CanAnyoneCapturePosition(get_position(3, 7), array, 4));
	EXPECT_FALSE(CanAnyoneCapturePosition(get_position(6, 3), array, 4));
}


TEST(CKnight, AverageTest) {
	CKnight knight1(false, get_position(6, 4));

	EXPECT_EQ(knight1.get_row(), 6);
	EXPECT_EQ(knight1.get_col(), 4);
	EXPECT_TRUE(knight1.CanCapturePosition(get_position(5, 2)));
	EXPECT_TRUE(knight1.CanCapturePosition(get_position(7, 2)));
	EXPECT_TRUE(knight1.CanCapturePosition(get_position(4, 3)));
	EXPECT_TRUE(knight1.CanCapturePosition(get_position(4, 5) + 128));
	EXPECT_TRUE(knight1.CanCapturePosition(get_position(5, 6)));
	EXPECT_TRUE(knight1.CanCapturePosition(get_position(7, 6) + 64));
	EXPECT_FALSE(knight1.CanCapturePosition(get_position(6, 4)));
	EXPECT_FALSE(knight1.CanCapturePosition(get_position(0, 0)));
	EXPECT_FALSE(knight1.CanCapturePosition(get_position(1, 0)));
	EXPECT_FALSE(knight1.CanCapturePosition(get_position(5, 0)));
	EXPECT_FALSE(knight1.CanCapturePosition(get_position(5, 4)));
	EXPECT_FALSE(knight1.CanCapturePosition(get_position(6, 6)));

	std::ostringstream dest;
	knight1.PrintName(dest);
	EXPECT_STREQ(dest.str().c_str(), "CKnight.\n");
	dest.str("");
	dest.clear();
}

TEST(CKnight, CornerTest) {
	CKnight knight2(true, get_position(0, 7));

	EXPECT_EQ(knight2.get_row(), 0);
	EXPECT_EQ(knight2.get_col(), 7);
	EXPECT_TRUE(knight2.CanCapturePosition(get_position(1, 5)));
	EXPECT_TRUE(knight2.CanCapturePosition(get_position(2, 6)));
	EXPECT_FALSE(knight2.CanCapturePosition(get_position(1, 6)));
	EXPECT_FALSE(knight2.CanCapturePosition(get_position(0, 6)));
	EXPECT_FALSE(knight2.CanCapturePosition(get_position(0, 7)));
	EXPECT_FALSE(knight2.CanCapturePosition(get_position(0, 5)));
	EXPECT_FALSE(knight2.CanCapturePosition(get_position(7, 7)));
	EXPECT_FALSE(knight2.CanCapturePosition(get_position(0, 0) + 70));

	std::ostringstream dest;
	knight2.PrintName(dest);
	EXPECT_STREQ(dest.str().c_str(), "CKnight.\n");
	dest.str("");
	dest.clear();
}

TEST(CRook, OveralTest) {
	// Average
	CRook rook1(false, get_position(5, 1));

	EXPECT_EQ(rook1.get_row(), 5);
	EXPECT_EQ(rook1.get_col(), 1);
	EXPECT_TRUE(rook1.CanCapturePosition(get_position(5, 0) + 64));
	EXPECT_TRUE(rook1.CanCapturePosition(get_position(5, 3)));
	EXPECT_TRUE(rook1.CanCapturePosition(get_position(5, 7)));
	EXPECT_TRUE(rook1.CanCapturePosition(get_position(4, 1)));
	EXPECT_TRUE(rook1.CanCapturePosition(get_position(2, 1)));
	EXPECT_TRUE(rook1.CanCapturePosition(get_position(7, 1) + 128));
	EXPECT_FALSE(rook1.CanCapturePosition(get_position(5, 1)));
	EXPECT_FALSE(rook1.CanCapturePosition(get_position(0, 0)));
	EXPECT_FALSE(rook1.CanCapturePosition(get_position(1, 0)));
	EXPECT_FALSE(rook1.CanCapturePosition(get_position(6, 0)));
	EXPECT_FALSE(rook1.CanCapturePosition(get_position(2, 4)));
	EXPECT_FALSE(rook1.CanCapturePosition(get_position(6, 6)));

	std::ostringstream dest;
	rook1.PrintName(dest);
	EXPECT_STREQ(dest.str().c_str(), "CRook.\n");
	dest.str("");
	dest.clear();
}

TEST(CQueen, OveralTest) {
	// Average
	CQueen queen1(false, get_position(0, 6));

	EXPECT_EQ(queen1.get_row(), 0);
	EXPECT_EQ(queen1.get_col(), 6);
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(0, 7) + 64));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(0, 0)));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(0, 2)));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(0, 5)));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(3, 6)));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(4, 6) + 128));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(1, 7)));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(2, 4)));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(1, 5)));
	EXPECT_TRUE(queen1.CanCapturePosition(get_position(6, 0)));
	EXPECT_FALSE(queen1.CanCapturePosition(get_position(0, 6)));
	EXPECT_FALSE(queen1.CanCapturePosition(get_position(1, 0)));
	EXPECT_FALSE(queen1.CanCapturePosition(get_position(2, 0)));
	EXPECT_FALSE(queen1.CanCapturePosition(get_position(7, 4)));
	EXPECT_FALSE(queen1.CanCapturePosition(get_position(7, 7)));
	EXPECT_FALSE(queen1.CanCapturePosition(get_position(4, 7)));

	std::ostringstream dest;
	queen1.PrintName(dest);
	EXPECT_STREQ(dest.str().c_str(), "CQueen.\n");
	dest.str("");
	dest.clear();
}
