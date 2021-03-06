#ifndef ELEMENTO2_H
#define ELEMENTO2_H

class ArvoreB_No; 

class Elemento2 {

	//* PRIVATE
	private:
	unsigned int valor; // valor do elemento
	Elemento2 * prox; // proximo elemento
	Elemento2 * prev; // elemento anterior (previo)
	ArvoreB_No * noMenor;
	ArvoreB_No * noMaior;
	friend class ArvoreB;
	
	//* PUBLIC
	public:
	Elemento2();
	unsigned int getValor();
	void setValor(unsigned int v);
	Elemento2 * getProx();
	void setProx(Elemento2 * e);
	Elemento2 * getPrev();
	void setPrev(Elemento2 * e);

};

#endif
