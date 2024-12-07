#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>

class CChessman {
public:
	CChessman(unsigned char position);
	virtual ~CChessman() = default;

	virtual bool CanCapturePosition(unsigned char ucPosition) const = 0;

	virtual void PrintName(std::ostream& out_stream) const = 0;

	unsigned char get_row() const;
	unsigned char get_col() const;

protected:
	unsigned char m_row;
	unsigned char m_col;
};

class CValuable {
protected:
	CValuable(bool is_white, unsigned char points);

	unsigned char get_points() const;
	bool get_is_white() const;

private:
	bool m_is_white;
	unsigned char m_points;
};

class CKnight : public CChessman, protected CValuable {
public:
	CKnight(bool is_white, unsigned char position);

	bool CanCapturePosition(unsigned char position) const override;

	void PrintName(std::ostream& out_stream) const override;
};

class CRook : public CChessman, protected CValuable {
public:
	CRook(bool is_white, unsigned char position);

	bool CanCapturePosition(unsigned char position) const override;

	void PrintName(std::ostream& out_stream) const override;
};

class CQueen : public CChessman, protected CValuable {
public:
	CQueen(bool is_white, unsigned char position);

	bool CanCapturePosition(unsigned char position) const override;

	void PrintName(std::ostream& out_stream) const override;
};

bool CanAnyoneCapturePosition(unsigned char position, CChessman** array, size_t size);

#endif // CLASSES_H_