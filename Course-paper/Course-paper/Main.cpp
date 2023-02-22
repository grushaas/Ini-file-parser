#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
	Parser parser("File.ini");

	auto result = parser.GetValue<string>("Section2", "var2");

	cout << result << endl;
}