#include "../include/celula.hpp"

Celula::Celula(int elemento) {
    _elemento = elemento;
    _proximo = nullptr;
}

void Celula::set_proximo(Celula *proximo) {
    _proximo = proximo;
}

Celula *Celula::get_proximo() {
    return _proximo;
}

int Celula::get_elemento() {
    return _elemento;
}
