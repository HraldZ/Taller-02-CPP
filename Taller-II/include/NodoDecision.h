//
// Created by Main on 20/10/2026.
//

#pragma once
#include <string>

using namespace std;

class NodoDecision {
public:
    string pregunta;
    string servicio;
    bool esHoja;

    NodoDecision* si;     //izquierda
    NodoDecision* no;     //derecha


    NodoDecision(string pregunta) {
        this->pregunta = pregunta;
        this->servicio = "";
        this->esHoja = false;
        this->si = nullptr;
        this->no = nullptr;
    }


    NodoDecision(string servicio, bool esHoja) {
        this->pregunta = "";
        this->servicio = servicio;
        this->esHoja = esHoja;
        this->si = nullptr;
        this->no = nullptr;
    }
};