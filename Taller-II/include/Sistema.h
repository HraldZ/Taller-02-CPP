#ifndef TALLER_I_CPP_SISTEMA_H
#define TALLER_I_CPP_SISTEMA_H

#include "Cola.h"
#include "Servicio.h"
#include "ArbolDecision.h"

class Sistema {
private:
    Cola* colaLista;
    Servicio* cabezaServicios;
    ArbolDecision* arbolDecision;

    Servicio* buscarServicioPorNombre(string nombre);

public:
    Sistema();
    ~Sistema();

    void inicializarServicios();
    void menuPrincipal();
    void atenderPaciente();
    void verDepartamentos();
    void buscarPaciente();
    void eliminarPaciente();
    void verMetricasYRecorridos();
};

#endif //TALLER_I_CPP_SISTEMA_H