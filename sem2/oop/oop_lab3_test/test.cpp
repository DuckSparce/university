#include "pch.h"

#include "../oop_lab3_prog/CBitField.h"

TEST(CBitFieldClassTest, GettersTest) {
	const CBitField obj1(2U);
	EXPECT_EQ(obj1.getValue(), 2U);
	EXPECT_EQ(obj1.getBit(0U), false);
	EXPECT_EQ(obj1.getBit(1U), true);
	EXPECT_EQ(obj1.getBit(2U), false);

	const CBitField obj2(15U);
	EXPECT_EQ(obj2.getValue(), 15U);
	EXPECT_EQ(obj2.getBit(0U), true);
	EXPECT_EQ(obj2.getBit(3U), true);
	EXPECT_EQ(obj2.getBit(7U), false);
}

TEST(CBitFieldClassTest, SettersTest) {
	CBitField obj1;
	obj1.setBit(1U, true);
	EXPECT_EQ(obj1.getValue(), 2U);
	EXPECT_EQ(obj1.getBit(0U), false);
	EXPECT_EQ(obj1.getBit(1U), true);

	obj1.setBit(5U, true);
	EXPECT_EQ(obj1.getValue(), 34U);
	EXPECT_EQ(obj1.getBit(5U), true);
	EXPECT_EQ(obj1.getBit(4U), false);

	obj1.setBit(1U, false);
	EXPECT_EQ(obj1.getValue(), 32U);

	obj1.setValue(6U);
	EXPECT_EQ(obj1.getValue(), 6U);
}

TEST(CBitFieldClassTest, DefaultConstructorTest) {
	const CBitField obj;
	EXPECT_EQ(obj.getValue(), 0U);
}

TEST(CBitFieldClassTest, NewValueConstructorTest) {
	const CBitField obj1(0U);
	EXPECT_EQ(obj1.getValue(), 0U);

	const CBitField obj2(1U);
	EXPECT_EQ(obj2.getValue(), 1U);

	const CBitField obj3(5U);
	EXPECT_EQ(obj3.getValue(), 5U);

	const CBitField obj4(321U);
	EXPECT_EQ(obj4.getValue(), 321U);

	const CBitField obj5(31U);
	EXPECT_EQ(obj5.getValue(), 31U);
}

TEST(CBitFieldClassTest, CopyConstructorTest) {
	const CBitField obj1;
	const CBitField obj2(obj1);
	EXPECT_EQ(obj2.getValue(), 0U);

	const CBitField obj3(5U);
	const CBitField obj4(obj3);
	EXPECT_EQ(obj4.getValue(), 5U);
}

TEST(CBitFieldClassTest, GetCountOfSetBitsTest) {
	CBitField obj1;
	EXPECT_EQ(obj1.getCountOfSetBits(), 0U);
	
	obj1.setBit(1U, true);
	EXPECT_EQ(obj1.getCountOfSetBits(), 1U);

	obj1.setValue(5U);
	EXPECT_EQ(obj1.getCountOfSetBits(), 2U);

	obj1.setBit(5U, true);
	EXPECT_EQ(obj1.getCountOfSetBits(), 3U);

	obj1.setBit(2U, false);
	EXPECT_EQ(obj1.getCountOfSetBits(), 2U);
}

TEST(CBitFieldClassTest, BitwiseOperationsTest) {
	CBitField obj1(1U);
	CBitField obj2(5U);
	EXPECT_EQ((obj1.bitwiseOr(obj2)).getValue(), 5U);
	
	obj1.setValue(9);
	obj2.setValue(6);
	EXPECT_EQ((obj1.bitwiseAnd(obj2)).getValue(), 0U);

	obj1.setValue(14);
	obj2.setValue(11);
	EXPECT_EQ((obj1.bitwiseXor(obj2)).getValue(), 5U);
}
