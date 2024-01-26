#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <string>
using namespace std;

class Producto
{
private:
    string nombre;
    float precio;
    bool oferta;
    int cantidad;

public:
    /*devuelve el nombre del producto*/
    string getNombre();

    /*devuelve el precio del producto*/
    float getPrecios();
    /*devuelve si hay alguna oferta en el producto*/
    bool getOferta();
    /*devuelve la cantidad de elementos de un producto*/
    int getCantidad();

    /*modivia la cantidad de elementos de un producto*/
    void setCantidad(int nuevCantidad);

    /* CONSTRUCTOR CON PARAMETROS
     pre: -
     pos: Inicializa el objeto Producto con nombre, precio, oferta y cantidad.*/
    Producto(string nombre, float precio, bool oferta, int cantidad);

    /* CONSTRUCTOR DE COPIA
     pre: -
     pos: Inicializa una copia de un objeto*/
    Producto(const Producto &Prod);
};
#endif