#pragma once
#include <iostream>
#include <iomanip>
#include "rlutil.h"
#include "Menu.h"

class Producto
{
private:
	char nombre[50], marca[50], descripcion[50];
    int codigo, categoria, stock ;
	float precio;
    bool estado;
public:
    void cargar();
    void cargar(int);
    void mostrar();
    void mostrarTodos();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    std::string getNombre();
    void setNombre(std::string nombre);

    std::string getMarca();
    void setMarca(std::string marca);

    std::string getDescripcion();
    void setDescripcion(std::string descripcion);

    int getCodigo();
    void setCodigo(int codigo);

    int getCategoria();
    void setCategoria(int categoria);

    int getStock();
    void setStock(int stock);

    float getPrecio();
    void setPrecio(float precio);

    bool getEstado();
    void setEstado(bool estado);

    int contRegistros();
    void modificarProducto();
    void eliminarProducto();
    void listarProducto();
    bool modificarEnDisco(int);
    int buscarRegistro(int);
    bool buscarcodigo(int);

};