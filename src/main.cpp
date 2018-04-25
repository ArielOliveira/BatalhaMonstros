#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "monstro.h"
#include "batalha.h"

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



Jogada escolherJogada() {
	int valor1, valor2;

	cout << "Escolha sua Jogada: " << endl;
	cout << "\t0 - Ataque Físico" << endl;
	cout << "\t1 - Ataque Mágico" << endl;
	cout << "\t2 - Melhorar Atributo" << endl;

	cin >> valor1;
	valor2 = valor1;

	if (valor1 == 2) {
		cout << "Escolha o Atributo: " << endl;
		cout << "\t0 - Vida Atual" << endl;
		cout << "\t1 - Força Física" << endl;
		cout << "\t2 - Força Mágica" << endl;
		cout << "\t3 - Defesa Física" << endl;
		cout << "\t4 - Defesa Mágica" << endl;

		cin >> valor2;
	}

	return Jogada((ACAO)valor1, (ATRIBUTO)valor2);
}

int main() {

	int classe = selecionarClasse();

	Monstro *monstro = new Monstro((ClasseMonstro)classe);

	cout << *monstro;

	Batalha *batalha = new Batalha(monstro);

	while(batalha->ninguemMorreu()) {
		Jogada jogada = escolherJogada();

		batalha->setJogada(jogada);
	}

	return 0;
}