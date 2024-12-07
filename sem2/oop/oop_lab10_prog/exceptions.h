#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

class MyException : public std::exception {
protected:
	explicit MyException(const char* message)
		: m_message(message) {}

	const char* what() const noexcept override {
		return m_message;
	}

	const char * m_message;
};

class StreamException : public MyException {
public:
	StreamException()
		: MyException("Exception. Error of stream input/output!") {}
};

class NonEmptyTableColumnException : public MyException {
public:
	NonEmptyTableColumnException()
		: MyException("Exception. You can't add any more columns to nonempty table!") {}
};

class ColumnWrongNameException : public MyException {
public:
	ColumnWrongNameException()
		: MyException("Exception. The column name can't have such characters (\\n, \\t).") {}
};

class RowSizeMismatchException : public MyException {
public:
	RowSizeMismatchException()
		: MyException("Exception. The row to be added must be the size of the columns number!") {}
};

class OutOfRangeException : public MyException {
protected:
	explicit OutOfRangeException(const char* message)
		: MyException(message) {}
};

class ColumnNameIndexOutOfRangeException : public OutOfRangeException {
public:
	ColumnNameIndexOutOfRangeException()
		: OutOfRangeException("Exception. The column names index is out of range.") {}
};

class TableValueIndexOutOfRangeException : public OutOfRangeException {
public:
	TableValueIndexOutOfRangeException()
		: OutOfRangeException("Exception. The table value index is out of range.") {}
};

class TablesSizeMismatchException : public MyException {
public:
	TablesSizeMismatchException()
		: MyException("Exception. You can't perform any operations with tables of different sizes!") {}
};

#endif // EXCEPTIONS_H_
