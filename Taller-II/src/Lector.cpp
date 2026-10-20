#include "../include/Paciente.h"
#include "../include/Cola.h"
#include "../include/Lector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Lector::Lector() {}

Cola* Lector::armarCola(string ruta) {
    Cola* cola = new Cola();
    char separador = ';';
    ifstream archivo(ruta);

    //abrir archivo y ver si es valido
    if (!archivo.is_open()) {
        cout << "no se pudo abrir el archivo " << ruta << endl;
        return cola;
    }

    string linea;
    int numeroLinea = 0;

    while (getline(archivo, linea)) {
        numeroLinea++;

       //esto se salta las lineas vacias
        if (linea == "" || linea == "\r") {
            continue;
        }

        stringstream ss(linea);
        string id, nombre, edadS, tempS, presionS, dolorS, tipoDolor;
        string traumaS, neuroS, cirugiaS, hospS;

       //sacar las partes
        getline(ss, id, separador);
        getline(ss, nombre, separador);
        getline(ss, edadS, separador);
        getline(ss, tempS, separador);
        getline(ss, presionS, separador);
        getline(ss, dolorS, separador);
        getline(ss, tipoDolor, separador);
        getline(ss, traumaS, separador);
        getline(ss, neuroS, separador);
        getline(ss, cirugiaS, separador);
        getline(ss, hospS, separador);

       //ver si hay espacios vacios
        if (id == "" || nombre == "" || edadS == "" || tempS == "" ||
            presionS == "" || dolorS == "" || tipoDolor == "" ||
            traumaS == "" || neuroS == "" || cirugiaS == "" || hospS == "") {
            cout << "Linea " << numeroLinea << " fallada, faltan datos" << endl;
            continue;
        }

        if (cola->existeId(id)) {
            cout << "Linea " << numeroLinea << ", el paciente con ID " << id << " ya existe." << endl;
            continue;
        }

        int edad = 0;
        float temperatura = 0.0;
        float presion = 0.0;
        int dolor = 0;
        int traumaNum = 0;
        int neuroNum = 0;
        int cirugiaNum = 0;
        int diasHosp = 0;

        try {
            edad = stoi(edadS);
            temperatura = stof(tempS);
            presion = stof(presionS);
            dolor = stoi(dolorS);
            traumaNum = stoi(traumaS);
            neuroNum = stoi(neuroS);
            cirugiaNum = stoi(cirugiaS);
            diasHosp = stoi(hospS);
        } catch (...) {
            cout << "Linea " << numeroLinea << ", formato invalido" << id << endl;
            continue;
        }

        if (edad < 0 || temperatura <= 0 || presion <= 0 || diasHosp < 0) {
            cout << "Linea " << numeroLinea << ", valores fuera de rango" << endl;
            continue;
        }

        if (dolor < 0 || dolor > 10) {
            cout << "Linea " << numeroLinea << ", valores fuera de rango" << endl;
            continue;
        }

        if ((traumaNum != 0 && traumaNum != 1) ||
            (neuroNum != 0 && neuroNum != 1) ||
            (cirugiaNum != 0 && cirugiaNum != 1)) {
            cout << "Linea " << numeroLinea << ", valores fuera de rango" << endl;
            continue;
        }

        if (tipoDolor != "pecho" && tipoDolor != "cabeza" &&
            tipoDolor != "abdomen" && tipoDolor != "extremidad" &&
            tipoDolor != "otro") {
            cout << "Linea " << numeroLinea << ", tipo de dolor no valido (" << tipoDolor << ")." << endl;
            continue;
        }

        bool trauma = (traumaNum == 1);
        bool sintomasNeurologicos = (neuroNum == 1);
        bool requiereCirugia = (cirugiaNum == 1);

        Paciente* paciente = new Paciente(
            id, nombre, edad, temperatura, presion,
            dolor, tipoDolor, trauma, sintomasNeurologicos,
            requiereCirugia, diasHosp
        );

        cola->encolar(paciente);
    }

    archivo.close();
    return cola;
}