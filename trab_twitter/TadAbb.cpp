#include <sstream>
#include "TadAbb.h"
#include "TadPilha.h"
#include "TadAbb.h"


TadAbb::TadAbb() {

	this->raiz = NULL;
	this->comparacoes = 1;
}

bool TadAbb::vazia() {

	return this->raiz == NULL;
}

void TadAbb::inserirRecursivo(string palavra) {
			
	NoAbb * no = new NoAbb(palavra);
	
	NoAbb * cursor = this->raiz;
	
	if(cursor == NULL){

		raiz = no;
	}

	else{

		inserirAux(raiz, palavra);
	}
}

int TadAbb::inserirAux(NoAbb *no, string palavra) {

	if(palavra < no->getPalavra()) {

		numeroComparacoes();

		if(no->getFilhoEsq() == NULL) {

			NoAbb *novoNoEsq = new NoAbb(palavra);
			no->setFilhoEsq(novoNoEsq); 
		}
		
		else {

			inserirAux(no->getFilhoEsq(), palavra);
		}
	}

	else if(palavra > no->getPalavra())	{

		numeroComparacoes();

		if(no->getFilhoDir() == NULL) {

			NoAbb *novoNoDir = new NoAbb(palavra);
			no->setFilhoDir(novoNoDir); 
		}

		else {

			inserirAux(no->getFilhoDir(), palavra);
		}
	}

	else {

		no->numeroPalavras();
	}
}


void TadAbb::emOrdemRecursivo() {

	NoAbb * cursor = this -> raiz;
	
	if(vazia()) {

		cout<<"\nArvore Vazia!\n";
		return;
	}
	
	cout << "FREQUENCIA DAS PALAVRAS EM ORDEM ALFABETICA: \n";

	printEmOrdemRecursivo(cursor);
}

void TadAbb::printEmOrdemRecursivo(NoAbb *no) {

	if(no != NULL) {

		printEmOrdemRecursivo(no->getFilhoEsq());
		cout << no->getPalavra() << ": " << no->getNumeroPalavras() << "\n";
		printEmOrdemRecursivo(no->getFilhoDir());
	}
}

string TadAbb::buscaElementoRecursivo(string valor) {

	if(vazia()) {

		cout<< "\nA arvore esta vazia!\n";
		return "-1";
	}
	
	NoAbb * cursor = this -> raiz;
	return buscaRecursivo(cursor, valor);
}

string TadAbb::buscaRecursivo(NoAbb *no, string valor) { 
	
	if(vazia()) {

		cout<< "\nO no nao esta na arvore!\n";
		return "-1";
	}
	
	if(no->getPalavra() == valor) {

		cout << no->getPalavra();
		cout<< "\nO no esta na arvore!\n";
		return valor;
	}
	
	if(no->getPalavra() < valor) {

		if(no->getFilhoDir() == NULL){
			cout<< "\nO no nao esta na arvore!\n";
			return "-1";
		}
		
		cout << no->getPalavra();
		buscaRecursivo(no->getFilhoDir(), valor);
	}
	
	if(no->getPalavra() > valor) {

		if(no->getFilhoEsq() == NULL) {

			cout<< "\nO no nao esta na arvore!\n";
			return "-1";
		}
		
		cout << no->getPalavra();
		buscaRecursivo(no->getFilhoEsq(), valor);
	}
}

void TadAbb::numeroComparacoes() {

	this->comparacoes = this->comparacoes + 1;
}

int TadAbb::getNumeroComparacoes() {

	return this->comparacoes;
}









