#ifndef LISTA_ADJACENCIA_HPP
#define LISTA_ADJACENCIA_HPP

#include "./lista.hpp"

class ListaAdjacencia {
    private:
        Lista *array;
        int index;

    public:
        ListaAdjacencia(int n_vertices);
        void adiciona_vertice(Lista novo_vertice);
        Lista *get_lista();

};

#endif