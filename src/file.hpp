#ifndef FILE_H
#define FILE_H

#include "string.hpp"
#include "stream.hpp"

class File : public Stream
{
public:
	File();
	File(const String &path);

	const String& path() const
	{
		return m_path;
	}

	FILE* fd() const
	{
		return m_stream;
	}

	bool open();
	bool writeLine(const String& line);

private:
	String m_path;
};

#endif // FILE_H
