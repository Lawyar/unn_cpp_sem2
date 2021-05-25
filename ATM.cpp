#include "ATM.h"

string Client::card_gen()
{
	if (n < 10000)
	{
		if (n < 1000)
		{
			if (n < 100)
			{
				if (n < 10)
				{
					card = "000" + to_string(n);
				}
				card = "00" + to_string(n);
			}
			card = "0" + to_string(n);
		}
		card = to_string(n);
	}
	return card;
}

string Client::pin_gen()
{
	string pincode;
	cout << "Pick a pin (4 digits): ";
	cin >> pincode;
	return pincode;
}

Client::Client()
{
	n++;
	name = "noname";
	surname = "nosurname";
	patronymic = "nopatronymic";
	full_name = name + " " + surname + " " + patronymic;
	card = card_gen();
	pin = pin_gen();
}

Client::Client(string _name, string _surname, string _patronymic)
{
	n++;
	name = _name;
	surname = _surname;
	patronymic = _patronymic;
	full_name = name + " " + surname + " " + patronymic;
	card = card_gen();
	pin = pin_gen();
}

Client::~Client()
{
	n--;
}

string Client::get_name()
{
	return name;
}

string Client::get_surname()
{
	return surname;
}

string Client::get_patronymic()
{
	return patronymic;
}

string Client::get_full_name()
{
	return full_name;
}

string Client::get_card()
{
	return card;
}

string Client::get_pin()
{
	return pin;
}

unsigned long Client::get_money()
{
	return money;
}

void Client::show_client()
{
	cout << full_name << endl;
	cout << card << endl;
}

void Client::change_name(string new_name)
{
	name = new_name;
}

void Client::change_surname(string new_surname)
{
	surname = new_surname;
}

void Client::change_patronymic(string new_patronymic)
{
	patronymic = new_patronymic;
}

void Client::change_pin(string new_pin)
{
	pin = new_pin;
}

Client ClientDatabase::get_client(string card)
{
	for (auto it : clients)
	{
		if (it.card == card)
		{
			return it;
		}
	}
	exit(1);
}

bool ClientDatabase::check_pin(string card, string pin)
{
	if (findby_card(card))
	{
		Client a = get_client(card);
		if (a.get_pin() == pin)
		{
			return true;
		}
		return false;
	}
}

void ClientDatabase::add_client(Client client)
{
	clients.push_back(client);
}

void ClientDatabase::deleteby_card(string card)
{
	for (int i = 0; i < clients.size(); i++)
	{
		if (clients[i].get_card() == card)
		{
			clients.erase(clients.begin() + i);
			break;
		}
	}
	n--;
}

void ClientDatabase::deleteby_full_name(string _full_name)
{
	for (int i = 0; i < clients.size(); i++)
	{
		if (clients[i].get_full_name() == _full_name)
		{
			clients.erase(clients.begin() + i);
			break;
		}
	}
	n--;
}

void ClientDatabase::show_all()
{
	for (auto it : clients)
	{
		it.show_client();
	}
}

bool ClientDatabase::findby_card(string _card)
{
	for (auto it : clients)
	{
		if (it.get_card() == _card)
		{
			return true;
			
		}
	}
	return false;
}

void ClientDatabase::findby_full_name(string _full_name)
{
	for (auto it : clients)
	{
		if (it.get_full_name() == _full_name)
		{
			it.show_client();
			break;
		}
	}
}

ATM::ATM(ClientDatabase _database)
{
	database = _database;
}

void ATM::show_bills()
{
	cout << "100: " << ohundred << "\n200: " << thundred << "\n500: " << fhundred
		<< "\n1000: " << othousand << "\n2000: " << tthousand << "\n5000: " << fthousand;

}

void ATM::withdraw_money(string card, string pin, unsigned long money)
{
	if (database.check_pin(card, pin))
	{
		if (money % 100 != 0)
		{
			cout << "Error";
			exit(1);
		}
		while (money != 0)
		{
			if (fthousand != 0)
			{
				if (money >= 5000)
				{
					fthousand--;
					cout << "You got a 5000\t";
					money = money - 5000;
					continue;
				}
			}
			else
			{
				if (money >= 5000)
				{
					if (tthousand != 0)
					{
						tthousand--;
						cout << "You got a 2000\t";
						money -= 2000;
						continue;
					}
					else
					{
						if (othousand != 0)
						{
							othousand--;
							cout << "You got a 1000\t";
							money -= 1000;
							continue;
						}
						else
						{
							if (fhundred != 0)
							{
								fhundred--;
								cout << "You got a 500\t";
								money -= 500;
								continue;
							}
							else
							{
								if (thundred != 0)
								{
									thundred--;
									cout << "You got a 200\t";
									money -= 200;
									continue;
								}
								else
								{
									if (ohundred != 0)
									{
										ohundred--;
										cout << "You got a 100\t";
										money -= 100;
										continue;
									}
									else
									{
										cout << "No bills\n";
										break;
									}
								}
							}
						}
					}
				}
			}
			if (money >= 2000)
			{
				if (tthousand != 0)
				{
					tthousand--;
					cout << "You got a 2000\t";
					money -= 2000;
					continue;
				}
				else
				{
					if (othousand != 0)
					{
						othousand--;
						cout << "You got a 1000\t";
						money -= 1000;
						continue;
					}
					else
					{
						if (fhundred != 0)
						{
							fhundred--;
							cout << "You got a 500\t";
							money -= 500;
							continue;
						}
						else
						{
							if (thundred != 0)
							{
								thundred--;
								cout << "You got a 200\t";
								money -= 200;
								continue;
							}
							else
							{
								if (ohundred != 0)
								{
									ohundred--;
									cout << "You got a 100\t";
									money -= 100;
									continue;
								}
								else
								{ 
									cout << "No bills\n";
									break;
								}
							}
						}
					}
				}
			}
			if (money >= 1000)
			{
				if (othousand != 0)
				{
					othousand--;
					cout << "You got a 1000\t";
					money -= 1000;
					continue;
				}
				else
				{
					if (fhundred != 0)
					{
						fhundred--;
						cout << "You got a 500\t";
						money -= 500;
						continue;
					}
					else
					{
						if (thundred != 0)
						{
							thundred--;
							cout << "You got a 200\t";
							money -= 200;
							continue;
						}
						else
						{
							if (ohundred != 0)
							{
								ohundred--;
								cout << "You got a 100\t";
								money -= 100;
								continue;
							}
							else
							{
								cout << "No bills\n";
								break;
							}
						}
					}
				}
			}
			if (money >= 500)
			{
				if (fhundred != 0)
				{
					fhundred--;
					cout << "You got a 500\t";
					money -= 500;
					continue;
				}
				else
				{
					if (thundred != 0)
					{
						thundred--;
						cout << "You got a 200\t";
						money -= 200;
						continue;
					}
					else
					{
						if (ohundred != 0)
						{
							ohundred--;
							cout << "You got a 100\t";
							money -= 100;
							continue;
						}
						else
						{
							cout << "No bills\n";
							break;
						}
					}
				}
			}
			if (money >= 200)
			{
				if (thundred != 0)
				{
					thundred--;
					cout << "You got a 200\t";
					money -= 200;
					continue;
				}
				else
				{
					if (ohundred != 0)
					{
						ohundred--;
						cout << "You got a 100\t";
						money -= 100;
						continue;
					}
					else
					{
						cout << "No bills\n";
						break;
					}
				}
			}
			if (money >= 100)
			{
				if (ohundred != 0)
				{
					ohundred--;
					cout << "You got a 100\t";
					money -= 100;
					continue;
				}
				else
				{
					cout << "No bills\n";
					break;
				}
			}
		}
	}
	cout << "Incorrect card\n";
}

void ATM::deposit_money(string card, string pin)
{
	if (database.check_pin(card, pin))
	{
		int t5;
		cout << "5000: ";
		cin >> t5;
		int t2;
		cout << "2000: ";
		cin >> t2;
		int t1;
		cout << "1000: ";
		cin >> t1;
		int h5;
		cout << "500: ";
		cin >> h5;
		int h2;
		cout << "200: ";
		cin >> h2;
		int h1;
		cout << "100: ";
		cin >> h1;
		if (t5 != 0)
		{
			if (t5 + fthousand > 2000)
			{
				cout << "Too much 5000";
			}
			else
			{
				fthousand += t5;
				cout << "Success";
			}
		}
		if (t2 != 0)
		{
			if (t2 + tthousand > 2000)
			{
				cout << "Too much 2000";
			}
			else
			{
				tthousand += t2;
				cout << "Success";
			}
		}
		if (t1 != 0)
		{
			if (t1 + othousand > 2000)
			{
				cout << "Too much 1000";
			}
			else
			{
				othousand += t1;
				cout << "Success";
			}
		}
		if (h5 != 0)
		{
			if (h5 + fhundred > 2000)
			{
				cout << "Too much 500";
			}
			else
			{
				fhundred += h5;
				cout << "Success";
			}
		}
		if (h2 != 0)
		{
			if (h2 + thundred > 2000)
			{
				cout << "Too much 200";
			}
			else
			{
				thundred += h2;
				cout << "Success";
			}
		}
		if (h1 != 0)
		{
			if (h1 + ohundred > 2000)
			{
				cout << "Too much 100";
			}
			else
			{
				ohundred += h1;
				cout << "Success";
			}
		}
	}
}
