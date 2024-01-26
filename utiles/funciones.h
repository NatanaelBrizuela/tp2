#ifndef MAIN_H
#define MAIN_H
#include "gondola.h"
#include "Productos.h"
#include "chango.h"
#include <string>

using namespace std;

const string PATH_PRODUCTOS = "./utiles/productos.txt";
const string PATH_COMPRA = "./utiles/compra.txt";

enum ModoLectura
{
    Lectura = 1,
    Escritura = 2
};

/*Abre un archivo en modo lectura para su manipulacion
PRE: debe existir el path del archivo y definir el modo de apertura que se desea
POS: devuelve un ifstream.*/
fstream abrirArch(string path, ModoLectura modo);
/*llena la gondola de productos en el arhcivo de productos
PRE: se debe ingresar una clase Gondola incializada correctamente
POS: llena la gondola de Productos*/
void llenarGondola(Gondola &gondolaN, fstream &archProductos);
/*llena el chango de productos disponibles en la gondola
Pre: debe haber prodcutos en la gondola
pos: devuelve el chango con los productos solicitados*/
void llenarChango(Chango &changoN, fstream &archProductos, Gondola &gondolaN);
/*en base al archio compra procesa si se puede comprar el producto y su cantidad
pre: -??
pos: coloca en el chango la cantidad sidponible para comprar de un producto*/
void procesarCompra(Chango &chagnoN, string nombreCompra, int cantidadCompra, Gondola &gondolaN, int indice);
/*actualiza la cantidad de elementos de un producto en la gondola
pre: se tiene que haber quitado un elemento de la gondola
pos: los elementos de un producto se actualizan, si se queda en 0 o menos se elimina de la gondola*/
void actualizarCantidadGondola(int incide, Gondola &gondolaN, int cantidadCompra);
/*actualiza el archivo de compras seguno lo que se coloco en el changuito
pre: -
pos: elimna el archivo de productos y crea uno nuevo con los valores actualizados de la gondola*/
void actualizarArchivos(Gondola &gondolaN);

#endif