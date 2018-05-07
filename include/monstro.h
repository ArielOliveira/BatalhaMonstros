#ifndef MONSTRO_H
#define MONSTRO_H

#include <ostream>
using std::ostream;

#include <istream>
using std::istream;

#include <string>
using std::string;

const string acoes[] = {"Ataque Físico",
						"Ataque Mágico",
						"Melhorar Atributo",
						"Defesa"};

enum ACAO {
	ATAQUE_FISICO,
	ATAQUE_MAGICO,
	MELHORAR_ATRIBUTO,
	DEFESA
};

const string atributos[] = {"Força Física",
							"Força Mágica",
							"Defesa Física",
							"Defesa Mágica",
							"Vida Atual"};

enum ATRIBUTO {
	FORCA_FISICA,
	FORCA_MAGICA,
	DEFESA_FISICA,
	DEFESA_MAGICA,
	VIDA_ATUAL
};

const string classes[] = {"BALANCEADO",
						  "GUERREIRO", 
						  "MAGO", 
						  "TANKER"};

enum ClasseMonstro {
	BALANCEADO,
	GUERREIRO,
	MAGO,
	TANKER
};

class Efeito {
	private:
		int duracao;
		ATRIBUTO atributo;
	public:
		Efeito(ATRIBUTO atributo): atributo(atributo) {duracao = 2;}
		Efeito(Efeito const &e) {*this = e;}
		Efeito() {}
		~Efeito() {}

		void setEfeito(ATRIBUTO atributo) {
			this->atributo = atributo;
			duracao = 2;
		}

		ATRIBUTO getEfeito() {return atributo;}

		int contar() {return duracao -= (duracao > 0) ? 1 : 0;}
};

class Monstro {
	private:
		ClasseMonstro classe;

		Efeito *efeito;

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

		Monstro(ClasseMonstro classe);
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

		friend void operator+ (Monstro &_monstro, Efeito &e);
};

#endif