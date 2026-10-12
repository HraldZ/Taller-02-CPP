//
// Created by joanj on 08-09-2026.
//

#ifndef TALLER_I_CPP_NODE_H
#define TALLER_I_CPP_NODE_H

#include "Paciente.h"
class Node {

public:
    Paciente* paciente;
    Node* siguiente;

    Node(Paciente* paciente) ;



};

#endif //TALLER_I_CPP_NODE_H
