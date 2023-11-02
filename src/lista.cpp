#include "../include/lista.hpp"

Lista::Lista() {}

Lista::Lista(int valor) {
    _inicio = nullptr;
    _fim = nullptr;
    proxima_lista = nullptr;
    //anterior_lista = nullptr;
    _tamanho = 0;
    _valor_vertice = valor;
}

void Lista::adiciona_elemento(Celula *novo_elemento) {
    if(_inicio == nullptr) 
        _inicio = novo_elemento;
    
    if(_fim != nullptr)
        _fim->set_proximo(novo_elemento);


    muda_fim(novo_elemento);
    _tamanho++;
}

void Lista::set_prox_lista(Lista *proxima) {
    proxima_lista = proxima;
}

int Lista::get_tamanho() {
    return _tamanho;
}

Celula *Lista::get_inicio() {
    return _inicio;
}

Celula *Lista::get_fim() {
    return _fim;
}

Lista *Lista::get_proxima_lista() {
    return proxima_lista;
}

void Lista::muda_inicio(Celula *novo_inicio) {
    _inicio = novo_inicio;
}

void Lista::muda_fim(Celula *novo_fim) {
    _fim = novo_fim;
}

int Lista::get_valor() {
    return _valor_vertice;
}

void Lista::set_cor(int cor) {
    _cor = cor;
}

int Lista::get_cor() {
    return _cor;
}