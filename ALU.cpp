#include "ALU.h"
#include "menu.h"
#include "datamgt.hpp"
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

ALU::ALU()
{
	menu_ativo = true;
	register_a = bitset<8>("00000000").to_string();
	register_b = bitset<8>("00000000").to_string();
	op_code = bitset<3>("000").to_string();
	register_flags = bitset<4>("0000").to_string();
}
void ALU::menuALU()
{
	string menu_op;
	menu::exibeMenuPrincipal();
	while (menu_ativo)
	{
		menu::exibeMenuPrincipal();
		menu_op = menu::inputMenu();
		switch (bitset<3>(menu_op).to_ulong())
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
			exibe_resultados();
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
	cout << "Registrador de Flags: " << register_flags <<endl;
	cout << "---------------------------------------------------"  << endl;
	cout << "|TABELA DE FLAGS                                  |" << endl;
	cout << "---------------------------------------------------"  << endl;
	cout << "| ALU FLAG BIT | NOME | Significado               |" << endl;
	cout << "---------------------------------------------------"  << endl;
	cout << "|      3       |   N  | Resultado Negativo        |" << endl;
	cout << "|      2       |   Z  | Resultado Zero            |" << endl;
	cout << "|      1       |   C  | Resultado Carry Out       |" << endl;
	cout << "|      0       |   V  | Resultado Overflow        |" << endl;
	cout << "---------------------------------------------------" << endl;
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
	system("CLS");
	cout << "****************************" << endl;
	cout << "Limpando o registrador de Flags: " << endl;
	limpa_flags();
	cout << "PRONTO PARA EXECUTAR A ALU:" << endl; 
	cout << "Operacao escolhida: ";
	switch (bitset<3>(op_code).to_ulong())
	{
	case 0:
		cout << "A+B" << endl;
		sleep_for(3000ms);
		a_plus_b();
		break;
	case 1:
		cout << "A-B" << endl;
		sleep_for(3000ms);
		a_minus_b();
		break;
	case 2:
		cout << "A AND B" << endl;
		sleep_for(3000ms);
		a_and_b();
		break;
	case 3:
		cout << "A OR B" << endl;
		sleep_for(3000ms);
		a_or_b();
		break;
	case 4:
		cout << "NOT A" << endl;
		sleep_for(3000ms);
		not_a();
		break;
	case 5:
		cout << "SLL A" << endl;
		sleep_for(3000ms);
		shift_left();
		break;
	case 6:
		cout << "SRL A" << endl;
		sleep_for(3000ms);
		shift_right();
		break;
	case 7:
		cout << "SWAP NIBBLES A" << endl;
		sleep_for(3000ms);
		swap_nibbles();
		break;
	}
}
void ALU::a_plus_b()
{
	int reg_a = bitset<8>(register_a).to_ulong();
	int reg_b = bitset<8>(register_b).to_ulong();
	int result = reg_a + reg_b;

	//FLAG V POIS SL REGISTER_A > 127 RESULTARA EM OVERFLOW
	// (1111 1111 + 0000 0001 -> [1] 0000 0000)
	if (result > 255) { register_flags = "0001"; }

	//FLAG Z POIS SL REGISTER_A > 127 RESULTARA EM OVERFLOW
	// (0000 0000 + 0000 0000 -> 0000 0000)
	if (result == 0) { register_flags = "0100"; }

	register_a = bitset<8>(result).to_string();
}
void ALU::a_minus_b() {
	int reg_a = bitset<8>(register_a).to_ulong();
	int reg_b = bitset<8>(register_b).to_ulong();
	int result = reg_a + reg_b;

	// FLAG N POIS SE REGISTER_A < REGISTER_B, REGISTER_A < 0
	// EX: ( 0000 0001 + 0000 0010 -> 0000 0000 [1] )
	if (result < 0) { register_flags = "1000"; }

	// FLAG Z POIS SE REGISTER_A = REGISTER_B, REGISTER_A = 0
	// EX: (0000 0001 - 0000 0001 -> 0000 0000)
	if (result == 0) { register_flags = "0100"; }

	register_a = bitset<8>(result).to_string();
};
void ALU::a_and_b() 
{
	int reg_a = bitset<8>(register_a).to_ulong();
	int reg_b = bitset<8>(register_b).to_ulong();
	int result = reg_a & reg_b;

	// FLAG Z POIS SE REGISTER_A = REGISTER_B, REGISTER_A = 0
	// EX: (0000 0001 & 0000 0001 -> 0000 0000)
	if (result == 0) { register_flags = "0100"; }
	register_a = bitset<8>(result).to_string();
}
void ALU::a_or_b()
{
	int reg_a = bitset<8>(register_a).to_ulong();
	int reg_b = bitset<8>(register_b).to_ulong();
	int result = reg_a | reg_b;

	// FLAG Z POIS SE REGISTER_A = REGISTER_B, REGISTER_A = 0
	// EX: (0000 0001 - 0000 0001 -> 0000 0000)
	if (result == 0) { register_flags = "0100"; }
	register_a = bitset<8>(result).to_string();
}
void ALU::not_a()
{
	int reg_a = bitset<8>(register_a).to_ulong();
	reg_a = ~reg_a;
	//FLAG Z POIS ~A RESULTA EM ZERO
	// EX: 1111 1111 -> 0000 0000
	if (reg_a == 0) { register_flags = "0100"; }
	register_a = bitset<8>(reg_a).to_string();
}
void ALU::shift_left()
{
	int reg_a = bitset<8>(register_a).to_ulong();
	reg_a = (reg_a << 1);
	//FLAG V POIS SL REGISTER_A > 127 RESULTARA EM OVERFLOW
	// (1000 0000 SL -> [1] 0000 0000)
	if (reg_a > 255) { register_flags = "0001"; }
	register_a = bitset<8>(reg_a).to_string();
}
void ALU::shift_right() 
{
	int reg_a = (bitset<8>(register_a).to_ulong() << 1);
	reg_a = (reg_a >> 1);
	//FLAG #DE ZERO POIS SLL REGISTER_A RESULTARA EM OVERFLOW
	// (0000 0001 SR -> 0000 0000)
	if (reg_a == 0) { register_flags = "0001"; }
	register_a = bitset<8>(reg_a).to_string();
}
void ALU::swap_nibbles()
{
	int reg_a = bitset<8>(register_a).to_ulong();
	reg_a = ((reg_a & 0x0F) << 4 | (reg_a & 0xF0) >> 4);

	//FLAG Z POIS SE REGISTER_A = 0, SW REGISTER_A RESULTARA EM 0
	// (0000 0000 SL -> 0000 0000)
	if (reg_a == 0) { register_flags = "0100"; }
	register_a = bitset<8>(reg_a).to_string();
	
};
void ALU::limpa_flags() { register_flags = "0000"; }
void ALU::exibe_resultados() {
	system("CLS");
	cout << "*************************" << endl;
	cout << "RESULTADO DA OPERACAO" << endl;
	cout << "REGISTRADOR A (APOS A OPERACAO): " << register_a << "( " << bitset<8>(register_a).to_ulong() << " );" << endl;
	cout << "REGISTRADOR DE FLAGS: " << register_flags << "( " << bitset<8>(register_flags).to_ulong() - 1 << " );" << endl;
	
	if (bitset<8>(register_flags).to_ulong() != 0)
	{
		cout << "---------------------------------------------------" << endl;
		cout << "|TABELA DE FLAGS                                  |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "| ALU FLAG BIT | NOME | Significado               |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "|      3       |   N  | Resultado Negativo        |" << endl;
		cout << "|      2       |   Z  | Resultado Zero            |" << endl;
		cout << "|      1       |   C  | Resultado Carry Out       |" << endl;
		cout << "|      0       |   V  | Resultado Overflow        |" << endl;
		cout << "---------------------------------------------------" << endl;
	}

	menu::retornarAoMenuPrincipal();
};