#ifndef TALLER_I_CPP_SERVICIO_H
#define TALLER_I_CPP_SERVICIO_H

#include "ArbolAVL.h"
#include "Paciente.h"
#include <string>

using namespace std;

class Servicio {
private:
    string nombre;
    ArbolAVL* arbolPacientes;
    int cantidadPacientes;

public:
    Servicio* siguiente;

    Servicio(string nombre);
    ~Servicio();

    string getNombre();
    int getCantidadPacientes();
    void agregarPaciente(Paciente* p);
    void mostrarPacientes();
    ArbolAVL* getArbol();
};

#endif //TALLER_I_CPP_SERVICIO_H