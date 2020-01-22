#pragma once
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Token.h"
using namespace std;

class Tokenizer
{
public:
	Tokenizer(string fileName) { this->fileName = fileName; scanFile(); };
	~Tokenizer();

	void scanFile();
	string scan(string myString, int lineNum);
protected:
	string fileName;
};

