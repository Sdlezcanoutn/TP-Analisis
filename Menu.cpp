#include "Menu.h"
using namespace std;

void menu() {
    system("cls");

    // PRESENTACION/PANTALLA DE INICIO
    cout << "==============================================\n";
    cout << "   PARCIAL 2 - ANALISIS DE DATOS\n";
    cout << "==============================================\n";
    cout << "Integrantes:\n";
    cout << "  - Garcia, Maria Lourdes\n";
    cout << "  - Lardo, Miguel Angel\n";
    cout << "  - Lezcano, Sol Danae" << endl << endl << endl;
    cout << "----------------------------------------------\n";
    cout << "         Materia: Analisis de Datos\n";
    cout << "----------------------------------------------\n";
    cout << "Este programa permite comparar plazos fijos\n";
    cout << "de tres bancos y determinar la mejor opcion\n";
    cout << "de inversion.\n" << endl << endl;
    system("pause");
    system("cls");

    // INGRESO DE CAPITAL (SOLICITUD AL USUARIO)
    float capital;
    do {
        cout << "Ingrese el capital a invertir: $";
        cin  >> capital;
        //validación
        if (capital <= 0) cout << "Error: el capital debe ser mayor que cero.\n";
    } while (capital <= 0);

    // LLAMADO A CARGA DE TASAS (SOLICITUD AL USUARIO)
    Banco bancos[CANT_BANCOS];
    cargarNombres(bancos);
    ingresarTasas(bancos);

    // MENU CON OPCIONES PARA TRABAJAR POST CAPITAL
    int opcion;
    do {
        system("cls");
        cout << "================== ELIJA LA OPCION DESEADA ==================\n";
        cout << "1) Ver resultados (rendimientos y recomendacion)\n";
        cout << "2) Ver tasas y promedios\n";
        cout << "0) Salir\n";
        cout << "------------------------------------------\n";
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");
        if (opcion == 1) {
            verResultados(bancos, capital);
            system("pause");
        } else if (opcion == 2) {
            verPromedios(bancos);
            system("pause");
        } else if (opcion == 0) {
            system("cls");
            cout << "Gracias por usar el programa.\n";
        } else {
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);
}
