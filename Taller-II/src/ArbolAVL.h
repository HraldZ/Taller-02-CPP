//
// Created by Main on 20/10/2026.
//
#include "../include/ArbolAVL.h"
#include <iostream>

using namespace std;

ArbolAVL::ArbolAVL() {
    this->raiz = nullptr;
}

ArbolAVL::~ArbolAVL() {
    destruirRecursivo(raiz);
}

void ArbolAVL::destruirRecursivo(NodoAVL* nodo) {
    if (nodo != nullptr) {
        destruirRecursivo(nodo->izquierdo);
        destruirRecursivo(nodo->derecho);
        //fokin liberrar memoria
        delete nodo->paciente;
        delete nodo;
    }
}

int ArbolAVL::obtenerAltura(NodoAVL* n) {
    if (n == nullptr) return 0;
    return n->altura;
}

int ArbolAVL::obtenerMaximo(int a, int b) {
    return (a > b) ? a : b;
}

//altura izquierdo - altura derecho
int ArbolAVL::obtenerBalance(NodoAVL* n) {
    if (n == nullptr) return 0;
    return obtenerAltura(n->izquierdo) - obtenerAltura(n->derecho);
}

// esto hace la rotacion pa la derecha
NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = obtenerMaximo(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = obtenerMaximo(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;

    return x;
}

//rotacion a la izquierd
NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x)
{
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = obtenerMaximo(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = obtenerMaximo(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;

    return y;
}

//insertar y rebalancear
NodoAVL* ArbolAVL::insertarRecursivo(NodoAVL* nodo, Paciente* p) {
    //insertamo
    if (nodo == nullptr) {
        return new NodoAVL(p);
    }

    if (p->getId() < nodo->paciente->getId()) {
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, p);
    } else if (p->getId() > nodo->paciente->getId()) {
        nodo->derecho = insertarRecursivo(nodo->derecho, p);
    } else {
        return nodo;
    }

    nodo->altura = 1 + obtenerMaximo(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    // rotar a la deerecha
    if (balance > 1 && p->getId() < nodo->izquierdo->paciente->getId()) {
        return rotacionDerecha(nodo);
    }

    //rotar a la izqueirda
    if (balance < -1 && p->getId() > nodo->derecho->paciente->getId()) {
        return rotacionIzquierda(nodo);
    }

    //esste es izquierda y luedo derecha
    if (balance > 1 && p->getId() > nodo->izquierdo->paciente->getId()) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    //al revez, dercha y depues izquiera
    if (balance < -1 && p->getId() < nodo->derecho->paciente->getId()) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }
    return nodo;
}

void ArbolAVL::insertar(Paciente* p) {
    raiz = insertarRecursivo(raiz, p);
}

NodoAVL* ArbolAVL::nodoConValorMinimo(NodoAVL* nodo) {
    NodoAVL* actual = nodo;
    while (actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

NodoAVL* ArbolAVL::eliminarRecursivo(NodoAVL* nodo, string id) {
    if (nodo == nullptr) return nodo;

    if (id < nodo->paciente->getId()) {
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, id);
    } else if (id > nodo->paciente->getId()) {
        nodo->derecho = eliminarRecursivo(nodo->derecho, id);
    } else {
        if ((nodo->izquierdo == nullptr) || (nodo->derecho == nullptr)) {
            NodoAVL* temp = nodo->izquierdo ? nodo->izquierdo : nodo->derecho;
            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            } else {
                *nodo = *temp;
            }
            delete temp->paciente;
            delete temp;
        } else {
            //si el nodo tiene 2 hijos se usa inorden
            NodoAVL* temp = nodoConValorMinimo(nodo->derecho);
            nodo->paciente = temp->paciente;
            nodo->derecho = eliminarRecursivo(nodo->derecho, temp->paciente->getId());
        }
    }

    if (nodo == nullptr) return nodo;

    nodo->altura = 1 + obtenerMaximo(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));
    int balance = obtenerBalance(nodo);

    if (balance > 1 && obtenerBalance(nodo->izquierdo) >= 0)
        return rotacionDerecha(nodo);
    if (balance > 1 && obtenerBalance(nodo->izquierdo) < 0) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    // dererecha
    if (balance < -1 && obtenerBalance(nodo->derecho) <= 0)
        return rotacionIzquierda(nodo);

    // derecha iazquierda
    if (balance < -1 && obtenerBalance(nodo->derecho) > 0) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }
    return nodo;
}

void ArbolAVL::eliminar(string id) {
    raiz = eliminarRecursivo(raiz, id);
}

Paciente* ArbolAVL::buscarPorIdRecursivo(NodoAVL* nodo, string id, string &ruta) {
    if (nodo == nullptr) return nullptr;

    if (ruta != "") ruta += " -> ";
    ruta += nodo->paciente->getId();

    if (id == nodo->paciente->getId()) {
        return nodo->paciente;
    }

    if (id < nodo->paciente->getId()) {
        return buscarPorIdRecursivo(nodo->izquierdo, id, ruta);
    } else {
        return buscarPorIdRecursivo(nodo->derecho, id, ruta);
    }
}

Paciente* ArbolAVL::buscarPorId(string id, string &ruta) {
    ruta = "";
    return buscarPorIdRecursivo(raiz, id, ruta);
}

Paciente* ArbolAVL::buscarPorNombreRecursivo(NodoAVL* nodo, string nombre) {
    if (nodo == nullptr) return nullptr;

    if (nodo->paciente->getNombre() == nombre) {
        return nodo->paciente;
    }

    Paciente* encontrado = buscarPorNombreRecursivo(nodo->izquierdo, nombre);
    if (encontrado != nullptr) return encontrado;

    return buscarPorNombreRecursivo(nodo->derecho, nombre);
}

Paciente* ArbolAVL::buscarPorNombre(string nombre) {
    return buscarPorNombreRecursivo(raiz, nombre);
}


int ArbolAVL::getAltura() {
    return obtenerAltura(raiz);
}

int ArbolAVL::getFactorBalanceRaiz() {
    return obtenerBalance(raiz);
}

bool ArbolAVL::estaVacio() {
    return raiz == nullptr;
}


void ArbolAVL::inordenRecursivo(NodoAVL* nodo) {
    if (nodo != nullptr) {
        inordenRecursivo(nodo->izquierdo);
        cout << nodo->paciente->getNombre() << " (" << nodo->paciente->getId() << ") ";
        inordenRecursivo(nodo->derecho);
    }
}

void ArbolAVL::mostrarInorden() {
    inordenRecursivo(raiz);
    cout << endl;
}

void ArbolAVL::preordenRecursivo(NodoAVL* nodo) {
    if (nodo != nullptr) {
        cout << nodo->paciente->getNombre() << " (" << nodo->paciente->getId() << ") ";
        preordenRecursivo(nodo->izquierdo);
        preordenRecursivo(nodo->derecho);
    }
}

void ArbolAVL::mostrarPreorden() {
    preordenRecursivo(raiz);
    cout << endl;
}

void ArbolAVL::postordenRecursivo(NodoAVL* nodo) {
    if (nodo != nullptr) {
        postordenRecursivo(nodo->izquierdo);
        postordenRecursivo(nodo->derecho);
        cout << nodo->paciente->getNombre() << " (" << nodo->paciente->getId() << ") ";
    }
}

void ArbolAVL::mostrarPostorden() {
    postordenRecursivo(raiz);
    cout << endl;
}