#pragma once
class menu
{
	bool menuOP_valido(int baixo, int alto, int x);



public:
	int principal();
	int OP_escolhida(int menuOP);
	bool menu_ativo = true;
};

