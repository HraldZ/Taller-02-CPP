//
// Created by Main on 15/09/2026.
//

#ifndef TALLER_I_CPP_PILA_H
#define TALLER_I_CPP_PILA_H

#include "Node.h"
#include "Paciente.h"

class Pila {
private:
    Node* top;

public:
    Pila();
    ~Pila();

    void push(Paciente* p);
    void mostrarHistorial();
    bool estaVacia();
};

#endif //TALLER_I_CPP_PILA_H

