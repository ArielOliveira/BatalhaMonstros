#ifndef IA_H
#define IA_H

#include <random>

#include "monstro.h"

class IA {
	private:
		Monstro *monstro_ia;

	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		IA();
		~IA();

		void exibirMonstro();
};

#endif