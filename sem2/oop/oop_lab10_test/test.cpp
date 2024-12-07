#include "pch.h"

#include "../oop_lab10_prog/ctable.h"
#include "../oop_lab10_prog/exceptions.h"
#include "../oop_lab10_prog/cbitfield.h"
#include "../oop_lab10_prog/find_element_function.h"

TEST(CTableInt, DefaultConstructorTest) {
	const CTable<int> table1;
	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
}

TEST(CTableInt, CopyConstructorTest) {
	CTable<int> table1;
	constexpr int row1_data[] = { 11, 21, 31 };
	constexpr int row2_data[] = { 12, 22, 32 };
	constexpr int row3_data[] = { 13, 23, 33 };
	constexpr int row4_data[] = { 14, 24, 34 };

	// 11 21 31
	// 12 22 32	
	// 13 23 33
	// 14 24 34	
	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_column("Column3");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	table1.add_row(row3_data, sizeof(row3_data) / sizeof(int));
	table1.add_row(row4_data, sizeof(row4_data) / sizeof(int));

	const CTable<int> table2(table1);
	EXPECT_EQ(table2.get_columns_number(), 3);
	EXPECT_EQ(table2.get_rows_number(), 4);
	EXPECT_EQ(table2.get_value(1, 0), 12);
	EXPECT_EQ(table2.get_value(0, 1), 21);
	EXPECT_EQ(table2.get_value(1, 1), 22);
	EXPECT_EQ(table2.get_value(3, 2), 34);
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");
	EXPECT_STREQ(table2.get_column_name(2), "Column3");

	EXPECT_EQ(table1.get_columns_number(), 3);
	EXPECT_EQ(table1.get_rows_number(), 4);
	EXPECT_EQ(table1.get_value(1, 0), 12);
	EXPECT_EQ(table1.get_value(0, 1), 21);
	EXPECT_EQ(table1.get_value(1, 1), 22);
	EXPECT_EQ(table1.get_value(3, 2), 34);
	EXPECT_STREQ(table1.get_column_name(0), "Column1");
	EXPECT_STREQ(table1.get_column_name(1), "Column2");
	EXPECT_STREQ(table1.get_column_name(2), "Column3");
}

TEST(CTableInt, MoveConstructorTest) {
	CTable<int> table1;
	constexpr int row1_data[] = { 11, 21, 31 };
	constexpr int row2_data[] = { 12, 22, 32 };
	constexpr int row3_data[] = { 13, 23, 33 };
	constexpr int row4_data[] = { 14, 24, 34 };

	// 11 21 31
	// 12 22 32	
	// 13 23 33
	// 14 24 34	
	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_column("Column3");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	table1.add_row(row3_data, sizeof(row3_data) / sizeof(int));
	table1.add_row(row4_data, sizeof(row4_data) / sizeof(int));

	const CTable<int> table2 = std::move(table1);
	EXPECT_EQ(table2.get_columns_number(), 3);
	EXPECT_EQ(table2.get_rows_number(), 4);
	EXPECT_EQ(table2.get_value(1, 0), 12);
	EXPECT_EQ(table2.get_value(0, 1), 21);
	EXPECT_EQ(table2.get_value(1, 1), 22);
	EXPECT_EQ(table2.get_value(3, 2), 34);
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");
	EXPECT_STREQ(table2.get_column_name(2), "Column3");

	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
	EXPECT_THROW(table1.get_value(1, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(0, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(1, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(2, 3), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(3, 2), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(0), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(1), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(2), ColumnNameIndexOutOfRangeException);
}

TEST(CTableInt, AssignmentOperatorTest) {
	CTable<int> table1;
	int row1_data[] = { 1, 2 };
	int row2_data[] = { 3, 4 };
	int row3_data[] = { 5, 6 };
	int row4_data[] = { 7, 8 };
	int row5_data[] = { 9, 0 };

	table1.add_column("Odd numbers");
	table1.add_column("Even numbers");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	table1.add_row(row3_data, sizeof(row3_data) / sizeof(int));
	table1.add_row(row4_data, sizeof(row4_data) / sizeof(int));
	table1.add_row(row5_data, sizeof(row5_data) / sizeof(int));

	CTable<int> table2 = table1;

	EXPECT_STREQ(table1.get_column_name(0), table2.get_column_name(0));
	EXPECT_STREQ(table1.get_column_name(0), "Odd numbers");
	EXPECT_STREQ(table2.get_column_name(0), "Odd numbers");
	EXPECT_STREQ(table1.get_column_name(1), table2.get_column_name(1));
	EXPECT_STREQ(table1.get_column_name(1), "Even numbers");
	EXPECT_STREQ(table2.get_column_name(1), "Even numbers");
	EXPECT_EQ(table1.get_columns_number(), table2.get_columns_number());
	EXPECT_EQ(table1.get_columns_number(), 2);
	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_EQ(table1.get_rows_number(), table2.get_rows_number());
	EXPECT_EQ(table1.get_rows_number(), 5);
	EXPECT_EQ(table2.get_rows_number(), 5);

	EXPECT_EQ(table1.get_value(0, 0), 1);
	EXPECT_EQ(table2.get_value(1, 0), 3);
	EXPECT_EQ(table1.get_value(2, 0), 5);
	EXPECT_EQ(table2.get_value(3, 0), 7);
	EXPECT_EQ(table1.get_value(4, 0), 9);
	EXPECT_EQ(table2.get_value(0, 1), 2);
	EXPECT_EQ(table1.get_value(1, 1), 4);
	EXPECT_EQ(table2.get_value(2, 1), 6);
	EXPECT_EQ(table1.get_value(3, 1), 8);
	EXPECT_EQ(table2.get_value(4, 1), 0);
}

TEST(CTableInt, MoveOperatorTest) {
	CTable<int> table1;
	constexpr int row1_data[] = { 1, 2 };
	constexpr int row2_data[] = { 3, 4 };
	constexpr int row3_data[] = { 5, 6 };
	constexpr int row4_data[] = { 7, 8 };
	constexpr int row5_data[] = { 9, 0 };

	table1.add_column("Odd numbers");
	table1.add_column("Even numbers");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	table1.add_row(row3_data, sizeof(row3_data) / sizeof(int));
	table1.add_row(row4_data, sizeof(row4_data) / sizeof(int));
	table1.add_row(row5_data, sizeof(row5_data) / sizeof(int));

	const CTable<int> table2(std::move(table1));

	EXPECT_THROW(table1.get_column_name(0), ColumnNameIndexOutOfRangeException);
	EXPECT_STREQ(table2.get_column_name(0), "Odd numbers");
	EXPECT_THROW(table1.get_column_name(1), ColumnNameIndexOutOfRangeException);
	EXPECT_STREQ(table2.get_column_name(1), "Even numbers");
	EXPECT_NE(table1.get_columns_number(), table2.get_columns_number());
	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_NE(table1.get_rows_number(), table2.get_rows_number());
	EXPECT_EQ(table1.get_rows_number(), 0);
	EXPECT_EQ(table2.get_rows_number(), 5);

	EXPECT_THROW(table1.get_value(0, 0), TableValueIndexOutOfRangeException);
	EXPECT_EQ(table2.get_value(1, 0), 3);
	EXPECT_THROW(table1.get_value(2, 0), TableValueIndexOutOfRangeException);
	EXPECT_EQ(table2.get_value(3, 0), 7);
	EXPECT_THROW(table1.get_value(4, 0), TableValueIndexOutOfRangeException);
	EXPECT_EQ(table2.get_value(0, 1), 2);
	EXPECT_THROW(table1.get_value(1, 1), TableValueIndexOutOfRangeException);
	EXPECT_EQ(table2.get_value(2, 1), 6);
	EXPECT_THROW(table1.get_value(3, 1), TableValueIndexOutOfRangeException);
	EXPECT_EQ(table2.get_value(4, 1), 0);
}

TEST(CTableInt, AdditionOperatorTest) {
	CTable<int> table1;
	CTable<int> table2;
	constexpr int row1_data[] = { 11, 21, 31 };
	constexpr int row2_data[] = { 12, 22, 32 };
	constexpr int row3_data[] = { 13, 23, 33 };
	constexpr int row4_data[] = { 14, 24, 34 };

	// 11 21 31
	// 12 22 32	
	// 13 23 33
	// 14 24 34	
	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_column("Column3");
	table2.add_column("Column1");
	table2.add_column("Column2");
	table2.add_column("Column3");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	table2.add_row(row3_data, sizeof(row3_data) / sizeof(int));
	table2.add_row(row4_data, sizeof(row4_data) / sizeof(int));

	const CTable<int> table3 = table1 + table2;

	EXPECT_EQ(table3.get_value(0, 0), 24);
	EXPECT_EQ(table3.get_value(0, 1), 44);
	EXPECT_EQ(table3.get_value(0, 2), 64);
	EXPECT_EQ(table3.get_value(1, 0), 26);
	EXPECT_EQ(table3.get_value(1, 1), 46);
	EXPECT_EQ(table3.get_value(1, 2), 66);

	constexpr int wrong_row_data[] = { 5, 6, 7, 4 };

	EXPECT_THROW(table1.add_row(wrong_row_data, sizeof(wrong_row_data) / sizeof(int)), RowSizeMismatchException);

	EXPECT_EQ(table1.get_columns_number(), 3);
	EXPECT_EQ(table1.get_rows_number(), 2);
	EXPECT_EQ(table1.get_value(0, 0), 11);
	EXPECT_EQ(table1.get_value(1, 0), 12);
	EXPECT_EQ(table1.get_value(0, 1), 21);
}

TEST(CTableInt, InputOperatorTest) {
	// stream format:
	// n m (n - columns number, m - rows number)
	// ColumnName1\tColumnName2\t...
	// data[0][0]\t data[0][1]\t...
	// data[1][0]\t data[1][1]\t...
	std::istringstream in;
	in.str("4 5\n"
		"Animal\tPlant\tFungus\tBacteria\tVirus\n"
		"23\t31\t65\t8\t1\n"
		"109\t7\t64\t84\t12\n"
		"72\t99\t16\t34\t12\n"
		"1\t2\t3\t4\t5\n");

	CTable<int> table1;
	in >> table1;

	EXPECT_STREQ(table1.get_column_name(0), "Animal");
	EXPECT_STREQ(table1.get_column_name(1), "Plant");
	EXPECT_STREQ(table1.get_column_name(2), "Fungus");
	EXPECT_STREQ(table1.get_column_name(3), "Bacteria");
	EXPECT_STREQ(table1.get_column_name(4), "Virus");
	EXPECT_EQ(table1.get_columns_number(), 5);
	EXPECT_EQ(table1.get_rows_number(), 4);

	EXPECT_EQ(table1.get_value(0, 0), 23);
	EXPECT_EQ(table1.get_value(1, 0), 109);
	EXPECT_EQ(table1.get_value(2, 0), 72);
	EXPECT_EQ(table1.get_value(3, 0), 1);
	EXPECT_EQ(table1.get_value(0, 1), 31);
	EXPECT_EQ(table1.get_value(1, 1), 7);
	EXPECT_EQ(table1.get_value(2, 1), 99);
	EXPECT_EQ(table1.get_value(3, 1), 2);
	EXPECT_EQ(table1.get_value(0, 2), 65);
	EXPECT_EQ(table1.get_value(1, 2), 64);
	EXPECT_EQ(table1.get_value(2, 2), 16);
	EXPECT_EQ(table1.get_value(3, 2), 3);
}

TEST(CTableInt, OutputOperatorTest) {
	CTable<int> table1;
	constexpr int row1_data[] = { 1, 2 };
	constexpr int row2_data[] = { 3, 4 };
	constexpr int row3_data[] = { 5, 6 };
	constexpr int row4_data[] = { 7, 8 };
	constexpr int row5_data[] = { 9, 0 };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	table1.add_row(row3_data, sizeof(row3_data) / sizeof(int));
	table1.add_row(row4_data, sizeof(row4_data) / sizeof(int));
	table1.add_row(row5_data, sizeof(row5_data) / sizeof(int));

	std::ostringstream out;

	out << table1;

	EXPECT_STREQ(out.str().c_str(), "5 2\nColumn1\tColumn2\n1\t2\n3\t4\n5\t6\n7\t8\n9\t0\n");
}

///////////////////////////////////////////////////////////////

TEST(CTableBool, DefaultConstructorTest) {
	const CTable<bool> table1;
	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
}

TEST(CTableBool, CopyConstructorAndOperatorTest) {
	CTable<bool> table1;
	bool row1_data[] = { true, true };
	bool row2_data[] = { true, false };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(bool));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(bool));
	
	CTable<bool> table2(table1);
	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_EQ(table2.get_rows_number(), 2);
	EXPECT_TRUE(table2.get_value(0, 0));
	EXPECT_TRUE(table2.get_value(1, 0));
	EXPECT_TRUE(table2.get_value(0, 1));
	EXPECT_FALSE(table2.get_value(1, 1));
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");
	
	EXPECT_EQ(table1.get_columns_number(), 2);
	EXPECT_EQ(table1.get_rows_number(), 2);
	EXPECT_TRUE(table1.get_value(0, 0));
	EXPECT_TRUE(table1.get_value(1, 0));
	EXPECT_TRUE(table1.get_value(0, 1));
	EXPECT_FALSE(table1.get_value(1, 1));
	EXPECT_STREQ(table1.get_column_name(0), "Column1");
	EXPECT_STREQ(table1.get_column_name(1), "Column2");

	CTable<bool> table3 = table2;
	EXPECT_EQ(table3.get_columns_number(), 2);
	EXPECT_EQ(table3.get_rows_number(), 2);
	EXPECT_TRUE(table3.get_value(0, 0));
	EXPECT_TRUE(table3.get_value(1, 0));
	EXPECT_TRUE(table3.get_value(0, 1));
	EXPECT_FALSE(table3.get_value(1, 1));
	EXPECT_STREQ(table3.get_column_name(0), "Column1");
	EXPECT_STREQ(table3.get_column_name(1), "Column2");

	EXPECT_EQ(table1.get_columns_number(), 2);
	EXPECT_EQ(table1.get_rows_number(), 2);
	EXPECT_TRUE(table1.get_value(0, 0));
	EXPECT_TRUE(table1.get_value(1, 0));
	EXPECT_TRUE(table1.get_value(0, 1));
	EXPECT_FALSE(table1.get_value(1, 1));
	EXPECT_STREQ(table1.get_column_name(0), "Column1");
	EXPECT_STREQ(table1.get_column_name(1), "Column2");
}

TEST(CTableBool, MoveConstructorAndOperatorTest) {
	CTable<bool> table1;
	bool row1_data[] = { true, true };
	bool row2_data[] = { true, false };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(bool));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(bool));

	CTable<bool> table2(std::move(table1));
	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_EQ(table2.get_rows_number(), 2);
	EXPECT_TRUE(table2.get_value(0, 0));
	EXPECT_TRUE(table2.get_value(1, 0));
	EXPECT_TRUE(table2.get_value(0, 1));
	EXPECT_FALSE(table2.get_value(1, 1));
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");

	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
	EXPECT_THROW(table1.get_value(0, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(1, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(0, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(1, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(0), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(1), ColumnNameIndexOutOfRangeException);

	CTable<bool> table3(std::move(table2));
	EXPECT_EQ(table3.get_columns_number(), 2);
	EXPECT_EQ(table3.get_rows_number(), 2);
	EXPECT_TRUE(table3.get_value(0, 0));
	EXPECT_TRUE(table3.get_value(1, 0));
	EXPECT_TRUE(table3.get_value(0, 1));
	EXPECT_FALSE(table3.get_value(1, 1));
	EXPECT_STREQ(table3.get_column_name(0), "Column1");
	EXPECT_STREQ(table3.get_column_name(1), "Column2");

	EXPECT_EQ(table2.get_columns_number(), 0);
	EXPECT_EQ(table2.get_rows_number(), 0);
	EXPECT_THROW(table2.get_value(0, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(1, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(0, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(1, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_column_name(0), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table2.get_column_name(1), ColumnNameIndexOutOfRangeException);
}

TEST(CTableBool, AdditionOperatorTest) {
	CTable<bool> table1;
	CTable<bool> table2;
	constexpr bool row1_data[] = { false, true };
	constexpr bool row2_data[] = { false, true };
	constexpr bool row3_data[] = { false, false };
	constexpr bool row4_data[] = { true, true };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table2.add_column("Column1");
	table2.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(bool));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(bool));
	table2.add_row(row3_data, sizeof(row3_data) / sizeof(bool));
	table2.add_row(row4_data, sizeof(row4_data) / sizeof(bool));

	const CTable<bool> table3 = table1 + table2;

	EXPECT_EQ(table1.get_value(0, 0), false);
	EXPECT_EQ(table1.get_value(0, 1), true);
	EXPECT_EQ(table1.get_value(1, 0), false);
	EXPECT_EQ(table1.get_value(1, 1), true);

	EXPECT_EQ(table2.get_value(0, 0), false);
	EXPECT_EQ(table2.get_value(0, 1), false);
	EXPECT_EQ(table2.get_value(1, 0), true);
	EXPECT_EQ(table2.get_value(1, 1), true);

	EXPECT_EQ(table3.get_value(0, 0), false);
	EXPECT_EQ(table3.get_value(0, 1), true);
	EXPECT_EQ(table3.get_value(1, 0), true);
	EXPECT_EQ(table3.get_value(1, 1), true);
}

TEST(CTableBool, InputOperatorTest) {
	// stream format:
	// n m (n - columns number, m - rows number)
	// ColumnName1\tColumnName2\t...
	// data[0][0]\t data[0][1]\t...
	// data[1][0]\t data[1][1]\t...
	std::istringstream in;
	in.str("4 2\n"
		"Animal\tPlant\n"
		"0\t1\n"
		"1\t1\n"
		"0\t0\n"
		"0\t0\n");

	CTable<bool> table1;
	in >> table1;

	EXPECT_STREQ(table1.get_column_name(0), "Animal");
	EXPECT_STREQ(table1.get_column_name(1), "Plant");
	EXPECT_EQ(table1.get_columns_number(), 2);
	EXPECT_EQ(table1.get_rows_number(), 4);

	EXPECT_FALSE(table1.get_value(0, 0));
	EXPECT_TRUE(table1.get_value(0,	1));
	EXPECT_TRUE(table1.get_value(1, 0));
	EXPECT_TRUE(table1.get_value(1, 1));
	EXPECT_FALSE(table1.get_value(2, 0));
	EXPECT_FALSE(table1.get_value(2, 1));
	EXPECT_FALSE(table1.get_value(3, 0));
	EXPECT_FALSE(table1.get_value(3, 1));
}

TEST(CTableBool, OutputOperatorTest) {
	CTable<bool> table1;
	constexpr bool row1_data[] = { true, true, false, true };
	constexpr bool row2_data[] = { true, false, false, false };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_column("Column3");
	table1.add_column("Column4");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(bool));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(bool));
	
	std::ostringstream out;

	out << table1;

	EXPECT_STREQ(out.str().c_str(), "2 4\nColumn1\tColumn2\tColumn3\tColumn4\n1\t1\t0\t1\n1\t0\t0\t0\n");
}

/////////////////////////////////////////////////

TEST(CTableBitField, DefaultConstructorTest) {
	const CTable<CBitField> table1;
	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
}

TEST(CTableBitField, CopyConstructorAndOperatorTest) {
	CTable<CBitField> table1;
	CBitField row1_data[] = { CBitField(6U), CBitField(3U) };
	CBitField row2_data[] = { CBitField(2U), CBitField(1U) };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(CBitField));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(CBitField));

	CTable<CBitField> table2(table1);
	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_EQ(table2.get_rows_number(), 2);
	EXPECT_EQ(table2.get_value(0, 0).getValue(), 6U);
	EXPECT_EQ(table2.get_value(0, 1).getValue(), 3U);
	EXPECT_EQ(table2.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table2.get_value(1, 1).getValue(), 1U);
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");

	EXPECT_EQ(table1.get_columns_number(), 2);
	EXPECT_EQ(table1.get_rows_number(), 2);
	EXPECT_EQ(table1.get_value(0, 0).getValue(), 6U);
	EXPECT_EQ(table1.get_value(0, 1).getValue(), 3U);
	EXPECT_EQ(table1.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table1.get_value(1, 1).getValue(), 1U);
	EXPECT_STREQ(table1.get_column_name(0), "Column1");
	EXPECT_STREQ(table1.get_column_name(1), "Column2");

	CTable<CBitField> table3 = table2;
	EXPECT_EQ(table3.get_columns_number(), 2);
	EXPECT_EQ(table3.get_rows_number(), 2);
	EXPECT_EQ(table3.get_value(0, 0).getValue(), 6U);
	EXPECT_EQ(table3.get_value(0, 1).getValue(), 3U);
	EXPECT_EQ(table3.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table3.get_value(1, 1).getValue(), 1U);
	EXPECT_STREQ(table3.get_column_name(0), "Column1");
	EXPECT_STREQ(table3.get_column_name(1), "Column2");

	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_EQ(table2.get_rows_number(), 2);
	EXPECT_EQ(table2.get_value(0, 0).getValue(), 6U);
	EXPECT_EQ(table2.get_value(0, 1).getValue(), 3U);
	EXPECT_EQ(table2.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table2.get_value(1, 1).getValue(), 1U);
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");
}

TEST(CTableBitField, MoveConstructorAndOperatorTest) {
	CTable<CBitField> table1;
	CBitField row1_data[] = { CBitField(6U), CBitField(3U) };
	CBitField row2_data[] = { CBitField(2U), CBitField(1U) };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(CBitField));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(CBitField));

	CTable<CBitField> table2(std::move(table1));
	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_EQ(table2.get_rows_number(), 2);
	EXPECT_EQ(table2.get_value(0, 0).getValue(), 6U);
	EXPECT_EQ(table2.get_value(0, 1).getValue(), 3U);
	EXPECT_EQ(table2.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table2.get_value(1, 1).getValue(), 1U);
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");

	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
	EXPECT_THROW(table1.get_value(0, 0).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(0, 1).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(1, 0).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(1, 1).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(0), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(1), ColumnNameIndexOutOfRangeException);

	CTable<CBitField> table3 = std::move(table2);
	EXPECT_EQ(table3.get_columns_number(), 2);
	EXPECT_EQ(table3.get_rows_number(), 2);
	EXPECT_EQ(table3.get_value(0, 0).getValue(), 6U);
	EXPECT_EQ(table3.get_value(0, 1).getValue(), 3U);
	EXPECT_EQ(table3.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table3.get_value(1, 1).getValue(), 1U);
	EXPECT_STREQ(table3.get_column_name(0), "Column1");
	EXPECT_STREQ(table3.get_column_name(1), "Column2");

	EXPECT_EQ(table2.get_columns_number(), 0);
	EXPECT_EQ(table2.get_rows_number(), 0);
	EXPECT_THROW(table2.get_value(0, 0).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(0, 1).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(1, 0).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(1, 1).getValue(), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_column_name(0), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table2.get_column_name(1), ColumnNameIndexOutOfRangeException);
}

TEST(CTableBitField, AdditionOperatorTest) {
	CTable<CBitField> table1;
	CTable<CBitField> table2;
	const CBitField row1_data[] = { CBitField(6U), CBitField(3U) };
	const CBitField row2_data[] = { CBitField(2U), CBitField(1U) };
	const CBitField row3_data[] = { CBitField(3U), CBitField(6U) };
	const CBitField row4_data[] = { CBitField(2U), CBitField(4U) };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table2.add_column("Column1");
	table2.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(CBitField));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(CBitField));
	table2.add_row(row3_data, sizeof(row3_data) / sizeof(CBitField));
	table2.add_row(row4_data, sizeof(row4_data) / sizeof(CBitField));

	const CTable<CBitField> table3 = table1 + table2;

	EXPECT_EQ(table1.get_value(0, 0).getValue(), 6U);
	EXPECT_EQ(table1.get_value(0, 1).getValue(), 3U);
	EXPECT_EQ(table1.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table1.get_value(1, 1).getValue(), 1U);

	EXPECT_EQ(table2.get_value(0, 0).getValue(), 3U);
	EXPECT_EQ(table2.get_value(0, 1).getValue(), 6U);
	EXPECT_EQ(table2.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table2.get_value(1, 1).getValue(), 4U);

	EXPECT_EQ(table3.get_value(0, 0).getValue(), 7U);
	EXPECT_EQ(table3.get_value(0, 1).getValue(), 7U);
	EXPECT_EQ(table3.get_value(1, 0).getValue(), 2U);
	EXPECT_EQ(table3.get_value(1, 1).getValue(), 5U);
}

TEST(CTableBitField, InputOperatorTest) {
	// stream format:
	// n m (n - columns number, m - rows number)
	// ColumnName1\tColumnName2\t...
	// data[0][0]\t data[0][1]\t...
	// data[1][0]\t data[1][1]\t...
	std::istringstream in;
	in.str("2 2\n"
		"Animal\tPlant\n"
		"00000000000000000000000000000011\t00000000000000000000000000000001\n"
		"00000000000000000000000000000101\t00000000000000000100000000000001\n");

	CTable<CBitField> table1;
	in >> table1;

	EXPECT_STREQ(table1.get_column_name(0), "Animal");
	EXPECT_STREQ(table1.get_column_name(1), "Plant");
	EXPECT_EQ(table1.get_columns_number(), 2);
	EXPECT_EQ(table1.get_rows_number(), 2);

	EXPECT_EQ(table1.get_value(0, 0).getValue(), 3);
	EXPECT_EQ(table1.get_value(0, 1).getValue(), 1);
	EXPECT_EQ(table1.get_value(1, 0).getValue(), 5);
	EXPECT_EQ(table1.get_value(1, 1).getValue(), 16385);
}

TEST(CTableBitField, OutputOperatorTest) {
	CTable<CBitField> table1;
	const CBitField row1_data[] = { CBitField(6U), CBitField(3U) };
	const CBitField row2_data[] = { CBitField(2U), CBitField(1U) };
	const CBitField row3_data[] = { CBitField(3U), CBitField(6U) };
	const CBitField row4_data[] = { CBitField(2U), CBitField(4U) };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(CBitField));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(CBitField));
	table1.add_row(row3_data, sizeof(row3_data) / sizeof(CBitField));
	table1.add_row(row4_data, sizeof(row4_data) / sizeof(CBitField));

	std::ostringstream out;

	out << table1;

	EXPECT_STREQ(out.str().c_str(),"4 2\n"
			"Column1\tColumn2\n"
			"00000000000000000000000000000110\t00000000000000000000000000000011\n"
			"00000000000000000000000000000010\t00000000000000000000000000000001\n"
			"00000000000000000000000000000011\t00000000000000000000000000000110\n"
			"00000000000000000000000000000010\t00000000000000000000000000000100\n");
}

///////////////////////////////////////////////

bool newFail = false;

void* operator new(size_t n) {
	if (newFail) {
		throw std::bad_alloc();
	}

	return malloc(n);
}

void operator delete(void* p) {
	free(p);
}

TEST(CTableExceptions, BadAllocExceptionTest) {
	newFail = true;
	CTable<int> table;
	EXPECT_THROW(table.add_column("Name"), std::bad_alloc);
	newFail = false;
}

TEST(CTableExceptions, InputStreamExceptionTest) {
	CTable<int> table;

	std::istringstream in(" ");
	EXPECT_THROW(in >> table, StreamException);

	in.clear();
	in.str("2 3");
	EXPECT_THROW(in >> table, StreamException);

	in.clear();
	in.str("4 5\n"
		"Animal\tBacteria\tVirus\n"
		"23\t31\t65\t8\t1\n"
		"109\t7\t64\t84\t12\n"
		"72\t99\t16\t34\t12\n"
		"1\t2\t3\t4\t5\n");
	EXPECT_THROW(in >> table, StreamException);

	in.clear();
	in.str("4 5\n"
		"23\t31\t65\t8\t1\n"
		"109\t7\t64\t84\t12\n"
		"72\t99\t16\t34\t12\n"
		"1\t2\t3\t4\t5\n");
	EXPECT_THROW(in >> table, StreamException);

	in.clear();
	in.str("4");
	EXPECT_THROW(in >> table, StreamException);
}

TEST(CTableExceptions, NonEmptyTableColumnExceptionTest) {
	CTable<int> table1;
	constexpr int row1_data[] = { 11, 21 };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, std::size(row1_data));
	EXPECT_THROW(table1.add_column("Column3"), NonEmptyTableColumnException);

	CTable<int> table2;
	constexpr int row2_data[] = { 1 };

	table2.add_column("Column1");
	table2.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	EXPECT_THROW(table2.add_column("Column3"), NonEmptyTableColumnException);
}

TEST(CTableExceptions, RowSizeMismatchExceptionTest) {
	CTable<int> table1;
	constexpr int row1_data[] = { 11, 21 };
	table1.add_column("Column3");
	EXPECT_THROW(table1.add_row(row1_data, sizeof(row1_data) / sizeof(int)), RowSizeMismatchException);

	CTable<int> table2;
	constexpr int row2_data[] = { 0 };
	EXPECT_THROW(table2.add_row(row2_data, 0), RowSizeMismatchException);

	CTable<int> table3;
	constexpr int row3_data[] = { 4, 6, 2, 1 };
	table3.add_column("Column1");
	table3.add_column("Column2");
	EXPECT_THROW(table3.add_row(row3_data, sizeof(row3_data) / sizeof(int)), RowSizeMismatchException);
}

TEST(CTableExceptions, ColumnNameIndexOutOfRangeExceptionTest) {
	CTable<int> table1;
	table1.add_column("Column1");
	EXPECT_THROW(table1.get_column_name(1), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(9), ColumnNameIndexOutOfRangeException);

	const CTable<int> table2;
	EXPECT_THROW(table2.get_column_name(0), ColumnNameIndexOutOfRangeException);

	CTable<int> table3;
	table3.add_column("Column1");
	table3.add_column("Column2");
	table3.add_column("Column3");
	table3.add_column("Column4");
	table3.add_column("Column5");
	EXPECT_THROW(table2.get_column_name(5), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table2.get_column_name(6), ColumnNameIndexOutOfRangeException);
}

TEST(CTableExceptions, TableValueIndexOutOfRangeExceptionTest) {
	CTable<int> table1;
	table1.add_column("Column1");
	constexpr int row1_data[] = { 11 };
	constexpr int row2_data[] = { 21 };
	table1.add_row(row1_data, 1);
	table1.add_row(row2_data, 1);
	EXPECT_THROW(table1.get_value(0, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(1, 2), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(3, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(10, 10), TableValueIndexOutOfRangeException);

	const CTable<int> table2;
	EXPECT_THROW(table2.get_value(0, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(1, 2), TableValueIndexOutOfRangeException);
}

TEST(CTableExceptions, TablesSizeMismatchExceptionTest) {
	CTable<int> table1;
	table1.add_column("Column1");
	table1.add_column("Column2");
	constexpr int row11_data[] = { 11, 21 };
	constexpr int row12_data[] = { 12, 22 };
	table1.add_row(row11_data, 2);
	table1.add_row(row12_data, 2);

	CTable<int> table2;
	table2.add_column("Column1");
	table2.add_column("Column2");
	table2.add_column("Column3");
	constexpr int row21_data[] = { 11, 21, 31 };
	constexpr int row22_data[] = { 12, 22, 32 };
	table2.add_row(row21_data, 3);
	table2.add_row(row22_data, 3);

	EXPECT_THROW(table1 + table2, TablesSizeMismatchException);

	CTable<int> table3;
	table3.add_column("Column1");
	constexpr int row31_data[] = { 11 };
	table3.add_row(row31_data, 1);

	CTable<int> table4;
	table4.add_column("Column1");
	constexpr int row41_data[] = { 11 };
	constexpr int row42_data[] = { 12 };
	constexpr int row43_data[] = { 13 };
	table4.add_row(row41_data, 1);
	table4.add_row(row42_data, 1);
	table4.add_row(row43_data, 1);

	EXPECT_THROW(table3.operator+(table4), TablesSizeMismatchException);
}

////////////////////////////////////

TEST(FindElementInArrayFunction, IntTest) {
	// Empty array
	int* array1 = nullptr; // size = 0
	EXPECT_EQ(findElementInArray(array1, 0, 0), 0);
	EXPECT_EQ(findElementInArray(array1, 0, 2), 0);

	// One elem
	int array2[] = { 5 }; // size = 1
	EXPECT_EQ(findElementInArray(array2, 1, 5), 0);
	EXPECT_EQ(findElementInArray(array2, 1, 2), 1);

	// Two different elements
	int array3[] = { 23, 1 }; // size = 2
	EXPECT_EQ(findElementInArray(array3, 2, 23), 0);
	EXPECT_EQ(findElementInArray(array3, 2, 1), 1);
	EXPECT_EQ(findElementInArray(array3, 2, 2), 2);

	// Five different elements
	int array4[] = { 7, 21, 4, 3, 1 }; // size = 5
	EXPECT_EQ(findElementInArray(array4, 5, 21), 1);
	EXPECT_EQ(findElementInArray(array4, 5, 3), 3);
	EXPECT_EQ(findElementInArray(array4, 5, 100), 5);

	// Two equal elements
	int array5[] = { 1, 5, 3, 1, 6, 6}; // size = 6
	EXPECT_EQ(findElementInArray(array5, 6, 1), 0);
	EXPECT_EQ(findElementInArray(array5, 6, 6), 4);
	EXPECT_EQ(findElementInArray(array5, 6, 3), 2);

	// All elements are equal
	int array6[] = { 3, 3, 3, 3 }; // size = 4
	EXPECT_EQ(findElementInArray(array6, 4, 3), 0);
	EXPECT_EQ(findElementInArray(array6, 4, 30), 4);
}

TEST(FindElementInArrayFunction, BoolTest) {
	// Empty array
	bool* array1 = nullptr; // size = 0
	EXPECT_EQ(findElementInArray(array1, 0, true), 0);
	EXPECT_EQ(findElementInArray(array1, 0, false), 0);

	// One elem
	bool array2[] = { false }; // size = 1
	EXPECT_EQ(findElementInArray(array2, 1, true), 1);
	EXPECT_EQ(findElementInArray(array2, 1, false), 0);

	// Elements repeating
	bool array3[] = { false, true, true, false }; // size = 4
	EXPECT_EQ(findElementInArray(array3, 4, true), 1);
	EXPECT_EQ(findElementInArray(array3, 4, false), 0);
}

TEST(FindElementInArrayFunction, BitFieldTest) {
	// Empty array
	CBitField* array1 = nullptr; // size = 0
	EXPECT_EQ(findElementInArray(array1, 0, CBitField(5)), 0);
	EXPECT_EQ(findElementInArray(array1, 0, CBitField(0)), 0);

	// One elem
	CBitField array2[] = { CBitField(1) }; // size = 1
	EXPECT_EQ(findElementInArray(array2, 1, CBitField(1)), 0);
	EXPECT_EQ(findElementInArray(array2, 1, CBitField(53)), 1);

	// Three different elements
	CBitField array3[] = { CBitField(10), CBitField(5), CBitField(2) }; // size = 3
	EXPECT_EQ(findElementInArray(array3, 3, CBitField(10)), 0);
	EXPECT_EQ(findElementInArray(array3, 3, CBitField(2)), 2);
	EXPECT_EQ(findElementInArray(array3, 3, CBitField(10000)), 3);

	// Elements repeating
	CBitField array4[] = { CBitField(10), CBitField(5), CBitField(5), CBitField(5) }; // size = 4
	EXPECT_EQ(findElementInArray(array4, 4, CBitField(10)), 0);
	EXPECT_EQ(findElementInArray(array4, 4, CBitField(5)), 1);
	EXPECT_EQ(findElementInArray(array4, 4, CBitField(0)), 4);
}
