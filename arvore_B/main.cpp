#include <iostream>
#include <stdlib.h>

#include "arvoreb.h"

using namespace std;

int main() {

    ArvoreB arvB;
    int ordem = arvB.getOrdem();

    while (true) {

        system("CLS");
        cout << "\n====================================";
        cout << "\n     EXERCICIO DE ARVORE B";
        cout << "\n====================================";

        cout << "\n0 - Sair";
        cout << "\n1 - Inserir (especifica o valor)";
        cout << "\n2 - Excluir (especifica o valor e exclui o primeiro encontrado)";
        cout << "\n3 - Imprimir";
        cout << "\n\nOpcao: ";
        int opc;
        cin >> opc;


        if (opc == 0) {
            break;
        } else if (opc == 1) {
            cout << "\nInforme o valor do elemento a ser inserido: ";
            unsigned int v1;
            cin >> v1;
            int x = arvB.inserir(v1);
            switch (x) {
            case -1:
                cout << "\n*** O No' esta' cheio.";
                break;
            case 0:
                cout << "\n*** Inserido com sucesso sem alteracoes na estrutura.";
                break;

                case 1:
                cout << "\n*** Inserido com reestruturacao.";
                break;

            default:
                cout << "\n### ERRO FATAL - retornado valor inesperado.";
            }


        } else if (opc == 3) {
            arvB.imprimirEmOrdem();
        }

        cout << "\n\n";
        system("PAUSE");

    }

    cout << "\n\n--- Ate' a proxima ---";
    cout << "\n\n";
    system("PAUSE");

    return 0;
}
