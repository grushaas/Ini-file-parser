#include <iostream>
#include "Parser.h"

int main()
{
	Parser parser("File.ini");

	parser.GetValue<int>("Section1", "var1");
}