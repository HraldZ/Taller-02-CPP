//
// Created by Main on 20/10/2026.
//

#pragma once
#include "NodoDecision.h"
#include "Paciente.h"
#include <string>

using namespace std;

class ArbolDecision {
private:
    NodoDecision* raiz;

    void destruirRecursivo(NodoDecision* nodo);
    void preordenRecursivo(NodoDecision* nodo);
    void inordenRecursivo(NodoDecision* nodo);
    void postordenRecursivo(NodoDecision* nodo);

public:
    ArbolDecision();
    ~ArbolDecision();

    void construirArbol();


    string evaluarPaciente(Paciente* p, string &ruta);
    
    void mostrarPreorden();
    void mostrarInorden();
    void mostrarPostorden();
};