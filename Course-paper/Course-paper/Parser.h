#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Parser
{
private:
	string fileName;
	vector<string> sections;
	vector<string> values;
	multimap<string, string> nameAndValue;
	ifstream iniFile;

	void Tokenize();
	void OnTheShelves();

public:
	Parser(string fileName);

	//template<class T>
	int GetValue(string section, string var)
	{
		OnTheShelves();
		Tokenize();

		iniFile.open(fileName);
		if (!iniFile.is_open())
		{
			cout << "Файл не смог открыться" << std::endl;
		}

		return 0;
	}
};