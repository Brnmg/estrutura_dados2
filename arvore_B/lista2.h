#ifndef LISTA2_H
#define LISTA2_H

#include "elemento2.h"

class Lista2 {

    /**
     * *********************
     * *** P R I V A T E ***
     * *********************
     */
private:
    //**************************************************************************
    //                        PARAMETROS DA LISTA
    //            devem ser configurados via metodo construtor
    //
    //* Aceita valores repetidos (true/false)
    bool repete;
    //* Ordenada (true/false)
    bool ordenada;
    //* Tamanho maximo (0 = tamanho ilimitado)
    int maxTam;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Elemento2 * inicio;
    Elemento2 * fim;
    int tamanho;

    int insereNoInicio(Elemento2 *);
    void excluiElemento2(Elemento2 * e);
    Elemento2 * criaElemento(unsigned int v);

    friend class ArvoreB;

    /**
     * *******************
     * *** P U B L I C ***
     * *******************
     */
public:
    Lista2(bool rep, bool ord, int max);
    ~Lista2();

    /**
     * *** int inserir(int v); ***
     * Insere um elemento na lista.
     * Retorno:
     *   0 = inserido com sucesso
     *   1 = Lista cheia (caso de controle de tamanho maximo - maxTam > 0
     *   2 = Ja' consta na lista (caso controle de repeticao)
     * Parametros:
     *   1 - (v) valor do elemento
     *   2 - (forca) true = forca a inclusao em caso de cheia; false = bloqueia a inclusao em caso de cheia
     */
    int inserir(unsigned int v, bool forca);

    /**
     * Remove um elemento de valor v.
     * Retorna o elemento ou NULL se nao estiver na Lista.
     */
    Elemento2 * remover(unsigned int v);

    /* Remove um elemento de posicao pos.
        Retorna o elemento ou NULL se nao existir a posicao (lista e' menor)
    */
    Elemento2 * removerPos(unsigned int pos);

    bool vazia();
    int getTamanho();
    bool cheia();

    void imprimir(bool cochetes);


    Elemento2 * getInicio();

    /* ---------------------------------------------------
       Retorna o elemento que esta' em determinada posicao
       ---------------------------------------------------
        Parametros:
        1 - (pos) posicao em que se encontra o elemento
            (o primeiro elemento e' o de posicao 1).
    */
    Elemento2 * getPos(int pos);


    Elemento2 * getValor(int valor);


};

#endif
