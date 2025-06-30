#include <iostream>
#include "structs.h"
#include "reportes.h"

using namespace std;

void reporteRecaudacionPorProducto(Producto productos[], int cantidadProductos, Venta ventas[], int cantidadVentas)
{
    Resultado resultados[20]; // máximo 20 productos

    // Inicializar resultados
    for (int i = 0; i < cantidadProductos; i++) {
        resultados[i].codigoProducto = productos[i].codigoProducto;
        resultados[i].nombreProducto = productos[i].nombre;
        resultados[i].totalRecaudado = 0;
        resultados[i].cantidadVendida = 0;
        resultados[i].stockRemanente = productos[i].stock;
    }

    // Procesar ventas
    for (int i = 0; i < cantidadVentas; i++) {
        for (int j = 0; j < cantidadProductos; j++) {
            if (ventas[i].codigoProducto == resultados[j].codigoProducto) {
                resultados[j].cantidadVendida += ventas[i].cantidadVendida;
                resultados[j].totalRecaudado += ventas[i].cantidadVendida * productos[j].precioVenta;
            }
        }
    }

    // Ordenar por cantidadVendida (mayor a menor)
    for (int i = 0; i < cantidadProductos - 1; i++) {
        for (int j = i + 1; j < cantidadProductos; j++) {
            if (resultados[j].cantidadVendida > resultados[i].cantidadVendida) {
                Resultado aux = resultados[i];
                resultados[i] = resultados[j];
                resultados[j] = aux;
            }
        }
    }

    // Mostrar resultados
    cout << "\n=== RECAUDACION POR PRODUCTO ===\n";
    for (int i = 0; i < cantidadProductos; i++) {
        cout << "Codigo Producto: " << resultados[i].codigoProducto << endl;
        cout << "Nombre: " << resultados[i].nombreProducto << endl;
        cout << "Cantidad Vendida: " << resultados[i].cantidadVendida << endl;
        cout << "Total Recaudado: $" << resultados[i].totalRecaudado << endl;
        cout << "Stock Remanente: " << resultados[i].stockRemanente << endl;
        cout << "-----------------------------\n";
    }

    system("pause");
    system("cls");
}

void menuReportes(Producto productos[], int cantidadProductos, Venta ventas[], int cantidadVentas)
{
    int opcion;
    do {
        cout << "\n===== MENU DE REPORTES =====\n";
        cout << "1. Recaudacion por producto\n";
        cout << "2. (Pendiente) Porcentaje de ventas por forma de pago\n";
        cout << "3. (Pendiente) Ventas por marca y forma de pago\n";
        cout << "4. (Pendiente) Productos sin ventas\n";
        cout << "5. (Pendiente) Top 10 clientes + sorteo\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            reporteRecaudacionPorProducto(productos, cantidadProductos, ventas, cantidadVentas);
            break;
        case 0:
            cout << "Volviendo al menu principal...\n";
            system("pause");
            system("cls");
            return;
        default:
            cout << "Opcion invalida.\n";
            system("pause");
            system("cls");
        }
    } while (opcion != 0);
}

