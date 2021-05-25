#include "Dict.h"

Dict::Dict()
{
	dict_size = 0;
}

Dict::Dict(std::string name, int size)
{
	dict_name = name;
	dict_size = size;
}

Dict::Dict(int size)
{
	dict_size = size;
}

Dict::Dict(std::string dir)
{
	std::ifstream file(dir);
	
	std::string key;
	std::string value;
	while (file >> key >> value)
		dict[key] = value;
}

void Dict::print()
{
	for (auto i : dict)
		std::cout << i.first << ": " << i.second << std::endl;
}

void Dict::name(std::string name)
{
	dict_name = name;
}

std::string Dict::get_name()
{
	return dict_name;
}

int Dict::size()
{
	return dict_size;
}

std::string Dict::translate(std::string translate_me)
{
	return dict[translate_me];
}

void Dict::add(std::string word, std::string translation)
{
	dict[word] = translation;
}

void Dict::del(std::string word)
{
	dict.erase(word);
}

void Dict::edit(std::string word)
{
	std::string new_translation;
	std::cout << "Enter new translation: ";
	std::cin >> new_translation;
	dict[word] = new_translation;
}

void Dict::save(std::string dir)
{
	if (dict_name.empty())
	{
		std::cout << "Enter the name: ";
		std::cin >> dict_name;
	}
	std::ofstream out(dict_name + ".txt");
	for (auto i = dict.begin(); i != dict.end(); i++)
	{
		out << i->first << " " << i->second << std::endl;
	}
	out.close();
}
