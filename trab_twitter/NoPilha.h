#ifndef  NOPILHA_H
#define NOPILHA_H

#include "NoAbb.h"

class NoPilha {

	private:
		NoAbb * noAbb;
		NoPilha * prox;

	public:
		NoPilha(NoAbb * no);
		NoAbb * getNoAbb();
		NoPilha * getProx();
		void setProx(NoPilha * no);
};

#endif
