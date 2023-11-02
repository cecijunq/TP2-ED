#include "../include/checa_coloracao.hpp"
#include <iostream>

void Coloracao::vizinhos(int n_cor) {
    soma_que_deve_ser = 0;
    n_vizinhos = n_cor-1;
    vizinhos_minimos = new int[n_vizinhos];

    for(int i = 0; i < n_vizinhos; i++) {
        vizinhos_minimos[i] = i+1;
        soma_que_deve_ser += i+1;
    }
}

int Coloracao::checa_condicao_vizinhos(Grafo *vertices) {
    Lista *lista = vertices->get_lista();

    
    // percorre cada um dos vértices do grafo
    for(int i = 0; i < vertices->get_num_vertices(); i++) {
        // armazena a cor do vértice corrente
        int cor_vertice_corrente = lista[i].get_cor();

        vizinhos(cor_vertice_corrente);
        Celula *aux = lista[i].get_inicio();

        int soma = 0;
        while(aux != nullptr) {
            // armazena qual é o vértice vizinho (armazena o valor do vértice)
            int index_vizinho = aux->get_elemento();

            // armazena a cor do vizinho
            int cor_vizinho = lista[index_vizinho].get_cor();

            if(vizinhos_minimos[cor_vizinho-1] == cor_vizinho) {
                soma += cor_vizinho;
                vizinhos_minimos[cor_vizinho-1] = 0;
            }
            aux = aux->get_proximo();
        }
        if(soma != soma_que_deve_ser) {
            return 0;
        }
        limpa();
    }
    return 1;
}

void Coloracao::limpa() {
    delete []vizinhos_minimos;
}