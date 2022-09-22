#pragma once
#include <string>

using namespace std; 

class menu
{

public:
	static void exibeMenuPrincipal();
	static void exibeMenuOperacoes();
	static string inputMenu();
	static void retornarAoMenuPrincipal();

	friend class ALU;
};

