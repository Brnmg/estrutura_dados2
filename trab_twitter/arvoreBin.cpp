#include <iostream>
#include "arvoreBin.h"

using namespace std;

arvore::arvore() {
    
    raiz = NULL;
}

void arvore::inserir(int chave) {

    if(raiz == NULL) {

        raiz = new No(chave);
    }
    else {

        inserirAux(raiz, chave);
    }
}

void arvore::inserirAux(No* no, int chave) {

    if(chave < no->getChave()) {

        if(no->getEsq() == NULL) {

            No* novo_no = new No(chave);
            no->setEsq(novo_no);
        }
        else {

            inserirAux(no->getDir(), chave);
        }
    }
}

No* arvore::getRaiz() {

    return raiz;
}

void arvore::emOrdem(No * no) {

    if(no != NULL) {

        emOrdem(no->getEsq());
        cout << no->getChave() << " ";
        emOrdem(no->getDir());
    }
}