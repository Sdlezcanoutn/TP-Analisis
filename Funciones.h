#pragma once
#include <string>
using namespace std;

// Constantes base
const int CANT_BANCOS = 3;
const int CANT_ANIOS  = 3;
const int ANIO_BASE   = 2025;

// Estructura básica
struct Banco {
    string nombre;
    float  tasas[CANT_ANIOS];  // 3 tasas históricas
    float  promedio;           // promedio de las tasas
};

// Prototipos
void cargarNombres(Banco bancos[]);
void ingresarTasas(Banco bancos[]);
void verPromedios(const Banco bancos[]);
void verResultados(const Banco bancos[], float capital);



