#include "CBitField.h"

CBitField::CBitField():
	m_value(0U)
	{}

CBitField::CBitField(unsigned int newValue):
	m_value(newValue)
	{}

CBitField::CBitField(const CBitField & pattern):
	m_value(pattern.m_value)
	{}

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

unsigned int CBitField::getCountOfSetBits() const {
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

CBitField& CBitField::bitwiseOr(const CBitField& bitField) {
	this->m_value |= bitField.m_value;
	return *this;
}

CBitField& CBitField::bitwiseXor(const CBitField& bitField) {
	this->m_value ^= bitField.m_value;
	return *this;
}
