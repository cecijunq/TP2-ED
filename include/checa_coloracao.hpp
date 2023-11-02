#ifndef CHECA_COLORACAO_HPP
#define CHECA_COLORACAO_HPP

#include "./grafo.hpp"

class Coloracao {
    private:
        int *vizinhos_minimos;
        int soma_que_deve_ser;
        int n_vizinhos;

    public:
        void vizinhos(int n_cor);
        int checa_condicao_vizinhos(Grafo *vertices);
        void limpa();
};

#endif