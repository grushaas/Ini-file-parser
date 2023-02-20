#pragma once
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
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
	multimap<string, pair<string, string>> sectionWithNameAndValue;
	ifstream iniFile;

	void Tokenize();
	void OnTheShelves();

public:
	Parser(string fileName);

	template<class T>
	void GetValue(string section, string var)
	{
		OnTheShelves();
		Tokenize();

		iniFile.open(fileName);
		if (!iniFile.is_open())
		{
			cout << "Файл не смог открыться" << std::endl;
		}

		for (auto& el : sectionWithNameAndValue)
		{
			cout << el.first << " => " << el.second << endl;
		}
	}
};