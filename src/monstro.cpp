#include "monstro.h"

#include <iostream>
using std::cout;
using std::endl;

#include "fileHandler.h"

Monstro::Monstro(ClasseMonstro classe): classe(classe) {
	ifstream file;
	file.open("./data/classes_monstros");

	if (!file) {
		cout << "Erro ao abrir arquivo!" << endl;
	} else {
		readFile(file, classe);
		file >> *this;
	}

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
		case DEFESA_FISICA: vidaAtual = (vidaAtual-monstro->getForcaFisica())+defesaFisica;
			break;
		case DEFESA_MAGICA: vidaAtual = (vidaAtual-monstro->getForcaMagica())+defesaMagica;
			break;
	}
}
		
void Monstro::melhorarAtributo(ATRIBUTO atributo) {
	if (!efeito) {
		switch(atributo) {
			case VIDA_ATUAL: vidaAtual += 150;
				break;
			case FORCA_FISICA: forcaFisica += 150;
				break;
			case FORCA_MAGICA: forcaMagica += 100;
				break;
			case DEFESA_FISICA: defesaFisica += 50;
				break;
			case DEFESA_MAGICA: defesaMagica += 50;
				break;
		}
	} else {
		cout << "Não posso melhorar atributo agora!" << endl;
	}
}

void Monstro::acao(Monstro *monstro, ACAO acao, ATRIBUTO atributo) {
	switch(acao) {
		case ATAQUE_FISICO: ataqueFisico(monstro);
			break;
		case ATAQUE_MAGICO: ataqueMagico(monstro);
			break;
		case MELHORAR_ATRIBUTO: melhorarAtributo(atributo);
			break;
		case DEFESA: defesa(monstro, atributo);
	}
	if (!efeito->contar()) {
		delete efeito;
	}
}

Monstro::~Monstro() {}

void Monstro::setClasseMonstro(ClasseMonstro classe) {this->classe = classe;}

ClasseMonstro Monstro::getClasseMonstro() {return classe;}

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
	o << "Classe: " << classes[_monstro.classe] << "\n"
	  << atributos[VIDA_ATUAL] << ": " << _monstro.vidaAtual << "/" << _monstro.vida << "\n"
	  << atributos[FORCA_FISICA] << ": " << _monstro.forcaFisica << "\n"	 
	  << atributos[FORCA_MAGICA] << ": " << _monstro.forcaMagica << "\n"
	  << atributos[DEFESA_FISICA] << ": " << _monstro.defesaFisica << "\n"
	  << atributos[DEFESA_MAGICA] << ": " << _monstro.defesaMagica << "\n";

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

void operator+ (Monstro &_monstro, Efeito &e) {
	if (!_monstro.efeito) {
		_monstro.efeito = new Efeito(e);
		cout << _monstro.efeito->getEfeito() << endl;
	}
}