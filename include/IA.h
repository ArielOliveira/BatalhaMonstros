#ifndef IA_H
#define IA_H

#include <random>

#include "monstro.h"

enum ClasseMonstro {
	BALANCEADO,
	GUERREIRO,
	MAGO,
	TANKER
};

class IA {
	private:
		Monstro *monstro_ia;

		ClasseMonstro classe;

	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		IA();
		~IA();

		void exibirMonstro();
};

#endif