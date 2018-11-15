#ifndef NO_H
#define NO_H


class No{
    private:
        No *esq, *dir;
        int dado;

    public:
        No(int n);
        //getters e setters;
        No* getDir();
        No* getEsq();
        int getDado();

        void setDir(No* no);
        void setEsq(No* no);
        void setDado(int n);

        void add(int n);
        void emOrdem();
};

#endif // NO_H
