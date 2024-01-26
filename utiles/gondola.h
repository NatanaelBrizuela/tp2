#ifndef GONDOLA_H
#define GONDOLA_H
#include "Productos.h"

class Gondola
{
private:
    int capacidad;
    int cantProductos;
    Producto **productosEnGondola;

public:
    /*CREADOR CON PARAMETROS*/
    Gondola(int capacidad, int cantProductos);
    /*CONSTRUCTOR DE COPIA*/
    Gondola(const Gondola &P);

    /*DESTRUCTOR*/
    ~Gondola();

    /* pre:-
     pos: devuelve el puntero de producto si el indice existe;*/
    Producto *getProductoI(int i) const;

    /*AGREGA PRODUCTOS A LA GONDOLA
    pre:-
    pos: agrega un producto ala gondola, si la gondola se llena, se duplica la capacidad*/
    void agregarProducto(const string nombre, float precio, bool oferta, int cantidad);

    // MUESTRA EL CONTENDIO DE LA GONDOLA
    void mostrar();

    // quitar producto
    void quitarProductoGondola(int indice);

    // swap
    void swap(int indice);

    void borrarAux(Producto **auxiliar, int cantProductos);

    Producto *getProductoI(int i); // no se si sirve

    /*devuelve la cantidad de productos dentro de la gondola*/
    int getCantProductos();
    /*devuelve en nombre del producot guardado en la posicion 'indice'  */
    string getNombreEnGodnola(int indice);
    /*devuelve el precio de un producto guardado en la posicion 'indice*/
    float getPrecioEnGodnola(int indice);
    /*devuelve el precio del producto guardado en la posicion 'indice'*/
    bool GetOfertaEnGondola(int indice);
    /*devuelve la cantidad de elementos del producto guardado en la posicion 'indice'*/
    int getCantProductEnGodnola(int indice);

    /*cambia la cantidad de elementos de un producto de la gondola en la posicion 'indice'
    por 'nuevaCantidad'*/
    void setCantidadGondola(int nuevCantidad, int indice);
};

#endif
