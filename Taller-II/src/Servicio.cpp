#include "../include/Servicio.h"
#include <iostream>

using namespace std;

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
    this->cabezaPacientes = nullptr;
    this->cantidadPacientes = 0;
    this->siguiente = nullptr;
}

Servicio::~Servicio() {
    Node* actual = cabezaPacientes;
    while (actual != nullptr) {
        Node* BorrarActual = actual;
        actual = actual->siguiente;

        delete BorrarActual->paciente;

        delete BorrarActual;
    }
}

string Servicio::getNombre() {
    return this->nombre;
}

void Servicio::agregarPaciente(Paciente* p) {
    Node* nuevoNodo = new Node(p);

    if (cabezaPacientes == nullptr) {
        cabezaPacientes = nuevoNodo;
    } else {
        Node* actual = cabezaPacientes;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
    cantidadPacientes++;
}


void Servicio::mostrarPacientes() {
    cout << "===ESTADO " << this->nombre << "===" << endl;
    cout << "Pacientes en el departamento de " << this->nombre << ": " << cantidadPacientes << endl;

    Node* actual = cabezaPacientes;
    while (actual != nullptr) {
        cout << "- " << actual->paciente->getNombre() << " (" << actual->paciente->getEdad() << ")" << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}