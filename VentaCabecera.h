#pragma once
#include "Cliente.h"
#include "Empleado.h"
#include "Producto.h"


class VentaCabecera
{
private:
    int numeroVenta=0, cantidadCuotas, IDVendedor, dniCliente, CantidadComprada;
    int Idproducto;
	FechaHora fechaYHoraDeLaVenta;
	char metodoPago;
	bool envioADomicilio, estado;
	float importeFinal, importeCuota;
public:
    void cargar();
    void mostrar(int pos);
    void mostrarTodos();
    bool grabarEnDisco();
    bool leerDeDisco(int pos);

    int getCantidadComprada() { return CantidadComprada; }
    void setCantidadComprada(int c) { CantidadComprada = c; }
     
    int getIdProducto() { return Idproducto; }
    void setIdProducto(int n) { Idproducto = n; }


    int getNumeroVenta() { return numeroVenta; }
    void setNumeroDeVenta(int n) { numeroVenta = n; }

    bool getEstado() { return estado; }
    void setEstado(bool estado) { this->estado = estado; }

    int getCantidadCuotas() { return cantidadCuotas; }
    void setCantidadCuotas(int cantidadCuotas) { this->cantidadCuotas = cantidadCuotas; }
    FechaHora getFechaYHoraDeLaVenta() { return fechaYHoraDeLaVenta; }
    void setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta) { this->fechaYHoraDeLaVenta = fechaYHoraDeLaVenta; }
    void setimporteFinal(float importe) { importeFinal = importe; }
    float getimporteFinal() { return importeFinal; }
        

    char getMetodoPago() { return metodoPago; }
    void setMetodoPago(char metodoPago) { this->metodoPago = metodoPago; }

    bool getEnvioADomicilio() { return envioADomicilio; }
    void setEnvioADomicilio(bool envioADomicilio) { this->envioADomicilio = envioADomicilio; }

    bool buscarVendedor(int);
    bool buscarProducto(int);
    bool buscarCliente(int);
    int contVentas();
    int getIDVendedor() { return IDVendedor; }
    void setIDVendedor(int IDVendedor) { this->IDVendedor = IDVendedor; }
    int getDniCliente() { return dniCliente; }
    void setDniCliente(int dniCliente) { this->dniCliente = dniCliente; }

    void modificarVenta();
    void eliminarVenta();
    void listarVenta();
    int buscarRegistro(int);
    bool modificarEnDisco(int);

};

