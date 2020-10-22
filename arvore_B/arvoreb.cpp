#include <iostream>
#include <stdlib.h>

#include "arvoreb.h"
#include "arvoreb_no.h"

using namespace std;


ArvoreB::ArvoreB() {
    raiz = novoNo();
    ordem = ORDEM;
}


int ArvoreB::getOrdem() {
    return this->ordem;
}


int ArvoreB::inserir(unsigned int novoValor) {

    //*** se a arvore esta' vazia -> cria o primeiro no' e insere a primeira chave
    if (vazia()) {
        raiz->inserir(novoValor, false);
        return 0;
    }
    //+++

    //*** localizar posicao do novo elemento
    ArvoreB_No * cursorB = raiz; //* criar um cursor para percorrer os nos da arvore

    Elemento2 * elemTemp; //* ponteiro temporario para um elemento qualquer.

    while (true) {

        Elemento2 * cursorE = cursorB->chaves->getInicio(); //* criar um cursor para percorrer a lisat de chaves

        while (cursorE != NULL) {

            //* se nao ha' ponteiro para no' inferior -> trata-se do ultimo nivel.
            if (cursorE == cursorB->chaves->getInicio() && cursorE->noMenor == NULL) {

                int x = cursorB->inserir(novoValor, false);

                if (x == 0 || x == 2) { 
                    return x;
                }
                else {
                    ArvoreB_No * novoRaiz = novoNo();
                    ArvoreB_No * novoNoh = novoNo();

                    if ((ORDEM - 1) % 2 == 0) { 
                        cursorB->inserir(novoValor, true);
                    }
                    Elemento2 * elemCentral = cursorB->getCentral();

                    novoRaiz->inserir(elemCentral->getValor(), false);

          
                    elemCentral = novoRaiz->chaves->getValor(elemCentral->getValor());
                    elemCentral->noMenor = cursorB;
                    elemCentral->noMaior = novoNoh;

                    int valorCentral = elemCentral->getValor();

                    int posCentral = (ORDEM - 1) % 2 + 1;

                    while (true) {
                        Elemento2 * e = cursorB->chaves->removerPos(posCentral + 1);
                        if (e == NULL)
                            break;
                        novoNoh->inserir(e->getValor(), false);
                        delete e;
                    }

                    Elemento2 * e = cursorB->chaves->removerPos(posCentral);
                    delete e; 

                    valorCentral = elemCentral->getValor();

                    if (novoValor < elemCentral->getValor()){
                      cursorB->inserir(novoValor, false);
                    }
                    else
                      novoNoh->inserir(novoValor, false);

                    this->raiz = novoRaiz;

                    cout << "\nNo' raiz     = ";
                    imprimirNo(novoRaiz);
                    cout << "\nNo' original = ";
                    imprimirNo(cursorB);
                    cout << "\nNovo no'     = ";
                    imprimirNo(novoNoh);

                    return 1;
                }
                
            }


        } 

        break;

    } 

}

bool ArvoreB::vazia() {
    return raiz->chaves->inicio == NULL;
}

bool ArvoreB::isInicio(ArvoreB_No * n, Elemento2 * e) {
    return e == n->chaves->inicio;
}

ArvoreB_No * ArvoreB::novoNo() {
    return new ArvoreB_No();
}


void ArvoreB::imprimirRaizEFilhos() {

    /*
    if (vazia()) {
    	std::cout << "A arvore esta' vazia.";
    	return;
    }

    imprimirNo(raiz);

    Elemento2 * cursor = raiz->chaves->inicio;
    if (cursor->noMenor == NULL) return;
    ArvoreB_No * noB = raiz->filhos[cursor->menores];
    raiz->filhos[cursor->menores];

    if (noB == NULL) {
    	std::cout << "\n*** A raiz nao tem filhos ***";
    	return;
    }
    imprimirNo(noB);

    while (cursor != NULL) {
    	noB = raiz->filhos[cursor->maiores];
    	imprimirNo(noB);
    	cursor = cursor->getProx();
    }
    */

}


void ArvoreB::imprimirNo(ArvoreB_No * no) {
    if (no == NULL)
        no = raiz;
    no->chaves->imprimir(true);
}




void ArvoreB::imprimirEmOrdem() {

    int prof = profundidade();

    if (prof==0) {
        imprimirNo(raiz);
        return;
    }

    cout << "[ ";

    if (!vazia()) {

        //=== Vetor de marcacao do caminho (pilha)
        //    Sao 3 vetores paralelos: o do no', o do elemento e o de qual lado o no' de baixo e' filho
        ArvoreB_No caminhoB[prof];
        Elemento2 caminhoE[prof];
        char filhoLado[prof]; // sinalizar de qual lado e' filho (E = esquerdo; D = direito)
        int topo = -1;
        //---

        bool esquerda = true;



        ArvoreB_No * cursorB = this->raiz;
        Elemento2 * cursorE;

        //* ir ao menor elemento
        while (true) {
            esquerda = true;
            cursorE = cursorB->chaves->getInicio();
            topo++;
            caminhoB[topo] = * cursorB;
            caminhoE[topo] = * cursorE;
            filhoLado[topo] = 'E'; //* caso seja o raiz, o lado nao tem significado
            if (cursorE->noMenor == NULL) {
                break;
            }
            cursorB = cursorE->noMenor;
        }

        //* chegou no menor elemento da arvore
        //  -> imprimir elementos do no'
//        cout << cursorB;
        imprimirNo(cursorB);

        char fl;
        while (true) {
            if (topo > 0) {
                fl = filhoLado[topo];
                topo--;
                * cursorB = caminhoB[topo];
                * cursorE = caminhoE[topo];
                //+ Se voltou do lado esquerdo -> imprime o pai e vai ao no' filho direito
                if (fl == 'E') {
                    cout << " - " << cursorE->getValor() << " - ";
                    cursorB = cursorE->noMaior;
                    cursorE = cursorB->chaves->getInicio();
                    topo++;
                    caminhoB[topo] = * cursorB;
                    caminhoE[topo] = * cursorE;
                    filhoLado[topo] = 'D';
                    imprimirNo(cursorB);
                }
                //+ Caso contrario (veio pelo lado direito), verifica se tem irmao.
                //  Se tiver irmao -> imprime o irmao e desce ao no' direito do irmao.
                else if (cursorE->getProx() != NULL) {
                    cursorE = cursorE->getProx();
//                    cout << cursorE->getValor();
                    cursorB = cursorE->noMaior;
                    cursorE = cursorB->chaves->getInicio();
                    topo++;
                    caminhoB[topo] = * cursorB;
                    caminhoE[topo] = * cursorE;
                    filhoLado[topo] = 'D';
                    imprimirNo(cursorB);
                }
            }

            break;

        }

    }

    cout << "]";

}


/*
    Retornos:
    int profundidade: 0 = raiz; -1 = arvore vazia
*/
int ArvoreB::profundidade() {
    int prof = -1;
    if (!vazia()) {
        ArvoreB_No * cursorB = this->raiz;
        prof++;
        while (cursorB->chaves->getInicio()->noMenor != NULL) {
            cursorB = cursorB->chaves->getInicio()->noMenor;
            prof++;
        }
    }
    return prof;
}









