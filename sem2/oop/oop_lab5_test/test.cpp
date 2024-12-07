#include "pch.h"
#include "../oop_lab5_prog/CTable.h"

TEST(CTable, DefaultConstructorTest) {
	CTable table1;
	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
	EXPECT_EQ(table1.get_value(1, 1), 0);
	EXPECT_EQ(table1.get_column_name(5), nullptr);
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
	EXPECT_EQ(table2.get_value(2, 3), 0);
	EXPECT_EQ(table2.get_value(3, 2), 34);
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");
	EXPECT_STREQ(table2.get_column_name(2), "Column3");

	EXPECT_EQ(table1.get_columns_number(), 3);
	EXPECT_EQ(table1.get_rows_number(), 4);
	EXPECT_EQ(table1.get_value(1, 0), 12);
	EXPECT_EQ(table1.get_value(0, 1), 21);
	EXPECT_EQ(table1.get_value(1, 1), 22);
	EXPECT_EQ(table1.get_value(2, 3), 0);
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
	EXPECT_EQ(table2.get_value(2, 3), 0);
	EXPECT_EQ(table2.get_value(3, 2), 34);
	EXPECT_STREQ(table2.get_column_name(0), "Column1");
	EXPECT_STREQ(table2.get_column_name(1), "Column2");
	EXPECT_STREQ(table2.get_column_name(2), "Column3");

	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table1.get_rows_number(), 0);
	EXPECT_EQ(table1.get_value(1, 0), 0);
	EXPECT_EQ(table1.get_value(0, 1), 0);
	EXPECT_EQ(table1.get_value(1, 1), 0);
	EXPECT_EQ(table1.get_value(2, 3), 0);
	EXPECT_EQ(table1.get_value(3, 2), 0);
	EXPECT_STREQ(table1.get_column_name(0), nullptr);
	EXPECT_STREQ(table1.get_column_name(1), nullptr);
	EXPECT_STREQ(table1.get_column_name(2), nullptr);
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

	EXPECT_STRNE(table1.get_column_name(0), table2.get_column_name(0));
	EXPECT_STREQ(table1.get_column_name(0), nullptr);
	EXPECT_STREQ(table2.get_column_name(0), "Odd numbers");
	EXPECT_STRNE(table1.get_column_name(1), table2.get_column_name(1));
	EXPECT_STREQ(table1.get_column_name(1), nullptr);
	EXPECT_STREQ(table2.get_column_name(1), "Even numbers");
	EXPECT_NE(table1.get_columns_number(), table2.get_columns_number());
	EXPECT_EQ(table1.get_columns_number(), 0);
	EXPECT_EQ(table2.get_columns_number(), 2);
	EXPECT_NE(table1.get_rows_number(), table2.get_rows_number());
	EXPECT_EQ(table1.get_rows_number(), 0);
	EXPECT_EQ(table2.get_rows_number(), 5);

	EXPECT_EQ(table1.get_value(0, 0), 0);
	EXPECT_EQ(table2.get_value(1, 0), 3);
	EXPECT_EQ(table1.get_value(2, 0), 0);
	EXPECT_EQ(table2.get_value(3, 0), 7);
	EXPECT_EQ(table1.get_value(4, 0), 0);
	EXPECT_EQ(table2.get_value(0, 1), 2);
	EXPECT_EQ(table1.get_value(1, 1), 0);
	EXPECT_EQ(table2.get_value(2, 1), 6);
	EXPECT_EQ(table1.get_value(3, 1), 0);
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

	EXPECT_EQ(table1.get_value(1000, 1), 0);
	EXPECT_EQ(table1.get_value(3, 5), 0);
	EXPECT_EQ(table1.get_value(0, 5), 0);

	int wrong_row_data[] = { 5, 6, 7, 4 };

	EXPECT_FALSE(table1.add_row(wrong_row_data, sizeof(wrong_row_data) / sizeof(int)));
	EXPECT_FALSE(table1.add_column("Wrong\tcolumn\tname"));

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
	EXPECT_STREQ(table1.get_column_name(6), nullptr);
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

	EXPECT_EQ(table1.get_value(5, 1), 0);
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
