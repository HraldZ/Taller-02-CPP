#pragma once
#include "Persona.h"
#include <string>

using namespace std;


class Paciente : public Persona {
private:
    string id , nombre , tipoDolor;
    float temperatura , presionArterial;
    int edad , dolor , diasHospitalizacion;
    bool trauma , sintomasNeurologicos , requiereCirujia;


public:
    Paciente(string id, string nombre, int edad, float temperatura, int presionArterial , int dolor , string tipoDolor ,
    bool trauma, bool sintomasNeurologicos, bool requiereCirujia , int diasHospitalizacion);
    
    ~Paciente();

    string getId();

    void imprimirPaciente();
};

