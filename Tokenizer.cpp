#include "Tokenizer.h"



Tokenizer::Tokenizer(string fileName)
{
}


Tokenizer::~Tokenizer()
{
}

void Tokenizer::scanFile()
{
	ifstream in(fileName);
}

string Tokenizer::scan(string myString, int lineNum)
{
	istringstream in(myString);
	ostringstream out;
// char c;
// in.get(c);	
	while (in)
	{
		char asciiChar = in.peek();
		if (asciiChar == ',')
		{
			Token token;
			token.setType("COMMA");
			token.setValue(",");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == '.')
		{
			Token token;
			token.setType("PERIOD");
			token.setValue(".");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == '?')
		{
			Token token;
			token.setType("Q_MARK");
			token.setValue("?");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == '(')
		{
			Token token;
			token.setType("LEFT_PAREN");
			token.setValue("(");
			in.ignore();
		}

		else if (asciiChar == ')')
		{
			Token token;
			token.setType("RIGHT_PAREN");
			token.setValue(")");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == ':')
		{
			//make dash a part
			Token token;
			token.setType("COLON_DASH");
			token.setValue(":-");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
			in.ignore();
		}

		else if (asciiChar == ':')
		{
			Token token;
			token.setType("COLON");
			token.setValue(":");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
			in.putback();
		}

		else if (asciiChar == '*')
		{
			Token token;
			token.setType("MULTIPLY");
			token.setValue("*");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == '+')
		{
			Token token;
			token.setType("ADD");
			token.setValue("+");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == 'S')
		{
			string tempString;
			//in.get(4, 6);
			out << in.str();
			Token token;
			token.setType("SCHEMES");
			token.setValue("Schemes");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == 'F')
		{
			Token token;
			token.setType("FACTS");
			token.setValue("Facts");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == 'R')
		{
			Token token;
			token.setType("RULES");
			token.setValue("Rules");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}

		else if (asciiChar == 'Q')
		{
			Token token;
			token.setType("QUERIES");
			token.setValue("Queries");
			out << "(" << token.getType() << ", \"" << token.getValue() << "\", " << lineNum << ")" << endl;
			in.ignore();
		}
		else
		{
		in.ignore();
		}
	}


/*	out << asciiChar;	
	while (in)
	{
		asciiChar = in.peek();
		out << asciiChar;
		in.ignore();
	}
*/
/*
	int numChars = 0;
	char tempChar;
	in.ignore();
	numChars++;
	tempChar = in.peek();
	if (tempChar == 'c')
	{
		in.ignore();
		numChars++;
		tempChar = in.peek();
		if (tempChar == 'h')
		{
			in.ignore();
			numChars++;
			tempChar = in.peek();
			if (tempChar == 'e')
			{
				in.ignore();
				numChars++;
				tempChar = in.peek();
				if (tempChar == 'm')
				{
					in.ignore();
					numChars++;
					tempChar = in.peek();
					if (tempChar == 'e')
					{
						in.ignore();
						numChars++;
						tempChar = in.peek();
						if (tempChar = 's')
						{

						}
						else
						{

						}
					}
				}

			}
		}
	}
*/
	return out.str();
}
