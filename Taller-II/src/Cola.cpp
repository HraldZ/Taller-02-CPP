//
// Created by joanj on 14-09-2026.
//
#include "../include/Cola.h"
#include "../include/Paciente.h"
#include <iostream>
#include <ostream>
using namespace std;


Cola::Cola() {
    primero = nullptr;
    ultimo = nullptr;

}

void Cola::encolar(Paciente* paciente) {

    Node* nuevo = new Node(paciente);

    if (ultimo == nullptr) {
        primero = nuevo;
        ultimo = nuevo;

    }else {
        ultimo -> siguiente = nuevo;
        ultimo = nuevo;
    }


}
Paciente* Cola::sacarDeCola() {
    if (primero == nullptr) {
        return nullptr;
    }

    Node* nodoBorrar = primero;
    Paciente* pacienteExtraido = nodoBorrar->paciente;

    primero = primero->siguiente;


    if (primero == nullptr) {
        ultimo = nullptr;
    }

    delete nodoBorrar;
    return pacienteExtraido;
}

void Cola::mostrar() {
    if (primero == nullptr) {
        cout << "La cola esta vacia" << endl;
    }else {
        cout << primero-> paciente->getNombre() << endl;

    }
}

bool Cola::estaVacia() {
    if (primero == nullptr) {
        return true;
    }
    return false;
}
bool Cola::existeId(string id) {
    Node* actual = primero;
    while (actual != nullptr) {
        if (actual->paciente != nullptr && actual->paciente->getId() == id) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

Cola::~Cola() {


}