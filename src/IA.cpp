#include "IA.h"

#include <iostream>
using std::cout;
using std::endl;

#include "fileHandler.h"

std::random_device IA::rd{};
std::mt19937 IA::gen(IA::rd());

IA::IA() {
	monstro_ia = new Monstro();

	std::uniform_int_distribution<> dis((int)GUERREIRO, (int)TANKER);
	classe = (ClasseMonstro)std::round(dis(gen));

	ifstream file;
	file.open("./data/classes_monstros");

	cout << classe << endl;

	if (!file) {
		cout << "Erro ao abrir arquivo!" << endl;
	} else {
		readFile(file, classe);
		file >> *monstro_ia;
	}
}

IA::~IA() {

}

void IA::exibirMonstro() {
	cout << *monstro_ia;
}