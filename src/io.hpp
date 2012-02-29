#ifndef IO_HPP
#define IO_HPP

namespace IO
{

enum OpenMode {
	ReadOnly  = (1 << 0),
	WriteOnly = (1 << 2),
	ReadWrite = (1 << 3),
	Append    = (1 << 4),
	Truncate  = (1 << 5)
};

typedef unsigned int flags_t;

}

#endif
