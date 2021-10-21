#include "Lista.h"

Lista::Lista() {
    // Completar
    header = new Nodo;
    trailer = new Nodo;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
    longitud_ = 0;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

void Lista::pop_front() {
    Nodo* nd = this->header->next->next;
    delete this->header->next;
    this->header->next = nd;
    nd->prev = this->header;
    this->longitud_ -= 1;
}

Lista::~Lista() {
    // Completar
    while (this->header->next != this->trailer){
        this->pop_front();
    }
    delete this->header;
    delete this->trailer;
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    while (this->header->next != this->trailer){
        this->pop_front();
    }
    Nodo* nd = aCopiar.header->next;
    while (nd != aCopiar.trailer){
        this->agregarAtras(nd->data);
        nd = nd->next;
    }
    this->longitud_ = aCopiar.longitud_;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
    Nodo* nd = new Nodo;
    nd->data = elem;
    nd->prev = this->header;
    nd->next = this->header->next;
    this->header->next->prev = nd;
    this->header->next = nd;
    this->longitud_ += 1;
}

void Lista::agregarAtras(const int& elem) {
    // Completar
    Nodo* nd = new Nodo();
    nd->data = elem;
    nd->next = this->trailer;
    nd->prev = this->trailer->prev;
    this->trailer->prev->next = nd;
    this->trailer->prev = nd;
    this->longitud_ += 1;
}

void Lista::eliminar(Nat i) {
    // Completar
    int j = 0;
    Nodo* nd = this->header->next;
    while (j <= i){
        if (j == i){
            nd->next->prev = nd->prev;
            nd->prev->next = nd->next;
            delete nd;
        }
        nd = nd->next;
        j++;
    }
    this->longitud_ -= 1;
}

int Lista::longitud() const {
    // Completar
    return this->longitud_;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    Nodo* nd = this->header->next;
    int j = 0;
    while (j < i){
        nd = nd->next;
        j++;
    }
    return nd->data;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* nd = this->header->next;
    int j = 0;
    while (j < i){
        nd = nd->next;
        j++;
    }
    return nd->data;
}

void Lista::mostrar(ostream& o) {
    // Completar
    Nodo* nd = this->header->next;
    while (nd->next != this->trailer){
        o << nd->data << " ";
        nd = nd->next;
    }
}

