#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

#include "Tokenizer.h"

using namespace std;

int main(int argc, char** argv)
{
		if (argc < 3)
		{
			cerr << "Please provide input and output files";
			return 1;
		}

	string fileName = argv[1];
	Tokenizer tokenizer(fileName);

	cout << tokenizer.scan();
	return 0;
}