#include "pch.h"
#include "../oop_lab7_prog/classes.h"

unsigned char get_position(unsigned char row, unsigned char col) {
	if (row > 7 || col > 7) {
		// Exception
		return 0;
	}

	return col * 8 + row;
}

TEST(CChessman, BaseClassTest) {
	CChessman piece1(true, get_position(3, 5));

	EXPECT_EQ(piece1.get_row(), 3);
	EXPECT_EQ(piece1.get_col(), 5);
}

TEST(CChessman, KnightTest) {
	// Average
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

	// Corner

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
}

TEST(CChessman, RookTest) {
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
}

// TODO:
TEST(CChessman, QueenTest) {
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
}
