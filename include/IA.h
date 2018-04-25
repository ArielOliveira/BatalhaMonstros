#ifndef IA_H
#define IA_H

#include <random>

#include "monstro.h"

class Jogada {
	private:
		ACAO acao;
		ATRIBUTO atributo;
		
	public:
		Jogada(ACAO acao, ATRIBUTO atributo): acao(acao), atributo(atributo) {}
		Jogada() {}
		~Jogada() {}

		void setAcao(ACAO acao) {this->acao = acao;}
		ACAO getAcao() {return acao;}

		void setAtributo(ATRIBUTO atributo) {this->atributo = atributo;}
		ATRIBUTO getAtributo() {return atributo;}
};

class IA {
	protected:
		Monstro *monstro_ia;

		int danoRecebido;
		int danoCausado;

	public:
		static std::random_device rd;
		static std::mt19937 gen;
		static std::uniform_int_distribution<> dis;

		IA(ClasseMonstro classe);
		IA();
		~IA();

		void exibirMonstro();

		Monstro* getMonstro();

		virtual Jogada jogadaIA() = 0;
};

class Guerreiro : public IA {
	public:
		Guerreiro(): IA(GUERREIRO) {}
		~Guerreiro() {}

		Jogada jogadaIA();
};

class Mago : public IA {
	public:
		Mago(): IA(MAGO) {}
		~Mago() {}

		Jogada jogadaIA();
};

class Tanker : public IA {
	private:
		Jogada *jogada;

	public:
		Tanker(): IA(TANKER) {}
		~Tanker() {}

		Jogada jogadaIA();
};

#endif