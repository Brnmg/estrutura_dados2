#ifndef TADPILHA_H
#define TADPILHA_H

#include "NoPilha.h"
#include "NoAbb.h"

class TadPilha {

	private:
		NoPilha * topo;

	public:
		TadPilha();
		bool vazia();
		void inserir(NoAbb * noAbb);
		NoPilha * remover();

};

#endif
