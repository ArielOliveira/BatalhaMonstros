#include "batalha.h"

Batalha::Batalha(Monstro *monstroPlayer): monstroPlayer(monstroPlayer) {
	turnos = 0;
	alguemMorreu = false;

	iniciarIA();
}

Batalha::Batalha() {
	monstroPlayer = 0;
	turnos = 0;
	alguemMorreu = false;

	iniciarIA();
}

Batalha::~Batalha() {}

void Batalha::iniciarIA() {
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
}

void Batalha::jogar(Jogada jogada) {
	switch(jogada.getAcao()) {
		case MELHORAR_ATRIBUTO: monstroPlayer->acao(NULL, jogada.getAcao(), jogada.getAtributo());
			break;
		default: monstroPlayer->acao(ia->getMonstro(), jogada.getAcao(), jogada.getAtributo());
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

void Batalha::setMonstro(Monstro *monstroPlayer) {
	if (ID == 1 && (!monstroPlayer)) {
		this->monstroPlayer = monstroPlayer;
	}
}

Monstro Batalha::getMonstro(int ID) {return *monstroPlayer;}

bool Batalha::ninguemMorreu() {
	if (alguemMorreu) 
		return false;
	else
		return true;
}