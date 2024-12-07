#ifndef C_BIT_FIELD_H
#define C_BIT_FIELD_H

#include <iostream>

// 32 bits
class CBitField {
private:
	unsigned int m_value;

public:
	CBitField();
	explicit CBitField(unsigned int newValue);
	CBitField(const CBitField& pattern);

	unsigned int getValue() const;
	void setValue(unsigned int newValue);

	bool getBit(unsigned int index) const;
	void setBit(unsigned int index, bool newBit);

	unsigned int getCountOfSetBits() const;

	CBitField& bitwiseAnd(const CBitField& bitField);
	CBitField& bitwiseAnd(unsigned int value);
	CBitField& bitwiseOr(const CBitField& bitField);
	CBitField& bitwiseOr(unsigned int value);
	CBitField& bitwiseXor(const CBitField& bitField);
	CBitField& bitwiseXor(unsigned int value);

	CBitField operator&(const CBitField& bitField) const;
	CBitField operator|(const CBitField& bitField) const;
	CBitField operator^(const CBitField& bitField) const;

	CBitField operator+(const CBitField& bitField) const;

	friend bool operator==(const CBitField& bitField1, const CBitField& bitField2);
	friend bool operator!=(const CBitField& bitField1, const CBitField& bitField2);

	friend std::istream& operator>>(std::istream& stream, CBitField& bitField);
	friend std::ostream& operator<<(std::ostream& stream, CBitField& bitField);
};

#endif // C_BIT_FIELD_H
