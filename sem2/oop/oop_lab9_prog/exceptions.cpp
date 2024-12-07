#include "exceptions.h"

#include <iostream>

MyException::MyException(std::string message)
	: m_message(std::move(message)) {}

const char* MyException::what() const noexcept {
	return m_message.c_str();
}

BadAllocException::BadAllocException()
	: MyException(std::string("Exception. Bad dynamic memory allocation!")) {}

StreamException::StreamException()
	: MyException(std::string("Exception. Error of stream input/output!")) {}

NonEmptyTableColumnException::NonEmptyTableColumnException()
	: MyException(std::string("Exception. You can't add any more columns to nonempty table!")) {}

RowSizeMismatchException::RowSizeMismatchException()
	: MyException(std::string("Exception. The row to be added must be the size of the columns number!")) {}

OutOfRangeException::OutOfRangeException(const std::string& message)
	: MyException(message) {}

ColumnNameIndexOutOfRangeException::ColumnNameIndexOutOfRangeException()
	: OutOfRangeException(std::string("Exception. The column names index is out of range.")) {}

TableValueIndexOutOfRangeException::TableValueIndexOutOfRangeException()
	: OutOfRangeException(std::string("Exception. The table value index is out of range.")) {}

TablesSizeMismatchException::TablesSizeMismatchException()
	: MyException(std::string("Exception. You can't perform any operations with tables of different sizes!")) {}
