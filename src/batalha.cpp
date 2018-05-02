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

void Batalha::jogar(Jogada jogada, Monstro *monstro1, Monstro *monstro2) {
	switch(jogada.getAcao()) {
		case MELHORAR_ATRIBUTO: monstro1->acao(NULL, jogada.getAcao(), jogada.getAtributo());
			break;
		default: monstro1->acao(monstro2, jogada.getAcao(), jogada.getAtributo());
			break;
	}
}

void Batalha::setJogada(Jogada jogada) {
	jogar(jogada, monstroPlayer, ia->getMonstro());

	if (ia->getMonstro()->getVidaAtual() <= 0) {
		alguemMorreu = true;
		return;
	}

	turnos++;
	
	Jogada jogadaIA = ia->jogadaIA();	

	jogar(jogadaIA, ia->getMonstro(), monstroPlayer);

	if (jogadaIA.getAcao() == MELHORAR_ATRIBUTO) {
		cout << "IA Escolheu ";
	} else {
		cout << "IA Usou ";
	}

	cout << acoes[jogadaIA.getAcao()] << endl;

	if (monstroPlayer->getVidaAtual() <= 0) {
		alguemMorreu = true;
		return;
	}
	
	cout << *monstroPlayer << endl;
	cout << *ia->getMonstro() << endl;

	turnos++;

}

void Batalha::setMonstro(Monstro *monstroPlayer) {this->monstroPlayer = monstroPlayer;}

Monstro Batalha::getMonstro() {return *monstroPlayer;}

bool Batalha::ninguemMorreu() {
	if (alguemMorreu) 
		return false;
	else
		return true;
}