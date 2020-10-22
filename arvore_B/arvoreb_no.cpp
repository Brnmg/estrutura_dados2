#include "arvoreb_no.h"


ArvoreB_No::ArvoreB_No() {
    chaves = new Lista2(false, true, ORDEM - 1);
}

ArvoreB_No::ArvoreB_No(int tam) {
    // chaves = new Lista2(false, true, tam);
    // filhos = new ArvoreB_No[tam + 1];
}

int ArvoreB_No::inserir(unsigned int v, bool forca) {
    return chaves->inserir(v, forca);
}

Elemento2 * ArvoreB_No::getCentral() {
    int elementoCentral = (ORDEM - 1) / 2 + 1;
    return chaves->getPos(elementoCentral);
}

Elemento2 * ArvoreB_No::getPos(int pos){
    return this->chaves->getPos(pos);
}


Elemento2 * ArvoreB_No::getElemento(int valor){

}

