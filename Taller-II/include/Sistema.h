#ifndef TALLER_I_CPP_SISTEMA_H
#define TALLER_I_CPP_SISTEMA_H

#include "Cola.h"
#include "Servicio.h"
#include "Pila.h"

class Sistema {
private:
    Cola* colaLista;
    Servicio* cabezaServicios;
    Pila* historial;

public:
    Sistema();
    ~Sistema();

    void inicializarServicios();
    void menuPrincipal();
    void menuAtender();
    void menuVerDepartamento();
};

#endif //TALLER_I_CPP_SISTEMA_H