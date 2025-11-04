#include <iostream>
#include <cstdlib>
#include "Menu.h"
using namespace std;

void menu() {
    system("cls");

    // PANTALLA DE INICIO!
    cout << "==============================================\n";
    cout << "   TRABAJO PRACTICO 2 - ANALISIS DE DATOS\n";
    cout << "==============================================\n";
    cout << "Integrantes:\n";
    cout << "  - Garcia, Maria Lourdes\n";
    cout << "  - Lardo, Miguel Angel\n";
    cout << "  - Lezcano, Sol" << endl << endl << endl;
    cout << "----------------------------------------------\n";
    cout << "         Materia: Analisis de Datos\n";
    cout << "----------------------------------------------\n";
    cout << "Este programa permite comparar plazos fijos\n";
    cout << "de tres bancos y determinar la mejor opcion\n";
    cout << "de inversion.\n" << endl << endl;
    system("pause");
    system("cls");

    // CARGA DE DATOS ANTES DE TRABAJAR CON ELLOS
    int opcion;
    Banco vBancos[CANTIDAD_BANCOS];

    cargarNombreBancos(vBancos);
    cargarTasaAnual(vBancos);

    // MENU CON OPCIONES PARA TRABAJAR
    do {
        system("cls");
        cout << "==============================================\n";
        cout << "         ELIJE LA OPCION QUE DESEES\n";
        cout << "==============================================\n";
        cout << "1. Ver rendimientos (Anual / Trimestral / Mensual)\n";
        cout << "2. Ver promedios de tasas\n";
        cout << "0. Salir\n";
        cout << "----------------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");
        if (opcion == 1) {
            mostrarRendimientos(vBancos);
            system("pause");
        } else if (opcion == 2) {
            mostrarPromedios(vBancos);
            system("pause");
        } else if (opcion == 0) {
            system("cls");
            cout << "Gracias por usar el programa." << endl << endl;
        } else {
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);
}
