#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;
using std::getline;

#include "monstro.h"
#include "batalha.h"

int Monstro::ID = 0;

template <typename T>
void lerTeclado(T &valor) {
	string informacao;
	bool valida = true;
	do {
		if (!valida)
			cout << "Entrada Inválida. Tente Novamente!" << endl;
		getline(cin, informacao);
	} while (!(valida = (bool)(stringstream(informacao) >> valor)));
}

ClasseMonstro selecionarClasse() {
	int valor;

	cout << "Selecione a Classe do Monstro: " << endl;
	for (int c = BALANCEADO; c <= TANKER; c++) {
		cout << "\t" << c << " - " << classes[c] << endl;
	}

	lerTeclado<int>(valor);

	return (ClasseMonstro)valor;
}

Jogada escolherJogada() {
	int valor1, valor2;
	string valor;

	cout << "Escolha sua Jogada: " << endl;
	for (int acao = ATAQUE_FISICO; acao < DEFESA; acao++) {
		cout << "\t" << acao << " - " << acoes[acao] << endl;
	}

	lerTeclado<int>(valor1);

	if (valor1 == 2) {
		cout << "Escolha o Atributo: " << endl;
		for (int a = FORCA_FISICA; a <= VIDA_ATUAL; a++) {
			cout << "\t" << a << " - " << atributos[a] << endl;
		} 

		lerTeclado<int>(valor2);
	} else {
		valor2 = valor1;
	}

	return Jogada((ACAO)valor1, (ATRIBUTO)valor2);
}

int main() {
	
	ClasseMonstro classe = selecionarClasse();

	Monstro *monstro = new Monstro(classe);

	Batalha *batalha = new Batalha(monstro);
	
	while(batalha->ninguemMorreu()) {
		Jogada jogada = escolherJogada();
		batalha->setJogada(jogada);
		cout << "Fim de Turno" << endl;
	}
	

	return 0;
}