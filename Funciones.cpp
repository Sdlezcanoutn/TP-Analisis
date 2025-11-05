#include <iostream>
#include <iomanip>   // para fixed
#include "Funciones.h"
using namespace std;

const string NOMBRES_FIJOS[CANT_BANCOS] = {"Provincia", "Nacion", "Hipotecario"};

// ACA CARGAMOS LOS NOMBRES DE LOS BANCOS YA ESTIPULADOS
void cargarNombres(Banco bancos[]) {
    for (int i = 0; i < CANT_BANCOS; i++) {
        bancos[i].nombre = NOMBRES_FIJOS[i];
    }
}

// ACA PEDIMOS LOS 3 VALORES HISTORICOS POR BANCO
void ingresarTasas(Banco bancos[]) {
    for (int i = 0; i < CANT_BANCOS; i++) {
        cout << "\nBanco: " << bancos[i].nombre << "\n";
        float suma = 0.0f;

        // 3 ANUALES
        for (int j = 0; j < CANT_ANIOS; j++) {
            int anio = ANIO_BASE - (CANT_ANIOS - 1 - j);  // años más viejos primero
            do {
                cout << "  Tasa anual (%) " << anio << ": ";
                cin  >> bancos[i].tasas[j];
                if (bancos[i].tasas[j] < 0 || bancos[i].tasas[j] > 100) {
                    cout << "  Error: ingrese un valor entre 0 y 100.\n";
                }
            } while (bancos[i].tasas[j] < 0 || bancos[i].tasas[j] > 100);

            suma += bancos[i].tasas[j];  // SUMAMOS
        }

        bancos[i].promedio = suma / CANT_ANIOS;  // HACEMOS PROMEDIO
    }
}

// ACA MOSTRAMOS LAS TASAS Y PROMEDIOS POR BANCO
void verPromedios(const Banco bancos[]) {
    cout << fixed; //PARA QUE NO SALGA CON NOTACION CIENTIFICA
    cout << "\n=== Tasas y promedios por banco ===\n";
    for (int i = 0; i < CANT_BANCOS; i++) {
        cout << "- " << bancos[i].nombre << "\n  Tasas: ";
        for (int j = 0; j < CANT_ANIOS; j++) {
            cout << bancos[i].tasas[j];
            if (j < CANT_ANIOS - 1) cout << " | ";
        }
        cout << "\n  Promedio: " << bancos[i].promedio << "%\n\n";
    }
}

// CALCALAMOS POR ANUAL, TRIMESTRAL Y MENSUAL, DESPUES SE RECOMIENDO LA MEJOR OPCION
void verResultados(const Banco bancos[], float capital) {
    cout << fixed; //OTRA VEZ POR LA N. CIENTIFICA
    cout << "\n=========== Resultados de inversion ===========\n";

    float mejorMonto = -1.0f;
    string mejorBanco = "";
    string mejorModo  = "";

    for (int i = 0; i < CANT_BANCOS; i++) {
        float i_anual = bancos[i].promedio / 100.0f; // porcentaje a decimal

        // ANUAL (1)
        float final_anual = capital + capital * i_anual;
        float gan_anual   = final_anual - capital;

        // TRIMESTRAL (4)
        float final_trim = capital;
        for (int t = 0; t < 4; t++) {
            final_trim += final_trim * (i_anual / 4.0f);
        }
        float gan_trim = final_trim - capital;

        // MENSUAL (12) (TIP: SIEMPRE VA A SER LA MEJOR OPCION)
        float final_mens = capital;
        for (int m = 0; m < 12; m++) {
            final_mens += final_mens * (i_anual / 12.0f);
        }
        float gan_mens = final_mens - capital;

        cout << "\nBanco: " << bancos[i].nombre << "\n";
        cout << "  Anual      -> Final: $" << final_anual << " | Ganancia: $" << gan_anual << "\n";
        cout << "  Trimestral -> Final: $" << final_trim  << " | Ganancia: $" << gan_trim  << "\n";
        cout << "  Mensual    -> Final: $" << final_mens  << " | Ganancia: $" << gan_mens  << "\n";

        // ACA COMPARAMOS Y GUARDAMOS LA MEJOR OPCION
        if (final_anual > mejorMonto) { mejorMonto = final_anual; mejorBanco = bancos[i].nombre; mejorModo = "Anual"; }
        if (final_trim  > mejorMonto) { mejorMonto = final_trim;  mejorBanco = bancos[i].nombre; mejorModo = "Trimestral"; }
        if (final_mens  > mejorMonto) { mejorMonto = final_mens;  mejorBanco = bancos[i].nombre; mejorModo = "Mensual"; }
    }

    cout << "\n----------------------------------------------\n";
    cout << "Recomendacion: " << mejorModo << " en " << mejorBanco
         << " | Monto final: $" << mejorMonto << "\n\n";
}
