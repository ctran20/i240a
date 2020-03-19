#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char *argv[]) {
	//Input & Error Check---------------------------------------------------------
	if (argc < 2 || argc > 3 || (argc == 3 && strcmp(argv[1], "-a") != 0)) {
		std::cerr << "usage: " << argv[0]
			<< " [-a] INTS_FILE_PATH" << std::endl;
		std::exit(1);
	}

	std::ifstream in(argv[argc-1]);
	//----------------------------------------------------------------------------

	//Check if exist and read in file
	while (in.good()) {
		std::string w;
		in >> w;
	}
	if (!in.eof()) {
		std::cerr << "cannot read " << argv[argc - 1]
			<< ": No such file or directory" << std::endl;
		std::exit(1);
	}


	return 0;
}