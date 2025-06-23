#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED


struct Marca {
    int codigo;
    char nombre[30];
};

struct Producto {
    int codigoProducto;      // 3 dígitos, no consecutivos
    char nombre[30];         // Nombre del producto
    float precioVenta;
    float precioCompra;
    int stock;
    int codigoMarca;         // Debe coincidir con una marca cargada
};

struct FormaPago {
    char codigo[3];      // EF, MP, TR, TC, CT
    char nombre[30];     // Efectivo, etc.
    int porcentaje;      // Positivo (interés), negativo (descuento)
};


#endif // STRUCTS_H_INCLUDED
