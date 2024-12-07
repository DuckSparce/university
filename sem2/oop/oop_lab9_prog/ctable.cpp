#include "ctable.h"
#include "exceptions.h"

CTable::CTable() noexcept :
    m_data_(nullptr),
    m_columns_names_(nullptr),
    m_columns_number_(0),
    m_rows_number_(0) {}

CTable::CTable(const CTable& table) :
    // Copy columns/rows sizes directly
    m_columns_number_(table.m_columns_number_),
    m_rows_number_(table.m_rows_number_) {

    // Copy data to newly allocated memory
    m_data_ = new int* [m_rows_number_ * sizeof(int*)];

    for (unsigned int i = 0; i < m_rows_number_; i++) {
        m_data_[i] = new int[m_columns_number_ * sizeof(int)];

        for (unsigned int j = 0; j < m_columns_number_; j++) {
            m_data_[i][j] = table.m_data_[i][j];
        }
    }

    m_columns_names_ = new char* [m_columns_number_ * sizeof(char*)];

    for (unsigned int i = 0; i < m_columns_number_; i++) {
        const size_t size = strlen(table.m_columns_names_[i]) + 1;
        m_columns_names_[i] = new char[size];
        strcpy_s(m_columns_names_[i], size, table.m_columns_names_[i]);
    }
}

CTable::CTable(CTable&& table) noexcept :
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

CTable::~CTable() {
    // Delete all the data and clear DM for each array of m_data_ double array
    for (unsigned int i = 0; i < m_rows_number_; i++) {
        delete[] m_data_[i];
    }
    delete[] m_data_;
    m_data_ = nullptr;

    for (unsigned int i = 0; i < m_columns_number_; i++) {
        delete[] m_columns_names_[i];
    }
    delete[] m_columns_names_;
    m_columns_names_ = nullptr;

    m_rows_number_ = 0;
    m_columns_number_ = 0;
}

CTable& CTable::operator=(const CTable& table) {
    // Check if it is not the same object
    if (this != &table) {
        m_rows_number_ = table.m_rows_number_;
        m_columns_number_ = table.m_columns_number_;

        // Delete previous data
        for (unsigned int i = 0; i < m_rows_number_; i++) {
            delete[] m_data_[i];
        }
        delete[] m_data_;

        for (unsigned int i = 0; i < m_columns_number_; i++) {
            delete[] m_columns_names_[i];
        }
        delete[] m_columns_names_;

        // Write new data
        m_data_ = new int* [table.m_rows_number_];

        for (unsigned int i = 0; i < m_rows_number_; i++) {
            m_data_[i] = new int[table.m_columns_number_];
            for (unsigned int j = 0; j < m_columns_number_; j++) {
                m_data_[i][j] = table.m_data_[i][j];
            }
        }

        m_columns_names_ = new char* [m_columns_number_];

        for (unsigned int i = 0; i < m_columns_number_; i++) {
            const size_t size = strlen(table.m_columns_names_[i]) + 1;
            m_columns_names_[i] = new char[size];
            strcpy_s(m_columns_names_[i], size, table.m_columns_names_[i]);
        }
    }

    return *this;
}

CTable& CTable::operator=(CTable&& table) noexcept {
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

void CTable::add_column(const char* column_name) {
    // Name cannot contain \t character
    if (strchr(column_name, '\t') != nullptr) {
        // Exception
        return;
    }

    if (m_data_ != nullptr) {
        throw NonEmptyTableColumnException();
    }

    unsigned int columns_number = m_columns_number_ + 1;

    char** new_columns_names = new char* [columns_number * sizeof(char*)];

    for (unsigned int i = 0; i < columns_number - 1; i++) {
        new_columns_names[i] = m_columns_names_[i];
    }

    delete[] m_columns_names_;
    m_columns_names_ = new_columns_names;
    size_t size = strlen(column_name) + 1;

    if (size > 256) {
        size = 256;
    }

    m_columns_names_[columns_number - 1] = new char[size];
    strncpy_s(m_columns_names_[columns_number - 1], size, column_name, 256);
    m_columns_number_ = columns_number;
}

void CTable::add_row(const int* row_data, const unsigned int row_size) {
    if (row_size == 0 || row_size != m_columns_number_) {
        throw RowSizeMismatchException();
    }

    m_rows_number_++;
    int** new_data = new int* [m_rows_number_ * sizeof(int*)];
    for (unsigned int i = 0; i < m_rows_number_ - 1; i++) {
        new_data[i] = m_data_[i];
    }
    new_data[m_rows_number_ - 1] = new int[row_size * sizeof(int)];
    memcpy(new_data[m_rows_number_ - 1], row_data, row_size * sizeof(int));

    delete[] m_data_;
    m_data_ = new_data;
}

unsigned int CTable::get_columns_number() const {
    return m_columns_number_;
}

unsigned int CTable::get_rows_number() const {
    return m_rows_number_;
}

char* CTable::get_column_name(const unsigned int index) const {
    if (index >= m_columns_number_) {
        throw ColumnNameIndexOutOfRangeException();
    }

    return m_columns_names_[index];
}

int CTable::get_value(unsigned int row, unsigned int column) const {
    if (row >= m_rows_number_ || column >= m_columns_number_) {
        throw TableValueIndexOutOfRangeException();
    }

    return m_data_[row][column];
}

void CTable::clear() noexcept {
    for (unsigned int i = 0; i < m_rows_number_; i++) {
        delete[] m_data_[i];
    }
    delete[] m_data_;
    m_data_ = nullptr;

    for (unsigned int i = 0; i < m_columns_number_; i++) {
        delete[] m_columns_names_[i];
    }
    delete[] m_columns_names_;
    m_columns_names_ = nullptr;
}

CTable CTable::operator+(const CTable& table) const {
    if (m_data_ == nullptr || table.m_data_ == nullptr) {
        throw TablesSizeMismatchException();
    }

    if (m_columns_number_ != table.m_columns_number_ || m_rows_number_ != table.m_rows_number_) {
        throw TablesSizeMismatchException();
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

    if (!os.good()) {
        throw StreamException();
    }

    return os;
}

std::istream& operator>>(std::istream& is, CTable& table) {
    table.clear();

	is >> table.m_rows_number_;
    is >> table.m_columns_number_;

    table.m_columns_names_ = new char* [table.m_columns_number_];

    is.get(); // skip '\n'
    for (unsigned int i = 0; i < table.m_columns_number_; i++) {
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

    table.m_data_ = new int* [table.m_rows_number_];

    for (unsigned int i = 0; i < table.m_rows_number_; i++) {
        table.m_data_[i] = new int[table.m_columns_number_];
        for (unsigned int j = 0; j < table.m_columns_number_; j++) {
            is >> table.m_data_[i][j];
        }
    }

    if (!is.good()) {
        throw StreamException();
    }

    return is;
}