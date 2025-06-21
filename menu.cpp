//#include "reportes.h"
#include <iostream>
#include "menu.h"
#include "structs.h"
#include "carga.h"

using namespace std;

void menuPrincipal()
{

    //lote carga
    Marca marcas[2];
    int opcion;
    do
    {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
         cout <<endl;
        cout << "1. Cargar marcas" << endl;
        cout << "2. Cargar productos" << endl;
        cout << "3. Cargar formas de pago" << endl;
        cout << "4. Cargar ventas" << endl;
        cout << "0. Salir" << endl;
        cout <<endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cargarMarcas(marcas);
            break;
        case 2:
            // mostrarReportes();
            break;
        case 0:
            cout << "Gracias por usar el sistema.\n";
            break;
        default:
            cout << "Opcion no valida.\n";
            system("pause");
            system("cls");
        }
    }
    while (opcion != 0);
}

