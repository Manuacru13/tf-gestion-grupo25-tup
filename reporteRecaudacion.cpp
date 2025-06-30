#include <iostream>
#include "structs.h"

using namespace std;

void reporteRecaudacionPorProducto(Producto productos[], int cantidadProductos, Venta ventas[], int cantidadVentas) {
    struct InfoProducto {
        int codigo;
        string nombre;
        float totalRecaudado;
        int cantidadVendida;
        int stockRestante;
    };

    InfoProducto resumen[20]; // Máximo 20 productos

    // Inicializamos el resumen
    for (int i = 0; i < cantidadProductos; i++) {
        resumen[i].codigo = productos[i].codigoProducto;
        resumen[i].nombre = productos[i].nombre;
        resumen[i].totalRecaudado = 0;
        resumen[i].cantidadVendida = 0;
        resumen[i].stockRestante = productos[i].stock;
    }

    // Calculamos recaudación y cantidad vendida por producto
    for (int i = 0; i < cantidadVentas; i++) {
        int codigo = ventas[i].codigoProducto;
        for (int j = 0; j < cantidadProductos; j++) {
            if (resumen[j].codigo == codigo) {
                resumen[j].cantidadVendida += ventas[i].cantidadVendida;
                resumen[j].totalRecaudado += ventas[i].cantidadVendida * productos[j].precioVenta;
                break;
            }
        }
    }

    // Ordenamos por cantidadVendida (burbujeo descendente)
    for (int i = 0; i < cantidadProductos - 1; i++) {
        for (int j = 0; j < cantidadProductos - i - 1; j++) {
            if (resumen[j].cantidadVendida < resumen[j + 1].cantidadVendida) {
                InfoProducto temp = resumen[j];
                resumen[j] = resumen[j + 1];
                resumen[j + 1] = temp;
            }
        }
    }

    // Mostramos el informe
    cout << "\n=== REPORTE: RECAUDACION POR PRODUCTO ===\n\n";
    cout << "COD\tNOMBRE\t\tRECAUDADO\tVENDIDO\tSTOCK\n";
    cout << "------------------------------------------------------\n";

    for (int i = 0; i < cantidadProductos; i++) {
        if (resumen[i].cantidadVendida > 0) {
            cout << resumen[i].codigo << "\t"
                 << resumen[i].nombre << "\t\t$"
                 << resumen[i].totalRecaudado << "\t"
                 << resumen[i].cantidadVendida << "\t"
                 << resumen[i].stockRestante << endl;
        }
    }

    cout << endl;
    system("pause");
    system("cls");
}


