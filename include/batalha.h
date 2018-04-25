#ifndef BATALHA_H
#define BATALHA_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "monstro.h"
#include "IA.h"

class Batalha {
	private:
		Monstro *monstroPlayer;
		IA *ia;

		bool alguemMorreu;

		int turnos;

		void iniciarIA();

	public:
		Batalha(Monstro *monstroPlayer);
		Batalha();
		~Batalha();

		void setup();

		void jogar(Jogada jogada);

		void setMonstro(Monstro *monstroPlayer, int ID);
		Monstro getMonstro(int ID);

		bool ninguemMorreu();
};

#endif