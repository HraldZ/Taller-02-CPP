//
// Created by joanj on 08-09-2026.
//
#include "Paciente.h"
#include "Cola.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Lector.h"
using namespace std;

Lector::Lector(){}

// hay que armar la queue con nodos


Cola* Lector::armarCola(string ruta) {
    Cola* cola = new Cola();
    char separador = ';';
    ifstream archivo(ruta);
    string linea;
    if (!archivo.is_open()) {
        cout << " Archivo no abierto ERROR" << endl;
    }
    while (getline(archivo,linea)) {
        stringstream ss(linea);
        string id,nombre , tipoDolor , edadS, dolorS, traumaS , sintomasNeurologicosS , requiereCirujiaS , diasHospitalizacionS ,temperaturaS , presionArterialS;

        getline(ss,id,separador);
        getline(ss,nombre,separador);
        getline(ss,edadS,separador);
        getline(ss,temperaturaS,separador);
        getline(ss,presionArterialS,separador);
        getline(ss,dolorS,separador);
        getline(ss,tipoDolor ,separador);
        getline(ss,traumaS,separador);
        getline(ss,sintomasNeurologicosS,separador);
        getline(ss,requiereCirujiaS,separador);
        getline(ss,diasHospitalizacionS,separador);

        int edad;
        float temperatura;
        int presionArterial;
        int dolor;
        bool trauma;
        bool sintomasNeurologicos;
        bool requiereCirujia;
        int diasHospitalizacion;

        try {
            edad = stoi(edadS);
            temperatura = stof(temperaturaS);
            dolor = stoi(dolorS);
            presionArterial = stoi(presionArterialS);

            //pregunta si el int valor trauma es igual a 1 si es igual manda un true sino false.
            int  valorTrauma = stoi(traumaS);
            trauma =  ( valorTrauma == 1);

            int valorSintomas = stoi(sintomasNeurologicosS);
            sintomasNeurologicos = (valorSintomas == 1);

            int valorCirujia = stoi(requiereCirujiaS);
            requiereCirujia = (valorCirujia == 1);

            diasHospitalizacion = stoi(diasHospitalizacionS);

        }catch (invalid_argument& e) {
            cout<< "Error de formato. texto a numero" << endl;
        }catch ( out_of_range& e) {
            cout << "error de rango numero muy grande" << endl;
        }catch (exception& e) {
            cout << "otro error" << endl;
        }

        Paciente* paciente = new Paciente(id,nombre,edad,temperatura,presionArterial , dolor, tipoDolor, trauma,sintomasNeurologicos , requiereCirujia , diasHospitalizacion);
        cola->encolar(paciente);
    }
    archivo.close();
    return cola;

}





















