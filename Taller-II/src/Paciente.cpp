#include "Paciente.h"

#include <iostream>


Paciente::Paciente(string id, string nombre, int edad, float temperatura, int presionArterial , int dolor , string tipoDolor ,
    bool trauma, bool sintomasNeurologicos, bool requiereCirujia , int diasHospitalizacion)
    :Persona(nombre, edad) {
    this->id = id;
}

Paciente::~Paciente() {}

string Paciente::getId() {
    return this->id;
}


void Paciente::imprimirPaciente() {
    cout << "ID: " << this->id << " | Nombre: " << this->nombre
         << " | Edad: " << this->edad
         << endl;
}