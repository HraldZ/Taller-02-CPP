#include "Paciente.h"
#include <iostream>

Paciente::Paciente(string id, string nombre, int edad, float temperatura, float presionArterial,
                   int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos,
                   bool requiereCirugia, int diasHospitalizacion)
    : Persona(nombre, edad) {

    this->id = id;
    this->temperatura = temperatura;
    this->presionArterial = presionArterial;
    this->dolor = dolor;
    this->tipoDolor = tipoDolor;
    this->trauma = trauma;
    this->sintomasNeurologicos = sintomasNeurologicos;
    this->requiereCirugia = requiereCirugia;
    this->diasHospitalizacion = diasHospitalizacion;
}

Paciente::~Paciente() {}


string Paciente::getId() { return this->id; }
float Paciente::getTemperatura() { return this->temperatura; }
float Paciente::getPresionArterial() { return this->presionArterial; }
int Paciente::getDolor() { return this->dolor; }
string Paciente::getTipoDolor() { return this->tipoDolor; }
bool Paciente::getTrauma() { return this->trauma; }
bool Paciente::getSintomasNeurologicos() { return this->sintomasNeurologicos; }
bool Paciente::getRequiereCirugia() { return this->requiereCirugia; }
int Paciente::getDiasHospitalizacion() { return this->diasHospitalizacion; }

void Paciente::imprimirPaciente() {


    cout << "ID: " << this->id << "\n"
         << "Nombre: " << this->nombre << "\n"
         << "Edad: " << this->edad << "\n"
         << "Temperatura: " << this->temperatura << "\n"
         << "Presion Arterial: " << this->presionArterial << "\n"
         << "Dolor: " << this->dolor << "\n"
         << "Tipo Dolor: " << this->tipoDolor << "\n"
         << "Trauma: " << (this->trauma ? "Si" : "No") << "\n"
         << "Sintomas Neurologicos: " << (this->sintomasNeurologicos ? "Si" : "No") << "\n"
         << "Requiere Cirugia: " << (this->requiereCirugia ? "Si" : "No") << "\n"
         << "Dias Hospitalizacion: " << this->diasHospitalizacion << "\n"
         << "----------------------------------------" << endl;
}