#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>
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

class No{

  private:
  No * esq, *dir;

  string nome;
  string cargo;
  string lotacao;
  string admissao;
  string nasc;
  float venc;
  float encargos;
  float benef;
  string meses;
  int quantMes;

  public:
  No(string nome, string cargo,  string lotacao, string admissao, string nasc, float venc, float encargos, float benef, string meses){

    this->nome = nome;
    this->cargo = cargo;
    this->lotacao = lotacao;
    this->admissao = admissao;
    this->nasc = nasc;
    this->venc = venc;
    this->encargos = encargos;
    this->benef = benef;
    this-> meses = meses;
    this->quantMes = 1;

    esq = NULL;
    dir = NULL;
  }

  string getNome() {return this->nome;}
  string getCargo(){return cargo;}
  string getLotacao(){return lotacao;}
  string getAdmissao(){return admissao;}
  string getNasc(){return nasc;}
  float getVenc(){return venc;}
  float getEncargos(){return encargos;}
  float getBenef(){return benef;}
  string getMeses(){return meses;}
  int getQuantMes() {return this->quantMes;}

  void incrementaMes() {this->quantMes = this->quantMes + 1;}
  void somarValorVencimentos(float vencAux) {this->venc = this->venc + vencAux;}
	void somarValorEncargos(float encargosAux) {this->encargos = this->encargos + encargosAux;}
	void somarValorBeneficios(float benefAux) {this->benef = this->benef + benefAux;}

  void printarNomesFunc() {cout << this->nome + "\n";}


  No * getEsq(){return esq;}
  No * getDir(){return dir;}

  void setEsq(No * no) {esq = no;}
  void setDir(No * no) {dir = no;}
};


class No_Valores{

  private:
  No_Valores * esq, *dir;

  float remuneracaoMin;
  float remuneracaoMax;
  string nomes;

  public:
  No_Valores(float remuneracaoMin, float remuneracaoMax) {

    this->esq = NULL;
    this->dir = NULL;

    this->remuneracaoMin = remuneracaoMin;
    this->remuneracaoMax = remuneracaoMax;
  }

  void IncluiFuncionario(string nomes) {
    this->nomes = this->nomes + "\n" + nomes;
  }

  void getNomes() {cout << this->nomes;}

  No_Valores * getEsq(){return esq;}
  No_Valores * getDir(){return dir;}

  void setEsq(No_Valores * no) {esq = no;}
  void setDir(No_Valores * no) {dir = no;}
};

class Arvore_Valores {

  private:
  No_Valores * raiz;
  No_Valores * a;
  No_Valores * b;
  No_Valores * c;
  No_Valores * d;
  No_Valores * e;
  No_Valores * f;
  No_Valores * g;
  No_Valores * h;
  No_Valores * i;
  string nome;



  public:

  Arvore_Valores() {raiz = NULL;}

  void inserirNome(string nome){
    this->nome = this->nome + "/" + nome;
  }

  void inserirNo() {

    //inserindo no A na arvore
    No_Valores * a = new No_Valores(7600, 10000);
    No_Valores * cursor = this->raiz;
    raiz = a;

    //inserindo no B na arvore
    No_Valores * b = new No_Valores(2500, 5000);
    a->setEsq(b);

    //inserindo no C na arvore
    No_Valores * c = new No_Valores(12500,15000);
    a->setDir(c);

    //inserindo no D na arvore
    No_Valores * d = new No_Valores(1000,2500);
    b->setEsq(d);

  //inserindo no E na arvore
    No_Valores * e = new No_Valores(5000,7500);
    b->setDir(e);

    //inserindo no F na arvore
    No_Valores * f = new No_Valores(10000,12500);
    c-> setEsq(f);

    //inserindo no G na arvore
    No_Valores * g = new No_Valores(15000,15500);
    c-> setDir(g);

    //inserindo no h na arvore
    No_Valores * h = new No_Valores(0,1000);
    d-> setEsq(h);

    //inserindo no i na arvore
    No_Valores * i = new No_Valores(17500,100000000000);
    g-> setDir(i);


  }


  void inserirNomeNo(float remuneracaoMensal, string nome) {
    No_Valores * cursor = this->raiz;

    //Comparação do no A
    if(remuneracaoMensal >= 7600 && remuneracaoMensal < 10000) {
      cursor->IncluiFuncionario(nome);
    }

    //Comparação do no B
    else if(remuneracaoMensal >= 2500 && remuneracaoMensal < 5000) {
      cursor->getEsq()->IncluiFuncionario(nome);
    }

    //Comparação no C
    else if(remuneracaoMensal >= 12500 && remuneracaoMensal < 15000) {
      cursor->getDir()->IncluiFuncionario(nome);
    }

    //Comparação do no D
    else if(remuneracaoMensal >= 1000 && remuneracaoMensal < 2500) {
      cursor->getEsq()->getEsq()->IncluiFuncionario(nome);
    }

    //Comparação do no E
    else if(remuneracaoMensal >= 5000 && remuneracaoMensal < 7500) {
      cursor->getEsq()->getDir()->IncluiFuncionario(nome);
    }

    //Comparacação No F
    else if(remuneracaoMensal >= 10000 && remuneracaoMensal < 12500) {
      cursor->getDir()->getEsq()->IncluiFuncionario(nome);
    }

    //Comparacação No G
    else if(remuneracaoMensal >= 15000  && remuneracaoMensal < 15500) {
      cursor->getDir()->getDir()->IncluiFuncionario(nome);
    }

    //Comparação do no H
    else if(remuneracaoMensal >= 0 && remuneracaoMensal < 1000) {
      cursor->getEsq()->getEsq()->getEsq()->IncluiFuncionario(nome);
    }

    //Se não for nenhum dos anteriores, colocar o nome no I
    else{
		cursor->getDir()->getDir()->getDir()->IncluiFuncionario(nome);
	  }
  }

  //void incluirValor()


  void imprimirMaior(float valor) {
    No_Valores * cursor = this->raiz;

    if (valor <= 7600) {
      cursor->getNomes();
    }

    if(valor <= 2500) {
      cursor->getEsq()->getNomes();
    }

    if(valor <= 12500){
      cursor->getDir()->getNomes();
    }

    if(valor <= 1000){
      cursor->getEsq()->getEsq()->getNomes();
    }

    if(valor <= 5000){
      cursor->getEsq()->getDir()->getNomes();
    }

    if(valor <= 10000){
      cursor->getDir()->getEsq()->getNomes();
    }

    if(valor <= 15000){
      cursor->getDir()->getDir()->getNomes();
    }

    if(valor <= 0){
      cursor->getEsq()->getEsq()->getEsq()->getNomes();
    }

    if(valor <= 17500){
      cursor->getDir()->getDir()->getDir()->getNomes();
    }
  }


  void imprimirMenor(float valor) {
    No_Valores * cursor = this->raiz;

    if (valor > 10000) {
      cursor->getNomes();
    }

    if(valor > 5000) {
      cursor->getEsq()->getNomes();
    }

    if(valor > 15000){
      cursor->getDir()->getNomes();
    }

    if(valor > 2500){
      cursor->getEsq()->getEsq()->getNomes();
    }

    if(valor > 7500){
      cursor->getEsq()->getDir()->getNomes();
    }

    if(valor > 12500){
      cursor->getDir()->getEsq()->getNomes();
    }

    if(valor > 15500){
      cursor->getDir()->getDir()->getNomes();
    }

    if(valor > 1000){
      cursor->getEsq()->getEsq()->getEsq()->getNomes();
    }

  }

  void imprimirEntre(float min, float max) {
    No_Valores * cursor = this->raiz;

    if(min >= 7600 && max < 10000){
		  cursor->getNomes();
	  }

    else if(min >= 2500 && max < 5000){
      cursor->getEsq()->getNomes();
    }

    else if(min >= 12500 && max < 15000){
      cursor->getDir()->getNomes();
    }

    else if(min >= 1000 && max < 2500){
      cursor->getEsq()->getEsq()->getNomes();
    }

    else if(min >= 5000 && max < 7500){
      cursor->getEsq()->getDir()->getNomes();
    }

    else if(min >= 10000 && max < 12500){
      cursor->getDir()->getEsq()->getNomes();
    }

    else if(min >= 15000 && max < 15500){
      cursor->getDir()->getDir()->getNomes();
    }

    else if(min >= 0 && max < 1000){
      cursor->getEsq()->getEsq()->getEsq()->getNomes();
    }

    else{
      cursor->getDir()->getDir()->getDir()->getNomes();
    }

  }


};

class Arvore {

  private:
  No * raiz;

  public:
  Arvore(){raiz = NULL;}

  No * getRaiz(){return raiz;}

  void inserirAlfa(string nome, string cargo,  string lotacao, string admissao, string nasc, float venc, float encargos, float benef, string meses){

    if (raiz == NULL) {
      raiz = new No(nome, cargo, lotacao, admissao, nasc, venc, encargos, benef, meses);
    }
    else{
      inserirAux_Alfa(raiz,nome, cargo, lotacao, admissao, nasc, venc, encargos, benef, meses);
    }

  }

  void inserirAux_Alfa(No * no,string nome, string cargo,  string lotacao, string admissao, string nasc, float venc, float encargos, float benef, string meses){

    if ( nome < no->getNome()) {
      if(no->getEsq() == NULL) {
        No * novo_no = new No(nome, cargo, lotacao, admissao, nasc, venc, encargos, benef, meses);
        no->setEsq(novo_no);
      }
      else{
        inserirAux_Alfa(no->getEsq(), nome, cargo, lotacao, admissao, nasc, venc, encargos, benef, meses);
      }
    }

    else if ( nome > no->getNome()) {
      if(no->getDir() == NULL) {
        No* novo_no = new No(nome, cargo, lotacao, admissao, nasc, venc, encargos, benef, meses);
        no->setDir(novo_no);
      }
      else{
        inserirAux_Alfa(no->getDir(), nome, cargo, lotacao, admissao, nasc, venc, encargos, benef, meses);
      }
    }

    else {
      no->somarValorBeneficios(benef);
      no->somarValorEncargos(encargos);
      no->somarValorVencimentos(venc);
      no->incrementaMes();
    }
  }

  void EmOrdem(No * no) {

    if(no != NULL) {
      EmOrdem(no->getEsq());
      cout << no->getNome() << "\n";
      EmOrdem(no->getDir());
    }

  }

  void IncluirValores(No * no, Arvore_Valores arv_val) {

    if(no != NULL) {
      IncluirValores(no->getEsq(), arv_val);
      IncluirValores(no->getDir(), arv_val);
      arv_val.inserirNomeNo((no->getVenc() + no->getBenef() - no->getEncargos()) / no->getQuantMes(), no->getNome());
    }
  }

  void incluirValoresMedios(Arvore_Valores arv_val) {
    No* cursor = this->raiz;

    IncluirValores(cursor,arv_val);
  }

  void  listarCargos(No * no) {

    if(no != NULL) {
      listarCargos(no->getEsq());
      cout << no->getCargo() << "\n";
      listarCargos(no->getDir());

    }
  }

  void listaTodosCargos() {
    No * cursor = this->raiz;

    listarCargos(cursor);


  }

  void listarFuncCargo(No* no, string cargo) {
    if(no != NULL) {
      listarFuncCargo(no->getEsq(), cargo);
      if(no->getCargo() == cargo) {
        no->printarNomesFunc();
      }
      listarFuncCargo(no->getDir(), cargo);
    }
  }

  void listarTodosFunc(string cargo){
    No * cursor = this->raiz;

    listarFuncCargo(cursor, cargo);

  }



};



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

  Arvore arv;
  Arvore_Valores arv_val;
  No * no;
  int opc;
  int i = 0;


	int tamanhoMax = 300;
	FILE * pFile;
	char linha[tamanhoMax];
	string linhaStr;

	pFile = fopen ("spcine.csv" , "r");

	if (pFile == NULL) cout << ("Erro na abertura do arquivo");
	else {
		while ( fgets (linha , tamanhoMax , pFile) != NULL ) {
			linhaStr = linha;
				if (i == 0){
					i++;
					continue;
				}

				string * linhaSeparadaEmVetor = split(linhaStr, ";", 15);

				linhaSeparadaEmVetor[0]; //EMPRESA
				string meses = linhaSeparadaEmVetor[1]; //MES
				linhaSeparadaEmVetor[2]; //ANO
				string nome = linhaSeparadaEmVetor[3]; //NOME
				string cargo = linhaSeparadaEmVetor[4]; //CARGO
				string lotacao = linhaSeparadaEmVetor[5]; //LOTACAO
				string admissao = linhaSeparadaEmVetor[6]; //ADMISSAO
				string nasc = linhaSeparadaEmVetor[7];  //NASCIMENTO

				string vencimento = linhaSeparadaEmVetor[8];  //VENCIMENTOS
				int tamanhoVencimentos = vencimento.length();
			    char char_array_vencimentos[tamanhoVencimentos + 1];
			    strcpy(char_array_vencimentos, vencimento.c_str());
			    float venc = atof(char_array_vencimentos);

				string encargosstr = linhaSeparadaEmVetor[9];  //ENCARGOS
				int tamanhoEncargos = encargosstr.length();
			    char char_array_encargos[tamanhoEncargos + 1];
			    strcpy(char_array_encargos, encargosstr.c_str());
			    float encargos = atof(char_array_encargos);

				string beneficios = linhaSeparadaEmVetor[10];  //BENEFICIOS
				int tamanhoBeneficios = beneficios.length();
			    char char_array_beneficios[tamanhoBeneficios + 1];
			    strcpy(char_array_beneficios, beneficios.c_str());
			    float benef = atof(char_array_beneficios);

				arv.inserirAlfa(nome, cargo, lotacao, admissao, nasc, venc, encargos, benef, meses);
		}
		fclose (pFile);
	}

  arv_val.inserirNo();
  arv.incluirValoresMedios(arv_val);


  while(true) {
    cout << "\nEscolha uma dentre as opcoes abaixo:\n\n";
    cout << "0 - encerrar.\n";
    cout << "1 - listar servidores em ordem alfabética.\n";
    cout << "2 - listar servidores que recebem media mensal acima de determinado valor.\n";
    cout << "3 - listar servidores que recebem media mensal abaixo de determinado valor.\n";
    cout << "4 - listar servidores que recebem media mensal entre dois valores.\n";
    cout << "5 - listar todos os cargos cadastrados na arvore.\n";
    cout << "6 - listar funcionarios de determinado cargo.\n\n";
    cout << "Escolha sua opcao: ";

    cin >> opc;


    if( opc == 0) {
      break;
    }

    else if (opc == 1) {
      arv.EmOrdem(arv.getRaiz());
    }

    else if (opc == 2){
      float valor;
      cout << "Digite o valor desejado: ";
      cin >> valor;
      arv_val.imprimirMaior(valor);

    }

    else if (opc == 3){
      float valor;
      cout << "Digite o valor desejado: ";
      cin >> valor;
      arv_val.imprimirMenor(valor);
    }

    else if (opc == 4){
      float min;
      cout << "Digite o valor minimo: ";
      cin >> min;

      float max;
      cout << "Digite o valor maximo: ";
      cin >> max;
      arv_val.imprimirEntre(min,max);

    }

    else if (opc == 5){

      arv.listaTodosCargos();

    }

    else if (opc == 6){
      string cargo;
      cout << "Escolha o cargo: ";
      cin.ignore();
      getline(cin,cargo);
      arv.listarTodosFunc(cargo);

    }

  }
}
