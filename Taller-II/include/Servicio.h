#ifndef TALLER_I_CPP_SERVICIO_H
#define TALLER_I_CPP_SERVICIO_H

#include "Node.h"
#include <string>

using namespace std;

class Servicio {
private:
    string nombre;
    Node* cabezaPacientes;
    int cantidadPacientes;

public:
    Servicio* siguiente;

    Servicio(string nombre);
    ~Servicio();

    string getNombre();
    void agregarPaciente(Paciente* p);
    void mostrarPacientes();
};

#endif //TALLER_I_CPP_SERVICIO_H