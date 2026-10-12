#include "Persona.h"

Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

Persona::~Persona() {

}

string Persona::getNombre() {
    return this->nombre;
}

int Persona::getEdad() {
    return this->edad;
}