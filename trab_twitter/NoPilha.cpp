#include <iostream>

#include "NoPilha.h"
#include "NoAbb.h"


NoPilha::NoPilha(NoAbb * no) {
	this->noAbb = no;
	this->prox = NULL;
}

void NoPilha::setProx(NoPilha * no) {
	this->prox = no;
}

NoPilha * NoPilha::getProx(){
	return this->prox;
}

NoAbb * NoPilha::getNoAbb(){
	return this->noAbb;
}
