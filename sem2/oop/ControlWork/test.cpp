#include "pch.h"

#include <cstring>

class String {
public:
	// 1
	String() :
		m_size(1) {
		m_data = new char[1];
		m_data[0] = '\0';
	}

	// 2
	String(const char* source) :
		m_size(strlen(source) + 1) {
		m_data = new char[m_size];
		strcpy_s(m_data, m_size, source);
	}

	// 3
	String(String&& other) noexcept :
		m_size(other.m_size),
		m_data(other.m_data) {
		other.m_size = 1;
		other.m_data = new char[1];
		other.m_data[0] = '\0';
	}

	// 4
	String(const String& other) = delete;

	// 5
	~String() {
		delete[] m_data;
	}

	// 6
	char * data() const {
		return m_data;
	}

	// 7
	size_t size() const {
		return m_size - 1; // minus '\0'
	}

	// 8
	void prepend(const String& other) {
		char* newString = new char[m_size + other.m_size - 1];
		strncpy_s(newString, other.m_size, other.m_data, other.m_size);
		strncpy_s(newString + other.m_size - 1, m_size, m_data, m_size);

		delete[] m_data;
		m_data = newString;
		m_size = strlen(newString) + 1;
	}

	// 9
	String concatenatedWith(const String& other) const {
		char* newString = new char[m_size + other.m_size - 1];
		strncpy_s(newString, m_size, m_data, m_size);
		strncpy_s(newString + m_size - 1, other.m_size, other.m_data, other.m_size);

		String result(newString);
		delete[] newString;
		return result;
	}

	// 10
	// Index must be less than size
	char& operator[](const size_t index) const {
		return m_data[index];
	}

	// 11
	bool operator>(const String& other) const {
		if (strcmp(other.m_data, m_data) < 0) { // -1 = '<'; 0 = '=='; 1 = '>'
			return true;
		}

		return false;
	}

private:
	size_t m_size; // including '\0'
	char* m_data;
};


TEST(String, DefaultConstructorTest) {
	String s;
	EXPECT_EQ(s.size(), 0);
	EXPECT_STREQ(s.data(), "");
}

TEST(String, SourceConstructorTest) {
	// Average case
	String s("some str");
	EXPECT_EQ(s.size(), 8);
	EXPECT_STREQ(s.data(), "some str");

	// Empty case
	String s2("");
	EXPECT_EQ(s2.size(), 0);
	EXPECT_STREQ(s2.data(), "");
}

TEST(String, MoveConstructorTest) {
	// Average case
	String s("just text");
	String s2(std::move(s));
	EXPECT_EQ(s.size(), 0);
	EXPECT_STREQ(s.data(), "");
	EXPECT_EQ(s2.size(), 9);
	EXPECT_STREQ(s2.data(), "just text");

	// Empty case
	String s3("");
	String s4(std::move(s3));
	EXPECT_EQ(s3.size(), 0);
	EXPECT_STREQ(s3.data(), "");
	EXPECT_EQ(s4.size(), 0);
	EXPECT_STREQ(s4.data(), "");
}

TEST(String, PrependTest) {
	// Average case
	String s("Lviv ");
	String s2("Polytechnic");
	EXPECT_EQ(s.size(), 5);
	EXPECT_STREQ(s.data(), "Lviv ");
	EXPECT_EQ(s2.size(), 11);
	EXPECT_STREQ(s2.data(), "Polytechnic");

	s.prepend(s2);
	EXPECT_EQ(s.size(), 16);
	EXPECT_STREQ(s.data(), "PolytechnicLviv ");
	EXPECT_EQ(s2.size(), 11);
	EXPECT_STREQ(s2.data(), "Polytechnic");

	// One empty case
	String s3("");
	String s4("second part");
	EXPECT_EQ(s3.size(), 0);
	EXPECT_STREQ(s3.data(), "");
	EXPECT_EQ(s4.size(), 11);
	EXPECT_STREQ(s4.data(), "second part");

	s4.prepend(s3);
	EXPECT_EQ(s3.size(), 0);
	EXPECT_STREQ(s3.data(), "");
	EXPECT_EQ(s4.size(), 11);
	EXPECT_STREQ(s4.data(), "second part");

	// Two empty case
	String s5;
	String s6("");
	EXPECT_EQ(s5.size(), s6.size());
	s6.prepend(s5);
	EXPECT_STREQ(s6.data(), "");
}

TEST(String, ConcatenatedWithTest) {
	// Average case
	String s("Lviv ");
	String s2("Polytechnic");
	EXPECT_EQ(s.size(), 5);
	EXPECT_STREQ(s.data(), "Lviv ");
	EXPECT_EQ(s2.size(), 11);
	EXPECT_STREQ(s2.data(), "Polytechnic");

	String s3 = s.concatenatedWith(s2);
	EXPECT_EQ(s.size(), 5);
	EXPECT_STREQ(s.data(), "Lviv ");
	EXPECT_EQ(s2.size(), 11);
	EXPECT_STREQ(s2.data(), "Polytechnic");
	EXPECT_EQ(s3.size(), 16);
	EXPECT_STREQ(s3.data(), "Lviv Polytechnic");

	// Empty case
	String s4("Start");
	String s5;
	String s6 = s4.concatenatedWith(s5);
	EXPECT_STREQ(s4.data(), s6.data());
	EXPECT_STRNE(s6.data(), s5.data());
	EXPECT_STREQ(s6.data(), "Start");
}

TEST(String, AccessOperatorTest) {
	String s("Lviv ");
	EXPECT_EQ(s.size(), 5);
	EXPECT_STREQ(s.data(), "Lviv ");
	EXPECT_EQ(s[0], 'L');
	EXPECT_EQ(s[1], 'v');
	EXPECT_EQ(s[2], 'i');
	EXPECT_EQ(s[3], 'v');
	EXPECT_EQ(s[4], ' ');
	EXPECT_EQ(s[5], '\0');

	String s2("");
	EXPECT_EQ(s2[0], '\0');

}

TEST(String, GreaterThanOperatorTest) {
	// Average case
	String s("Lviv ");
	String s2("Polytechnic");
	String s3;

	EXPECT_GT(s2, s3);
	EXPECT_GT(s, s3);
	EXPECT_GT(s2, s);

	// Close case
	String s4("Lviv1");
	String s5("Lviv2");

	EXPECT_GT(s5, s4);
	EXPECT_FALSE(s4 > s5);

	// Equal case
	String s6("Lviv2");
	EXPECT_FALSE(s6 > s5);
}