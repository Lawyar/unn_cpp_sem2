#include "filmlib.h"

film::film()
{
	name = "Alexey";
	producer = "Alexey";
	scenarist = "Alexey";
	composer = "Alexey";
	money = 0;
	release_date = "00.00.0000";
}

film::film(std::string _name, std::string _producer, std::string _scenarist, std::string _composer, std::string _release_date, int _money)
{
	name = _name;
	producer = _producer;
	scenarist = _scenarist;
	composer = _composer;
	money = _money;
	if (_release_date.size() != 10)
	{
		std::cout << "Incorrect date\nExample: 12.02.2021; 05.06.1996\n";
		release_date = "00.00.0000";
	}
	else
	{
		release_date = _release_date;
	}
}

void film::change_name(std::string new_name)
{
	name = new_name;
}

void film::change_producer(std::string new_producer)
{
	producer = new_producer;
}

void film::change_scenarist(std::string new_scenarist)
{
	scenarist = new_scenarist;
}

void film::change_composer(std::string new_composer)
{
	composer = new_composer;
}

void film::change_release_date(std::string new_release_date) //Example: "12.02.2021"; "05.06.1996"
{
	if(new_release_date.size() != 12)
	{
		std::cout << "Incorrect date\nExample: 12.02.2021; 05.06.1996\n";
	}
	else
	{
		release_date = new_release_date;
	}
	
}

void film::change_money(unsigned int new_money)
{
	money = new_money;
}

void film::show_info()
{
	std::cout << "Film name: " << name << std::endl;
	std::cout << "Producer: " << producer << std::endl;
	std::cout << "Scenarist: " << scenarist << std::endl;
	std::cout << "Composer: " << composer << std::endl;
	std::cout << "Release date: " << release_date << std::endl;
	std::cout << "Money: " << money << std::endl;

}

std::string film::get_name()
{
	return name;
}

std::string film::get_producer()
{
	return producer;
}

std::string film::get_scenarist()
{
	return scenarist;
}

std::string film::get_composer()
{
	return composer;
}

std::string film::get_release_date()
{
	return release_date;
}

unsigned int film::get_money()
{
	return money;
}

filmlib::filmlib(std::string name)
{
	this->name = name;
	film_quantity = 0;
}

filmlib::filmlib()
{
	film_quantity = 0;
}

void filmlib::add_film(film filmie)
{
	films.push_back(filmie);
}

void filmlib::remove_film(std::string name)
{
	for (int i = 0; i < films.size(); i++)
	{
		if (films[i].get_name() == name)
		{
			films.erase(films.begin() + i);
			break;
		}
	}
	std::cout << "No such film\n";
}

void filmlib::sort_by_release()
{
	for (int i = 0; i < films.size() - 1; i++)
	{
		for (int j = i; j < films.size(); j++)
		{
			if (films[i].get_release_date()[6] > films[j].get_release_date()[6])
			{
				std::swap(films[i], films[j]);
			}
			else if (films[i].get_release_date()[6] == films[j].get_release_date()[6] && films[i].get_release_date()[7] > films[j].get_release_date()[7])
			{
				std::swap(films[i], films[j]);
			}
		}
	}

}

void filmlib::sort_by_name()
{
	for (int i = 0; i < films.size() - 1; i++)
	{
		for (int j = i; j < films.size(); j++)
		{
			if (films[i].get_name() > films[j].get_name())
			{
				std::swap(films[i], films[j]);
			}
		}
	}

}

void filmlib::change_film_date(std::string name)
{
	for (auto it : films)
	{
		if (it.get_name() == name)
		{
			std::cout << "Press to change:\n1)Change name\n2Change producer\n3)Change scenarist\n4)Change composer\n5)Change release date\n6)Change money\n)";
			int n;
			std::cin >> n;
			if (n == 1)
			{
				std::string new_name;
				std::cout << "Enter new name: ";
				std::cin >> new_name;
				it.change_name(new_name);
			}
			if (n == 2)
			{
				std::string new_producer;
				std::cout << "Enter new producer: ";
				std::cin >> new_producer;
				it.change_producer(new_producer);
			}
			if (n == 3)
			{
				std::string new_scenarist;
				std::cout << "Enter new scenarist: ";
				std::cin >> new_scenarist;
				it.change_scenarist(new_scenarist);
			}
			if (n == 4)
			{
				std::string new_release_date;
				std::cout << "Enter new release date: ";
				std::cin >> new_release_date;
				it.change_release_date(new_release_date);
			}
			if (n == 5)
			{
				std::string new_name;
				std::cout << "Enter new name: ";
				std::cin >> new_name;
				it.change_name(new_name);
			}
			if (n == 6)
			{
				unsigned int new_money;
				std::cout << "Enter new money: ";
				std::cin >> new_money;
				it.change_money(new_money);
			}
			break;
		}
	}
	std::cout << "No such film\n";
}

void filmlib::show_by_producer(std::string _producer)
{
	for (auto it : films)
	{
		if (it.producer == _producer)
		{
			it.show_info();
			break;
		}
	}
	std::cout << "No such film\n";
}


int filmlib::get_size()
{
	return films.size();
}

void filmlib::save_to_file(std::string filename)
{
	std::ofstream out;
	out.open(filename);

	for (auto it : films)
	{
		out << name << std::endl;		
		out << it.get_name() << std::endl;
		out << it.get_release_date() << std::endl;
		out << it.get_producer() << std::endl;
		out << it.get_scenarist() << std::endl;
		out << it.get_composer() << std::endl;
		out << it.get_money() << std::endl;
	}
}

void filmlib::read_from_file(std::string path)
{
	std::ifstream in(path);
	if (in.is_open())
	{
		while (!in.eof())
		{
			film a;
			std::string cache;
			getline(in, name);
			getline(in, cache);
			a.change_name(cache);
			getline(in, cache);
			a.change_release_date(cache);
			getline(in, cache);
			a.change_producer(cache);
			getline(in, cache);
			a.change_scenarist(cache);
			getline(in, cache);
			a.change_composer(cache);
			getline(in, cache);
			int buf = std::stoi(cache);
			a.change_money(buf);
		}
	}

}

void filmlib::show_by_year(unsigned int year)
{
	std::string syear = std::to_string(year);
	for (auto it : films)
	{
		if (it.get_release_date()[0] == syear[0])
		{
			if (it.get_release_date()[1] == syear[1])
			{
				if(it.get_release_date()[2] == syear[2])
				{
					if (it.get_release_date()[3] == syear[3])
					{
						it.show_info();
					}

				}
			}
		}
	}
}

