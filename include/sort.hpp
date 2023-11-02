#ifndef SORT_HPP
#define SORT_HPP

#include "./grafo.hpp"

class Sort {
    private:
        int n_vertices;
        Grafo *_grafo;

    public:
        Sort(Grafo *grafo);
        void Troca(int item1, int item2);
        void bubble_sort();
        void selection_sort();
        void insertion_sort();
        int particiona(int comeco, int fim);
        void quicksort(int comeco, int fim);
        void merge(int elem_esq, int mediana, int elem_dir);
        void mergesort(int elem_esq, int elem_dir);
        void heapify(int no);
        void heapsort();
        void counting_sort(int max);
        void deixa_estavel();

};

#endif