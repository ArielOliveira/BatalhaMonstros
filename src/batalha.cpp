#include "batalha.h"

Batalha::Batalha(Monstro *monstro_1, Monstro *monstro_2) {
	this->monstro_1 = monstro_1;
	this->monstro_2 = monstro_2;

	alguemMorreu = false;

	turnos = 0;
}
Batalha::Batalha() {
	monstro_1 = 0;
	monstro_2 = 0;

	alguemMorreu = false;

	turnos = 0;
}

Batalha::~Batalha() {}

void Batalha::setup() {
	int valor;

	cout << "Insira os atributos do seu monstro: " << endl;
	
	cout << "Vida: ";
	cin >> valor;
	cout << endl;
	monstro_1->setVida(valor);
	
	cout << "Força Física: ";
	cin >> valor;
	cout << endl;
	monstro_1->setForcaFisica(valor);

	cout << "Defesa Física: ";
	cin >> valor;
	cout << endl;
	monstro_1->setDefesaFisica(valor);

	cout << "Força Mágica: ";
	cin >> valor;
	cout << endl;
	monstro_1->setForcaMagica(valor);

	cout << "Defesa Mágica: ";
	cin >> valor;
	cout << endl;
	monstro_1->setDefesaMagica(valor);
}

void Batalha::jogar(ACAO acao, ATRIBUTO atributo) {
	switch(acao) {
		case MELHORAR_ATRIBUTO: monstro_1->acao(NULL, acao, atributo);
			break;
		default: monstro_1->acao(monstro_2, acao, atributo);
			break;
	}

	if (monstro_2->getVidaAtual() <= 0) {
		alguemMorreu = true;
		return;
	}

	Monstro *aux = monstro_1;
	
	monstro_1 = monstro_2;
	monstro_2 = aux;

	aux = NULL;

	turnos++;
}

void Batalha::setMonstro(Monstro *monstro, int ID) {
	if (ID == 1 && (!monstro_1)) {
		this->monstro_1 = monstro;
	}
	if (ID == 2 && (!monstro_2)) {
		this->monstro_2 = monstro;
	}
}

Monstro Batalha::getMonstro(int ID) {return *monstro_1;}

bool Batalha::ninguemMorreu() {
	if (alguemMorreu) 
		return false;
	else
		return true;
}