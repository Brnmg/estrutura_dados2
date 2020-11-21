#include <iostream>
#include "no_binario.cpp"

class arvore {

    private:
       No * raiz;
    public:
        arvore();
        void inserir(int chave);
        void inserirAux(No * no, int chave);
        No* getRaiz();
        void emOrdem(No * no);
};

