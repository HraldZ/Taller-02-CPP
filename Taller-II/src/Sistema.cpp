#include "../include/Sistema.h"
#include "../include/Lector.h"
#include <iostream>
#include <string>

using namespace std;

Sistema::Sistema() {
    this->cabezaServicios = nullptr;
    inicializarServicios();
    this->arbolDecision = new ArbolDecision();

    Lector lector;
    this->colaLista = lector.armarCola("pacientes.txt");
}

Sistema::~Sistema() {
    delete colaLista;
    delete arbolDecision;

    Servicio* actual = cabezaServicios;
    while (actual != nullptr) {
        Servicio* aBorrar = actual;
        actual = actual->siguiente;
        delete aBorrar;
    }
}

void Sistema::inicializarServicios() {
    string nombres[] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };
    Servicio* ultimo = nullptr;

    for (int i = 0; i < 8; i++) {
        Servicio* nuevo = new Servicio(nombres[i]);
        if (cabezaServicios == nullptr) {
            cabezaServicios = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }
}

Servicio* Sistema::buscarServicioPorNombre(string nombre) {
    Servicio* actual = cabezaServicios;
    while (actual != nullptr) {
        if (actual->getNombre() == nombre) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void Sistema::menuPrincipal() {
    int opcion = 0;
    do {
        cout << "\n=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamentos" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Eliminar paciente" << endl;
        cout << "5. Ver recorridos y metricas AVL" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccionar opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                atenderPaciente();
                break;
            case 2:
                verDepartamentos();
                break;
            case 3:
                buscarPaciente();
                break;
            case 4:
                eliminarPaciente();
                break;
            case 5:
                verMetricasYRecorridos();
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (opcion != 6);
}


void Sistema::atenderPaciente() {
    if (colaLista->estaVacia()) {
        cout << "\nNo hay pacientes en espera en la cola." << endl;
        return;
    }

    Paciente* p = colaLista->sacarDeCola();
    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
    cout << "ID: " << p->getId() << endl;
    cout << "Nombre: " << p->getNombre() << endl;
    cout << "Edad: " << p->getEdad() << endl;
    cout << "Temperatura: " << p->getTemperatura() << endl;
    cout << "Dolor: " << p->getDolor() << endl;
    cout << "TipoDolor: " << p->getTipoDolor() << endl;
    cout << "Trauma: " << (p->getTrauma() ? 1 : 0) << endl;
    cout << "SintomasNeurologicos: " << (p->getSintomasNeurologicos() ? 1 : 0) << endl;
    cout << "RequiereCirugia: " << (p->getRequiereCirugia() ? 1 : 0) << endl;
    cout << "DiasHospitalizacion: " << p->getDiasHospitalizacion() << endl;

    string ruta = "";
    string servicioAsignado = arbolDecision->evaluarPaciente(p, ruta);

    cout << "\nRuta: " << ruta << endl;
    cout << "Servicio asignado: " << servicioAsignado << endl;

    Servicio* s = buscarServicioPorNombre(servicioAsignado);
    if (s != nullptr) {
        s->agregarPaciente(p);
        cout << "Paciente insertado en el AVL de " << servicioAsignado << "." << endl;
    } else {
        cout << "Error: Servicio no encontrado en el sistema." << endl;
    }
}

void Sistema::verDepartamentos() {
    cout << "\n=== ESTADO DE LOS DEPARTAMENTOS ===" << endl;
    Servicio* actual = cabezaServicios;
    while (actual != nullptr) {
        actual->mostrarPacientes();
        cout << endl;
        actual = actual->siguiente;
    }
}

void Sistema::buscarPaciente() {
    cout << "\n=== BUSCAR PACIENTE ===" << endl;
    cout << "Indique el ID o Nombre del paciente: ";
    string termino;
    cin.ignore();
    getline(cin, termino);

    cout << "Buscando en AVL..." << endl;

    bool encontrado = false;
    Servicio* actual = cabezaServicios;

    while (actual != nullptr) {
        string rutaBusqueda = "";
        Paciente* p = actual->getArbol()->buscarPorId(termino, rutaBusqueda);
        if (p == nullptr) {

            p = actual->getArbol()->buscarPorNombre(termino);
            if (p != nullptr) {

                actual->getArbol()->buscarPorId(p->getId(), rutaBusqueda);
            }
        }

        if (p != nullptr) {
            cout << "\nPaciente encontrado:" << endl;
            cout << "-------" << endl;
            cout << "ID: " << p->getId() << endl;
            cout << "Nombre: " << p->getNombre() << endl;
            cout << "Edad: " << p->getEdad() << endl;
            cout << "Departamento: " << actual->getNombre() << endl;
            cout << "T: " << p->getTemperatura() << "° | D: " << p->getDolor()
                 << " | TD: " << p->getTipoDolor()
                 << " | T: " << (p->getTrauma() ? "Si" : "No")
                 << " | SN: " << (p->getSintomasNeurologicos() ? "Si" : "No")
                 << " | RC: " << (p->getRequiereCirugia() ? "Si" : "No")
                 << " | DH: " << p->getDiasHospitalizacion() << endl;
            cout << "-------" << endl;
            cout << "Ruta de busqueda:\n" << rutaBusqueda << endl;
            encontrado = true;
            break;
        }

        actual = actual->siguiente;
    }

    if (!encontrado) {
        cout << "Paciente no encontrado en ningun departamento." << endl;
    }
}

void Sistema::eliminarPaciente() {
    cout << "\n=== ELIMINAR PACIENTE ===" << endl;
    cout << "Indique el ID del paciente a eliminar: ";
    string id;
    cin >> id;

    bool eliminado = false;
    Servicio* actual = cabezaServicios;

    while (actual != nullptr) {
        string ruta = "";
        Paciente* p = actual->getArbol()->buscarPorId(id, ruta);
        if (p != nullptr) {
            actual->getArbol()->eliminar(id);
            cout << "Paciente con ID " << id << " eliminado correctamente de " << actual->getNombre() << "." << endl;
            eliminado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!eliminado) {
        cout << "No se encontro ningun paciente con ese ID para eliminar." << endl;
    }
}

void Sistema::verMetricasYRecorridos() {
    cout << "\n=== METRICAS Y RECORRIDOS ===" << endl;
    cout << "1. Ver metricas y recorridos de un Departamento (AVL)" << endl;
    cout << "2. Ver recorridos del Arbol de Decision" << endl;
    cout << "Seleccione: ";
    int sub;
    cin >> sub;

    if (sub == 1) {
        cout << "\nSeleccione departamento (1 a 8):" << endl;
        Servicio* actual = cabezaServicios;
        int i = 1;
        while (actual != nullptr) {
            cout << i << ". " << actual->getNombre() << endl;
            actual = actual->siguiente;
            i++;
        }
        int depNum;
        cin >> depNum;

        actual = cabezaServicios;
        for (int k = 1; k < depNum && actual != nullptr; k++) {
            actual = actual->siguiente;
        }

        if (actual != nullptr) {
            cout << "\n--- AVL " << actual->getNombre() << " ---" << endl;
            cout << "Altura del arbol: " << actual->getArbol()->getAltura() << endl;
            cout << "Factor de balance raiz: " << actual->getArbol()->getFactorBalanceRaiz() << endl;
            cout << "Recorrido Inorden: ";
            actual->getArbol()->mostrarInorden();
            cout << "Recorrido Preorden: ";
            actual->getArbol()->mostrarPreorden();
            cout << "Recorrido Postorden: ";
            actual->getArbol()->mostrarPostorden();
        } else {
            cout << "Departamento invalido." << endl;
        }
    } else if (sub == 2) {
        cout << "\n--- ARBOL DE DECISION ---" << endl;
        arbolDecision->mostrarPreorden();
        arbolDecision->mostrarInorden();
        arbolDecision->mostrarPostorden();
    }
}