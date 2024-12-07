#ifndef C_TABLE_H_
#define C_TABLE_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "exceptions.h"

template<typename T>
class CTable {
public:
    CTable() = default;

    CTable(const CTable& table)
        // Copy columns/rows sizes directly
		: m_data_(table.m_data_)
        , m_columns_names_(table.m_columns_names_) {}

    CTable(CTable&& table) noexcept
        // Get all the data directly
		: m_data_(std::move(table.m_data_))
        , m_columns_names_(std::move(table.m_columns_names_)) {}

    ~CTable() {
        clear();
    }

    CTable<T>& operator=(const CTable& table) {
        // Guard self-assignment
        if (this == &table) {
            return *this;
        }

        m_data_ = table.m_data_;
        m_columns_names_ = table.m_columns_names_;
        
        return *this;
    }

    CTable<T>& operator=(CTable&& table) noexcept {
        // Guard self-assignment
        if (this == &table) {
            return *this;
        }

        m_data_ = std::move(table.m_data_);
        m_columns_names_ = std::move(table.m_columns_names_);

        return *this;
    }

    CTable<T> operator+(const CTable<T>& other) const {
        if (m_columns_names_.size() != other.m_columns_names_.size()) {
            throw TablesSizeMismatchException();
        }

        CTable<T> result;

        result.m_columns_names_ = m_columns_names_;
        
        result.m_data_.resize(m_data_.size() + other.m_data_.size());
        std::copy(m_data_.begin(), m_data_.end(), result.m_data_.begin());
        std::copy(other.m_data_.begin(), other.m_data_.end(), result.m_data_.begin() + m_data_.size());

        return result;
    }

    void add_column(const char* column_name) {
        add_column(std::string(column_name));
    }

    void add_column(const std::string& column_name) {
        // Name cannot contain \t character
        if (column_name.find('\t') != std::string::npos || column_name.find('\n') != std::string::npos) {
            throw ColumnWrongNameException();
        }

        if (m_data_.size() != 0) {
            throw NonEmptyTableColumnException();
        }

        m_columns_names_.push_back(column_name);
    }

    void add_row(const T* row_data, size_t row_size) {
        if (row_size == 0 || row_size != m_columns_names_.size()) {
            throw RowSizeMismatchException();
        }

        
        m_data_.resize(m_data_.size() + row_size);
        std::copy(row_data, row_data + row_size, m_data_.end() - row_size);
    }

    size_t get_columns_number() const {
        return m_columns_names_.size();
    }

    size_t get_rows_number() const {
        if (m_columns_names_.empty()) {
            return 0;
        }

        return m_data_.size() / m_columns_names_.size();
    }

    const std::string& get_column_name(const size_t index) const {
        if (index >= m_columns_names_.size()) {
            throw ColumnNameIndexOutOfRangeException();
        }

        return m_columns_names_[index];
    }

    const T& get_value(const size_t row, const size_t column) const {
        if (row >= get_rows_number() || column >= m_columns_names_.size()) {
            throw TableValueIndexOutOfRangeException();
        }

        return m_data_[row * m_columns_names_.size() + column];
    }

    std::vector<std::vector<T>> get_data() const {
        std::vector<std::vector<T>> result;
        const size_t rows = get_rows_number();
        const size_t columns = get_columns_number();

        for (size_t i = 0; i < rows; i++) {
            result.push_back(std::vector<T>(m_data_.begin() + i * columns, m_data_.begin() + (i + 1) * columns));
        }

        return result;
    }

    void reverse_columns() {
        std::ranges::reverse(m_columns_names_);

        const size_t rows = get_rows_number();
        const size_t columns = get_columns_number();

        for (size_t i = 0; i < rows; i++) {
            std::reverse(m_data_.begin() + i * columns, m_data_.begin() + (i + 1) * columns);
        }
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const CTable<U>& table);

    template<typename U>
    friend std::istream& operator>>(std::istream& is, CTable<U>& table);

private:
    void clear() noexcept {
        m_data_.clear();
        m_columns_names_.clear();
    }

    std::vector<T> m_data_;
    std::vector<std::string> m_columns_names_;
};

template<typename T>
std::istream& operator>>(std::istream& is, CTable<T>& table) {
    table.clear();

    size_t rows = 0;
    size_t columns = 0;

    is >> rows >> columns;

    for (size_t i = 0; i < columns; i++) {
    	std::string column_name_to_add;
        is >> column_name_to_add;
        table.m_columns_names_.push_back(column_name_to_add);
    }

    for (size_t i = 0; i < rows * columns; i++) {
        T item;
        is >> item;
        table.m_data_.push_back(item);
    }

    if (!is.good()) {
        table.clear();
    	throw StreamException{};
    }

    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const CTable<T>& table) {
    // stream format:
    // n m (n - rows number, m - columns number)
    // ColumnName1\t ColumnName2\t...
    // data[0][0]\t data[0][1]\t...
    // data[1][0]\t data[1][1]\t...

    const size_t rows = table.get_rows_number();
    const size_t columns = table.get_columns_number();

    os << rows << ' ' << columns << '\n';

    if (columns == 0) {
        return os;
    }

    std::for_each(table.m_columns_names_.begin(), table.m_columns_names_.end(),
        [&os](const std::string& column_name) {
            os << column_name << '\t';
        });

    os << '\n';

    for (size_t i = 0; i < rows; i++) {
        std::for_each(table.m_data_.begin() + i * columns, table.m_data_.begin() + (i + 1) * columns,
            [&os](const T& item) {
                os << item << '\t';
            });

        os << '\n';
    }

    if (!os.good()) {
        throw StreamException();
    }

    return os;
}

#endif // C_TABLE_H_
