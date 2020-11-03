#include <iostream>
#include <stdlib.h>

#include "no.h"

class arvoreB { 

  No* raiz; 
  void inserirDentro(int, No*, No*); 
  No* pai(No*, No*); 
  
  public:   
    arvoreB(); 
    void buscar(int); 
    void inserir(int); 
    void remover(int);
    void imprimir(No*); 
    No* getRaiz(); 
};
