#include "CBitField.h"

unsigned int CBitField::s_objectsCount = 0;

CBitField::CBitField() :
	m_value(0U) {
	s_objectsCount++;
}

CBitField::CBitField(unsigned int newValue) :
	m_value(newValue) {
	s_objectsCount++;
}

CBitField::CBitField(const CBitField& pattern) :
	m_value(pattern.m_value) {
	s_objectsCount++;
}

CBitField::~CBitField() {
	s_objectsCount--;
}

unsigned int CBitField::getObjectsCount() {
	return s_objectsCount;
}

unsigned int CBitField::getValue() const {
	return m_value;
}

void CBitField::setValue(unsigned int newValue) {
	m_value = newValue;
}

bool CBitField::getBit(unsigned int index) const {
	if (index > 31U) {
		return false;
	}

	unsigned int mask = 1U << index;
	return (mask & m_value) == mask;
}

void CBitField::setBit(unsigned int index, bool newBit) {
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

unsigned int CBitField::getTrueBitsNumber() const {
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

CBitField& CBitField::bitwiseAnd(const CBitField& bitField) {
	this->m_value &= bitField.m_value;
	return *this;
}

CBitField& CBitField::bitwiseAnd(unsigned int value) {
	this->m_value &= value;
	return *this;
}

CBitField& CBitField::bitwiseOr(const CBitField& bitField) {
	this->m_value |= bitField.m_value;
	return *this;
}

CBitField& CBitField::bitwiseOr(unsigned int value) {
	this->m_value |= value;
	return *this;
}

CBitField& CBitField::bitwiseXor(const CBitField& bitField) {
	this->m_value ^= bitField.m_value;
	return *this;
}

CBitField& CBitField::bitwiseXor(unsigned int value) {
	this->m_value ^= value;
	return *this;
}

CBitField CBitField::operator&(const CBitField& bitField) const {
	return CBitField(this->m_value & bitField.getValue());
}

CBitField CBitField::operator|(const CBitField& bitField) const {
	return CBitField(this->m_value | bitField.getValue());
}

CBitField CBitField::operator^(const CBitField& bitField) const {
	return CBitField(this->m_value ^ bitField.getValue());
}

bool CBitField::operator[](unsigned int index) const {
	return getBit(index);
}

std::istream& operator>>(std::istream & stream, CBitField& bitField) {
	unsigned int prevValue = bitField.m_value;
	bitField.m_value = 0;
	char str[33] = {};
	stream.get(str, 33);

	if (stream.fail()) {
		return stream;
	}

	for (int i = 0; i < 32; i++) {
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

std::ostream& operator<<(std::ostream& stream, CBitField& bitField) {
	for (int i = 31; i >= 0; --i) {
		stream << ((bitField.m_value & (1 << i)) ? '1' : '0');
	}

	return stream;
}

bool operator==(const CBitField& bitField1, const CBitField& bitField2) {
	return bitField1.getValue() == bitField2.getValue();
}

bool operator!=(const CBitField& bitField1, const CBitField& bitField2) {
	return !operator==(bitField1, bitField2);
}
