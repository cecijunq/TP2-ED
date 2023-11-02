#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "./listaadjacencia.hpp"
#include "./lista.hpp"

class entrada_invalida_e {};

class Grafo {
    private:
        Lista *_vertices;
        int _numero_vertices;

    public:
        Grafo(int numero_vertices);
        ~Grafo();
        void Limpa();
        void insere_aresta(int v1, int v2);
        void imprime_vizinhos();
        void set_cor(int vertice, int cor);
        Lista *get_lista();
        int get_num_vertices();
};

#endif