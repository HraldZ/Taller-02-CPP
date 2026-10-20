//
// Created by Main on 20/10/2026.
//

#pragma once
#include "Paciente.h"

class NodoAVL {
public:
    Paciente* paciente;
    NodoAVL* izquierdo;
    NodoAVL* derecho;
    int altura;

    NodoAVL(Paciente* p) {
        this->paciente = p;
        this->izquierdo = nullptr;
        this->derecho = nullptr;
        this->altura = 1; 
    }
};