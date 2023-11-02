#include <iostream>

#include "../include/grafo.hpp"
#include "../include/sort.hpp"
#include "../include/checa_coloracao.hpp"

int main() {
    char metodo_ordenacao;
    int numero_vertices, max = 0;

    std::cin >> metodo_ordenacao;
    std::cin >> numero_vertices;

    Grafo *grafo = new Grafo(numero_vertices);

    for(int i = 0; i < numero_vertices; i++) {
        int numero_vizinhos, adjacente;
        std::cin >> numero_vizinhos;

        for(int j = 0; j < numero_vizinhos; j++) {
            std::cin >> adjacente;
            grafo->insere_aresta(i, adjacente);
        }
    }

    for(int i = 0; i < numero_vertices; i++) {
        int cor_vertice;
        std::cin >> cor_vertice;
        grafo->set_cor(i, cor_vertice);
        if(cor_vertice > max) max = cor_vertice;
    }

    Sort s(grafo);
    //grafo->imprime_vizinhos();
    //std::cout << std::endl;
    Coloracao c;
    int resultado_coloracao = c.checa_condicao_vizinhos(grafo);

    switch(metodo_ordenacao) {
        case 'b': {
            // implementa o BUBBLE SORT
            s.bubble_sort();

            break;
        }
        case 's': {
            // implementa o SELECTION SORT
            s.selection_sort();

            break;
        }
        case 'i': {
            // implementa o INSERTION SORT
            s.insertion_sort();

            break;
        }
        case 'q': {
            // implementa o QUICKSORT
            s.quicksort(0, numero_vertices-1);

            break;
        }
        case 'm': {
            // implementa o MERGESORT
            s.mergesort(0, numero_vertices);

            break;
        }
        case 'p': {
            // implementa o HEAPSORT
            s.heapsort();

            break;
        }
        case 'y': {
            s.counting_sort(max);
            break;
        }
    }

    if(resultado_coloracao == 0) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "1 ";
        grafo->imprime_vizinhos();
    }

}