//
// Created by Main on 15/09/2026.
//

#ifndef TALLER_I_CPP_PERSONA_H
#define TALLER_I_CPP_PERSONA_H
#include <string>

using namespace std;

class Persona {
protected:

    string nombre;
    int edad;

public:

    Persona(string nombre, int edad);

    virtual ~Persona();

    string getNombre();
    int getEdad();

};

#endif //TALLER_I_CPP_PERSONA_H

