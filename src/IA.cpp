#include "IA.h"

#include <iostream>
using std::cout;


std::random_device IA::rd{};
std::mt19937 IA::gen(IA::rd());

IA::IA(ClasseMonstro classe) {
	monstro_ia = new Monstro(classe);
}

IA::IA() {
	monstro_ia = new Monstro();
}

IA::~IA() {}

void IA::exibirMonstro() {
	cout << *monstro_ia;
}

void IA::jogarIA() {}