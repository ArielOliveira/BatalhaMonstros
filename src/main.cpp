#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "monstro.h"
#include "batalha.h"
#include "IA.h"

int Monstro::ID = 0;

int selecionarClasse() {
	int valor;

	cout << "Selecione a Classe do Monstro: " << endl;
	cout << "\t0 - Balanceado" << endl;
	cout << "\t1 - Guerreiro" << endl;
	cout << "\t2 - Mago" << endl;
	cout << "\t3 - TANKER" << endl;

	cin >> valor;

	return valor;
}

IA* iniciarIA() {
	IA *ia;

	std::uniform_int_distribution<> dis((int)GUERREIRO, (int)TANKER);

	ClasseMonstro classe = (ClasseMonstro)std::round(dis(IA::gen));

	switch(classe) {
		case GUERREIRO: ia = new Guerreiro();
			break;
		case MAGO: ia = new Mago();
			break;
		case TANKER: ia = new Tanker();
			break;
		default:
			break;
	}

	return ia;
}

int main() {
	IA *ia = iniciarIA();

	ia->exibirMonstro();

	int classe = selecionarClasse();

	Monstro *monstro = new Monstro((ClasseMonstro)classe);

	cout << *monstro;

	//while(batalha->ninguemMorreu()) {}

	return 0;
}