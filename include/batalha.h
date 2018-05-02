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
		void jogar(Jogada jogada, Monstro *monstro1, Monstro *monstro2);

	public:
		Batalha(Monstro *monstroPlayer);
		Batalha();
		~Batalha();

		void setJogada(Jogada jogada);

		void setMonstro(Monstro *monstroPlayer);
		Monstro getMonstro();

		bool ninguemMorreu();
};

#endif