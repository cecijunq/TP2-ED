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
            try {
                grafo->insere_aresta(i, adjacente);

            } catch(entrada_invalida_e &e) {
                return 0;
            }
        }
    }

    for(int i = 0; i < numero_vertices; i++) {
        int cor_vertice;
        std::cin >> cor_vertice;
        try {
            grafo->set_cor(i, cor_vertice);

        } catch(entrada_invalida_e &e) {
            return 0;
        }
        if(cor_vertice > max) max = cor_vertice;
    }

    Sort s(grafo);
    Coloracao c;
    int resultado_coloracao = c.checa_condicao_vizinhos(grafo);

    if(resultado_coloracao == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

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

        default: {
            return 1;
        }
    }

    std::cout << "1 ";
    grafo->imprime_vizinhos();
    return 0;
    /*if(resultado_coloracao == 0) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "1 ";
        grafo->imprime_vizinhos();
    }*/

    //grafo.Limpa();

}