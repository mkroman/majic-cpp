#ifndef STREAM_HPP
#define STREAM_HPP

#include <cstdio>

class String;

class Stream
{
public:
	Stream();
	Stream(FILE* stream);

	~Stream();

	bool close();
	
	bool write(const String& string, bool flush = true) const;
	void flush() const;

protected:
	FILE* m_stream;
};

#endif // STREAM_HPP
