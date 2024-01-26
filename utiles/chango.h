#ifndef CHANGO_H
#define CHANGO_H
#include <string>
#include "Productos.h"

using namespace std;

class Chango

{
private:
    int cantidaEnChango;
    Producto **productosChango;

public:
    /*CONSTRUCTOR CON PARAMETROS
     pre: -
     pos: Inicializa el objeto Chango con una cantidad de elementos*/
    Chango(int cantidaEnChango);

    /*AGREGA PRODUCTOS AL CHANGO
     pre:-
     pos: agrega un nuevo producto al vector de productosChango*/
    void agrearAChango(string nombre, float precio, bool oferta, int cantidad);

    /* pre:tienen que haber porductos en el chango
     pos: muestra el contendido del chango*/
    void mostrar();

    /*  elimina la memoria dinamica solicitada.*/
    ~Chango();
};

#endif