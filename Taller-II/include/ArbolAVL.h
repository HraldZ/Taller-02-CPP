//
// Created by Main on 20/10/2026.
//


#pragma once
#include "NodoAVL.h"
#include <string>

using namespace std;

class ArbolAVL {
private:
    NodoAVL* raiz;


    int obtenerAltura(NodoAVL* n);
    int obtenerMaximo(int a, int b);
    int obtenerBalance(NodoAVL* n);
    NodoAVL* nodoConValorMinimo(NodoAVL* nodo);

    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);
    
    NodoAVL* insertarRecursivo(NodoAVL* nodo, Paciente* p);
    NodoAVL* eliminarRecursivo(NodoAVL* nodo, string id);
    Paciente* buscarPorIdRecursivo(NodoAVL* nodo, string id, string &ruta);
    Paciente* buscarPorNombreRecursivo(NodoAVL* nodo, string nombre);

    void inordenRecursivo(NodoAVL* nodo);
    void preordenRecursivo(NodoAVL* nodo);
    void postordenRecursivo(NodoAVL* nodo);
    void destruirRecursivo(NodoAVL* nodo);

public:
    ArbolAVL();
    ~ArbolAVL();

    void insertar(Paciente* p);
    void eliminar(string id);
    Paciente* buscarPorId(string id, string &ruta);
    Paciente* buscarPorNombre(string nombre);

    int getAltura();
    int getFactorBalanceRaiz();

    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();
    bool estaVacio();
};