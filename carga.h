#ifndef CARGA_H_INCLUDED
#define CARGA_H_INCLUDED
#include "structs.h"

void cargarMarcas(Marca marcas[], int &cantidad, bool &cargado);

void cargarProductos(Producto productos[], int &cantidadProductos, bool &productosCargados, Marca marcas[], int cantidadMarcas);

void cargarFormasPago(FormaPago formas[], bool &cargado, int &cantidad);

void cargarVentas(Producto productos[], int cantidadProductos, FormaPago formas[], int cantidadFormas);



#endif // CARGA_H_INCLUDED
