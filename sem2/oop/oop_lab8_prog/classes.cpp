#include "classes.h"

#include <iostream>
#include <cmath>

CChessman::CChessman(unsigned char position)
	: m_row(position % 8)
	, m_col(position % 64 / 8) {}

unsigned char CChessman::get_row() const {
	return m_row;
}

unsigned char CChessman::get_col() const {
	return m_col;
}

CValuable::CValuable(bool is_white, unsigned char points)
	: m_is_white(is_white)
	, m_points(points) {}

unsigned char CValuable::get_points() const {
	return m_points;
}

bool CValuable::get_is_white() const {
	return m_is_white;
}

CKnight::CKnight(bool is_white, unsigned char position)
	: CChessman(position)
	, CValuable(is_white, 3){}

bool CKnight::CanCapturePosition(unsigned char other_position) const {
	const int other_row = other_position % 8;
	const int other_col = other_position % 64 / 8;

	if ((abs(m_row - other_row) == 2 && abs(m_col - other_col) == 1) ||
		(abs(m_row - other_row) == 1 && abs(m_col - other_col) == 2)) {
		return true;
	}

	return false;
}

void CKnight::PrintName(std::ostream& out_stream) const {
	out_stream << "CKnight.\n";
}

CRook::CRook(bool is_white, unsigned char position)
	: CChessman(position)
	, CValuable(is_white, 5) {}

bool CRook::CanCapturePosition(unsigned char other_position) const {
	// The exact same position
	if (m_col * 8 + m_row == other_position % 64) {
		return false;
	}

	const int other_row = other_position % 8;
	const int other_col = other_position % 64 / 8;

	if (m_row == other_row || m_col == other_col) {
		return true;
	}

	return false;
}

void CRook::PrintName(std::ostream& out_stream) const {
	out_stream << "CRook.\n";
}

CQueen::CQueen(bool is_white, unsigned char position)
	: CChessman(position)
	, CValuable(is_white, 9) {}

bool CQueen::CanCapturePosition(unsigned char other_position) const {
	// The exact same position
	if (m_col * 8 + m_row == other_position % 64) {
		return false;
	}

	const int other_row = other_position % 8;
	const int other_col = other_position % 64 / 8;

	if (m_row == other_row || m_col == other_col) {
		return true;
	}

	// Bishop
	if (abs(m_row - m_col) == abs(other_row - other_col) ||
		m_row + m_col == other_row + other_col) {
		return true;
	}

	return false;
}

void CQueen::PrintName(std::ostream& out_stream) const {
	out_stream << "CQueen.\n";
}

bool CanAnyoneCapturePosition(unsigned char position, CChessman** array, size_t size) {
	if (array == nullptr) {
		// Exception
		return false;
	}

	for (size_t i = 0; i < size; i++) {
		if (array[i]->CanCapturePosition(position)) {
			return true;
		}
	}

	return false;
}