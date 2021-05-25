#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#pragma once
class Dict
{
private:

	std::string dict_name;
	std::map<std::string, std::string> dict;
	int dict_size = dict.size();

public:
	Dict();

	Dict(std::string name, int size);

	Dict(int size);

	Dict(std::string dir);

	void print();

	void name(std::string name);

	std::string get_name();

	int size();

	std::string translate(std::string translate_me);

	void add(std::string word, std::string translation);

	void del(std::string word);

	void edit(std::string word);

	void save(std::string dir);
};

