#include "../include/Servicio.h"
#include <iostream>

using namespace std;

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
    this->arbolPacientes = new ArbolAVL();
    this->cantidadPacientes = 0;
    this->siguiente = nullptr;
}

Servicio::~Servicio()
{
    delete arbolPacientes;
}

string Servicio::getNombre() {
    return this->nombre;
}

int Servicio::getCantidadPacientes() {
    return this->cantidadPacientes;
}

void Servicio::agregarPaciente(Paciente* p) {
    arbolPacientes->insertar(p);
    cantidadPacientes++;
}

void Servicio::mostrarPacientes() {
    cout << this->nombre << endl;
    if (arbolPacientes->estaVacio()) {
        cout << "Sin pacientes" << endl;
    } else {
        cout << "Pacientes: ";
        arbolPacientes->mostrarInorden();
    }
}

ArbolAVL* Servicio::getArbol() {
    return this->arbolPacientes;
}