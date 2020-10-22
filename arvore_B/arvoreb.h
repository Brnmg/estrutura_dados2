#ifndef ARVOREB_H
#define ARVOREB_H

#include "arvoreb_no.h"

class ArvoreB {

private:

    //* no' raiz da arvore
    ArvoreB_No * raiz;

    //* Ordem da arvore. O criterio utilizado é o da quantidade de chaves + 1
    int ordem;

    //* metodo auxiliar para criar um novo no'
    ArvoreB_No * novoNo();

    //* Metodo auxiliar para verificar se um elemento e' o primeiro da lista.
    bool isInicio(ArvoreB_No *, Elemento2 * );


public:

    //* construtor
    ArvoreB();

    //* retorna a ordem da arvore (constante definida no header arvoreb_no.h
    int getOrdem();

    //* inserir novo elemento na arvore
    int inserir(unsigned int );

    //* verifica se a arvore esta' vazia
    bool vazia();

    void imprimirRaizEFilhos();

    //* imprime as chaves de um no'
    void imprimirNo(ArvoreB_No * );

    //* imprime a arvore pelo criterio "Em Ordem".
    void imprimirEmOrdem();

    //* retorna a profundidade da arvore (raiz e' o nivel 0).
    int profundidade();


};

#endif
