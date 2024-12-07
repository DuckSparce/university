#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <string>

class MyException : public std::exception {
protected:
	explicit MyException(std::string message);
	~MyException() = default;

	const char * what() const noexcept override;

	std::string m_message;
};

class BadAllocException : public MyException {
public:
	BadAllocException();
	~BadAllocException() = default;
};

class StreamException : public MyException {
public:
	StreamException();
	~StreamException() = default;
};

class NonEmptyTableColumnException : public MyException {
public:
	NonEmptyTableColumnException();
	~NonEmptyTableColumnException() = default;
};

class RowSizeMismatchException : public MyException {
public:
	RowSizeMismatchException();
	~RowSizeMismatchException() = default;
};

class OutOfRangeException : public MyException {
protected:
	explicit OutOfRangeException(const std::string& message);
	~OutOfRangeException() = default;
};

class ColumnNameIndexOutOfRangeException: public OutOfRangeException {
public:
	ColumnNameIndexOutOfRangeException();
	~ColumnNameIndexOutOfRangeException() = default;
};

class TableValueIndexOutOfRangeException : public OutOfRangeException {
public:
	TableValueIndexOutOfRangeException();
	~TableValueIndexOutOfRangeException() = default;
};

class TablesSizeMismatchException : public MyException {
public:
	TablesSizeMismatchException();
	~TablesSizeMismatchException() = default;
};


#endif // EXCEPTIONS_H_
