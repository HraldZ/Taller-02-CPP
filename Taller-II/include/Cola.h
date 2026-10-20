//
// Created by joanj on 14-09-2026.
//

#ifndef TALLER_I_CPP_COLA_H
#define TALLER_I_CPP_COLA_H

#include "Node.h"
#include "Paciente.h"
class Cola {
private:
    Node* primero;
    Node* ultimo;

public:
    Cola();
    ~Cola();
    bool existeId(string id);

    void encolar(Paciente* paciente);
    Paciente* sacarDeCola();

    void mostrar();
    bool estaVacia();

};













#endif //TALLER_I_CPP_COLA_H
