#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Parser::Parser(string fileName) : fileName(fileName)
{
	
}

bool Parser::IsNumber(const string& str)
{
	return !str.empty() && find_if(str.begin(),
		str.end(), [](unsigned char c) { return !isdigit(c); }) == str.end();
}

void Parser::OnTheShelves()
{
	iniFile.open(fileName);
	if (!iniFile.is_open())
	{
		cout << "Файл не смог открыться" << std::endl;
	}

	//Раскладываем значение из файла по векторам
	string str;
	while (getline(iniFile, str))
	{
		if (str[0] == '[')
		{
			sections.push_back(str);
		}
		else if (str[0] == ';')
		{
			continue;
		}
		else
		{
			values.push_back(str);
		}
	}

	iniFile.close();
}

void Parser::Tokenize()
{
	int cValues = 0;
	int cSections = 0;

	while (cValues < values.size() && cSections < sections.size())
	{
		stringstream ss(values[cValues]);
		string line;
		string name;
		string value;

		while (getline(ss, line))
		{
			size_t prev = 0, pos;
			while ((pos = line.find_first_of("=", prev)) != string::npos)
			{
				if (pos > prev)
				{
					name = line.substr(prev, pos - prev);
				}
				prev = pos + 1;
			}

			if (prev < line.length())
			{
				value = line.substr(prev, string::npos);

				if (value.find_first_of(";", prev = 0))
				{
					while ((pos = value.find_first_of(";", prev)) != string::npos)
					{
						if (pos > prev)
						{
							value = value.substr(prev, pos - prev);
						}
					}
				}
			}
		}
		if (!(name.empty() || name == " " && value.empty() || value == " "))
		{
			sectionWithNameAndValue.insert(make_pair(sections[cSections], make_pair(name, value)));

			cValues += 1;
		}
		else
		{
			cSections += 1;
			cValues += 1;
		}
	}
}