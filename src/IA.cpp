#include "IA.h"

#include <iostream>
using std::cout;


std::random_device IA::rd{};
std::mt19937 IA::gen(IA::rd());

IA::IA(ClasseMonstro classe) {
	monstro_ia = new Monstro(classe);
}

IA::IA() {
	std::uniform_int_distribution<> dis((int)GUERREIRO, (int)TANKER);
	monstro_ia = new Monstro((ClasseMonstro)std::round(dis(gen)));
}

IA::~IA() {}

void IA::exibirMonstro() {
	cout << *monstro_ia;
}