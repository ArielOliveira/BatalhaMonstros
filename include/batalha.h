#ifndef BATALHA_H
#define BATALHA_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "acoes.h"

#include "monstro.h"

class Batalha {
	private:
		Monstro *monstro_1;
		Monstro *monstro_2;

		bool alguemMorreu;

		int turnos;

	public:
		Batalha(Monstro *monstro_1, Monstro *monstro_2);
		Batalha();
		~Batalha();

		void setup();

		void jogar(ACAO acao, ATRIBUTO atributo);

		void setMonstro(Monstro *monstro, int ID);
		Monstro getMonstro(int ID);

		bool ninguemMorreu();
};

#endif