#include "pch.h"
#include "../oop_lab9_prog/ctable.h"
#include "../oop_lab9_prog/exceptions.h"

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
	CTable table;
	EXPECT_THROW(table.add_column("Name"), std::bad_alloc);
	newFail = false;
}

TEST(CTableExceptions, InputStreamExceptionTest) {
	CTable table;

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
	CTable table1;
	int row1_data[] = { 11, 21 };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	EXPECT_THROW(table1.add_column("Column3"), NonEmptyTableColumnException);

	CTable table2;
	int row2_data[] = { 1 };

	table2.add_column("Column1");
	table2.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	EXPECT_THROW(table2.add_column("Column3"), NonEmptyTableColumnException);
}

TEST(CTableExceptions, RowSizeMismatchExceptionTest) {
	CTable table1;
	int row1_data[] = { 11, 21 };
	table1.add_column("Column3");
	EXPECT_THROW(table1.add_row(row1_data, sizeof(row1_data) / sizeof(int)), RowSizeMismatchException);

	CTable table2;
	int row2_data[] = { 0 };
	EXPECT_THROW(table2.add_row(row2_data, 0), RowSizeMismatchException);

	CTable table3;
	int row3_data[] = { 4, 6, 2, 1 };
	table3.add_column("Column1");
	table3.add_column("Column2");
	EXPECT_THROW(table3.add_row(row3_data, sizeof(row3_data) / sizeof(int)), RowSizeMismatchException);
}

TEST(CTableExceptions, ColumnNameIndexOutOfRangeExceptionTest) {
	CTable table1;
	table1.add_column("Column1");
	EXPECT_THROW(table1.get_column_name(1), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table1.get_column_name(9), ColumnNameIndexOutOfRangeException);

	CTable table2;
	EXPECT_THROW(table2.get_column_name(0), ColumnNameIndexOutOfRangeException);

	CTable table3;
	table3.add_column("Column1");
	table3.add_column("Column2");
	table3.add_column("Column3");
	table3.add_column("Column4");
	table3.add_column("Column5");
	EXPECT_THROW(table2.get_column_name(5), ColumnNameIndexOutOfRangeException);
	EXPECT_THROW(table2.get_column_name(6), ColumnNameIndexOutOfRangeException);
}

TEST(CTableExceptions, TableValueIndexOutOfRangeExceptionTest) {
	CTable table1;
	table1.add_column("Column1");
	int row1_data[] = { 11 };
	int row2_data[] = { 21 };
	table1.add_row(row1_data, 1);
	table1.add_row(row2_data, 1);
	EXPECT_THROW(table1.get_value(0, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(1, 2), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(3, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(10, 10), TableValueIndexOutOfRangeException);

	CTable table2;
	EXPECT_THROW(table2.get_value(0, 0), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table2.get_value(1, 2), TableValueIndexOutOfRangeException);
}

TEST(CTableExceptions, TablesSizeMismatchExceptionTest) {
	CTable table1;
	table1.add_column("Column1");
	table1.add_column("Column2");
	int row11_data[] = { 11, 21 };
	int row12_data[] = { 12, 22 };
	table1.add_row(row11_data, 2);
	table1.add_row(row12_data, 2);

	CTable table2;
	table2.add_column("Column1");
	table2.add_column("Column2");
	table2.add_column("Column3");
	int row21_data[] = { 11, 21, 31 };
	int row22_data[] = { 12, 22, 32 };
	table2.add_row(row21_data, 3);
	table2.add_row(row22_data, 3);

	EXPECT_THROW(table1 + table2, TablesSizeMismatchException);

	CTable table3;
	table3.add_column("Column1");
	int row31_data[] = { 11 };
	table3.add_row(row31_data, 1);
	
	CTable table4;
	table4.add_column("Column1");
	int row41_data[] = { 11 };
	int row42_data[] = { 12 };
	int row43_data[] = { 13 };
	table4.add_row(row41_data, 1);
	table4.add_row(row42_data, 1);
	table4.add_row(row43_data, 1);

	EXPECT_THROW(table3.operator+(table4), TablesSizeMismatchException);
}


TEST(CTable, DefaultConstructorTest) {
	CTable table1;
	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
}

TEST(CTable, CopyConstructorTest) {
	CTable table1;
	int row1_data[] = { 11, 21, 31 };
	int row2_data[] = { 12, 22, 32 };
	int row3_data[] = { 13, 23, 33 };
	int row4_data[] = { 14, 24, 34 };

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

	CTable table2(table1);
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

TEST(CTable, MoveConstructorTest) {
	CTable table1;
	int row1_data[] = { 11, 21, 31 };
	int row2_data[] = { 12, 22, 32 };
	int row3_data[] = { 13, 23, 33 };
	int row4_data[] = { 14, 24, 34 };

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

	CTable table2 = std::move(table1);
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

TEST(CTable, AssignmentOperatorTest) {
	CTable table1;
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

	CTable table2 = table1;

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

TEST(CTable, MoveOperatorTest) {
	CTable table1;
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

	CTable table2 = std::move(table1);

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

TEST(CTable, AdditionOperatorTest) {
	CTable table1;
	CTable table2;
	const int row1_data[] = { 11, 21, 31 };
	const int row2_data[] = { 12, 22, 32 };
	const int row3_data[] = { 13, 23, 33 };
	const int row4_data[] = { 14, 24, 34 };

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

	CTable table3 = table1 + table2;

	EXPECT_EQ(table3.get_value(0, 0), 24);
	EXPECT_EQ(table3.get_value(0, 1), 44);
	EXPECT_EQ(table3.get_value(0, 2), 64);
	EXPECT_EQ(table3.get_value(1, 0), 26);
	EXPECT_EQ(table3.get_value(1, 1), 46);
	EXPECT_EQ(table3.get_value(1, 2), 66);

	EXPECT_THROW(table1.get_value(1000, 1), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(3, 5), TableValueIndexOutOfRangeException);
	EXPECT_THROW(table1.get_value(0, 5), TableValueIndexOutOfRangeException);

	int wrong_row_data[] = { 5, 6, 7, 4 };

	EXPECT_THROW(table1.add_row(wrong_row_data, sizeof(wrong_row_data) / sizeof(int)), RowSizeMismatchException);

	EXPECT_EQ(table1.get_columns_number(), 3);
	EXPECT_EQ(table1.get_rows_number(), 2);
	EXPECT_EQ(table1.get_value(0, 0), 11);
	EXPECT_EQ(table1.get_value(1, 0), 12);
	EXPECT_EQ(table1.get_value(0, 1), 21);
}


TEST(CTable, InputOperatorTest) {
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

	CTable table1;
	in >> table1;

	EXPECT_STREQ(table1.get_column_name(0), "Animal");
	EXPECT_STREQ(table1.get_column_name(1), "Plant");
	EXPECT_STREQ(table1.get_column_name(2), "Fungus");
	EXPECT_STREQ(table1.get_column_name(3), "Bacteria");
	EXPECT_STREQ(table1.get_column_name(4), "Virus");
	EXPECT_THROW(table1.get_column_name(6), ColumnNameIndexOutOfRangeException);
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

	EXPECT_THROW(table1.get_value(5, 1), TableValueIndexOutOfRangeException);
}

TEST(CTable, OutputOperatorTest) {
	// Test correct input
	CTable table1;
	int row1_data[] = { 1, 2 };
	int row2_data[] = { 3, 4 };
	int row3_data[] = { 5, 6 };
	int row4_data[] = { 7, 8 };
	int row5_data[] = { 9, 0 };

	table1.add_column("Column1");
	table1.add_column("Column2");
	table1.add_row(row1_data, sizeof(row1_data) / sizeof(int));
	table1.add_row(row2_data, sizeof(row2_data) / sizeof(int));
	table1.add_row(row3_data, sizeof(row3_data) / sizeof(int));
	table1.add_row(row4_data, sizeof(row4_data) / sizeof(int));
	table1.add_row(row5_data, sizeof(row5_data) / sizeof(int));

	std::ostringstream out;

	out << table1;

	EXPECT_STREQ(out.str().c_str(), "2 5\nColumn1\tColumn2\n1\t2\n3\t4\n5\t6\n7\t8\n9\t0\n");
}
