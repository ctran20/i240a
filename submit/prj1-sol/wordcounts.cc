#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>

int main(int argc, char *argv[]) {

	//No input error
	if (argc == 1) {
		std::cerr << "usage: " << argv[0]
			      << " MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..." << std::endl;
		std::exit(1);
	}

	std::ifstream inFile;

	//Open input file
	inFile.open("file1.txt");

	std::string test;

	while (inFile) {
		inFile >> test;
		std::cout << test << std::end;
	}

	//Close input file
	inFile.close();
}