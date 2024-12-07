#include "pch.h"

#include "../oop_lab4_prog/CBitField.h"

TEST(CBitFieldClassTest, ObjectCountTest) {
	CBitField obj1;
	CBitField obj2(1U);
	EXPECT_EQ(CBitField::getObjectsCount(), 2);

	CBitField obj3(obj2);
	EXPECT_EQ(CBitField::getObjectsCount(), 3);

	do {
		CBitField obj4;
		EXPECT_EQ(CBitField::getObjectsCount(), 4);
	} while (false);

	EXPECT_EQ(CBitField::getObjectsCount(), 3);
}

TEST(CBitFieldClassTest, GettersTest) {
	CBitField obj1(2U);
	EXPECT_EQ(obj1.getValue(), 2U);
	EXPECT_EQ(obj1.getBit(0U), 0U);
	EXPECT_EQ(obj1.getBit(1U), 1U);
	EXPECT_EQ(obj1.getBit(2U), 0U);

	CBitField obj2(15U);
	EXPECT_EQ(obj2.getValue(), 15U);
	EXPECT_EQ(obj2.getBit(0U), 1U);
	EXPECT_EQ(obj2.getBit(3U), 1U);
	EXPECT_EQ(obj2.getBit(7U), 0U);
}

TEST(CBitFieldClassTest, BitAccessTest) {
	CBitField obj1(2U);
	EXPECT_EQ(obj1[0U], 0U);
	EXPECT_EQ(obj1[1U], 1U);
	EXPECT_EQ(obj1[2U], 0U);

	CBitField obj2(15U);
	EXPECT_EQ(obj2[0U], 1U);
	EXPECT_EQ(obj2[3U], 1U);
	EXPECT_EQ(obj2[7U], 0U);
}

TEST(CBitFieldClassTest, SettersTest) {
	CBitField obj1;
	obj1.setBit(1U, 1U);
	EXPECT_EQ(obj1.getValue(), 2U);
	EXPECT_EQ(obj1.getBit(0U), 0U);
	EXPECT_EQ(obj1.getBit(1U), 1U);

	obj1.setBit(5U, 1U);
	EXPECT_EQ(obj1.getValue(), 34U);
	EXPECT_EQ(obj1.getBit(5U), 1U);
	EXPECT_EQ(obj1.getBit(4U), 0U);

	obj1.setBit(1U, 0U);
	EXPECT_EQ(obj1.getValue(), 32U);

	obj1.setValue(6U);
	EXPECT_EQ(obj1.getValue(), 6U);
}

TEST(CBitFieldClassTest, DefaultConstructorTest) {
	CBitField obj;
	EXPECT_EQ(obj.getValue(), 0U);
}

TEST(CBitFieldClassTest, NewValueConstructorTest) {
	CBitField obj1(0U);
	EXPECT_EQ(obj1.getValue(), 0U);

	CBitField obj2(1U);
	EXPECT_EQ(obj2.getValue(), 1U);

	CBitField obj3(5U);
	EXPECT_EQ(obj3.getValue(), 5U);

	CBitField obj4(321U);
	EXPECT_EQ(obj4.getValue(), 321U);

	CBitField obj5(31U);
	EXPECT_EQ(obj5.getValue(), 31U);
}

TEST(CBitFieldClassTest, CopyConstructorTest) {
	CBitField obj1;
	CBitField obj2(obj1);
	EXPECT_EQ(obj2.getValue(), 0U);

	CBitField obj3(5U);
	CBitField obj4(obj3);
	EXPECT_EQ(obj4.getValue(), 5U);
}

TEST(CBitFieldClassTest, GetBitsNumberTest) {
	CBitField obj1;
	EXPECT_EQ(obj1.getTrueBitsNumber(), 0U);

	obj1.setBit(1U, 1U);
	EXPECT_EQ(obj1.getTrueBitsNumber(), 1U);

	obj1.setValue(5U);
	EXPECT_EQ(obj1.getTrueBitsNumber(), 2U);

	obj1.setBit(5U, 1U);
	EXPECT_EQ(obj1.getTrueBitsNumber(), 3U);

	obj1.setBit(2U, 0U);
	EXPECT_EQ(obj1.getTrueBitsNumber(), 2U);
}

TEST(CBitFieldClassTest, BitwiseOperationsTest) {
	CBitField obj1(9U);
	CBitField obj2(6U);
	EXPECT_EQ((obj1.bitwiseAnd(7U)).getValue(), 1U);
	EXPECT_EQ((obj1.bitwiseAnd(obj2)).getValue(), 0U);

	obj1.setValue(1U);
	obj2.setValue(5U);
	EXPECT_EQ((obj1.bitwiseOr(8U)).getValue(), 9U);
	EXPECT_EQ((obj1.bitwiseOr(obj2)).getValue(), 13U);

	obj1.setValue(14U);
	obj2.setValue(11U);
	EXPECT_EQ((obj1.bitwiseXor(38)).getValue(), 40U);
	EXPECT_EQ((obj1.bitwiseXor(obj2)).getValue(), 35U);
}

TEST(CBitFieldClassTest, BitwiseOperatorsTest) {
	CBitField obj1(9U);
	CBitField obj2(6U);
	EXPECT_EQ((obj1 & obj2).getValue(), 0U);

	obj1.setValue(1U);
	obj2.setValue(5U);
	EXPECT_EQ((obj1 | obj2).getValue(), 5U);

	obj1.setValue(14U);
	obj2.setValue(11U);
	EXPECT_EQ((obj1 ^ obj2).getValue(), 5U);
}

TEST(CBitFieldClassTest, BitAccessOperatorTest) {
	CBitField obj(9U);
	EXPECT_EQ(obj[0], 1);
	EXPECT_EQ(obj[1], 0);
	EXPECT_EQ(obj[2], 0);
	EXPECT_EQ(obj[3], 1);
	EXPECT_EQ(obj[5], 0);

	obj.setValue(3U);
	EXPECT_EQ(obj[0], 1);
	EXPECT_EQ(obj[1], 1);
	EXPECT_EQ(obj[2], 0);
}

TEST(CBitFieldClassTest, CorrectInputOperatorTest) {
	CBitField obj;
	std::istringstream stream1("00000000000000000000000000000001");
	stream1.clear();
	stream1 >> obj;
	EXPECT_EQ(obj.getValue(), 1U);
	
	std::istringstream stream2("00000000000000000000000000001101");
	stream2.clear();
	stream2 >> obj;
	EXPECT_EQ(obj.getValue(), 13U);

	std::istringstream stream3("00000000000000000000011111000000");
	stream3.clear();
	stream3 >> obj;
	EXPECT_EQ(obj.getValue(), 1984U);

	std::istringstream stream4("00000000000000000000000010101010");
	stream4.clear();
	stream4 >> obj;
	EXPECT_EQ(obj.getValue(), 170U);

	std::istringstream stream5("01000000000000000000000010101010");
	stream5.clear();
	stream5 >> obj;
	EXPECT_EQ(obj.getValue(), 1073741994U);
}

TEST(CBitFieldClassTest, IncorrectInputOperatorTest) {
	CBitField obj;
	std::istringstream stream1("00adbbcbabdb00000001");
	stream1 >> obj;
	EXPECT_EQ(obj.getValue(), 0U);

	std::istringstream stream2("000032452332000000000000000000001101");
	stream2 >> obj;
	EXPECT_EQ(obj.getValue(), 0U);

	obj.setValue(5U);

	std::istringstream stream3("00000009483740000400011111000000");
	stream3 >> obj;
	EXPECT_EQ(obj.getValue(), 5U);

	std::istringstream stream4("00fdgrenghm0000fdsgr00000010101010");
	stream4 >> obj;
	EXPECT_EQ(obj.getValue(), 5U);

	std::istringstream stream5("0100098770000000010101010");
	stream5 >> obj;
	EXPECT_EQ(obj.getValue(), 5U);
}

TEST(CBitFieldClassTest, OutputOperatorTest) {
	CBitField obj(1U);
	std::ostringstream stream1;
	stream1 << obj;
	EXPECT_EQ(stream1.str(), "00000000000000000000000000000001");

	obj.setValue(0U);
	std::ostringstream stream2;
	stream2 << obj;
	EXPECT_EQ(stream2.str(), "00000000000000000000000000000000");

	obj.setValue(877U);
	std::ostringstream stream3;
	stream3 << obj;
	EXPECT_EQ(stream3.str(), "00000000000000000000001101101101");

	obj.setValue(8U);
	std::ostringstream stream4;
	stream4 << obj;
	EXPECT_EQ(stream4.str(), "00000000000000000000000000001000");
}

TEST(CBitFieldClassTest, ComparisonOperatorsTest) {
	CBitField obj1(1U);
	CBitField obj2(1U);
	EXPECT_EQ(obj1, obj2);

	obj2.setValue(0U);
	EXPECT_NE(obj1, obj2);

	obj1.setValue(17U);
	obj2.setValue(16U);
	EXPECT_NE(obj1, obj2);

	obj2.setBit(0, true);
	EXPECT_EQ(obj1, obj2);
}
/*
TEST(C, C) {
	CBitField obj1;
	std::istringstream stream1("00101010101010101010101010101010");
	stream1 >> obj1;

	CBitField obj2;
	std::istringstream stream2("10101010101010101010101010101010");
	stream2 >> obj2;

	CBitField objXored = obj1 ^ obj2;

	std::ostringstream streamXored;
	streamXored << objXored;
	EXPECT_EQ(streamXored.str(), "10000000000000000000000000000000");
}
*/
