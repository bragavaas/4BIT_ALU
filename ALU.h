#pragma once
#include <string>


using namespace std;

class ALU
{
private:
	string register_a, register_b, register_flags, op_code;
	bool menu_ativo;

	void a_plus_b();
	void a_minus_b();
	void a_and_b();
	void a_or_b();
	void not_a();
	void shift_left();
	void shift_right();
	void swap_nibbles();
	void limpa_flags();
public:
	ALU();
	void menuALU();
	void define_reg_a();
	void imprime_reg_a();
	void define_reg_b();
	void imprime_reg_b();
	void imprime_reg_flag();
	void define_op();
	void executar();
};

