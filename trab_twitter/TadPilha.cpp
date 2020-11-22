#include <iostream>

#include "TadPilha.h"

TadPilha::TadPilha() {

	this->topo = NULL;
}

bool TadPilha::vazia() {

	return this->topo == NULL;
}

void TadPilha::inserir(NoAbb * noAbb) {

	NoPilha * no = new NoPilha(noAbb);

	if (!this->vazia()) {

		no->setProx(this->topo);
	}

	this->topo = no;
}

NoPilha * TadPilha::remover() {

	if (vazia()) {

		return NULL;
	}

	NoPilha * no = this->topo;
	this->topo = no->getProx();
	return no;
}
