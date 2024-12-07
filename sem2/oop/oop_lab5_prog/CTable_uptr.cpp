#include "CTable_uptr.h"

CTable::CTable() :
    m_columns_number_(0),
    m_rows_number_(0) {}

CTable::CTable(const CTable& table) :
    m_columns_number_(table.get_columns_number()),
    m_rows_number_(table.get_rows_number()) {
    // Copy data to newly allocated memory
    m_data_.reset(new std::unique_ptr<int[]>[m_rows_number_ * sizeof(std::unique_ptr<int[]>)]);

    for (unsigned int i = 0; i < m_rows_number_; i++) {
        m_data_[i].reset(new int[m_columns_number_ * sizeof(int)]);

        for (unsigned int j = 0; j < m_columns_number_; j++) {
            m_data_[i][j] = table.m_data_[i][j];
        }
    }

    m_columns_names_.reset(new std::unique_ptr<char[]>[m_rows_number_ * sizeof(std::unique_ptr<char[]>)]);

    for (unsigned int i = 0; i < m_columns_number_; i++) {
        const size_t size = strlen(table.m_columns_names_[i].get()) + 1;
        m_columns_names_[i].reset(new char[size]);
        strcpy_s(m_columns_names_[i].get(), size, table.m_columns_names_[i].get());
    }
}

CTable::CTable(CTable&& table) noexcept {
    // Get all the data directly
    m_data_ = std::move(table.m_data_);
    m_columns_names_ = std::move(table.m_columns_names_);
    m_columns_number_ = table.m_columns_number_;
    m_rows_number_ = table.m_rows_number_;
    // Disconnect table pointers from the data
    table.m_data_ = nullptr;
    table.m_columns_names_ = nullptr;
    table.m_columns_number_ = 0;
    table.m_rows_number_ = 0;
}

CTable& CTable::operator=(const CTable& table) {
    // Check if it is not the same object
    if (this != &table) {
        m_rows_number_ = table.m_rows_number_;
        m_columns_number_ = table.m_columns_number_;

        // Write new data
        m_data_.reset(new std::unique_ptr<int[]>[m_rows_number_ * sizeof(std::unique_ptr<int[]>)]);

        for (unsigned int i = 0; i < m_rows_number_; i++) {
            m_data_[i].reset(new int[m_columns_number_]);
            for (unsigned int j = 0; j < m_columns_number_; j++) {
                m_data_[i][j] = table.m_data_[i][j];
            }
        }

        m_columns_names_.reset(new std::unique_ptr<char[]>[m_rows_number_ * sizeof(std::unique_ptr<char[]>)]);

        for (unsigned int i = 0; i < m_columns_number_; i++) {
            const size_t size = strlen(table.m_columns_names_[i].get()) + 1;
            m_columns_names_[i].reset(new char[size]);
            strcpy_s(m_columns_names_[i].get(), size, table.m_columns_names_[i].get());
        }
    }

    return *this;
}

CTable& CTable::operator=(CTable&& table) noexcept {
    // Check if it is not the same object
    if (this != &table) {
        // Get the data directly
        m_data_.reset(table.m_data_.get());
        m_columns_names_.reset(table.m_columns_names_.get());
        m_columns_number_ = table.m_columns_number_;
        m_rows_number_ = table.m_rows_number_;

        table.m_data_ = nullptr;
        table.m_columns_names_ = nullptr;
        table.m_columns_number_ = 0;
        table.m_rows_number_ = 0;
    }

    return *this;
}

bool CTable::add_column(const char* column_name) {
    // Name cannot contain \t character
    if (strchr(column_name, '\t') != nullptr) {
        // Exception
        return false;
    }

    if (m_data_ != nullptr) {
        return false;
    }

    m_columns_number_++;
    std::unique_ptr<std::unique_ptr<char[]>[]> new_columns_names
		(new std::unique_ptr<char[]>[m_columns_number_ * sizeof(std::unique_ptr<char[]>)]);

    for (size_t index = 0; index != m_columns_number_ - 1U; ++index) {
        new_columns_names[index] = std::move(m_columns_names_[index]);
    }

    // create char array and set to the last unique_ptr
    size_t size = strlen(column_name) + 1;

    if (size > 256) {
        size = 256;
    }

    new_columns_names[m_columns_number_ - 1].reset(new char[size]);
    strncpy_s(new_columns_names[m_columns_number_ - 1].get(), size, column_name, 256);
    m_columns_names_ = std::move(new_columns_names);

    return true;
}

bool CTable::add_row(const int* row_data, const unsigned int row_size) {
    if (row_size == 0 || row_size != m_columns_number_) {
        return false;
    }

    m_rows_number_++;

    std::unique_ptr<std::unique_ptr<int[]>[]> new_data
			(new std::unique_ptr<int[]>[m_rows_number_ * sizeof(std::unique_ptr<int[]>)]);
    for (size_t index = 0; index != m_rows_number_ - 1U; ++index) {
        new_data[index] = std::move(m_data_[index]);
    }

    new_data[m_rows_number_ - 1].reset(new int[row_size * sizeof(int)]);
    memcpy(new_data[m_rows_number_ - 1].get(), row_data, row_size * sizeof(int));

    m_data_ = std::move(new_data);

    return true;
}

unsigned int CTable::get_columns_number() const {
    return m_columns_number_;
}

unsigned int CTable::get_rows_number() const {
    return m_rows_number_;
}

char* CTable::get_column_name(const unsigned int index) const {
    if (index >= m_columns_number_) {
        // Index out of range exception
        return nullptr;
    }

    return m_columns_names_[index].get();
}

int CTable::get_value(unsigned int row, unsigned int column) const {
    if (row >= m_rows_number_ || column >= m_columns_number_) {
        // Index out of range exception.
        return 0;
    }

    return m_data_[row][column];
}

CTable CTable::operator+(const CTable& table) const {
    if (m_data_ == nullptr || table.m_data_ == nullptr) {
        // Empty tables exception
        return {};
    }

    if (m_columns_number_ != table.m_columns_number_ || m_rows_number_ != table.m_rows_number_) {
        // Size mismatch exception.
        return {};
    }

    CTable result(table);

    for (unsigned int i = 0; i < m_rows_number_; i++) {
        for (unsigned int j = 0; j < m_columns_number_; j++) {
            result.m_data_[i][j] += m_data_[i][j];
        }
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const CTable& table) {
    // stream format:
    // n m (n - columns number, m - rows number)
    // ColumnName1\tColumnName2\t...
    // data[0][0]\t data[0][1]\t...
    // data[1][0]\t data[1][1]\t...

    os << table.m_columns_number_ << ' ' << table.m_rows_number_ << '\n';
    char sep = '\t';

    for (unsigned int i = 0; i < table.m_columns_number_; i++) {
        if (i == table.m_columns_number_ - 1) {
            sep = '\n';
        }
        os << table.m_columns_names_[i] << sep;
    }

    for (unsigned int i = 0; i < table.m_rows_number_; i++) {
        sep = '\t';

        for (unsigned int j = 0; j < table.m_columns_number_; j++) {
            if (j == table.m_columns_number_ - 1) {
                sep = '\n';
            }

            os << table.m_data_[i][j] << sep;
        }
    }

    return os;
}

std::istream& operator>>(std::istream& is, CTable& table) {
    is >> table.m_rows_number_;
    is >> table.m_columns_number_;

    table.m_columns_names_.reset(new std::unique_ptr<char[]>[table.m_columns_number_ * sizeof(std::unique_ptr<char[]>)]);

    is.get();
    for (unsigned int i = 0; i < table.m_columns_number_; i++) {
        char temp[256];
        if (i == table.m_columns_number_ - 1) {
            is.getline(temp, 256, '\n');
        } else {
            is.getline(temp, 256, '\t');
        }
        const size_t size = strlen(temp) + 1;
        table.m_columns_names_[i].reset(new char[size]);
        memcpy(table.m_columns_names_[i].get(), temp, size);
    }

    table.m_data_.reset(new std::unique_ptr<int[]>[table.m_rows_number_ * sizeof(std::unique_ptr<int[]>)]);
    
    for (unsigned int i = 0; i < table.m_rows_number_; i++) {
        table.m_data_[i].reset(new int[table.m_columns_number_]);
        for (unsigned int j = 0; j < table.m_columns_number_; j++) {
            is >> table.m_data_[i][j];
        }
    }

    return is;
}
