#include <stdlib.h>
#include <iostream>

#include "lista2.h"

Lista2::Lista2(bool rep, bool ord, int max) {
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
    repete = rep;
    ordenada = ord;
    maxTam = max;
}

Lista2::~Lista2() {
    if (inicio == NULL)
        return;
    if (inicio->getProx() == NULL) {
        delete(inicio);
        return;
    }
    Elemento2 * cursor = inicio;
    while (cursor->getProx() != NULL)
        cursor = cursor->getProx();
    while (true) {
        if (inicio->getProx() == NULL) {
            delete(inicio);
            break;
        }
        delete(cursor->getProx());
        cursor = cursor->getPrev();
    }

}

int Lista2::inserir(unsigned int v, bool forca) {

    if (!forca && cheia()) { // se controla tamanho maximo...
        return 1;
    }

    Elemento2 * e = criaElemento(v);
    if (vazia()) { // se estiver vazia
        inicio = e;
        fim = e;
        tamanho++;
        return 0;
    } else if (!ordenada || v <= inicio->getValor()) { // se nao requer ordenacao -> insere no inicio
        if (!repete && v == inicio->getValor()) {
            return 2;
        }
        return insereNoInicio(e);
    }

    //*** Localizar posicao do novo elemento
    Elemento2 * cursor = inicio;
    while (cursor->getProx() != NULL && cursor->getValor() <= v) {
        cursor = cursor->getProx();
    }

    if (!repete && cursor->getValor() == v) {
        delete(e);
        return 2;
    }

    if (cursor->getProx() == NULL) {
        if (e->getValor() > cursor->getValor()) { // maior que todos -> insere no fim
            e->setPrev(fim);
            fim->setProx(e);
            fim = e;
        } else { // e' menor que o ultimo -> insere em penultimo
            e->setProx(fim);
            e->setPrev(fim->getPrev());
            fim->setPrev(e);
            e->getPrev()->setProx(e);
        }
    } else {
        if (!repete && cursor->getProx()->getValor() == v) {
            delete(e);
            return 2;
        }
        e->setProx(cursor);
        e->setPrev(cursor->getPrev());
        cursor->setPrev(e);
        e->getPrev()->setProx(e);

    }

    //+++

    tamanho++;
    return 0;
}




int Lista2::insereNoInicio(Elemento2 * e) {
    if (vazia()) {
        inicio = e;
        fim = e;
        tamanho++;
        return 0;
    }
    if (!repete && !ordenada) {
        Elemento2 * cursor = inicio;
        while (cursor != NULL) {
            if (cursor->getValor() == e->getValor())
                return 2;
            cursor = cursor->getProx();
        }
    }
    e->setProx(inicio);
    inicio->setPrev(e);
    inicio = e;
    tamanho++;
    return 0;
}

Elemento2 * Lista2::remover(unsigned int v) {

    if (vazia())
        return NULL;

    Elemento2 * cursor = inicio;
    while(cursor != NULL && cursor->getValor() != v) {
        cursor = cursor->getProx();
    }
    if (cursor == NULL)
        return NULL;

    if (tamanho == 1) { // so' tem um elemento na lista -> torna lista vazia e retorna o elemento
        inicio = NULL;
        fim = NULL;
    }

    else if (cursor == inicio) { // tem mais de um elemento na lista e o elemento procurado e' o primeiro da lista
        inicio = cursor->getProx();
        cursor->getProx()->setPrev(NULL);
        cursor->setProx(NULL);
    }

    else if (cursor == fim) {
        fim = cursor->getPrev();
        cursor->setPrev(NULL);
        fim->setProx(NULL);
    }

    else {
        excluiElemento2(cursor);
    }

    tamanho--;
    return cursor;

}

Elemento2 * Lista2::removerPos(unsigned int pos) {

    if (vazia() || pos > this->tamanho) {
        return NULL;
    }

    Elemento2 * cursor = this->inicio;

    int p = 1;
    while (p < pos) {
        cursor = cursor->getProx();
        p++;
    }

    excluiElemento2(cursor);

    //tamanho--;
    return cursor;

}


Elemento2 * Lista2::criaElemento(unsigned int v) {
    Elemento2 * elemen = new Elemento2();
    elemen->setValor(v);
    return elemen;
}

bool Lista2::vazia() {
    return inicio == NULL;
}

bool Lista2::cheia() {
    if (maxTam == 0)
        return false;
    else
        return tamanho == maxTam;
}

void Lista2::imprimir(bool colchetes) {
    if (colchetes)
        std::cout << "[ ";
    Elemento2 * cursor = inicio;
    while (cursor != NULL) {
        std::cout << cursor->getValor() << " ";
        cursor = cursor->getProx();
    }
    if (colchetes)
        std::cout << "]";
}


Elemento2 * Lista2::getInicio() {
    return inicio;
}


Elemento2 * Lista2::getPos(int pos) {
    Elemento2 * cursor = this->inicio;
    int p = 1;
    while (cursor != NULL && p < pos) {
        cursor = cursor->getProx();
        p++;
    }
    return cursor;
}


Elemento2 * Lista2::getValor(int valor) {
    Elemento2 * cursor = this->inicio;
    while (cursor != NULL) {
        if (cursor->getValor() > valor) { //* passou o valor -> elemento nao esta' na arvore
            break;
        }
        if (cursor->getValor() == valor) { //* localizou o elemento -> retorna
            return cursor;
        }
        cursor = cursor->getProx();
    }
    return NULL; //* nao localizou
}


void Lista2::excluiElemento2(Elemento2 * e) {
    if (e->getPrev() != NULL)
        e->getPrev()->setProx(e->getProx());
    if (e->getProx() != NULL)
        e->getProx()->setPrev(e->getPrev());
    e->setProx(NULL);
    e->setPrev(NULL);
    tamanho--;
    if (tamanho == 0)
        inicio = NULL;
}
