#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>

class CChessman {
public:
	CChessman(bool is_white, unsigned char position);

	void PrintName(std::ostream& out_stream) const;

	unsigned char get_row() const;
	unsigned char get_col() const;

protected:
	bool m_is_white;
	unsigned char m_row;
	unsigned char m_col;
};

class CKnight : public CChessman {
public:
	CKnight(bool is_white, unsigned char position);

	bool CanCapturePosition(unsigned char position) const;

	void PrintName(std::ostream& out_stream) const;
};

class CRook : public CChessman {
public:
	CRook(bool is_white, unsigned char position);

	bool CanCapturePosition(unsigned char position) const;

	void PrintName(std::ostream& out_stream) const;
};

class CQueen : public CRook {
public:
	CQueen(bool is_white, unsigned char position);

	bool CanCapturePosition(unsigned char position) const;

	void PrintName(std::ostream& out_stream) const;
};

#endif // CLASSES_H_