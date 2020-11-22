#ifndef NO_H
#define NO_H

#include <string>
using namespace std;

class NoAbb {

	private:
		NoAbb * filhoEsq;
		NoAbb * filhoDir;
		
		string palavra;
		int vezesPalavraAparece;
	
	public:
		NoAbb();
		NoAbb(string palavra);
			
		void setFilhoEsq(NoAbb * no);
		NoAbb * getFilhoEsq();
		void setFilhoDir(NoAbb * no);
		NoAbb * getFilhoDir();
		
		string getPalavra();
		
		void numeroPalavras();
		int getNumeroPalavras();
};

#endif
