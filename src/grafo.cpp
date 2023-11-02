#include "../include/grafo.hpp"

#include <iostream>

Grafo::Grafo(int numero_vertices) {
    _vertices = new Lista[numero_vertices];
    _numero_vertices = numero_vertices;

    for(int i = 0; i < _numero_vertices; i++) {
        Lista novo_vertice = Lista(i);
        _vertices[i] = novo_vertice;
    }
}

Grafo::~Grafo() {
    Limpa();
}

void Grafo::Limpa() {
    delete _vertices;

}

void Grafo::insere_aresta(int v1, int v2) {
    if(v1 >= _numero_vertices || v2 >= _numero_vertices) {
        throw entrada_invalida_e();
    }

    Celula *novo_elem = new Celula(v2);
    _vertices[v1].adiciona_elemento(novo_elem);
}

void Grafo::imprime_vizinhos() {
    for(int i = 0; i < _numero_vertices; i++) {
        if(i == _numero_vertices)
            std::cout << _vertices[i].get_valor() << std::endl;
        else
            std::cout << _vertices[i].get_valor() << " ";
    }
}

void Grafo::set_cor(int vertice, int cor) {

    if(vertice >= _numero_vertices) throw entrada_invalida_e();

    _vertices[vertice].set_cor(cor);
    
}

Lista *Grafo::get_lista() {
    return _vertices;
}

int Grafo::get_num_vertices() {
    return _numero_vertices;
}