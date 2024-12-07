#ifndef C_TABLE_H
#define C_TABLE_H

#include <iostream>
#include "exceptions.h"

template<typename T>
class CTable {
public:
    CTable() noexcept :
        m_data_(nullptr),
        m_columns_names_(nullptr),
        m_columns_number_(0),
        m_rows_number_(0) {}

    CTable(const CTable& table) :
        // Copy columns/rows sizes directly
        m_columns_number_(table.m_columns_number_),
        m_rows_number_(table.m_rows_number_) {
        // Copy data to newly allocated memory
        m_data_ = new T * [m_rows_number_ * sizeof(T*)];

        for (size_t i = 0; i < m_rows_number_; i++) {
            m_data_[i] = new T[m_columns_number_ * sizeof(T)];

            for (size_t j = 0; j < m_columns_number_; j++) {
                m_data_[i][j] = table.m_data_[i][j];
            }
        }

        m_columns_names_ = new char* [m_columns_number_ * sizeof(char*)];

        for (size_t i = 0; i < m_columns_number_; i++) {
            const size_t size = strlen(table.m_columns_names_[i]) + 1;
            m_columns_names_[i] = new char[size];
            strcpy_s(m_columns_names_[i], size, table.m_columns_names_[i]);
        }
    }

    CTable(CTable&& table) noexcept :
        // Get all the data directly
        m_data_(table.m_data_),
        m_columns_names_(table.m_columns_names_),
        m_columns_number_(table.m_columns_number_),
        m_rows_number_(table.m_rows_number_) {
        // Disconnect table pointers from the data
        table.m_data_ = nullptr;
        table.m_columns_names_ = nullptr;
        table.m_columns_number_ = 0;
        table.m_rows_number_ = 0;
    }

    ~CTable() {
        clear();
    }

    CTable<T>& operator=(const CTable& table) {
        // Guard self-assignment
        if (this == &table) {
            return *this;
        }

        clear();
        m_rows_number_ = table.m_rows_number_;
        m_columns_number_ = table.m_columns_number_;

        // Write new data
        m_data_ = new T * [table.m_rows_number_];

        for (size_t i = 0; i < m_rows_number_; i++) {
            m_data_[i] = new T[table.m_columns_number_];
            for (size_t j = 0; j < m_columns_number_; j++) {
                m_data_[i][j] = table.m_data_[i][j];
            }
        }

        m_columns_names_ = new char* [m_columns_number_];

        for (size_t i = 0; i < m_columns_number_; i++) {
            const size_t size = strlen(table.m_columns_names_[i]) + 1;
            m_columns_names_[i] = new char[size];
            strcpy_s(m_columns_names_[i], size, table.m_columns_names_[i]);
        }

        return *this;
    }

    CTable<T>& operator=(CTable&& table) noexcept {
        // Check if it is not the same object
        if (this != &table) {
            // Get the data directly
            m_data_ = table.m_data_;
            m_columns_names_ = table.m_columns_names_;
            m_columns_number_ = table.m_columns_number_;
            m_rows_number_ = table.m_rows_number_;

            table.m_data_ = nullptr;
            table.m_columns_names_ = nullptr;
            table.m_columns_number_ = 0;
            table.m_rows_number_ = 0;
        }

        return *this;
    }

    CTable<T> operator+(const CTable& table) const {
        if (m_data_ == nullptr || table.m_data_ == nullptr) {
            throw TablesSizeMismatchException();
        }

        if (m_columns_number_ != table.m_columns_number_ || m_rows_number_ != table.m_rows_number_) {
            throw TablesSizeMismatchException();
        }

        CTable result(table);

        for (size_t i = 0; i < m_rows_number_; i++) {
            for (size_t j = 0; j < m_columns_number_; j++) {
                result.m_data_[i][j] = result.m_data_[i][j] + m_data_[i][j];
            }
        }

        return result;
    }

    void add_column(const char* column_name) {
        // Name cannot contain \t character
        if (strchr(column_name, '\t') != nullptr || strchr(column_name, '\n') != nullptr) {
            throw ColumnWrongNameException();
        }

        if (m_data_ != nullptr) {
            throw NonEmptyTableColumnException();
        }

        const size_t new_columns_number = m_columns_number_ + 1;

        // Potentially throws std::bad_alloc
        char** new_columns_names = new char* [new_columns_number * sizeof(char*)];

        for (size_t i = 0; i < new_columns_number - 1; i++) {
            new_columns_names[i] = m_columns_names_[i];
        }

        size_t size = strlen(column_name) + 1;

        if (size > 256) {
            size = 256;
        }

        // Potentially throws std::bad_alloc
        new_columns_names[new_columns_number - 1] = new char[size];
        strncpy_s(new_columns_names[new_columns_number - 1], size, column_name, 256);

        delete[] m_columns_names_;
        m_columns_names_ = new_columns_names;
        m_columns_number_ = new_columns_number;
    }

    void add_row(const T* row_data, size_t row_size) {
        if (row_size == 0 || row_size != m_columns_number_) {
            throw RowSizeMismatchException();
        }

        const size_t new_rows_number = m_rows_number_ + 1;

        // Potentially throws std::bad_alloc
        T** new_data = new T * [new_rows_number * sizeof(T*)];
        for (size_t i = 0; i < new_rows_number - 1; i++) {
            new_data[i] = m_data_[i];
        }

    	// Potentially throws std::bad_alloc
        new_data[new_rows_number - 1] = new T[row_size * sizeof(T)];
        for (size_t i = 0; i < m_columns_number_; i++) {
            new_data[new_rows_number - 1][i] = row_data[i];
        }

        delete[] m_data_;
        m_data_ = new_data;
        m_rows_number_ = new_rows_number;
    }

    size_t get_columns_number() const {
        return m_columns_number_;
    }

    size_t get_rows_number() const {
        return m_rows_number_;
    }

    const char* get_column_name(const size_t index) const {
        if (index >= m_columns_number_) {
            throw ColumnNameIndexOutOfRangeException();
        }

        return m_columns_names_[index];
    }

    const T& get_value(const size_t row, const size_t column) const {
        if (row >= m_rows_number_ || column >= m_columns_number_) {
            throw TableValueIndexOutOfRangeException();
        }

        return m_data_[row][column];
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const CTable<U>& table);

    template<typename U>
    friend std::istream& operator>>(std::istream& is, CTable<U>& table);

private:
    void clear() noexcept {
        for (size_t i = 0; i < m_rows_number_; i++) {
            delete[] m_data_[i];
        }
        delete[] m_data_;
        m_data_ = nullptr;

        for (size_t i = 0; i < m_columns_number_; i++) {
            delete[] m_columns_names_[i];
        }
        delete[] m_columns_names_;
        m_columns_names_ = nullptr;

        m_columns_number_ = 0;
        m_rows_number_ = 0;
    }

    T** m_data_;
    char** m_columns_names_;
    size_t m_columns_number_;
    size_t m_rows_number_;
};

template<typename T>
std::istream& operator>>(std::istream& is, CTable<T>& table) {
    table.clear();

    is >> table.m_rows_number_;
    is >> table.m_columns_number_;

    table.m_columns_names_ = new char* [table.m_columns_number_];

    is.get(); // skip '\n'
    for (size_t i = 0; i < table.m_columns_number_; i++) {
        char temp[256];
        if (i == table.m_columns_number_ - 1) {
            is.getline(temp, 256, '\n');
        } else {
            is.getline(temp, 256, '\t');
        }
        const size_t size = strlen(temp) + 1;
        table.m_columns_names_[i] = new char[size];
        strcpy_s(table.m_columns_names_[i], size, temp);
    }

    table.m_data_ = new T * [table.m_rows_number_];

    for (size_t i = 0; i < table.m_rows_number_; i++) {
        table.m_data_[i] = new T[table.m_columns_number_];
        for (size_t j = 0; j < table.m_columns_number_; j++) {
            is >> table.m_data_[i][j];
        }
    }

    if (!is.good()) {
        throw StreamException{};
    }

    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const CTable<T>& table) {
    // stream format:
    // n m (n - rows number, m - columns number)
    // ColumnName1\tColumnName2\t...
    // data[0][0]\t data[0][1]\t...
    // data[1][0]\t data[1][1]\t...

    os << table.m_rows_number_ << ' ' << table.m_columns_number_ << '\n';
    char sep = '\t';

    for (size_t i = 0; i < table.m_columns_number_; i++) {
        if (i == table.m_columns_number_ - 1) {
            sep = '\n';
        }
        os << table.m_columns_names_[i] << sep;
    }

    for (size_t i = 0; i < table.m_rows_number_; i++) {
        sep = '\t';

        for (size_t j = 0; j < table.m_columns_number_; j++) {
            if (j == table.m_columns_number_ - 1) {
                sep = '\n';
            }

            os << table.m_data_[i][j] << sep;
        }
    }

    if (!os.good()) {
        throw StreamException();
    }

    return os;
}

#endif // C_TABLE_H
