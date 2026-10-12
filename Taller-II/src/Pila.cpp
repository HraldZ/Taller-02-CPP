//
// Created by Main on 15/09/2026.
//

#include "../include/Pila.h"
#include <iostream>
using namespace std;

Pila::Pila() {
    top = nullptr;
}

Pila::~Pila() {
    Node* actual = top;
    while (actual != nullptr) {
        Node* actualBorrar = actual;
        actual = actual->siguiente;
        delete actualBorrar;
    }
}

void Pila::push(Paciente* p) {
    Node* nuevoNodo = new Node(p);
    nuevoNodo->siguiente = top;
    top = nuevoNodo;
}

void Pila::mostrarHistorial() {
    cout << "=== HISTORIAL DE ÚLTIMAS ATENCIONES DEL HOSPITAL ===" << endl;

    if (top == nullptr) {
        cout << "No hay atenciones aun." << endl;
        return;
    }

    Node* actual = top;
    while (actual != nullptr) {
        cout << "nombre: " << actual->paciente->getNombre()
             << " | edad: " << actual->paciente->getEdad()
             <<endl;

        actual = actual->siguiente;
    }
    cout << endl;
}

bool Pila::estaVacia() {
    return top == nullptr;
}