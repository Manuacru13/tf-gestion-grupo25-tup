#include <iostream>
#include <cstring>  // para usar strcpy y strlen
#include "carga.h"
#include "structs.h"

using namespace std;

void cargarMarcas(Marca marcas[]) {
    cout << "\n--- CARGA DE MARCAS ---\n";
    int cantidad = 0;

    for (int i = 0; i < 2; i++) {
        int codigo;
        char nombre[30];

        cout <<endl;
        cout << "Marca #" << (i + 1) << endl;

        cout << "Codigo de marca (1 a 10): ";
        cin >> codigo;

        if (codigo < 1 || codigo > 2) {
            cout <<endl;
            cout << "Codigo invalido. Debe estar entre 1 y 10.\n";
            cout <<endl;
            cantidad = 0;
            system("pause");
            system("cls");
            return;  // salir de la carga
        }

        cout << "Nombre de la marca: ";
        cin.ignore();  // limpiar el buffer
        cin.getline(nombre, 30);

        if (strlen(nombre) == 0) {// devuelve la longitud del texto (string) que está almacenado en el array
            cout << "Nombre no puede estar vacío.\n";
            cantidad = 0;
            system("pause");
            system("cls");
            return;
        }

        marcas[i].codigo = codigo;
        strcpy(marcas[i].nombre, nombre);//copia una cadena de caracteres (un char[]) en otra.
        cantidad++;
    }

    cout << "\n Lote de marcas cargado correctamente.\n";
    cout<<endl;
    system("pause");
    system("cls");
}
