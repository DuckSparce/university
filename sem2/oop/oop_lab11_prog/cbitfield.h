#ifndef C_BIT_FIELD_H_
#define C_BIT_FIELD_H_

#include <iostream>

// 32 bits
class CBitField {
public:
	CBitField() :
		m_value(0U) {}

	CBitField(const unsigned int newValue) :
		m_value(newValue) {}

	CBitField(const CBitField& pattern) = default;
	CBitField(CBitField&& pattern) = default;

	CBitField& operator=(const CBitField& pattern) = default;
	CBitField& operator=(CBitField&& pattern) = default;

	~CBitField() = default;

	unsigned int getValue() const {
		return m_value;
	}

	void setValue(unsigned int newValue) {
		m_value = newValue;
	}

	bool getBit(unsigned int index) const {
		const unsigned int mask = 1U << index;
		return (mask & m_value) == mask;
	}

	void setBit(unsigned int index, bool newBit) {
		if (index > 31U) {
			return;
		}

		unsigned int mask = 1 << index;
		if (newBit) {
			m_value |= mask;
		} else {
			mask = ~mask;
			m_value &= mask;
		}
	}

	unsigned int getCountOfSetBits() const {
		unsigned int result = 0;
		unsigned int valueCopy = m_value;

		while (valueCopy) {
			if (valueCopy % 2U) {
				result++;
			}

			valueCopy >>= 1;
		}

		return result;
	}

	CBitField& bitwiseAnd(const CBitField& bitField) {
		this->m_value &= bitField.m_value;
		return *this;
	}

	CBitField& bitwiseAnd(unsigned int value) {
		this->m_value &= value;
		return *this;
	}

	CBitField& bitwiseOr(const CBitField& bitField) {
		this->m_value |= bitField.m_value;
		return *this;
	}

	CBitField& bitwiseOr(unsigned int value) {
		this->m_value |= value;
		return *this;
	}

	CBitField& bitwiseXor(const CBitField& bitField) {
		this->m_value ^= bitField.m_value;
		return *this;
	}

	CBitField& bitwiseXor(unsigned int value) {
		this->m_value ^= value;
		return *this;
	}

	CBitField operator&(const CBitField& bitField) const {
		return (this->m_value & bitField.getValue());
	}

	CBitField operator|(const CBitField& bitField) const {
		return (this->m_value | bitField.getValue());
	}

	CBitField operator^(const CBitField& bitField) const {
		return (this->m_value ^ bitField.getValue());
	}

	CBitField operator+(const CBitField& bitField) const {
		return operator|(bitField);
	}

	friend bool operator==(const CBitField& bitField1, const CBitField& bitField2);
	friend bool operator!=(const CBitField& bitField1, const CBitField& bitField2);

	friend std::istream& operator>>(std::istream& stream, CBitField& bitField);
	friend std::ostream& operator<<(std::ostream& stream, const CBitField& bitField);

private:
	unsigned int m_value;
};

inline bool operator==(const CBitField& bitField1, const CBitField& bitField2) {
	return bitField1.getValue() == bitField2.getValue();
}

inline bool operator!=(const CBitField& bitField1, const CBitField& bitField2) {
	return !operator==(bitField1, bitField2);
}

inline std::istream& operator>>(std::istream& stream, CBitField& bitField) {
	const unsigned int prevValue = bitField.m_value;
	bitField.m_value = 0;

	while (	std::isspace(stream.peek()))
		stream.get();

	char str[33] = {};
	stream.get(str, 33);

	if (stream.fail()) {
		return stream;
	}

	for (unsigned int i = 0; i < 32; i++) {
		if (str[i] != '0' && str[i] != '1') {
			bitField.m_value = prevValue;
			return stream;
		}

		if (str[i] == '1') {
			bitField.m_value |= 1 << (31 - i);
		}
	}

	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const CBitField& bitField) {
	for (int i = 31; i >= 0; --i) {
		stream << ((bitField.m_value & (1 << i)) ? '1' : '0');
	}

	return stream;
}

#endif // C_BIT_FIELD_H_
