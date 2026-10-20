//
// Created by Main on 20/10/2026.
//
#include "../include/ArbolDecision.h"
#include <iostream>

using namespace std;

ArbolDecision::ArbolDecision() {
    this->raiz = nullptr;
    construirArbol();
}

ArbolDecision::~ArbolDecision() {
    destruirRecursivo(raiz);
}

void ArbolDecision::destruirRecursivo(NodoDecision* nodo) {
    if (nodo != nullptr) {
        destruirRecursivo(nodo->si);
        destruirRecursivo(nodo->no);
        delete nodo;
    }
}


void ArbolDecision::construirArbol() {
    //pregunta edad < 14
    raiz = new NodoDecision("Edad < 14?");

    //tiene menos de 14 años va a pediatria
    raiz->si = new NodoDecision("Pediatria", true);

    //no tiene
    raiz->no = new NodoDecision("Trauma == 1?");

    //si trauma 1
    raiz->no->si = new NodoDecision("RequiereCirugia == 1?");
    raiz->no->si->si = new NodoDecision("Cirugia", true);
    raiz->no->si->no = new NodoDecision("Traumatologia", true);

    //si trauma 0
    raiz->no->no = new NodoDecision("SintomasNeurologicos == 1?");
    raiz->no->no->si = new NodoDecision("Neurologia", true);

    //SintomasNeurologicos 0
    raiz->no->no->no = new NodoDecision("TipoDolor == 'pecho'?");
    raiz->no->no->no->si = new NodoDecision("Cardiologia", true);

    //TipoDolor != pecho
    raiz->no->no->no->no = new NodoDecision("Temperatura >= 38.5 o Dolor >= 8?");
    raiz->no->no->no->no->si = new NodoDecision("Urgencias", true);

    //no urgencias
    raiz->no->no->no->no->no = new NodoDecision("DiasHospitalizacion >= 2?");
    raiz->no->no->no->no->no->si = new NodoDecision("Hospitalizacion", true);
    raiz->no->no->no->no->no->no = new NodoDecision("Medicina General", true);
}


string ArbolDecision::evaluarPaciente(Paciente* p, string &ruta) {
    if (p == nullptr || raiz == nullptr) {
        return "Medicina General";
    }

    ruta = "";

    if (p->getEdad() < 14) {
        ruta += "Edad < 14";
        return raiz->si->servicio; // Pediatria
    }
    ruta += "Edad >= 14 -> ";

    if (p->getTrauma()) {
        ruta += "Trauma == 1 -> ";
        if (p->getRequiereCirugia()) {
            ruta += "RequiereCirugia == 1";
            return "Cirugia";
        } else {
            ruta += "RequiereCirugia == 0";
            return "Traumatologia";
        }
    }
    ruta += "Trauma == 0 -> ";

    if (p->getSintomasNeurologicos()) {
        ruta += "SintomasNeurologicos == 1";
        return "Neurologia";
    }
    ruta += "SintomasNeurologicos == 0 -> ";

    if (p->getTipoDolor() == "pecho") {
        ruta += "TipoDolor == pecho";
        return "Cardiologia";
    }
    ruta += "TipoDolor != pecho -> ";

    if (p->getTemperatura() >= 38.5 || p->getDolor() >= 8) {
        ruta += "(Temperatura >= 38.5 o Dolor >= 8)";
        return "Urgencias";
    }
    ruta += "(Temperatura < 38.5 y Dolor < 8) -> ";

    if (p->getDiasHospitalizacion() >= 2) {
        ruta += "DiasHospitalizacion >= 2";
        return "Hospitalizacion";
    }

    ruta += "DiasHospitalizacion < 2";
    return "Medicina General";
}

void ArbolDecision::preordenRecursivo(NodoDecision* nodo) {
    if (nodo == nullptr) return;
    if (nodo->esHoja) {
        cout << "[Hoja: " << nodo->servicio << "] ";
    } else {
        cout << "(" << nodo->pregunta << ") ";
    }
    preordenRecursivo(nodo->si);
    preordenRecursivo(nodo->no);
}

void ArbolDecision::mostrarPreorden() {
    cout << "Recorrido Preorden del Arbol de Decision:" << endl;
    preordenRecursivo(raiz);
    cout << endl;
}

void ArbolDecision::inordenRecursivo(NodoDecision* nodo) {
    if (nodo == nullptr) return;
    inordenRecursivo(nodo->si);
    if (nodo->esHoja) {
        cout << "[Hoja: " << nodo->servicio << "] ";
    } else {
        cout << "(" << nodo->pregunta << ") ";
    }
    inordenRecursivo(nodo->no);
}

void ArbolDecision::mostrarInorden() {
    cout << "Recorrido Inorden del Arbol de Decision:" << endl;
    inordenRecursivo(raiz);
    cout << endl;
}

void ArbolDecision::postordenRecursivo(NodoDecision* nodo) {
    if (nodo == nullptr) return;
    postordenRecursivo(nodo->si);
    postordenRecursivo(nodo->no);
    if (nodo->esHoja) {
        cout << "[Hoja: " << nodo->servicio << "] ";
    } else {
        cout << "(" << nodo->pregunta << ") ";
    }
}

void ArbolDecision::mostrarPostorden() {
    cout << "Recorrido Postorden del Arbol de Decision:" << endl;
    postordenRecursivo(raiz);
    cout << endl;
}