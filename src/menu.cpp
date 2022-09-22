#include "../include/menu.h"
#include "../include/datamgt.hpp"
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void menu::exibeMenuPrincipal()
{
	system("CLS");
	cout << "\n\n--------------------------------" << endl;
	cout << "MENU PRINCIPAL DA ULA" << endl;
	cout << "0. (000) Sair" << endl;
	cout << "1. (001) Definir registrador A" << endl;
	cout << "2. (010) Definir registrador B" << endl;
	cout << "3. (011) Ler registrador A (Acc)" << endl;
	cout << "4. (100) Ler registrador B" << endl;
	cout << "5. (101) Ler registrador de Flags" << endl;
	cout << "6. (110) Definir Operacao" << endl;
	cout << "7. (111) Executar ULA" << endl;
	cout << "--------------------------------" << endl;
}

void menu::exibeMenuOperacoes()
{
	system("CLS");
	cout << "\n\n";
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "|MENU DE OPERACOES                                                                                         |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "|Op_code| Operacao    | Significado                                                                        |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "| (000) | A + B       | Bit-wise AND                                                                       |" << endl;
	cout << "| (001) | A - B       | Bit-wise OR                                                                        |" << endl;
	cout << "| (010) | A AND B     | Bit-wise XOR                                                                       |" << endl;
	cout << "| (011) | A OR B      | Bit-wise A+B                                                                       |" << endl;
	cout << "| (100) | NOT A       | Invert todos os Bits do Registrador A                                              |" << endl;
	cout << "| (101) | Shift Left  | Move todos os bits do regitrador uma posicao para a direita e completa o LSB com 0.|" << endl;
	cout << "| (110) | Shift Right | Move todos os bits do regitrador uma posicao para a direita e completa o MSB com 0.|" << endl;
	cout << "| (111) | Swap nibbles| Dado um byte, inverte a ordem dos dois nibbles dele.                               |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

string menu::inputMenu()
{
	string menuInput;
	menuInput = input_data("Controle de Menu", 3);	
	return menuInput;
}

void menu::retornarAoMenuPrincipal()
{
	char option;
	cout << "\n Deseja voltar ao menu principal? (S/N)";
	cin >> option;
	while (option != 'S')
	{
		cout << "\n Deseja voltar ao menu principal? (S/N)";
		cin >> option;
	} 
}

