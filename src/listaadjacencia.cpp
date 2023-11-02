#include "../include/listaadjacencia.hpp"
#include <iostream>

ListaAdjacencia::ListaAdjacencia(int n_vertices) {
    array = new Lista[n_vertices];
    index = 0;
}

void ListaAdjacencia::adiciona_vertice(Lista novo_vertice) {
    std::cout << "entrou" << std::endl;
    array[index] = novo_vertice;
    index++;
}

Lista *ListaAdjacencia::get_lista() {
    return array;
}
