#ifndef CARGA_H_INCLUDED
#define CARGA_H_INCLUDED
#include "structs.h"

void cargarMarcas(Marca marcas[], int &cantidad, bool &cargado);

void cargarProductos(Producto productos[], int &cantidadProductos, bool &productosCargados, Marca marcas[], int cantidadMarcas);



#endif // CARGA_H_INCLUDED
