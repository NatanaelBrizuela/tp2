#include <iostream>
#include "Productos.h"

Producto::Producto(const string nombre, float precio, bool oferta, int cantidad)
{
    this->nombre = nombre;
    this->precio = precio;
    this->oferta = oferta;
    this->cantidad = cantidad;
}

Producto::Producto(const Producto &Prod)
{
    this->nombre = Prod.nombre;
    this->precio = Prod.precio;
    this->oferta = Prod.oferta;
    this->cantidad = Prod.cantidad;
}

string Producto::getNombre() { return nombre; }
float Producto::getPrecios() { return precio; }
bool Producto::getOferta() { return oferta; }
int Producto::getCantidad() { return cantidad; }

void Producto::setCantidad(int nuevCantidad) { this->cantidad = nuevCantidad; }
