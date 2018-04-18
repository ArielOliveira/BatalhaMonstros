#include "monstro.h"

Monstro::Monstro(int vida, int forcaFisica, int forcaMagica, int defesaFisica, int defesaMagica) {
	this->vida = vida;
	this->vidaAtual = vida;
	this->forcaFisica = forcaFisica;
	this->forcaMagica = forcaMagica;
	this->defesaFisica = defesaFisica;
	this->defesaMagica = defesaMagica;

	ID++;
}

Monstro::Monstro() {
	vida = 0;
	vidaAtual = 0;
	forcaFisica = 0;
	forcaMagica = 0;
	defesaFisica = 0;
	defesaMagica = 0;

	ID++;
}

void Monstro::ataqueFisico(Monstro *monstro) {
	monstro->acao(this, DEFESA, DEFESA_FISICA);
}

void Monstro::ataqueMagico(Monstro *monstro) {
	monstro->acao(this, DEFESA, DEFESA_MAGICA);	
}

void Monstro::defesa(Monstro *monstro, short int defesa) {
	switch(defesa) {
		case DEFESA_FISICA: vidaAtual -= monstro->getForcaFisica()-defesaFisica;
			break;
		case DEFESA_MAGICA: vidaAtual -= monstro->getForcaMagica()-defesaMagica;
			break;
	}
}
		
void Monstro::melhorarAtributo(ATRIBUTO atributo) {
	switch(atributo) {
		case VIDA_ATUAL: vidaAtual += 10;
			break;
		case FORCA_FISICA: forcaFisica += 5;
			break;
		case FORCA_MAGICA: forcaMagica += 5;
			break;
		case DEFESA_FISICA: defesaFisica += 5;
			break;
		case DEFESA_MAGICA: defesaMagica += 5;
			break;
	}
}

void Monstro::acao(Monstro *monstro, ACAO acao, ATRIBUTO atributo) {
	switch(acao) {
		case MELHORAR_ATRIBUTO: melhorarAtributo(atributo);
			break;
		case ATAQUE_FISICO: ataqueFisico(monstro);
			break;
		case ATAQUE_MAGICO: ataqueMagico(monstro);
			break;
		case DEFESA: defesa(monstro, atributo);
	}
}

Monstro::~Monstro() {}

void setClasseMonstro(ClasseMonstro classe) {this->classe = classe;}

ClasseMonstro getClasseMonstro() {return classe;}

void Monstro::setVida(int vida) {
	this->vida = vida;
	vidaAtual = vida;
}
int Monstro::getVida() {return vida;}

int Monstro::getVidaAtual() {return vidaAtual;}

void Monstro::setForcaFisica(int forcaFisica) {this->forcaFisica = forcaFisica;}
int Monstro::getForcaFisica() {return forcaFisica;}

void Monstro::setDefesaFisica(int defesaFisica) {this->defesaFisica = defesaFisica;}
int Monstro::getDefesaFisica() {return defesaFisica;}

void Monstro::setForcaMagica(int forcaMagica) {this->forcaMagica = forcaMagica;}
int Monstro::getForcaMagica() {return forcaMagica;}

void Monstro::setDefesaMagica(int defesaMagica) {this->defesaMagica = defesaMagica;}
int Monstro::getDefesaMagica() {return defesaMagica;}

ostream& operator<< (ostream &o, Monstro const _monstro) {
	o << "Vida atual: " << _monstro.vida << "/" << _monstro.vidaAtual << "\n"
	  << "Força Física: " << _monstro.forcaFisica << "\n"	 
	  << "Força Magica: " << _monstro.forcaMagica << "\n"
	  << "Defesa Física: " << _monstro.defesaFisica << "\n"
	  << "Defesa Mágica: " << _monstro.defesaMagica << "\n";

	return o; 	 	 
}


istream& operator>> (istream &i, Monstro &_monstro) {
	i >> _monstro.vidaAtual;
	_monstro.vida = _monstro.vidaAtual;
	i.ignore();
	i >> _monstro.forcaFisica;
	i.ignore();
	i >> _monstro.forcaMagica;
	i.ignore();
	i >> _monstro.defesaFisica;
	i.ignore();
	i >> _monstro.defesaMagica;
	
	return i;
}