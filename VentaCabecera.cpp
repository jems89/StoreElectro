#include "VentaCabecera.h"
#include <cstdlib>
#include <ctype.h>


/*
Validar si es letra en C++
int main() {
    char letra;
    std::cout << "Escribe un carácter:\n";
    std::cin >> letra;
    if (isalpha(letra)) {
        std::cout << "Es una letra";
    }
    else {
        std::cout << "NO es una letra";
    }
}*/

void VentaCabecera::cargar()
{
    Producto producto;
    /*bool salir = false;

    bool bandera = true;
    int  cantidadComprada, descuentoPorCantidad, codigoProducto , numeroRegistro, numeroVenta;
    char metodoPago;
    bool envioADomicilio, estado;
    float importePorProducto;
    int confirmar, pos = 0;
    numeroVenta = contVentas() + 1;
    estado = true;*/
    
    int numeroRegistro, codigoProducto, cantidadComprada=0;
    bool MenuDeVenta = true;
    
    system("cls");
    Menu o;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);

    while (MenuDeVenta==true) {
        system("cls");
        o.Menurectangulo(49, 8, 25, 3, "");
        std::cout << "Código del producto: ";
        std::cin >> codigoProducto;
        numeroRegistro = producto.buscarRegistro(codigoProducto);
        
        // A continuación se comprueba si existe el producto, en caso de encontrarlo la bandera se activa y sale del while.
        if (numeroRegistro == -1 )
        {
            system("cls");
            o.Menurectangulo(49, 8, 65, 3, "");
            std::cout << "No se ha encontrado el producto o No hay stock del producto. ";
            //std::cout << "Por favor elija otro producto.";
            rlutil::anykey();
            rlutil::cls();
            MenuDeVenta = false;
        }
        else {
            
            producto.leerDeDisco(numeroRegistro);
            if (producto.getEstado() == false || producto.getStock() == 0) {
                system("cls");
                o.Menurectangulo(49, 8, 65, 3, "");
                std::cout << "No se ha encontrado el producto o No hay stock del producto. ";
                //std::cout << "Por favor elija otro producto.";
                rlutil::anykey();
                rlutil::cls();
                MenuDeVenta = false;
            }
            else {
                o.Menurectangulo(49, 11, 25, 3, "");
                std::cout << "Cantidad comprada: ";
                std::cin >> cantidadComprada;

                while (producto.getStock() < cantidadComprada) // Verificación del máximo de productos posibles a comprar
                {
                    std::cout << std::endl << std::endl << "La cantidad indicada es menor al stock disponible. Por favor vuelva a intentarlo.";
                    rlutil::anykey();
                    rlutil::cls();
                    o.Menurectangulo(49, 11, 25, 3, "");
                    std::cout << "Cantidad comprada: ";
                    std::cin >> cantidadComprada;
                }
                
                
                producto.leerDeDisco(numeroRegistro);
                producto.setStock(producto.getStock() - cantidadComprada);
                //setimporteFinal(producto.getPrecio() * cantidadComprada);
                //setCantidadComprada(cantidadComprada);
                // Formula para aplicar el descuento
                //setNumeroDeVenta(contVentas());

               if (contVentas() == 0) { setNumeroDeVenta(numeroVenta = 1); }
                else {
                    setNumeroDeVenta(getNumeroVenta()+1);
                }
                
                if (producto.modificarEnDisco(numeroRegistro))  MenuDeVenta = false;// Modifico la clase Producto el stock y saco el importe
                

                Cliente cliente;
                bool salir = true;
                do { // Comprobación de ingreso correcto
                    o.Menurectangulo(49, 14, 25, 3, "");
                    std::cout << "Método de pago (e - efectivo/t - tarjeta): ";
                    std::cin >> metodoPago;

                    o.Menurectangulo(49, 17, 25, 3, "");
                    std::cout << "¿Se envía al domicilio del cliente? (1 - Sí/0 - No): ";
                    std::cin >> envioADomicilio;

                    o.Menurectangulo(49, 20, 25, 3, "");
                    std::cout << "ID del vendedor: ";
                    std::cin >> IDVendedor;

                    if (!buscarVendedor(IDVendedor))
                    {
                        rlutil::cls();
                        o.Menurectangulo(49, 8, 25, 3, "");
                        std::cout << " No se ha encontrado el vendedor. Por favor vuelva a intentarlo.";
                        rlutil::anykey();
                        rlutil::cls();
                    }
                    else salir = false;
                    
                } while (salir);

               producto.leerDeDisco(producto.buscarRegistro(codigoProducto));
               
                

                setIdProducto(codigoProducto);
               setEstado(true);
               setimporteFinal(producto.getPrecio() * cantidadComprada);
               setCantidadComprada(cantidadComprada);
               FechaHora horadecompra;
               setFechaYHoraDeLaVenta( horadecompra);
                if (grabarEnDisco()) std::cout << "Venta cargada con exito." << std::endl;
                rlutil::anykey();

            }

        }
    }
        
}
	
void VentaCabecera::mostrar(int pos)
{
   
    int reg;
    //bool primeraVuelta = false;
   Producto producto;
    Cliente cliente;
    Empleado vendedor;
    //cliente.buscarRegistro(dniCliente);
    
    leerDeDisco(pos);
        if (getEstado()) {
            std::cout << std::endl << std::endl;
            std::cout << "______________________________________________________________________________________" << std::endl;
            std::cout << "______________________________________________________________________________________" << std::endl;
            std::cout << " Ventaa N°" << getNumeroVenta() << std::endl << std::endl;
            std::cout << "--------------------------------------------------------------------------------------" << std::endl;
            /*while (ventaDetalle.leerDeDisco(pos++)) // Muestra todos los productos
            {
                if (numeroVenta == ventaDetalle.getNumeroVenta() && ventaDetalle.getEstado()) {  // Verifica que los productos sean de la misma venta
                    if (!primeraVuelta)
                    {
                        ventaDetalle.mostrar();
                        primeraVuelta = true;
                    }
                    else
                    {
                        std::cout << std::endl << std::endl << "-------------------------------------" << std::endl;
                        ventaDetalle.mostrar();
                    }
                }
            }*/
            
           reg = producto.buscarRegistro(getIdProducto());
            producto.leerDeDisco(reg);
            std::cout << "Nombre Del Pructo: " << producto.getNombre() << std::endl;
            std::cout << "Valor x Unidad: $" << producto.getPrecio() << std::endl;
            leerDeDisco(pos);
            std::cout << "Cantidad comprada: " << getCantidadComprada() << " " << std::endl;
            std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "Importe total: $" << getimporteFinal() << std::endl;
            std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
            //std::cout << "Comprador/a: " << cliente.getNombre() << ' ' << cliente.getApellido() << '\t';
            //std::cout << "DNI: " << cliente.getDni() << std::endl << std::endl;
            std::cout << "Envío a domicilio: ";
            if (getEnvioADomicilio()) std::cout << "Sí";
            else std::cout << "No";
            reg = vendedor.buscarRegistro(getIDVendedor());
            vendedor.leerDeDisco(reg);
            std::cout << std::endl << std::endl << "Venta a cargo de: " << vendedor.getNombre() << ' ' << vendedor.getApellido() << std::endl;
            std::cout << "Vendedor N°: " << getIDVendedor() << std::endl << std::endl;
            std::cout << "--------------------------------------------------------------------------------------" << std::endl;
            fechaYHoraDeLaVenta.mostrarFecha();
            std::cout << std::endl << "Hora: \t";
            fechaYHoraDeLaVenta.mostrarHora();


            
        }
        
    
}

void VentaCabecera::mostrarTodos(){
    int pos = 0, reg;
   
    Producto producto;
    Cliente cliente;
    Empleado vendedor;
        rlutil::cls();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        Menu ob;
        rlutil::cls();


        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::cls();
        while (leerDeDisco(pos))
        {

            if (getEstado()) {
                std::cout << "___________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
                std::cout << " Venta N°" << "\t" << "Nombre Del Pructo: " << "\t" << "Valor x Unidad: $" << "\t" << "Cantidad comprada: " << "\t" << "Importe total: $" << "\t" << "Envío a domicilio: " << "\t" << "Venta a cargo de: " << "\t" << "Vendedor N°: " << "\t" << "Hora: \t"; std::cout << std::endl << std::endl;
                reg = producto.buscarRegistro(getIdProducto());
                producto.leerDeDisco(reg);
                reg = vendedor.buscarRegistro(getIDVendedor());
                vendedor.leerDeDisco(reg);
                
                std::cout<<" "<< numeroVenta << "\t\t\t" << producto.getNombre() << "\t\t\t" << producto.getPrecio() << "\t\t\t" << CantidadComprada << "\t\t\t" << importeFinal << "\t\t\t" << getEnvioADomicilio() << "\t\t\t" << vendedor.getNombre() << " " << vendedor.getApellido() << "\t\t" << getIDVendedor() << "\t";
                fechaYHoraDeLaVenta.mostrarHora();
                std::cout << std::endl;
                /*std::cout << "______________________________________________________________________________________" << std::endl;
                std::cout << "______________________________________________________________________________________" << std::endl;
                std::cout << " Venta N°" << numeroVenta << std::endl << std::endl;
                std::cout << "--------------------------------------------------------------------------------------" << std::endl;
                reg = producto.buscarRegistro(getIdProducto());
                producto.leerDeDisco(reg);
                std::cout << "Nombre Del Pructo: " << producto.getNombre() << std::endl;
                std::cout << "Valor x Unidad: $" << producto.getPrecio() << std::endl;
                std::cout << "Cantidad comprada: " << CantidadComprada << " " << std::endl;
                std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
                std::cout << "Importe total: $" << importeFinal << std::endl;
                std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
                std::cout << "Envío a domicilio: ";
                if (getEnvioADomicilio()) std::cout << "Sí";
                else std::cout << "No";
                reg = vendedor.buscarRegistro(getIDVendedor());
                vendedor.leerDeDisco(reg);
                std::cout << std::endl << std::endl << "Venta a cargo de: " << vendedor.getNombre() << ' ' << vendedor.getApellido() << std::endl;
                std::cout << "Vendedor N°: " << getIDVendedor() << std::endl << std::endl;
                std::cout << "--------------------------------------------------------------------------------------" << std::endl;
                fechaYHoraDeLaVenta.mostrarFecha();
                std::cout << std::endl << "Hora: \t";
                fechaYHoraDeLaVenta.mostrarHora();
                */

            }
            
            pos++;

        }
    


}

bool VentaCabecera::grabarEnDisco()
{
    FILE* p = NULL;
    p = fopen("ventasCabecera.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        return 0;
    }
    fwrite(this, sizeof(VentaCabecera), 1, p);
    fclose(p);
    return 1;
}

bool VentaCabecera::leerDeDisco(int pos)
{
   
    FILE* p = NULL;
    p = fopen("ventasCabecera.dat", "rb");
    if (p == NULL)
    {   
        
        //std::cout << "Todavía no se ha realizado ninguna venta.\n";
        return false;
    }
    fseek(p, pos * sizeof(VentaCabecera), 0);
    bool leyo = fread(this, sizeof(VentaCabecera), 1, p);
    fclose(p);
    return leyo;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
}

bool VentaCabecera::buscarVendedor(int id)
{
    Empleado e;
    int pos = 0;
    while (e.leerDeDisco(pos++))
    {
        if (id == e.getID() && e.getEstado())return 1;
    }
    return 0;
}

bool VentaCabecera::buscarProducto(int codigo)
{
    Producto p;
    int pos = 0;
    while (p.leerDeDisco(pos++))
    {
        if (p.getCodigo() == codigo && p.getEstado()) return true;
    }
    return false;
}

bool VentaCabecera::buscarCliente(int dni)
{
    Cliente c;
    int pos = 0;
    while (c.leerDeDisco(pos++))
    {
        if (c.getDni() == dni) {
            //if (c.getEstado())
            //{

            return true;
            //}
        }
    }
    return false;
}

int VentaCabecera::contVentas()
{
   /* FILE* p = fopen("ventasCabecera.dat", "rb");
    if (p == NULL) {
        return 0; ///cantidad de registros cero 0
    }
   // size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    
   
    cant_reg = ftell(p) / sizeof(VentaCabecera);
    fclose(p);
    return cant_reg;*/
    int pos = 0;
    
    while (leerDeDisco(pos)) 
    {
        

        pos++;
    }
    
    
    return pos;
}

void VentaCabecera::modificarVenta()
{
    int opcion, ingreso, n, nReg ,y;
    Producto producto;
    //VentaDetalle ventaDetalle;
    system("cls");
    Menu o;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);

    do {
        system("cls");
        o.Menurectangulo(49, 8, 55, 3, "");
        std::cout << "Ingrese el número de venta a modificar o 0 para volver: ";
        std::cin >> n;
        nReg = buscarRegistro(n);
        if (nReg > 0)
        {
            do
            {
                y = 8;
                rlutil::setColor(rlutil::WHITE);
                rlutil::setBackgroundColor(rlutil::BLACK);
                mostrar(nReg);
                o.Menurectangulo(45, 8, 35, 2, "VENTAS:");
                o.Menurectangulo(5, y, 25, 2, "");
                std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
                o.Menurectangulo(5, y += 2, 25, 2, "");
                std::cout << "1-Cantidad de cuotas" << std::endl;
                o.Menurectangulo(5, y, 25, 2, "");
                std::cout << "2-Método de pago" << std::endl;
                o.Menurectangulo(5, y, 25, 2, "");
                std::cout << "3-Envío a domicilio" << std::endl;
                o.Menurectangulo(5, y, 25, 2, "");
                std::cout << "0-Volver" << std::endl << std::endl;
                o.Menurectangulo(5, y, 25, 2, "");
                std::cout << "Ingrese una opción: ";
                std::cin >> opcion;
                rlutil::cls();
                switch (opcion)
                {
                case 1:
                    system("cls");
                    
                    std::cout << "Ingrese la cantidad de cuotas a pagar:" << std::endl;
                    o.Menurectangulo(20, 14, 80, 3, "");
                    std::cin >> cantidadCuotas;
                    setCantidadCuotas(cantidadCuotas);
                    break;
                case 2:
                    std::cout << "Ingrese el metodo de pago" << std::endl;
                    o.Menurectangulo(20, 14, 80, 3, "");
                    std::cin >> metodoPago;
                    setMetodoPago(metodoPago);
                    break;
                case 3:
                    int opc;
                    std::cout << "envio a domicilio 1 si 2 no" << std::endl;
                    std::cin >> opc;
                    switch (opc)
                    {
                    case 1: setEnvioADomicilio(true);
                    break;
                case 2:    setEnvioADomicilio(false);
                    break;
                    default:  std::cout << "Opcion incorrecta" << std::endl;
                        
                    }
                    
                    if (opcion != 0)
                    {
                        o.Menurectangulo(49, 11, 55, 3, "");
                        std::cout << "Por favor ingrese una opción correcta.";
                    }
                    break;
                }
                if (opcion != 0) {
                    if (modificarEnDisco(nReg)) std::cout << "Modificación realizada con éxito.";
                    else std::cout << "Error al modificar.";
                }
                rlutil::cls();
            } while (opcion != 0);
        }
        else if (n != 0)
        {
            std::cout << "Error. No se ha encontrado la venta.";
            rlutil::anykey();
        }
        rlutil::cls();
    } while (n != 0);
}

void VentaCabecera::eliminarVenta()
{
   int c, confirmar, pos;
    Menu ob;
    do {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        ob.Menurectangulo(5, 10, 70, 2, "");
        std::cout << "Ingrese el numero de la venta que quiere eliminar o 0 para volver: ";
        ob.Menurectangulo(5, 12, 70, 2, "");
        std::cin >> c;
        pos = buscarRegistro(c);
        rlutil::cls();

        if (pos < 0) {
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
            ob.Menurectangulo(45, 8, 55, 3, "");
            std::cout << "No se ha podido encontrar el producto.";

        }

        else
        {
            leerDeDisco(pos);
            if (getEstado()) {
                rlutil::cls();
                
                std::cout << std::endl << std::endl << "¿Seguro de eliminar producto? Presione 1 para eliminar/2 para cancelar:" << std::endl;
                std::cin >> confirmar;
                rlutil::cls();
                if (confirmar == 1)
                {
                    setEstado(false);
                    if (modificarEnDisco(pos)) { ob.Menurectangulo(5, 10, 70, 2, ""); std::cout << "Eliminado con exito."; }
                    else { rlutil::cls(); ob.Menurectangulo(5, 10, 70, 2, ""); std::cout << "Error al eliminar."; }
                }
                else if (confirmar != 2) {
                    rlutil::cls();
                    ob.Menurectangulo(5, 10, 70, 2, "");
                    std::cout << "Por favor ingrese una opción válida.";
                }
            }
            else { rlutil::cls(); ob.Menurectangulo(5, 10, 70, 2, ""); std::cout << "No se ha podido encontrar el producto."; }
        }
        if (c != 0) 
        rlutil::cls();
    } while (c != 0);
    

    /*
    Menu ob;
    int n, confirmar, reg;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    ob.Menurectangulo(38, 8, 76, 3, " ");
    std::cout << "Ingrese el número de la venta que quiere eliminar o ingrese 0 para volver: ";
    std::cin >> n;
    
    
    if (!(-1 == buscarRegistro(n) || n == 0))
    {
        reg = buscarRegistro(n);
            leerDeDisco(reg);
            if (getNumeroVenta() == n) {
                rlutil::cls();
                ob.Menurectangulo(38,6,35,3, " ");
                std::cout << "¿Seguro de eliminar la venta?" << std::endl;
                
                ob.Menurectangulo(38,29,55,3, " ");
                std::cout << " Presione 1 para eliminar / 2 para cancelar : " << std::endl;
                std::cin >> confirmar;

                if (confirmar == 1)
                {
                    setEstado(false);
                    modificarEnDisco(reg);
                    rlutil::cls();
                    ob.Menurectangulo(38, 8, 15, 3, " ");
                    std::cout << "Venta Eliminada";
                }
                else if (confirmar != 2) {
                    rlutil::cls();
                    ob.Menurectangulo(5, 10, 70, 2, "");
                    std::cout << "Por favor ingrese una opción válida.";
                
                }

            }
    }
    else {
        if (n == 0) {
            rlutil::cls();
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
            ob.Menurectangulo(38, 8, 15, 3, " ");
            std::cout << "No se Elimino Nada";
            rlutil::anykey();
        }
        else {
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
            ob.Menurectangulo(38, 8, 15, 3, " ");
            std::cout << "No hay registros";
            rlutil::anykey();
        }
    }
 
        

    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    */
}
void VentaCabecera::listarVenta()
{
    int opcion, d, pos, numeroReg,regg;
    bool bandera = false;
    rlutil::cls();
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    
    Menu ob;
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    do
    {
        pos = 0;
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        ob.Menurectangulo(45, 8, 35, 3, "");
        std::cout << "1-Listar todas las ventas" << std::endl;
        ob.Menurectangulo(45, 11, 35, 3, "");
        std::cout << "2-Listar una venta" << std::endl;
        ob.Menurectangulo(45, 14, 35, 3, "");
        std::cout << "0-Volver" << std::endl << std::endl;
        ob.Menurectangulo(45, 17, 35, 3, "");
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            mostrarTodos();
            break;
        case 2:
            rlutil::cls();
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
            ob.Menurectangulo(45, 8, 65, 3, "");
            std::cout << "Ingrese el número de venta que quiere listar o 0 para volver: ";
            std::cin >> d;
            if (d != 0) {
                rlutil::cls();
                if (buscarRegistro(d) < 0)
                {
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::setBackgroundColor(rlutil::BLACK);
                    ob.Menurectangulo(38, 14, 45, 3, "");
                    std::cout << "No se ha podido encontrar la venta.";
                }
                else
                {
                    regg=buscarRegistro(d);
                    leerDeDisco(regg);
                    if (getEstado()) {
                        bandera = true;
                        mostrar(regg);
                    }
                    else std::cout << "No se ha podido encontrar la venta.";
                }
            }
            break;
        default:
            if (opcion != 0)
            {
                std::cout << "Por favor ingrese una opción correcta.";
            }
            break;
        }
        bandera = false;
        if (opcion != 0)rlutil::anykey();
        rlutil::cls();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
}

int VentaCabecera::buscarRegistro(int n)
{
    int pos = 0;
    while (leerDeDisco(pos))
    {

        if (n == numeroVenta) 
        { return pos; }

        pos++;
    }

    return -1;
}

bool VentaCabecera::modificarEnDisco(int pos)
{
    FILE* p = NULL;
    p = fopen("ventasCabecera.dat", "rb+");
    if (p == NULL)return 0;
    fseek(p, pos * sizeof(VentaCabecera), 0);
    bool escribio = fwrite(this, sizeof(VentaCabecera), 1, p);
    fclose(p);
    return escribio;
}
/*
void VentaDetalle::cargar()
{
    Producto producto;
    bool MenuDeVenta = true;
    bool bandera = true;
    int numeroRegistro;
    estado = true;
    system("cls");
    Menu o;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    while (MenuDeVenta) {
        system("cls");
        o.Menurectangulo(49, 8, 25, 3, "");
        std::cout << "Código del producto: ";
        std::cin >> codigoProducto;
        numeroRegistro = producto.buscarRegistro(codigoProducto);
        // A continuación se comprueba si existe el producto, en caso de encontrarlo la bandera se activa y sale del while.
        if (numeroRegistro == -1 || producto.getStock() < 1)
        {
            system("cls");
            o.Menurectangulo(49, 8, 65, 3, "");
            std::cout << "No se ha encontrado el producto o No hay stock del producto. ";
            //std::cout << "Por favor elija otro producto.";

            rlutil::anykey();
            rlutil::cls();
            MenuDeVenta = false;
        }
        else {

            do
            {

                o.Menurectangulo(49, 11, 25, 3, "");
                std::cout << "Cantidad comprada: ";
                std::cin >> cantidadComprada;
                if (producto.getStock() < cantidadComprada) // Verificación del máximo de productos posibles a comprar
                {
                    std::cout << std::endl << std::endl << "La cantidad indicada es menor al stock disponible. Por favor vuelva a intentarlo.";
                    rlutil::anykey();
                    rlutil::cls();
                }
                else bandera = true;
            } while (!bandera);

            producto.setStock(producto.getStock() - cantidadComprada); // Actualización de stock
            producto.modificarEnDisco(numeroRegistro - 1); // Actualización en disco
            // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
            if (cantidadComprada <= 25) descuentoPorCantidad = cantidadComprada / 5 * 5; // Cada 5 productos hace un %5 de descuento hasta llegar a 25 productos.
            else descuentoPorCantidad = 25;
            importePorProducto = producto.getPrecio() * cantidadComprada - producto.getPrecio() * cantidadComprada * descuentoPorCantidad / 100; // Formula para aplicar el descuento
            grabarEnDisco();
        }
    }
}

void VentaDetalle::mostrar()
{
    Producto producto;
    float precio;
    if (estado)
    {
        producto.buscarRegistro(codigoProducto);
        std::cout << "Producto: " << producto.getNombre() << std::endl;
        std::cout << "Cantidad: " << cantidadComprada << std::endl;
        precio = producto.getPrecio() * cantidadComprada - producto.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;
        if (descuentoPorCantidad > 0) std::cout << "Descuento por cantidad comprada: " << descuentoPorCantidad << '%' << std::endl << std::endl;
        std::cout << "Precio: $" << precio << std::endl << std::endl;
    }
}
*/





/*
  if (tolower(metodoPago) != 'e' && tolower(metodoPago) != 't') {
   rlutil::cls(); o.Menurectangulo(49, 8, 25, 3, "");
                std::cout << "Por favor ingrese una opción válida.";
                rlutil::anykey();
                rlutil::cls();
            
              while (tolower(metodoPago) != 'e' && tolower(metodoPago) != 't');

             bool salir = false;
             do { // Comprobación de existencia del archivo del vendedor*/
                 
                





/*reg = producto.buscarRegistro(getIdProducto());
producto.leerDeDisco(reg);
std::cout  producto.getNombre() << std::endl;
std::cout  producto.getPrecio() << std::endl;
std::cout  CantidadComprada << " " << std::endl;
std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
 importeFinal << std::endl;
std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
std::cout << 
if (getEnvioADomicilio()) std::cout << "Sí";
else std::cout << "No";
reg = vendedor.buscarRegistro(getIDVendedor());
vendedor.leerDeDisco(reg);
std::cout << std::endl << std::endl  vendedor.getNombre() << ' ' << vendedor.getApellido() << std::endl;
std::cout  getIDVendedor() << std::endl << std::endl;
std::cout << "--------------------------------------------------------------------------------------" << std::endl;
fechaYHoraDeLaVenta.mostrarFecha();
std::cout << std::endl 
fechaYHoraDeLaVenta.mostrarHora();*/