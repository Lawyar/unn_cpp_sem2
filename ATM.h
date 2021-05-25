#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n = 0;
class Client
{
private:

	string name;
	string surname;
	string patronymic;
	string card;
	string full_name;
	string pin;
	unsigned long money;

	string card_gen();
	string pin_gen();


public:

	Client();
	Client(string _name, string _surname, string _patronymic);
	~Client();

	string get_name();
	string get_surname();
	string get_patronymic();
	string get_full_name();
	string get_card();
	string get_pin();
	unsigned long get_money();

	void show_client();

	void change_name(string new_name);
	void change_surname(string new_surname);
	void change_patronymic(string new_patronymic);
	void change_pin(string new_pin);

	friend class ClientDatabase;

};

class ClientDatabase
{
private:
	Client get_client(string card);
	bool check_pin(string card, string pin);
	vector <Client> clients;

public:
	void add_client(Client client);

	void deleteby_card(string card);
	void deleteby_full_name(string full_name);

	void show_all();

	void findby_full_name(string full_name);
	bool findby_card(string card);
	friend class ATM;
};

class ATM
{
private:
	ClientDatabase database;

	unsigned int ohundred = 1600;
	unsigned int thundred = 1600;
	unsigned int fhundred = 1600;
	unsigned int othousand = 1600;
	unsigned int tthousand = 1600;
	unsigned int fthousand = 1600;

public:
	ATM(ClientDatabase _database);
	void show_bills();
	
	void withdraw_money(string card, string pin, unsigned long money);
	void deposit_money(string card, string pin);

};

