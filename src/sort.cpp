#include "../include/sort.hpp"
#include <iostream>

Sort::Sort(Grafo *grafo) : _grafo(grafo) {
    n_vertices = _grafo->get_num_vertices();
}

void Sort::Troca(int item1, int item2) {
    if(item1 == item2) return ;
    Lista *lista = _grafo->get_lista();
    if(lista[item1].get_cor() == lista[item2].get_cor()) {
        if(lista[item1].get_valor() < lista[item2].get_valor()) {
            return;
        }
    }

    Lista aux = lista[item1];
    lista[item1] = lista[item2];
    lista[item2] = aux;
}

void Sort::bubble_sort() {
    Lista *lista = _grafo->get_lista();
    for(int i = 0; i < n_vertices-1; i++) {
        for(int j = 0; j < n_vertices-1; j++) {
            if(lista[j].get_cor() > lista[j+1].get_cor()) {
                Troca(j, j+1);
            }
        }
    }
}

void Sort::selection_sort() {
    Lista *lista = _grafo->get_lista();
    int minimo;
    for(int i = 0; i < n_vertices-1; i++) {
        minimo = i;

        for(int j = i+1; j < n_vertices; j++) {
            if(lista[j].get_cor() < lista[minimo].get_cor()) {
                minimo = j;
            } else if(lista[j].get_cor() == lista[minimo].get_cor()) {
                if(lista[j].get_valor() < lista[minimo].get_valor()) {
                    minimo = j;
                }
            }
        }
        if(minimo != i) {
            Lista tmp = lista[minimo];
            for(int k = minimo; k > i; k--) {
                lista[k] = lista[k-1];
            }
            lista[i] = tmp;
        }
    }
}

void Sort::insertion_sort() {
    Lista aux;
    Lista *lista = _grafo->get_lista();

    for(int i = 1; i < n_vertices; i++) {
        aux = lista[i];
        int j = i-1;

        while(j >= 0 && aux.get_cor() < lista[j].get_cor()) {
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = aux;
    }
}

void Sort::deixa_estavel() {
    Lista *lista = _grafo->get_lista();

    for(int i = 0; i < _grafo->get_num_vertices() - 1; i++) {
        if(lista[i].get_cor() == lista[i+1].get_cor()) {
            if(lista[i].get_valor() > lista[i+1].get_valor()) {
                Troca(i, i+1);
            }
        }
    }
}

int Sort::particiona(int comeco, int fim) {
    Lista *lista = _grafo->get_lista();
    int i = comeco;

    for(int j = comeco; j < fim; j++) {
        if(lista[j].get_cor() <= lista[fim].get_cor()) {
            Troca(i++, j);
        }
    }
    Troca(i, fim);
    return i;
}

void Sort::quicksort(int comeco, int fim) {
    if(comeco >= fim) return;
    int pivot = particiona(comeco, fim); // n log2 n

    quicksort(comeco, pivot-1);
    quicksort(pivot+1, fim);

    deixa_estavel();
}

void Sort::merge(int elem_esq, int elem_dir, int mediana) {
    Lista *lista = _grafo->get_lista();
    Lista *aux;
    aux = new Lista[elem_dir - elem_esq + 1];
    int i = elem_esq;
    int j = mediana;
    int k = 0;

    while(i < mediana && j < elem_dir) {
        if(lista[i].get_cor() <= lista[j].get_cor()) {
            aux[k] = lista[i];
            i++;
        } else {
            aux[k] = lista[j];
            j++;
        }
        k++;
    }
    while(i < mediana) {
        aux[k] = lista[i];
        i++;
        k++;
    }
    while(j < elem_dir) {
        aux[k] = lista[j];
        j++;
        k++;
    }

    for(i = elem_esq; i < elem_dir; ++i) lista[i] = aux[i-elem_esq];
    delete []aux;
}

void Sort::mergesort(int elem_esq, int elem_dir) {
    if(elem_esq < elem_dir-1) {
        int mediana = (elem_esq + elem_dir)/2; // criado log2 n vezes
        mergesort(elem_esq, mediana);
        mergesort(mediana, elem_dir);
        merge(elem_esq, elem_dir, mediana);
    }
}

void Sort::heapify(int no, int tamanho) {
    Lista *lista = _grafo->get_lista();
    int menor_elem = no;

    int index_ramo_esq = 2 * no + 1;
    int index_ramo_dir = 2 * no + 2;

    if(index_ramo_esq < tamanho) {
        if (lista[index_ramo_esq].get_cor() > lista[menor_elem].get_cor() || 
            (lista[index_ramo_esq].get_cor() == lista[menor_elem].get_cor() && 
             lista[index_ramo_esq].get_valor() > lista[menor_elem].get_valor())) {
            menor_elem = index_ramo_esq;
        }
    }

    if (index_ramo_dir < tamanho) {
        // Comparação baseada nas cores dos elementos
        if (lista[index_ramo_dir].get_cor() > lista[menor_elem].get_cor() || 
            (lista[index_ramo_dir].get_cor() == lista[menor_elem].get_cor() && 
             lista[index_ramo_dir].get_valor() > lista[menor_elem].get_valor())) {
            menor_elem = index_ramo_dir;
        }
    }

    if (menor_elem != no) {
        Troca(menor_elem, no);
        heapify(menor_elem, tamanho);
    }
}

void Sort::heapsort() {
    int n_vertices = _grafo->get_num_vertices();

    for(int i = n_vertices/2 - 1; i >= 0; i--) {
        heapify(i, n_vertices);
    }

    for(int i = n_vertices-1; i > 0; i--) {
        Troca(0, i);
        heapify(0, i);
    }
}

void Sort::counting_sort(int max) {
    Lista *aux = new Lista[max];
    Lista *tmp = new Lista[_grafo->get_num_vertices()];
    Lista *lista = _grafo->get_lista();

    for(int i = 0; i < _grafo->get_num_vertices(); i++) {
        int cor_vertice = lista[i].get_cor();
        Celula *c = new Celula(lista[i].get_valor());
        aux[cor_vertice - 1].adiciona_elemento(c);
    }

    int index = 0;
    int i = 0;

    while(i < max) {
        if(aux[i].get_tamanho() != 0) {
            while(aux[i].get_inicio() != nullptr) {
                tmp[index] = lista[aux[i].get_inicio()->get_elemento()];
                aux[i].muda_inicio(aux[i].get_inicio()->get_proximo());
                index++;
            }
        }
        i++;
    }
    delete []lista;
    for(int i = 0; i < _grafo->get_num_vertices(); i++) {
        lista[i] = tmp[i];
    }
    delete []tmp;
    delete []aux;
}

/*
    2 inteiros (index, i) --> 2
    1 lista com o tamanho da cor máxima --> pior caso: quando a cor máxima for maior do que 
    2 lista com o tamanho de n_vertices --> 2n
 */
