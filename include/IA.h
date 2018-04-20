#ifndef IA_H
#define IA_H

#include <random>

#include "monstro.h"

class IA {
	protected:
		Monstro *monstro_ia;

		int danoCausado;
	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		IA(ClasseMonstro classe);
		IA();
		~IA();

		void exibirMonstro();

		virtual void jogarIA();
};

class Guerreiro : public IA {
	public:
		Guerreiro(): IA(GUERREIRO) {}
		~Guerreiro() {}

		void jogarIA() {

		}
};

class Mago : public IA {
	public:
		Mago(): IA(MAGO) {}
		~Mago() {}

		void jogarIA();
};

class Tanker : public IA {
	public:
		Tanker(): IA(TANKER) {}
		~Tanker() {}

		void jogarIA();
};

#endif