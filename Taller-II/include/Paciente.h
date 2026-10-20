#pragma once
#include "Persona.h"
#include <string>

using namespace std;

class Paciente : public Persona {
private:
    string id, tipoDolor;
    float temperatura, presionArterial;
    int dolor, diasHospitalizacion;
    bool trauma, sintomasNeurologicos, requiereCirugia;

public:
    Paciente(string id, string nombre, int edad, float temperatura, float presionArterial,
             int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos,
             bool requiereCirugia, int diasHospitalizacion);

    ~Paciente();

    string getId();
    float getTemperatura();
    float getPresionArterial();
    int getDolor();
    string getTipoDolor();
    bool getTrauma();
    bool getSintomasNeurologicos();
    bool getRequiereCirugia();
    int getDiasHospitalizacion();

    void imprimirPaciente();
};