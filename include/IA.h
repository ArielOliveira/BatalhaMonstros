#ifndef IA_H
#define IA_H

#include <random>

#include "monstro.h"

class IA {
	protected:
		Monstro *monstro_ia;

	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		IA(ClasseMonstro classe);
		IA();
		~IA();

		void exibirMonstro();

		virtual void jogarIA() = 0;
};

class Guerreiro : public IA {
	public:
		Guerreiro(ClasseMonstro classe): IA(classe) {}	
};

class Mago : public IA {
	
};

class Tanker : public IA {
	
};

#endif