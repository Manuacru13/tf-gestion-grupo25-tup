#include <iostream>
#include <cstring>
#include "structs.h"
#include "carga.h"

using namespace std;


void cargarMarcas(Marca marcas[], int &cantidad, bool &cargado) {
    cout << "\n--- CARGA DE MARCAS ---\n";

    for (int i = 0; i < 2; i++) {
        int codigo;
        char nombre[30];

        cout << endl;
        cout << "Marca #" << (i + 1) << endl;

        cout << "Ingresa codigo de marca (de 1 a 10): ";
        cin >> codigo;

        if (codigo < 1 || codigo > 10) {
            cout << "Codigo invalido. Debe estar entre 1 y 10.\n";
            cantidad = 0;
            cargado = false;
            system("pause");
            system("cls");
            return;
        }

        cout << "Nombre de la marca: ";
        cin.ignore();  // limpiar buffer
        cin.getline(nombre, 30);

        if (strlen(nombre) == 0) {
            cout << "Nombre no puede estar vac�o.\n";
            cantidad = 0;
            cargado = false;
            system("pause");
            system("cls");
            return;
        }

        marcas[i].codigo = codigo;
        strcpy(marcas[i].nombre, nombre);
        cantidad++;
    }

    cargado = true;
    cout << "\nLote de marcas cargado correctamente.\n";
    system("pause");
    system("cls");
}

void cargarProductos(Producto productos[], int &cantidadProductos, bool &productosCargados, Marca marcas[], int cantidadMarcas) {
    if (!cantidadMarcas) {
        cout << "No se han cargado marcas. Debe cargar el lote de marcas antes.\n";
        system("pause");
        system("cls");
        return;
    }

    if (productosCargados) {
        cout << "Ya se cargaron los productos.\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n--- CARGA DE PRODUCTOS ---\n";

    for (int i = 0; i < 2; i++) {
        Producto p;

        cout << "\nProducto #" << i + 1 << endl;

        cout << "Codigo de producto (3 digitos): ";
        cin >> p.codigoProducto;
        if (p.codigoProducto < 100 || p.codigoProducto > 999) {
            cout << "Codigo invalido. Debe tener 3 digitos.\n";
            cantidadProductos = 0;
            system("pause");
            system("cls");
            return;
        }

        cout << "Nombre del producto: ";
        cin.ignore();
        cin.getline(p.nombre, 30);
        if (strlen(p.nombre) == 0) {
            cout << "El nombre no puede estar vac�o.\n";
            cantidadProductos = 0;
            system("pause");
            system("cls");
            return;
        }

        cout << "Precio de venta: ";
        cin >> p.precioVenta;
        if (p.precioVenta <= 0) {
            cout << "El precio debe ser mayor a 0.\n";
            cantidadProductos = 0;
            system("pause");
            system("cls");
            return;
        }

        cout << "Precio de compra: ";
        cin >> p.precioCompra;
        if (p.precioCompra <= 0) {
            cout << "El precio debe ser mayor a 0.\n";
            cantidadProductos = 0;
            system("pause");
            system("cls");
            return;
        }

        cout << "Stock disponible: ";
        cin >> p.stock;
        if (p.stock <= 0) {
            cout << "El stock debe ser mayor a 0.\n";
            cantidadProductos = 0;
            system("pause");
            system("cls");
            return;
        }

        cout << "Codigo de marca: ";
        cin >> p.codigoMarca;

        bool marcaExiste = false;
        for (int j = 0; j < cantidadMarcas; j++) {
            if (p.codigoMarca == marcas[j].codigo) {
                marcaExiste = true;
                break;
            }
        }

        if (!marcaExiste) {
            cout << "Codigo de marca no encontrado. No se puede continuar.\n";
            cantidadProductos = 0;
            system("pause");
            system("cls");
            return;
        }

        productos[i] = p;
        cantidadProductos++;
    }

    productosCargados = true;
    cout << "\nProductos cargados correctamente.\n";
    system("pause");
    system("cls");
}

void cargarFormasPago(FormaPago formas[], bool &formasCargadas, int &cantidadFormas) {
    if (formasCargadas) {
        cout << "Ya se cargaron las formas de pago.\n";
        system("pause");
        system("cls");
        return;
    }

    const char* codigosValidos[] = {"EF", "MP", "TR", "TC", "CT"};
    bool codigoUsado[5] = {false};

    cout << "\n--- CARGA DE FORMAS DE PAGO ---\n";

    while (cantidadFormas < 5) {
        FormaPago f;
        char codigoIngresado[3];

        cout << "\nForma de pago #" <<(cantidadFormas + 1) << endl;
        cout << "Codigo (EF, MP, TR, TC, CT): ";
        cin >> codigoIngresado;

        bool valido = false;
        for (int j = 0; j < 5; j++) {
            if (strcmp(codigoIngresado, codigosValidos[j]) == 0 && !codigoUsado[j]) {
                strcpy(f.codigo, codigoIngresado);
                codigoUsado[j] = true;
                valido = true;
                break;
            }
        }

        if (!valido) {
            cout << "Codigo invalido o repetido. Solo se permite uno de: EF, MP, TR, TC, CT.\n";
            cantidadFormas = 0;
            formasCargadas = false;
            system("pause");
            system("cls");
            return;
        }

        cout << "Nombre de la forma de pago: ";
        cin.ignore();
        cin.getline(f.nombre, 30);

        if (strlen(f.nombre) == 0) {
            cout << "El nombre no puede estar vac�o.\n";
            cantidadFormas = 0;
            formasCargadas = false;
            system("pause");
            system("cls");
            return;
        }

       cout << "Porcentaje de descuento/interes (negativo = descuento, positivo = interes): ";
        cin >> f.porcentaje;

        if (f.porcentaje == 0 || f.porcentaje < -100 || f.porcentaje > 100) {
            cout << "Porcentaje invalido. Debe estar entre -100 y 100 y no puede ser 0.\n";
            cantidadFormas = 0;
            formasCargadas = false;
            system("pause");
            system("cls");
            return;
        }
        formas[cantidadFormas] = f;
        cantidadFormas++;

         if (cantidadFormas < 5) {
            char opcion;
            cout << "�Deseas cargar otra forma de pago? (S/N): ";
            cin >> opcion;

            if (toupper(opcion) != 'S') {
                break;
            }
        }
    }

    formasCargadas = true;
    cout << "\n Formas de pago cargadas correctamente.\n";
    system("pause");
    system("cls");
}

