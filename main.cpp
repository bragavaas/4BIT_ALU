#include <iostream>
#include <string>
#include "menu.h"
#include <chrono>
#include <thread>
#include "globalfunctions.h"
#include <regex>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

bool regex_validation(string s);
int input_data();
int convert_to_decimal(string s, int base);

int main()
{
	int register_a = input_data();
	system("CLS");
	cout << "Register A: " << register_a;

	//string register_a = input_dados();
	//ALU.setRegister_a(register_a)
}

bool regex_validation(string s)
{
	regex exp("(([1-9]|1[0-5])|([0-1]{4}))");
	return regex_match(s, exp);
}
int input_data()
{
	string s;
	bool input_valid = 0;
	int base;

	while (!input_valid)
	{
		cout << "\nEntre com o input de 4 bits desejado (bin ou dec, ate 1111 ou 15): ";
		getline(cin, s);
		input_valid = regex_validation(s);
		s.length() == 4 ? base = 2 : base = 10;
	}
	return convert_to_decimal(s, base);

}
int convert_to_decimal(string s, int base)
{
	int n;
	try {
		n = stoi(s, 0, base);
	}
	catch (exception e)
	{
		cout << "Input invalido. tente novamente!" << endl;
	}
	return n;
}