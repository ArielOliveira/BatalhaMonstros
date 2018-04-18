#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "monstro.h"
#include "batalha.h"
#include "IA.h"
#include "fileHandler.h"

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

int main() {
	Monstro *monstro = new Monstro();
	IA *ia = new IA();

	ia->exibirMonstro();

	int classe = selecionarClasse();

	ifstream file;
	file.open("./data/classes_monstros");

	if (!file) {
		cout << "Erro ao abrir arquivo!" << endl;
	} else {
		readFile(file, classe);
		file >> *monstro;
	}

	cout << *monstro;

	//while(batalha->ninguemMorreu()) {}

	return 0;
}