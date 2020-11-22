#ifndef TADABB_H
#define TADABB_H

#include <iostream>
#include "NoAbb.h"

using namespace std;

class TadAbb {

	private:
		NoAbb * raiz;
		
		int comparacoes;
		
		void printEmOrdemRecursivo(NoAbb *no);	
		string buscaRecursivo(NoAbb *no, string valor);
		int inserirAux(NoAbb *no, string nomeChave);
		
	public:
		TadAbb();
		bool vazia();
		void inserirRecursivo(string palavra);
		void emOrdemRecursivo();
		string buscaElementoRecursivo(string valor);
		
		void numeroComparacoes();
		int getNumeroComparacoes();
};

#endif
