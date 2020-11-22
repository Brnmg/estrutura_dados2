#include <iostream>

#include "NoAbb.h"

NoAbb::NoAbb(string palavra) {

	this->filhoEsq = NULL;
	this->filhoDir = NULL;
	this->vezesPalavraAparece = 1;
	this->palavra = palavra;
}

void NoAbb::setFilhoEsq(NoAbb * no) {
	this->filhoEsq = no;
}

NoAbb * NoAbb::getFilhoEsq() {
	return this->filhoEsq;
}

void NoAbb::setFilhoDir(NoAbb * no) {
	this->filhoDir = no;
}

NoAbb * NoAbb::getFilhoDir() {
	return this->filhoDir;
}

string NoAbb::getPalavra(){
	return this->palavra;
}

void NoAbb::numeroPalavras(){
	this->vezesPalavraAparece = this->vezesPalavraAparece + 1;
}

int NoAbb::getNumeroPalavras(){
	return this->vezesPalavraAparece;
}






