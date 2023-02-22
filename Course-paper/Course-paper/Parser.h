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
	multimap<string, pair<string, string>> sectionWithNameAndValue;
	ifstream iniFile;

	void Tokenize(); // ����� ������ �� ������ ����� � ���������� � ���� ��������� sectionWithNameAndValue
	void OnTheShelves(); // ������������ ����� � �������� ini ����� �� ��������
	bool IsNumber(const string& str); // ��������� ���� �� � ������ ������������� �����

public:
	Parser(string fileName);

	// ����� ����������� �������� � ���� int � double
	template<class T>
	T GetValue(string section, string var)
	{
		T result;

		OnTheShelves();
		Tokenize();

		iniFile.open(fileName);
		if (!iniFile.is_open())
		{
			cout << "���� �� ���� ���������" << std::endl;
		}

		for (auto& el : sectionWithNameAndValue)
		{
			if (el.first == "[" + section + "]")
			{
				if (el.second.first == var)
				{
					if (IsNumber(el.second.second))
					{
						result = stoi(el.second.second);
					}
					else
					{
						result = stod(el.second.second);
					}
				}
			}
		}
		return result;
	}

	// ����� ������������ �������� � ���� string
	template<>
	string GetValue(string section, string var)
	{
		string result = "";

		OnTheShelves();
		Tokenize();

		iniFile.open(fileName);
		if (!iniFile.is_open())
		{
			cout << "���� �� ���� ���������" << std::endl;
		}

		for (auto& el : sectionWithNameAndValue)
		{
			if (el.first == "[" + section + "]")
			{
				if (el.second.first == var)
				{
					result = el.second.second;
				}
			}
		}
		return result;
	}
};