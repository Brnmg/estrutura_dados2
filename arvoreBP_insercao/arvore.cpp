#include <iostream>
#include <stdlib.h>

#include "arvore.h"

using namespace std;

arvoreB::arvoreB() {

  raiz = NULL; 
} 


No* arvoreB::getRaiz() {

  return raiz; 
} 


void arvoreB::buscar(int chave) {

  //Esse método ira buscar a chave passada como argumento.
}


void arvoreB::inserir(int valor) {

  int ordem = 5;

  if (raiz == NULL) { 

    raiz = new No; 
    raiz->chave[0] = valor; 
    raiz->isFolha = true; 
    raiz->tam = 1; 
  } 
  else { 

    No* cursor = raiz; 
    No* pai; 

    while (cursor->isFolha == false) { 

      pai = cursor; 

      for (int i = 0; i < cursor->tam; i++) { 

        if (valor < cursor->chave[i]) { 
          cursor = cursor->pont[i]; 
          break; 
        } 

        // If reaches the end 
        if (i == cursor->tam - 1) { 
          cursor = cursor->pont[i + 1]; 
          break; 
        }  
      } 
    } 
  
    if (cursor->tam < ordem) { 

      int i = 0; 
      
      while (valor > cursor->chave[i] && i < cursor->tam) { 

        i++; 
      } 

      for (int j = cursor->tam; j > i; j--) { 

        cursor->chave[j] = cursor->chave[j - 1]; 
      } 

      cursor->chave[i] = valor; 
      cursor->tam++; 

      cursor->pont[cursor->tam] = cursor->pont[cursor->tam - 1]; 
      cursor->pont[cursor->tam - 1] = NULL; 
    } 

    else { 

      No* novaFolha = new No; 

      int noVirtual[ordem + 1]; 

      for (int i = 0; i < ordem; i++) { 

        noVirtual[i] = cursor->chave[i]; 
      } 

      int i = 0, j; 

      while (valor > noVirtual[i] && i < ordem) { 

        i++; 
      } 

      for (int j = ordem + 1; j > i; j--) { 

        noVirtual[j] = noVirtual[j - 1]; 
      } 

      noVirtual[i] = valor; 
      novaFolha->isFolha = true; 

      cursor->tam = (ordem + 1) / 2; 
      novaFolha->tam = ordem + 1 - (ordem + 1) / 2; 

      cursor->pont[cursor->tam] = novaFolha; 

      novaFolha->pont[novaFolha->tam] = cursor->pont[ordem]; 

      cursor->pont[ordem] = NULL; 

      for (i = 0; i < cursor->tam; i++) { 

        cursor->chave[i] = noVirtual[i]; 
      } 

      for (i = 0, j = cursor->tam; i < novaFolha->tam; i++, j++) { 

        novaFolha->chave[i] = noVirtual[j]; 
      } 

      if (cursor == raiz) { 

        No* novaRaiz = new No; 

        novaRaiz->chave[0] = novaFolha->chave[0]; 
        novaRaiz->pont[0] = cursor; 
        novaRaiz->pont[1] = novaFolha; 
        novaRaiz->isFolha = false; 
        novaRaiz->tam = 1; 
        raiz = novaRaiz; 
      } 

      else { 

        inserirDentro(novaFolha->chave[0], pai, novaFolha); 
      }
    }   
  } 
} 



void arvoreB::inserirDentro(int valor, No * cursor, No * filho) {

  int ordem = 5;

  if (cursor->tam < ordem) { 

    int i = 0; 

    while (valor > cursor->chave[i] && i < cursor->tam) { 

      i++; 
    } 

    for (int j = cursor->tam; j > i; j--) { 

      cursor->chave[j] = cursor->chave[j - 1]; 
    } 

    for (int j = cursor->tam + 1; j > i + 1; j--) { 
        cursor->pont[j] = cursor->pont[j - 1]; 
    } 

    cursor->chave[i] = valor; 
    cursor->tam++; 
    cursor->pont[i + 1] = filho; 
  } 
  
  else { 
    
    No* novoInterno = new No; 
    int chaveVirtual[ordem + 1]; 
    No* pontVirtual[ordem + 2]; 

    for (int i = 0; i < ordem; i++) { 

      chaveVirtual[i] = cursor->chave[i]; 
    } 
 
    for (int i = 0; i < ordem + 1; i++) {

      pontVirtual[i] = cursor->pont[i]; 
    } 

    int i = 0, j; 

    while (valor > chaveVirtual[i] && i < ordem) { 

      i++; 
    } 

    for (int j = ordem + 1; j > i; j--) { 

      chaveVirtual[j] = chaveVirtual[j - 1]; 
    } 

    chaveVirtual[i] = valor; 

    for (int j = ordem + 2; j > i + 1; j--) { 

      pontVirtual[j] = pontVirtual[j - 1]; 
    } 

    pontVirtual[i + 1] = filho; 
    novoInterno->isFolha = false; 

    cursor->tam = (ordem + 1) / 2; 

    novoInterno->tam = ordem - (ordem + 1) / 2; 

    for (i = 0, j = cursor->tam + 1; i < novoInterno->tam; i++, j++) { 

      novoInterno->chave[i] = chaveVirtual[j]; 
    } 

    for (i = 0, j = cursor->tam + 1; i < novoInterno->tam + 1; i++, j++) { 

      novoInterno->pont[i] = pontVirtual[j]; 
    } 

    if (cursor == raiz) { 

      No* novaRaiz = new No; 

       
      novaRaiz->chave[0] = cursor->chave[cursor->tam]; 

        
      novaRaiz->pont[0] = cursor; 
      novaRaiz->pont[1] = novoInterno; 
      novaRaiz->isFolha = false; 
      novaRaiz->tam = 1; 
      raiz = novaRaiz; 
    } 
    
    else { 

      inserirDentro(cursor->chave[cursor->tam], pai(raiz, cursor), novoInterno);    
    } 
  } 
}


void arvoreB::remover(int chave) {

  //Esse método ira remover do nó a chave passada como argumento
}

void arvoreB::imprimir(No* cursor) {

  if(cursor != NULL) {

    for(int i = 0; i < cursor->tam; i++) {

      cout << cursor->chave[i] << " - ";
    }

    cout << "\n";

    if(cursor->isFolha != true) {

      for(int i = 0; i < cursor->tam + 1; i++) {

        imprimir(cursor->pont[i]);
      }
    }
  }
}


No * arvoreB::pai(No * cursor, No * filho) {

  No* paiNo; 
  
  if (cursor->isFolha || (cursor->pont[0])->isFolha) {

    return NULL; 
  } 
  
  for (int i = 0; i < cursor->tam + 1; i++) { 

    if (cursor->pont[i] == filho) { 

      paiNo = cursor; 
      return paiNo; 
    } 

    else { 

      paiNo = pai(cursor->pont[i], filho); 

      if (paiNo != NULL) { 

        return paiNo;
      } 
    } 
  } 
  
  return paiNo; 
}


