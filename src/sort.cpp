#include "../include/sort.hpp"
#include <iostream>

Sort::Sort(Grafo *grafo) : _grafo(grafo) {
    n_vertices = _grafo->get_num_vertices();
}

void Sort::Troca(int item1, int item2) {
    if(item1 == item2) return ;
    Lista *lista = _grafo->get_lista();
    if(lista[item1].get_cor() == lista[item2].get_cor()) {
        if(lista[item1].get_valor() < lista[item1].get_valor()) {
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
    int maximo;
    for(int i = n_vertices-1; i > 0; i--) {
        maximo = i;

        for(int j = i-1; j > 0; j--) {
            if(lista[j].get_cor() > lista[maximo].get_cor()) {
                maximo = j;
            }
        }
        Troca(maximo, i);
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
    int pivot = particiona(comeco, fim);

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
        int mediana = (elem_esq + elem_dir)/2;
        mergesort(elem_esq, mediana);
        mergesort(mediana, elem_dir);
        merge(elem_esq, elem_dir, mediana);
    }
}

void Sort::heapify(int no) {
    /*Lista *lista = _grafo->get_lista();
    int no_pai = no;
    int ramo_esq = 2 * no_pai;
    Lista cor_no_pai = lista[no_pai];
    while(ramo_esq <= _grafo->get_num_vertices()-1) {
        if(ramo_esq < _grafo->get_num_vertices()-1) {
            if(lista[ramo_esq].get_cor() > lista[ramo_esq+1].get_cor()) ramo_esq = ramo_esq + 1;
            if(cor_no_pai.get_cor() <= lista[ramo_esq].get_cor()) break;
            lista[no_pai] = lista[ramo_esq];
            no_pai = ramo_esq;
            ramo_esq = 2 * no_pai;
        }
        lista[no_pai] = cor_no_pai;
    }*/
    Lista *lista = _grafo->get_lista();
    int menor_elem = no;

    int index_ramo_esq = 2 * no + 1;
    int index_ramo_dir = 2 * no + 2;
    bool condicao1 = index_ramo_esq < _grafo->get_num_vertices();
    bool condicao2 = index_ramo_dir < _grafo->get_num_vertices();

    if(condicao1 && lista[index_ramo_esq].get_cor() < lista[menor_elem].get_cor()) {
        menor_elem = index_ramo_esq;
    }
    
    if(condicao2 && lista[index_ramo_dir].get_cor() < lista[menor_elem].get_cor()) {
        menor_elem = index_ramo_dir;
    }

    if(menor_elem != no) {
        Troca(no, menor_elem);

        if(lista[menor_elem].get_cor() == lista[menor_elem - 1].get_cor() && lista[menor_elem].get_valor() < lista[menor_elem - 1].get_valor()) {
            Troca(menor_elem, menor_elem - 1);
        }
        
        if(lista[menor_elem].get_cor() == lista[menor_elem + 1].get_cor() && lista[menor_elem].get_valor() > lista[menor_elem + 1].get_valor()) {
            Troca(menor_elem, menor_elem + 1);
        }

        if(lista[no].get_cor() == lista[no - 1].get_cor() && lista[no].get_valor() < lista[no - 1].get_valor()) {
            Troca(no, no - 1);
        }
        
        if(lista[no].get_cor() == lista[no + 1].get_cor() && lista[no].get_valor() > lista[no + 1].get_valor()) {
            Troca(no, no + 1);
        }
        heapify(menor_elem);
    }

    if(condicao1 && condicao2 && lista[index_ramo_esq].get_cor() > lista[index_ramo_dir].get_cor()) {
        Troca(index_ramo_esq, index_ramo_dir);
    }
}

void Sort::heapsort() {
    Lista *lista = _grafo->get_lista();
    int n_vertices = _grafo->get_num_vertices();
    //Lista *aux = new Lista[n_vertices];
    //int i = 0;

    // constroi o heap
    /*int no_interno = n_vertices/2 + 1;
    while(no_interno > 0) {
        no_interno--;
        heapify(no_interno);
    }
    while(n_vertices > 0) {
        Lista primeiro_elem = lista[0];
        lista[0] = lista[n_vertices-1];
        lista[n_vertices-1] = primeiro_elem;
        n_vertices--;
        heapify(0);
    }*/
    for(int i = n_vertices/2 + 1; i >= 0; i--) {
        heapify(i);
    }
    /*while(n_vertices > 0) {
        Lista primeiro_elem = lista[0];
        lista[0] = lista[n_vertices-1];
        lista[n_vertices-1] = primeiro_elem;
        n_vertices--;
        heapify(0);
    }*/
    //deixa_estavel();
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
    lista = tmp;
    /*for(int i = 0; i < _grafo->get_num_vertices(); i++) {
        lista[i] = tmp[i];
    }
    delete []tmp;*/
    delete []aux;
}