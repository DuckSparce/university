#ifndef C_BIT_FIELD_H
#define C_BIT_FIELD_H

// 32 bits
class CBitField {
private:
	unsigned int m_value;

public:
	CBitField();
	explicit CBitField(unsigned int newValue);
	CBitField(const CBitField & pattern);

	unsigned int getValue() const;
	void setValue(unsigned int newValue);

	bool getBit(unsigned int index) const;
	void setBit(unsigned int index, bool newBit);

	unsigned int getCountOfSetBits() const;

	CBitField& bitwiseAnd(const CBitField& bitField);
	CBitField& bitwiseOr(const CBitField& bitField);
	CBitField& bitwiseXor(const CBitField& bitField);
};

#endif // C_BIT_FIELD_H