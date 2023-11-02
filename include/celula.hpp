#ifndef CELULA_HPP
#define CELULA_HPP

class Celula {
    private:
        int _elemento;
        Celula *_proximo;

    public:
        Celula(int elemento);
        void set_proximo(Celula *proximo);
        Celula *get_proximo();
        int get_elemento();
};

#endif