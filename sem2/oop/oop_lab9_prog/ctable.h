#ifndef C_TABLE_H
#define C_TABLE_H

#include <iostream>

class CTable {
public:
	CTable() noexcept;
	CTable(const CTable& table);
	CTable(CTable&& table) noexcept;
	~CTable();

	CTable& operator=(const CTable& table);
	CTable& operator=(CTable&& table) noexcept;

	CTable operator+(const CTable& table) const;

	void add_column(const char* column_name);
	void add_row(const int* row_data, const unsigned int row_size);

	unsigned int get_columns_number() const;
	unsigned int get_rows_number() const;

	char* get_column_name(const unsigned int index) const;
	int get_value(unsigned int row, unsigned int column) const;

	friend std::ostream& operator<<(std::ostream& os, const CTable& table);
	friend std::istream& operator>>(std::istream& is, CTable& table);

private:
	int** m_data_;
	char** m_columns_names_;
	unsigned int m_columns_number_;
	unsigned int m_rows_number_;
};

#endif // C_TABLE_H
