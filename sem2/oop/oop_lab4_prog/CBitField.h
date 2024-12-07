#ifndef C_BIT_FIELD_H
#define C_BIT_FIELD_H

#include <bitset>
#include <cmath>
#include <sstream>
#include <string>

// 32 bits
class CBitField {
public:
	CBitField();
	explicit CBitField(unsigned int newValue);
	explicit CBitField(const CBitField& pattern);
	~CBitField();

	static unsigned int getObjectsCount();

	unsigned int getValue() const;
	void setValue(unsigned int newValue);

	bool getBit(unsigned int index) const;
	void setBit(unsigned int index, bool newBit);

	unsigned int getTrueBitsNumber() const;

	CBitField& bitwiseAnd(const CBitField& bitField);
	CBitField& bitwiseAnd(unsigned int value);
	CBitField& bitwiseOr(const CBitField& bitField);
	CBitField& bitwiseOr(unsigned int value);
	CBitField& bitwiseXor(const CBitField& bitField);
	CBitField& bitwiseXor(unsigned int value);
	
	CBitField operator&(const CBitField& bitField) const;
	CBitField operator|(const CBitField& bitField) const;
	CBitField operator^(const CBitField& bitField) const;

	bool operator[](unsigned int index) const;

	friend std::istream& operator>>(std::istream& stream, CBitField& bitField);
	friend std::ostream& operator<<(std::ostream& stream, CBitField& bitField);

	friend bool operator==(const CBitField& bitField1, const CBitField& bitField2);
	friend bool operator!=(const CBitField& bitField1, const CBitField& bitField2);

private:
	static unsigned int s_objectsCount;

	unsigned int m_value;
};

#endif // C_BIT_FIELD_H
