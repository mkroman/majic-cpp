#ifndef STRING_HPP
#define STRING_HPP

#include <stddef.h>
#include <string.h>

class String
{
public:

	String();
	String(char character);
	String(const char* string);
	String(const String& string);

	~String();

	// Assignment operators
	String& operator=(const String& right);

	inline String operator+(const String& right)
	{
		String string(this->data());
		string.append(right);

		return string;
	}

	String& operator+=(const String& right)
	{
		return this->append(right);
	}

	inline String& operator<<(const String& right)
	{
		return this->append(right);
	}

	// Comparison operators
	bool operator==(const String& right) const;

	size_t length() const
	{
		if (m_data != nullptr)
			return strlen(m_data);
		else
			return 0;
	}

	const char* data() const
	{
		return m_data;
	}

	const char* toASCII() const
	{
		return strdup(m_data);
	}

	String& append(const String& string);

private:
	char* m_data;
};

String operator+(const char* left, const String& right);

#endif // STRING_HPP
