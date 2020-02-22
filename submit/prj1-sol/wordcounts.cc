#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

typedef std::pair<std::string, int> WordCount;

int InputIntCheck(char *argv, std::string name);
std::string CleanString(std::string str);
bool wordCountCompare(const WordCount &a, const WordCount &b);

int main(int argc, char *argv[]) {

	//Input & Error Check---------------------------------------------------------
	if (argc < 5) {
		std::cerr << "usage: " << argv[0]
			<< " MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..." << std::endl;
		std::exit(1);
	}

	const unsigned int MAX_N_OUT = InputIntCheck(argv[1], "MAX_N_OUT");
	const unsigned int MIN_WORD_LEN = InputIntCheck(argv[2], "MIN_WORD_LEN");
	const unsigned int MAX_WORD_LEN = InputIntCheck(argv[3], "MAX_WORD_LEN");

	if (!(MAX_WORD_LEN >= MIN_WORD_LEN))
	{
		std::cerr << "MIN_WORD_LEN " << MIN_WORD_LEN
			<< " is greater than MAX_WORD_LEN "
			<< MAX_WORD_LEN << std::endl;
		std::exit(1);
	}
	else if (MAX_WORD_LEN < 1) {
		std::cerr << "MAX_WORD_LEN can't be 0" << std::endl;
		std::exit(1);
	}

	std::ifstream in(argv[4]);
	std::unordered_map<std::string, int> map;
	//----------------------------------------------------------------------------

	//Check if exist and read in file
	while (in.good()) {
		std::string w;
		in >> w;
		w = CleanString(w);
		if (w.length() >= MIN_WORD_LEN && w.length() <= MAX_WORD_LEN && w.length() > 0) {
			map[w] += 1;
		}
	}
	if (!in.eof()) {
		std::cerr << "cannot read " << argv[4]
			<< ": No such file or directory" << std::endl;
		std::exit(1);
	}

	auto wordCounts =
		std::vector<WordCount>(map.begin(), map.end());

	sort(wordCounts.begin(), wordCounts.end(),
		wordCountCompare);

	for (unsigned int i = 0; i < MAX_N_OUT; i++)
	{
		std::cout << wordCounts[i].first << ": "
			<< wordCounts[i].second << std::endl;
	}

	return 0;
}

//Check input to make sure they are integers
int InputIntCheck(char *argv, std::string name)
{
	int ret = atoi(argv);
	std::string error = argv;

	while (*argv != 0)
	{
		if (*argv && (!isdigit(*argv++)))
		{
			std::cerr << "bad integer value: '" << error
				<< "' for " << name << std::endl;
			std::exit(1);
		}
	}
	return ret;
}

//Remove non-alphabetical characters and lowercase the string
std::string CleanString(std::string str) {
    std::string s = str;
	for (std::string::iterator i = s.begin(); i != s.end(); i++)
	{
		if (!isalpha(s.at(i - s.begin())))
		{
			s.erase(i);
			i--;
		}
	}
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

bool wordCountCompare(const WordCount &a, const WordCount &b){
	if (a.second == b.second) {
		if (a.first[0] < b.first[0]) {
			return true;
		}
		if (a.first[1] < b.first[1]) {
			return true;
		}
	}
	return (a.second > b.second);
}