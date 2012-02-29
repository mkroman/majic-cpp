#include "majic.hpp"
#include "file.hpp"
#include "io.hpp"

int main(int argc, char* argv[])
{
	File textDocument("/home/mk/novel.txt");

	if (textDocument.open()) {
		textDocument.writeLine("Pænt goddag");
	} else {
		kDebug() << "Could not open document!";
	}

  OBSOLETE(argc)
  OBSOLETE(argv)

  return 0;
}
