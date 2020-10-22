#ifndef ARVOREB_NO_H
#define ARVOREB_NO_H

#define ORDEM 4

#include "lista2.h"

class Elemento2;

class ArvoreB_No {

private:

    //* Lista duplamente ligada com as chaves (Elemento2)
    Lista2 * chaves;

    //* Metodo auxiliar para obter o elemento central da lista ligada.
    //  Neste algoritmo, este metodo sempre e' usado na lista com numero impar de elementos
    Elemento2 * getCentral();


    friend class ArvoreB; // para a classe ArvoreB poder acessar os membros privados

public:

    //* Metodos construtores
    ArvoreB_No();
    ArvoreB_No(int tam);

    //* Insere um novo elemento no no'
    int inserir(unsigned int v, bool forca);

    //* Obtem o elemento de uma determinada posicao (o primeiro e' o de posicao 1).
    Elemento2 * getPos(int pos);

    //* Obtem o elemento de um determinado valor.
    Elemento2 * getElemento(int valor);



};

#endif
