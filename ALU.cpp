#include "ALU.h"
#include "menu.h"
#include "datamgt.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

ALU::ALU()
{
	menu_ativo = true;
	register_a = "00000000";
	register_b = "00000000";
	op_code = "000";
	register_flags = "000";
}
void ALU::menuALU()
{
	string menu_op;
	menu::exibeMenuPrincipal();
	while (menu_ativo)
	{
		menu::exibeMenuPrincipal();
		menu_op = menu::inputMenu();
		switch (stoi(menu_op, 0, 2))
		{
		case 0:
			break;
		case 1:
			define_reg_a();
			break;
		case 2:
			define_reg_b();
			break;
		case 3:
			imprime_reg_a();
			break;
		case 4:
			imprime_reg_b();
			break;
		case 5:
			imprime_reg_flag();
			break;
		case 6:
			define_op();
			break;
		case 7:
			executar();
			break;
		}
	}
}
void ALU::define_reg_a()
{
	system("CLS");
	cout << "*******************************************" << endl;
	cout << "Metodo para definir Registrador A invocado" << endl;
	register_a = input_data("Registrador A", 8);
	menu::retornarAoMenuPrincipal();
}
void ALU::define_reg_b()
{
	system("CLS");
	cout << "*******************************************" << endl;
	cout << "Metodo para definir Registrador B invocado" << endl;
	register_a = input_data("Registrador B", 8);
	menu::retornarAoMenuPrincipal();
}
void ALU::imprime_reg_a()
{
	system("CLS");
	cout << "*******************************************" << endl;
	cout << "Metodo para imprimir o Registrador A invocado" << endl;
	cout << "Registrador A: " << register_a;
	menu::retornarAoMenuPrincipal();
}
void ALU::imprime_reg_b()
{
	system("CLS");
	cout << "*******************************************" << endl;
	cout << "Metodo para imprimir o Registrador B invocado" << endl;
	cout << "Registrador B: " << register_b;
	menu::retornarAoMenuPrincipal();
}
void ALU::imprime_reg_flag()
{
	system("CLS");
	cout << "*******************************************" << endl;
	cout << "Metodo para imprimir o Registrador de flags invocado" << endl;
	cout << "Registrador de Flags: " << register_flags;
	menu::retornarAoMenuPrincipal();
}
void ALU::define_op()
{
	menu::exibeMenuOperacoes();
	op_code = menu::inputMenu();
	menu::retornarAoMenuPrincipal();
}
void ALU::executar()
{

}