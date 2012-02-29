#include "stream.hpp"
#include "string.hpp"

Stream::Stream()
{
}

Stream::Stream(FILE* stream) 
	: m_stream(stream)
{
}

Stream::~Stream()
{
}

void Stream::flush() const
{
	if (m_stream) {
		fflush(m_stream);
	}
}

bool Stream::close()
{
	if (m_stream != nullptr && fclose(m_stream) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Stream::write(const String& string, bool flush) const
{
	size_t length = string.length();

	if (fwrite(string.data(), 1, length, m_stream) != length) {
		return false;
	}
	else {
		if (flush)
			this->flush();

		return true;
	}
}
