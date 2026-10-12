#include <iostream>
#include "../include/Sistema.h"
#include "../include/Lector.h"
#include "../include/Cola.h"
#include "../include/Servicio.h"
#include <string>




using namespace std;


Sistema::Sistema(){
    this->cabezaServicios = nullptr;
    inicializarServicios();
    this->historial = new Pila();

    Lector lector;
    this->colaLista = lector.armarCola("pacientes.txt");
}

Sistema::~Sistema() {
    delete colaLista;
    Servicio* actual = cabezaServicios;
    delete historial;
    while (actual != nullptr) {
        Servicio* aBorrar = actual;
        actual = actual->siguiente;
        delete aBorrar;
    }
}


void Sistema::inicializarServicios() {
    string nombres[] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia", "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};
    Servicio* ultimo = nullptr;

    for (int i = 0; i < 8; i++) {
        Servicio* nuevoServicio = new Servicio(nombres[i]);
        if (cabezaServicios == nullptr) {
            cabezaServicios = nuevoServicio;
            ultimo = nuevoServicio;
        } else {
            ultimo->siguiente = nuevoServicio;
            ultimo = nuevoServicio;
        }
    }
}

//menu

void Sistema::menuPrincipal() {
    int opcion;
    do {
        opcion = 0;
        cout <<"-----Hospital---" << endl;
        cout << "1) Atender Pacientes" << endl;
        cout << "2) Ver Departamento" << endl;
        cout <<"3) Revisar Historial De Atencion" << endl;
        cout <<"4)Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuAtender();

                break;
            case 2:
                menuVerDepartamento();
                break;
            case 3:
                // historial
                //en esta cosa irá la pila dfjfjj
                historial->mostrarHistorial();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "opcion invalida" << endl;
        }
    } while (opcion != 4);
}


void Sistema::menuAtender() {
    int atenderP = 0;
    cout <<"---Pacientes en espera---" << endl;

    if(colaLista->estaVacia()){
        cout << "No hay pacientes." << endl;
        return;
    }

    colaLista->mostrar();





}

void Sistema::menuVerDepartamento() {
    int opcionDepartamento = 0;
    cout <<"--Departamentos/Servicios--" << endl;
    cout <<"1) Urgencias" << endl;
    cout <<"2) Medicina General"<< endl;
    cout <<"3) Cardiologia" << endl;
    cout <<"4) Neurologia" << endl;
    cout <<"5) Traumatologia" << endl;
    cout <<"6) Cirujia " << endl;
    cout <<"7) Pediatria" << endl;
    cout <<"8) Hospitalizacion" << endl;
    cin >> opcionDepartamento;

    if (opcionDepartamento >= 1 && opcionDepartamento <= 8) {
        Servicio* actual = cabezaServicios;
        for (int i = 1; i < opcionDepartamento; i++) {
            actual = actual->siguiente;
        }
        actual->mostrarPacientes();
    } else {
        cout << "Opcion invalida" << endl;
    }
}