cmake_minimum_required(VERSION 4.3)
project(taller2)

set(CMAKE_CXX_STANDARD 14)

include_directories(Taller-II/include)
include_directories(Taller-II/src)

add_executable(taller2
        Taller-II/include/Cola.h
        Taller-II/include/Lector.h
        Taller-II/include/Node.h
        Taller-II/include/Paciente.h
        Taller-II/include/Persona.h
        Taller-II/include/Pila.h
        Taller-II/include/Servicio.h
        Taller-II/include/Sistema.h
        Taller-II/src/Cola.cpp
        Taller-II/src/Lector.cpp
        Taller-II/src/main.cpp
        Taller-II/src/Node.cpp
        Taller-II/src/Paciente.cpp
        Taller-II/src/Persona.cpp
        Taller-II/src/Pila.cpp
        Taller-II/src/Servicio.cpp
        Taller-II/src/Sistema.cpp
        pacientes.txt
        Taller-II/include/NodoDecision.h
        Taller-II/include/ArbolDecision.h
        Taller-II/src/ArbolDecision.cpp)
