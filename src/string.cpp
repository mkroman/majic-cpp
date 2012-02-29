#include <stdlib.h>

#include "string.hpp"
#include "stream.hpp"
#include "debugstream.hpp"

String::String() : m_data(nullptr)
{
}

String::String(const String& string)
{
	m_data = static_cast<char*>(malloc(string.length()));

	memcpy(m_data, string.data(), string.length());
}

String::String(const char* string)
{
	m_data = strdup(string);
}

String::String(char character)
{
	m_data = static_cast<char*>(calloc(2, sizeof(char)));
	m_data[0] = character;
}

String& String::operator=(const String& right)
{
	if (this == &right)
		return *this;

	char *buffer;

	buffer = static_cast<char*>(malloc(right.length()));

	if (buffer != nullptr) {
		free(m_data);
		strcpy(buffer, right.data());

		m_data = buffer;
	}
	else {
		perror("String::operator=(...) could not allocate memory");

		return *this;
	}

	return *this;
}

bool String::operator==(const String &right) const
{
	if (this->length() == right.length() && strcmp(this->data(), right.data()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

String& String::append(const String& string)
{
	char * ptr;
	size_t length_a, length_b;

	length_a = this->length();
	length_b = string.length();

	m_data = static_cast<char*>(realloc(m_data, length_a + length_b + 1));

	ptr = m_data + length_a;
	strcpy(ptr, string.data());

	return *this;
}

String::~String()
{
	if (m_data != nullptr)
		free(m_data);
}

String operator+(const char *left, const String &right)
{
		String string(left);

		string.append(right);

		return string;
}
