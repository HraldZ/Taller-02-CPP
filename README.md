# Taller-02-CPP

## Integrantes
Lucas Gonzalez - 223368956 - 67PooGod - ICCI - C1

Joan Zambra - 218869750 - HraldZ - ICCI - C1

## Diseño del Árbol de Decisión
### Esquema del Árbol

¿Edad < 14?
|-- Sí: Pediatría
|-- No:
    ¿Trauma == 1?
    |-- Sí:
    |   ¿RequiereCirugía == 1?
    |   |-- Sí: Cirugía
    |   |-- No: Traumatología
    |-- No:
        ¿SíntomasNeurológicos == 1?
        |-- Sí: Neurología
        |-- No:
            ¿TipoDolor == "pecho"?
            |-- Sí: Cardiología
            |-- No:
                ¿Temperatura >= 38.5 o Dolor >= 8?
                |-- Sí: Urgencias
                |-- No:
                    ¿DíasHospitalización >= 2?
                    |-- Sí: Hospitalización
                    |-- No: Medicina General

## Instrucciones de compilación

Abrir CMD, terminal o GitHub Codespaces en la carpeta raíz del proyecto `Taller-02-CPP` y ejecutar el siguiente comando:

### g++ -std=c++14 Taller-II/src/*.cpp -I Taller-II/include -o Taller.exe

---

## Instrucciones de ejecución

Luego de compilar, se puede abrir el taller ejecutando:

* En Windows:
### .\Taller.exe

* En Linux / Codespaces:
### ./Taller.exe

