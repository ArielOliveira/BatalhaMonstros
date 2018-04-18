#ifndef MONSTRO_H
#define MONSTRO_H

#include <ostream>
using std::ostream;

#include <istream>
using std::istream;

#include "acoes.h"

class Monstro {
	private:
		ClasseMonstro classe;

		int vida;
		int vidaAtual;

		int forcaFisica;
		int forcaMagica;

		int defesaFisica;
		int defesaMagica;

		void ataqueMagico(Monstro *monstro);
		void ataqueFisico(Monstro *monstro);

		void defesa(Monstro *monstro, short int defesa);
		
		void melhorarAtributo(ATRIBUTO atributo);

	public:
		static int ID;

		Monstro(int vida, int forcaFisica, int forcaMagica, int defesaFisica, int defesaMagica);
		Monstro();
		~Monstro();

		void acao(Monstro *monstro, ACAO acao, ATRIBUTO atributo);

		void setClasseMonstro(ClasseMonstro classe);
		ClasseMonstro getClasseMonstro();

		void setVida(int vida);
		int getVida();

		int getVidaAtual();

		void setForcaFisica(int forcaFisica);
		int getForcaFisica();

		void setDefesaFisica(int defesaFisica);
		int getDefesaFisica();

		void setForcaMagica(int forcaMagica);
		int getForcaMagica();

		void setDefesaMagica(int defesaMagica);
		int getDefesaMagica();

		friend ostream& operator<< (ostream &o, Monstro const _monstro);

		friend istream& operator>> (istream &i, Monstro &_monstro);
};

#endif