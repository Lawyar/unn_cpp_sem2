#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
class film
{
private:
	std::string name;
	std::string producer;
	std::string scenarist;
	std::string composer;
	std::string release_date;
	unsigned int money;
public:
	film();
	film(std::string _name, std::string _producer, std::string _scenarist, std::string _composer, std::string _release_date, int _money);
	void change_name(std::string new_name);
	void change_producer(std::string new_producer);
	void change_scenarist(std::string new_scenarist);
	void change_composer(std::string new_composer);
	void change_release_date(std::string new_release_date);
	void change_money(unsigned int new_money);
	void show_info();

	std::string get_name();
	std::string get_producer();
	std::string get_scenarist();
	std::string get_composer();
	std::string get_release_date();
	unsigned int get_money();

	friend class filmlib;
};
class filmlib
{
private:
	std::vector<film> films;
	std::string name;
	int film_quantity;

public:
	filmlib();
	filmlib(std::string name);
	void add_film(film filmie);
	void remove_film(std::string name);
	void sort_by_release();
	void sort_by_name();
	void change_film_date(std::string name);
	void show_by_producer(std::string _producer);
	void show_by_year(unsigned int year);
	int get_size();
	void save_to_file(std::string filename);
	void read_from_file(std::string path);
};

