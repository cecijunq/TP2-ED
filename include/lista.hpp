#ifndef LISTA_HPP
#define LISTA_HPP

#include "./celula.hpp"

class Lista {
    private:
        Celula *_inicio;
        Celula *_fim;
        // Lista *proxima_lista;
        int _valor_vertice;
        int _cor;
        int _tamanho;

    public:
        Lista(int valor);
        Lista();
        void adiciona_elemento(Celula *novo_elemento);
        void set_prox_lista(Lista *proxima);
        int get_tamanho();
        Celula *get_inicio();
        Celula *get_fim();
        Lista *get_proxima_lista();
        void muda_inicio(Celula *novo_inicio);
        void muda_fim(Celula *novo_fim);
        int get_valor();
        void set_cor(int cor);
        int get_cor();
        
};

#endif