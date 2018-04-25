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

Monstro* IA::getMonstro() {return monstro_ia;}

Jogada Guerreiro::jogadaIA() {
	Jogada jogada;

	if (monstro_ia->getVidaAtual() > monstro_ia->getVida()/(monstro_ia->getVida()/30)) {
		jogada = Jogada(ATAQUE_FISICO, FORCA_FISICA);
	} else {
		jogada = Jogada(MELHORAR_ATRIBUTO, VIDA_ATUAL);
	}

	return jogada;
}

Jogada Mago::jogadaIA() {
	Jogada jogada;

	if (monstro_ia->getVidaAtual() > monstro_ia->getVida()/(monstro_ia->getVida()/30)) {
		jogada = Jogada(ATAQUE_MAGICO, FORCA_MAGICA);
	} else {
		jogada = Jogada(MELHORAR_ATRIBUTO, VIDA_ATUAL);
	}

	return jogada;
}

Jogada Tanker::jogadaIA() {
	if (!jogada) {
		jogada = new Jogada(MELHORAR_ATRIBUTO, FORCA_FISICA);

	} else if (monstro_ia->getVidaAtual() > monstro_ia->getVida()/(monstro_ia->getVida()/30)) {
		jogada->setAcao(ATAQUE_FISICO);
		jogada->setAtributo(FORCA_FISICA);
	} else {
		jogada->setAcao(MELHORAR_ATRIBUTO);
		jogada->setAtributo(VIDA_ATUAL);
	}

	return *jogada;
}