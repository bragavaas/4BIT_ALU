#include "menu.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void menu::principal()
{
	bool menuAtivo = true;
	int menuOP;

	while (menuAtivo)
	{
		system("CLS");
		cout << "\n\n--------------------------------" << endl;
		cout << "MENU PRINCIPAL DA ULA" << endl;
		cout << "1. Definir registrador A" << endl;
		cout << "2. Definir registrador B" << endl;
		cout << "3. Ler registrador A (Acc)" << endl;
		cout << "4. Ler registrador B" << endl;
		cout << "5. Ler registrador de Flags" << endl;
		cout << "6. Definir Operação" << endl;
		cout << "7. Executar ULA" << endl;
		cout << "8. Sair" << endl;
		cout << "--------------------------------" << endl;

		cout << "Digite a opcao desejada:" << endl;
		cin >> menuOP;

		if (menuOP_valido(1, 8, menuOP))
		{
			switch (menuOP)
			{
				case 1:
					menuOP_1();
					menuAtivo = false;
					break;
				case 2:
					menuOP_2();
					menuAtivo = false;
					break;
				case 3:
					menuOP_3();
					menuAtivo = false;
					break;
				case 4:
					menuOP_4();
					menuAtivo = false;
					break;
				case 5:
					menuOP_5();
					menuAtivo = false;
					break;
				case 6:
					menuOP_6();
					menuAtivo = false;
					break;
				case 7:
					menuOP_7();
					menuAtivo = false;
					break;
				case 8:
					menuOP_8();
					menuAtivo = false;
					break;

			}
		}
		else {

			system("CLS");
			cout << "OPCAO INVALIDA, POR FAVOR TENTE NOVAMENTE";
			abort;
		}
	}
}

bool menu::menuOP_valido(int baixo, int alto, int x)
{
	return  ((x - baixo) <= (alto - baixo));
}

void menu::menuOP_1()
{
	cout << "Definir Registrador A";
}
void menu::menuOP_2()
{
	cout << "Definir Registrador B";
}
void menu::menuOP_3()
{
	cout << "Ler Registrador A (Acc)";
}
void menu::menuOP_4()
{
	cout << "Ler Registrador B";
}
void menu::menuOP_5()
{
	cout << "Ler Registrador de Flags";
}
void menu::menuOP_6()
{
	cout << "Definir Operação";
}
void menu::menuOP_7()
{
	cout << "Executar ULA";
}
void menu::menuOP_8()
{
	cout << "**Sair**";
}