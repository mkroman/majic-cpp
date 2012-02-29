#ifndef DEBUGSTREAM_HPP
#define DEBUGSTREAM_HPP

#include "string.hpp"
#include "stream.hpp"

class DebugStream : public Stream
{
public:
	DebugStream();

	inline DebugStream& operator<<(const String& string)
	{
		
		this->write("\"" + string + "\" ");

		return *this;
	}
};

static DebugStream& kDebug()
{
	static DebugStream stream;
	return stream;
}

#endif // DEBUGSTREAM_HPP
