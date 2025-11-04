#include <iostream>
#include "Funciones.h"
using namespace std;

const string NOMBRE_BANCOS[CANTIDAD_BANCOS] = {"Provincia", "Nacion", "Hipotecario"};

void cargarNombreBancos(Banco vBancos[]) {
    for (int i = 0; i < CANTIDAD_BANCOS; i++) {
        vBancos[i].nombre = NOMBRE_BANCOS[i];
    }
}

void cargarTasaAnual(Banco vBancos[]) {
    for (int i = 0; i < CANTIDAD_BANCOS; i++) {
        cout << "\nIngrese las tasas anuales (%) de los ultimos " << CANTIDAD_ANIOS
             << " anios para el Banco " << vBancos[i].nombre << ":\n";
        float suma = 0;
        for (int j = 0; j < CANTIDAD_ANIOS; j++) {
            cout << "  Anio " << (ANIO_ACTUAL - j) << ": ";
            cin >> vBancos[i].tasasAnual[j];
            suma += vBancos[i].tasasAnual[j];
        }
        vBancos[i].promedio = suma / CANTIDAD_ANIOS;
    }
}

void mostrarPromedios(Banco vBancos[]) {
    cout << fixed;
    cout << "\nPromedios de tasas anuales por banco:\n";
    cout << "-------------------------------------\n";
    for (int i = 0; i < CANTIDAD_BANCOS; i++) {
        cout << "Banco: " << vBancos[i].nombre << "\n";
        cout << "  Tasas ingresadas: ";
        for (int j = 0; j < CANTIDAD_ANIOS; j++) {
            cout << vBancos[i].tasasAnual[j];
            if (j < CANTIDAD_ANIOS - 1) cout << " | ";
        }
        cout << "\n  Promedio: " << vBancos[i].promedio << "%\n\n";
    }
}

void mostrarRendimientos(Banco vBancos[]) {
    cout << fixed;
    cout << "\nRendimientos obtenidos:\n";
    cout << "-----------------------\n";

    float mejorMonto = 0;
    string mejorBanco = "";
    string mejorModo = "";

    for (int i = 0; i < CANTIDAD_BANCOS; i++) {
        float i_anual = vBancos[i].promedio / 100.0f;

        // Anual (1 año)
        float gan_anual = CAPITAL_INICIAL * i_anual;
        float final_anual = CAPITAL_INICIAL + gan_anual;

        // Trimestral (4 con reinversion, usando i_anual/4)
        float capital_trim = CAPITAL_INICIAL;
        for (int t = 1; t <= 4; t++) {
            float ganancia_trim = capital_trim * (i_anual / 4.0f);
            capital_trim += ganancia_trim;
        }
        float final_trim = capital_trim;
        float gan_trim = final_trim - CAPITAL_INICIAL;

        // Mensual (12 con reinversion, usando i_anual/12)
        float capital_mens = CAPITAL_INICIAL;
        for (int m = 1; m <= 12; m++) {
            float ganancia_mens = capital_mens * (i_anual / 12.0f);
            capital_mens += ganancia_mens;
        }
        float final_mens = capital_mens;
        float gan_mens = final_mens - CAPITAL_INICIAL;

        cout << "\nBanco: " << vBancos[i].nombre << "\n";
        cout << "Promedio anual de tasa: " << vBancos[i].promedio << "%\n";
        cout << "  Anual -> Monto final: $" << final_anual << " | Ganancia: $" << gan_anual << "\n";
        cout << "  Trimestral -> Monto final: $" << final_trim << " | Ganancia: $" << gan_trim << "\n";
        cout << "  Mensual -> Monto final: $" << final_mens << " | Ganancia: $" << gan_mens << "\n";

        if (final_anual > mejorMonto) { mejorMonto = final_anual; mejorBanco = vBancos[i].nombre; mejorModo = "Anual"; }
        if (final_trim  > mejorMonto) { mejorMonto = final_trim;  mejorBanco = vBancos[i].nombre; mejorModo = "Trimestral"; }
        if (final_mens  > mejorMonto) { mejorMonto = final_mens;  mejorBanco = vBancos[i].nombre; mejorModo = "Mensual"; }
    }

    cout << "\n-----------------------\n";
    cout << "Recomendacion: " << mejorModo << " en Banco " << mejorBanco
         << " con monto final $" << mejorMonto << endl << endl;
}
