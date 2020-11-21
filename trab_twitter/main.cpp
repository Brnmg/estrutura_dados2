#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string * split(string str, string del, int qtd){

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

   int tamanhoMax = 300;
	FILE * pFile;
	char linha[tamanhoMax];
	string linhaStr;

	pFile = fopen ("arquivo.txt" , "r");

    if(pFile == NULL) {

        cout << "Erro na abertura do arquivo";
    }


}