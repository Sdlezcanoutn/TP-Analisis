#pragma once
#include <string>
using namespace std;

// Constantes
const int CANTIDAD_BANCOS = 3;
const int CANTIDAD_ANIOS  = 3;
const float CAPITAL_INICIAL = 850000.0f;
const int ANIO_ACTUAL = 2025;

// Estructura
struct Banco {
    string nombre;
    float tasasAnual[CANTIDAD_ANIOS];
    float promedio;
};

// Prototipos
void cargarNombreBancos(Banco vBancos[]);
void cargarTasaAnual(Banco vBancos[]);
void mostrarPromedios(Banco vBancos[]);
void mostrarRendimientos(Banco vBancos[]);

