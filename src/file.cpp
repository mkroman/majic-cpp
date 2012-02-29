#include "file.hpp"
#include "debugstream.hpp"

File::File()
{
	
}

File::File(const String& path)
	: m_path(path)
{
  
}

bool File::open()
{
	FILE* file;

	file = fopen(m_path.toASCII(), "a+");

	if (file != nullptr) {
		m_stream = file;
		
		return true;
	}
	else {
		return false;
	}
}

bool File::writeLine(const String& line)
{
	String copy(line);

	return write(copy + "\r\n");
}
