#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "windows.h" 
#include <bits/stdc++.h>

#include "TadAbb.h"
using namespace std;

/*
nome: Bruno Munis Gerardo
TIA:  31908551

nome: Lucas Marra Rebello
TIA:  31851606

nome: Nasser Mohamad Bazaan
TIA:  31906168

nome: Victor Raphael de Moraes G. Pereira
TIA:  31927475

nome: Siyu wei
TIA:  31965598
*/

string * separa(string str, string del, int qtd){
	
	string * vetor = new string[qtd];
	
	size_t pos = 0;
	std::string token;
	int idx = 0;
	while ((pos = str.find(del)) != std::string::npos) {
	    token = str.substr(0, pos);
	    vetor[idx] = token;
	    idx++;
	    str.erase(0, pos + del.length());
	}
	vetor[idx] = str;
	
	return vetor;
}

int main() {

	TadAbb arv;

	clock_t inicio, fim;

	double tempo;


	int tamanhoMax = 435; 
	FILE * pFile; 
	char linha[tamanhoMax];
	string linhaStr;
	
	inicio = clock();
	
	pFile = fopen ("texto.txt" , "r"); 

	if (pFile == NULL) {

		cout << ("Erro na abertura do arquivo");
	}
	 
	else {

		while ( fgets (linha , tamanhoMax , pFile) != NULL ) { 

			linhaStr = linha; 
						
			string * linhaVetor = separa(linhaStr, ";", 15);
			
			string vetor = linhaVetor[0];
				
			int n = vetor.length();

			char caractereVetor[n + 1];
			
			strcpy(caractereVetor, vetor.c_str());
				
			char* token;
			token = strtok(caractereVetor, " ");

			while (token != NULL) {

				arv.inserirRecursivo(token);
				token = strtok(NULL, " ");
			}
		}
		fclose (pFile);
		Sleep(1000);
	}
	
	fim = clock();
	tempo = (fim - inicio)/(double)CLOCKS_PER_SEC;
	cout<< "ARVORE BINARIA DE BUSCA: \n";
	cout<< arv.getNumeroComparacoes() << " COMPARACOES \n";
	cout<< "Tempo de execucao: " << tempo << " segundos \n";
	
	cout<< "\n";
	
	arv.emOrdemRecursivo();
	
	
	cout<<"\n";
	system("pause");
	cout << "\n\nObrigado e ate breve!\n\n";

	return 0;
}



