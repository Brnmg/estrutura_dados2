#include <iostream>
#include <stdlib.h>

#include "arvore.h"

using namespace std;


int main() {
  
  arvoreB arv;

  while(true) {

    cout << "\n| --------------------------------------------------------------------- |" << endl;
    cout << "|                              MENU                                     |" << endl;
    cout << "| --------------------------------------------------------------------- |";
    cout << "\n\n 0 - Sair do programa";
    cout << "\n 1 - Inserir no na arvore";
    cout << "\n 2 - Remover no da arvore (nao implementado)";
    cout << "\n 3 - Buscar no na arvore(nao implementado)";
    cout << "\n 4 - Imprimir arvore";
    cout << "\n\n Digite a opcao desejada: ";
    
    int opc;
    cin >> opc;

    if (opc == 0) {

      break;
    }

    else if (opc == 1) {

      cout << "Digite o valor a ser inserido: ";
      int val;
      cin >> val;
      arv.inserir(val);
    }

    else if (opc == 4) {

      cout << "\n";
      arv.imprimir(arv.getRaiz());
    }
  }

  return 0;
}