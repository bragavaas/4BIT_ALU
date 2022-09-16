#include "menu.h"
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int menu::principal()
{
	int menuOP;
	while (menu_ativo)
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
		return OP_escolhida(menuOP);
	}
}

int menu::OP_escolhida(int menuOP)
{
	if (menuOP_valido(1, 8, menuOP)) return menuOP;
	else {
		system("CLS");
		cout << "OPCAO INVALIDA, POR FAVOR TENTE NOVAMENTE";
		sleep_for(5s);
		return -1;
	}
}

bool menu::menuOP_valido(int baixo, int alto, int x)
{
	return  ((x - baixo) <= (alto - baixo));
}
