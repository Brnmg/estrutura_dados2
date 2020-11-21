#include <iostream>


class No {

    private:
        int chave;
        No *esq, *dir;

    public:
        No(int chave);
        int getChave();
        No * getEsq();
        No * getDir();
        void setEsq(No * no);
        void setDir(No * no);
};