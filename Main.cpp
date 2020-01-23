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

	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open input file";
	}

	string fileName = argv[1];
	Tokenizer tokenizer(fileName);

	ofstream out(argv[2]);
	if (!out)
	{
		cerr << "Unable to open output file:";
	}

	out << tokenizer.scan();
	return 0;
}