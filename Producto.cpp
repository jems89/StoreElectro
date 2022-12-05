#include "Producto.h"

std::string Producto::getNombre() 
{
    std::string nombre = this->nombre;
    return nombre;
}

void Producto::setNombre(std::string nombre)
{
    strcpy(this->nombre, nombre.c_str());
}

std::string Producto::getMarca() 
{
    std::string marca = this->marca;
    return marca;
}

void Producto::setMarca(std::string marca)
{
    strcpy(this->marca , marca.c_str());
}

std::string Producto::getDescripcion() 
{
    std::string descripcion = this->descripcion;
    return descripcion;
}

void Producto::setDescripcion(std::string descripcion)
{
    strcpy(this->descripcion , descripcion.c_str());
}

int Producto::getCodigo() 
{
    return codigo;
}

void Producto::setCodigo(int codigo)
{
    this->codigo = codigo;
}

bool Producto::getEstado() 
{
    return estado;
}

void Producto::setEstado(bool estado)
{
    this->estado = estado;
}

int Producto::getCategoria() 
{
    return categoria;
}

void Producto::setCategoria(int categoria)
{
    this->categoria = categoria;
}

int Producto::getStock() 
{
    return stock;
}

void Producto::setStock(int stock)
{
    this->stock = stock;
}

float Producto::getPrecio() 
{
    return precio;
}

void Producto::setPrecio(float precio)
{
    this->precio = precio;
}

void Producto::cargar() {

	rlutil::cls();
	Menu ob;
	int pos = 0;
	int codigoo,tam,posicion;
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
	ob.Menurectangulo(45,9, 45, 3, "");
	//tam = contRegistros();
    std::cout << "Ingrese el Codigo o 0 para salir ";
    std::cin >> codigoo;
	while (codigoo != 0 && buscarcodigo(codigoo)==false)
	{

		pos = buscarRegistro(codigoo);
		if (pos == -1) { pos += 1; }
		if (pos < 0) {
			rlutil::cls();
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::WHITE);
			ob.Menurectangulo(30, 11, 55, 3, "");
			std::cout << "Error para agregar Productos.";
			rlutil::anykey();
			codigoo = 0;

		}
		else {
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::WHITE);

			do {


				setCodigo(codigoo);
				rlutil::cls();
				rlutil::setColor(rlutil::BLACK);
				rlutil::setBackgroundColor(rlutil::WHITE);
				ob.Menurectangulo(45, 9, 45, 3, "");
				//tam = contRegistros();
				std::cout << "Codigo: "<< getCodigo();
				
				ob.Menurectangulo(45, 12, 60, 3, "");
				std::cout << "Categoria(1-Linea blanca/2-Electrónica/3-Videojuegos): ";
				std::cin >> categoria;

				if (categoria < 1 && categoria>3) {
					rlutil::cls();
					rlutil::setColor(rlutil::BLACK);
					rlutil::setBackgroundColor(rlutil::WHITE);
					ob.Menurectangulo(45, 9, 45, 3, "");
					std::cout << "Por favor ingrese una opción válida.";
					rlutil::anykey();
					rlutil::cls();
				}
			} while (categoria < 1 && categoria>3);

			ob.Menurectangulo(45, 15, 45, 3, "");
			std::cout << "Marca: ";
			std::cin.ignore();
			std::cin.getline(marca, 50);
			ob.Menurectangulo(45, 18, 45, 3, "");
			std::cout << "Nombre: ";
			std::cin.getline(nombre, 50);
			ob.Menurectangulo(45, 21, 45, 3, "");
			std::cout << "Descripción: ";
			std::cin.getline(descripcion, 50);
			ob.Menurectangulo(45, 24, 45, 3, "");
			std::cout << "Precio: $";
			std::cin >> precio;
			ob.Menurectangulo(45, 27, 45, 3, "");
			std::cout << "Stock: ";
			std::cin >> stock;
			setEstado(true);
			//setCodigo(codigo);

			if (grabarEnDisco())
			{
				system("cls");
				ob.Menurectangulo(45, 9, 45, 3, "");
				std::cout << "Producto guardado con exito" << std::endl;
				rlutil::anykey();
				system("cls");
			}

		}
		
		
	}
	
	/*/
	}*/
	

	
}
		
		
	
	
void Producto::cargar(int cod) {
	codigo = cod;
	Menu ob;
	do {
		
		ob.Menurectangulo(45, 12, 45, 3, "");
		std::cout << "Categoria(1-Linea blanca/2-Electrónica/3-Videojuegos): ";
		std::cin >> categoria;

		if (categoria < 1 && categoria>3) {
			rlutil::cls();
			ob.Menurectangulo(45, 9, 45, 3, "");
			std::cout << "Por favor ingrese una opción válida.";
			rlutil::anykey();
			rlutil::cls();
		}
	} while (categoria < 1 && categoria>3);
	ob.Menurectangulo(45, 15, 45, 3, "");
    std::cout << "Marca: ";
    std::cin.ignore();
    std::cin.getline(marca, 50);
	ob.Menurectangulo(45, 18, 45, 3, "");
    std::cout << "Nombre: ";
    std::cin.getline(nombre, 50);
	ob.Menurectangulo(45, 21, 45, 3, "");
    std::cout << "Descripción: ";
    std::cin.getline(descripcion, 50);
	ob.Menurectangulo(45, 24, 45, 3, "");
    std::cout << "Precio: $";
    std::cin >> precio;
	ob.Menurectangulo(45, 27, 45, 3, "");
    std::cout << "Stock: ";
    std::cin >> stock;
    if (grabarEnDisco())
    {
        system("cls");
		ob.Menurectangulo(45, 9, 45, 3, "");
        std::cout << "Producto guardado con exito" << std::endl;
		rlutil::anykey();
		rlutil::cls();
    }
}
void Producto::mostrar() {
    if (estado) {
		rlutil::cls();
		rlutil::setColor(rlutil::BLACK);
		rlutil::setBackgroundColor(rlutil::WHITE);
		Menu ob;
		int y = 10;
		rlutil::setColor(rlutil::BLACK);
		rlutil::setBackgroundColor(rlutil::WHITE);
		ob.Menurectangulo(45, y, 35, 3, "");
        std::cout << "Código: ";
        std::cout << codigo << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Nombre: ";
        std::cout << nombre << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Categoría: ";
		switch (categoria)
		{
		case 1: std::cout << "Línea blanca";
			break;
		case 2: std::cout << "Electrónica";
			break;
		default: std::cout << "Videojuegos";
			break;
		}
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Marca: ";
        std::cout << marca << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Descripción: ";
        std::cout << descripcion << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Precio: $";
        std::cout << precio << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Stock: ";
        std::cout << stock << std::endl;
		
    }
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
}
void Producto::mostrarTodos() {
	int y = 0, pos = 0;
	rlutil::cls();
	rlutil::setBackgroundColor(rlutil::WHITE);
	rlutil::setColor(rlutil::BLACK);
	Menu ob;
	rlutil::cls();
	
	
	rlutil::setBackgroundColor(rlutil::WHITE);
	rlutil::setColor(rlutil::BLACK);
	rlutil::cls();
	while (leerDeDisco(pos))
	{
		
		if (getEstado()) {
			y += 10;
			ob.Menurectangulo(45, y, 35, 3, "");
			std::cout << "Códigoo: ";
			std::cout << codigo << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Nombre: ";
			std::cout << nombre << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Categoría: ";
			switch (categoria)
			{
			case 1: std::cout << "Línea blanca";
				break;
			case 2: std::cout << "Electrónica";
				break;
			default: std::cout << "Videojuegos";
				break;
			}
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Marca: ";
			std::cout << marca << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Descripción: ";
			std::cout << descripcion << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Precio: $";
			std::cout << precio << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Stock: ";
			std::cout << stock << std::endl;
			//std::cout << "estado " << estado << std::endl;

		}
		pos++;

	}
}

bool Producto::grabarEnDisco() {
    FILE* p = NULL;
    p = fopen("productos.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
    return 1;
}
bool Producto::leerDeDisco(int pos) {
	
	
    FILE* p = NULL;
    p = fopen("productos.dat", "rb");
    if (p == NULL)
    {   
		
		
        std::cout << "No hay productos cargados ";
		
		//rlutil::anykey();
        return false;
    }
    fseek(p, pos * sizeof(Producto), 0);
    bool leyo=fread(this, sizeof(Producto), 1, p);
    fclose(p);
    return leyo;
	
}

int Producto::contRegistros() {
	FILE* p = fopen("productos.dat", "rb");
	if (p == NULL) {
		return 0; ///cantidad de registros cero 0
	}
	
	fseek(p, 0, SEEK_END);
	int cant_reg = ftell(p) / sizeof(Producto);
	fclose(p);
	return cant_reg;
}

void Producto::modificarProducto() {
	Menu ob;
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
	std::string palabra;
	int opcion, ingreso, c, pos, y;
	bool ingresoCorrecto = true;
	rlutil::setBackgroundColor(rlutil::WHITE);
	rlutil::setColor(rlutil::BLACK);
	ob.Menurectangulo(30, 8, 65, 3, "");
	std::cout << "Ingrese el código del producto a modificar o 0 para volver: ";
	std::cin >> c;
	while (c != 0) 
	{
		
		pos = buscarRegistro(c);

		if (pos < 0) {
			rlutil::cls();
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::WHITE);
			ob.Menurectangulo(30,11, 55, 3, "");
			std::cout << "No se ha podido encontrar el producto.";
			rlutil::anykey();
			c = 0;

		}

		else
		{
			leerDeDisco(pos);
			do
			{
				y = 8;
				rlutil::setColor(rlutil::BLACK);
				rlutil::setBackgroundColor(rlutil::WHITE);
				mostrar();
				ob.Menurectangulo(45, 8, 35, 2, "PRODUCTO:");
				ob.Menurectangulo(5, y, 25, 2, "");
				std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "1-Nombre" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "2-Marca" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "3-Descripción" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "4-Categoría" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "5-Stock" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "6-Precio" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "0-Volver" << std::endl << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "Ingrese una opción: ";
				std::cin >> opcion;
				rlutil::cls();
				rlutil::setColor(rlutil::BLACK);
				rlutil::setBackgroundColor(rlutil::WHITE);
				ob.Menurectangulo(20, 11, 80, 3, "");
				switch (opcion)
				{
				case 1:
					std::cout << "Ingrese el nombre nuevo: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setNombre(palabra);
					break;
				case 2:
					std::cout << "Ingrese la nueva marca: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setMarca(palabra);
					break;
				case 3:
					std::cout << "Ingrese la nueva descripción: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setDescripcion(palabra);
					break;
				case 4:
					std::cout << "Ingrese la nueva categoría(1-Línea blanca, 2-Electrónica o 3-Videojuegos):" << std::endl;

					ob.Menurectangulo(20, 14, 80, 3, "");
					rlutil::locate(37, 15);
					std::cin >> categoria;
					setCategoria(categoria);
					break;
				case 5:
					std::cout << "Ingrese el stock actual: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					rlutil::locate(37, 15);
					std::cin >> stock;
					setStock(stock);
					break;
				case 6:
					std::cout << "Ingrese el nuevo precio: ";

					ob.Menurectangulo(20, 14, 80, 3, "$");
					rlutil::locate(24, 15);
					std::cin >> precio;
					setPrecio(precio);
					break;
				default:

					std::cout << "Por favor ingrese una opción correcta.";


					break;
				}
				if (opcion != 0) {
					rlutil::cls();
					ob.Menurectangulo(44, 20, 36, 3, "");
					if (modificarEnDisco(pos)) std::cout << "Modificación realizada con éxito.";
					else std::cout << "Error al modificar.";
					rlutil::anykey();
				}
				rlutil::cls();
			} while (opcion != 0);

			rlutil::setBackgroundColor(rlutil::WHITE);
			rlutil::setColor(rlutil::BLACK);
			ob.Menurectangulo(30, 8, 65, 3, "");
			std::cout << "Ingrese el código del producto a modificar o 0 para volver: ";
			std::cin >> c;

		}
		/*}
		else 
		{
			rlutil::cls();
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::RED);
			ob.Menurectangulo(44, 20, 45, 3, "");
			std::cout << "Error. No se ha encontrado el producto.";
			rlutil::anykey();
		}
		rlutil::cls();
		rlutil::setBackgroundColor(rlutil::WHITE);
		rlutil::setColor(rlutil::BLACK);*/
			

	} 
}

void Producto::eliminarProducto() {
	int c, confirmar, pos;
	Menu ob;
	do {
		rlutil::setBackgroundColor(rlutil::WHITE);
		rlutil::setColor(rlutil::BLACK);
		ob.Menurectangulo(5, 10, 70, 2, "");
		std::cout << "Ingrese el código del producto que quiere eliminar o 0 para volver: ";
		ob.Menurectangulo(5, 12, 70, 2, "");
		std::cin >> c;
		pos = buscarRegistro(c);
		rlutil::cls();
		
		if (pos < 0){
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::WHITE);
			ob.Menurectangulo(45, 8, 55, 3, "");
			std::cout << "No se ha podido encontrar el producto.";
		
	     }
		
		else
		{
			leerDeDisco(pos);
			if (getEstado()) {
				rlutil::cls();
				mostrar();
				std::cout << std::endl << std::endl << "¿Seguro de eliminar producto? Presione 1 para eliminar/2 para cancelar:" << std::endl;
				std::cin >> confirmar;
				rlutil::cls();
				if (confirmar == 1)
				{
					setEstado(false);
					if (modificarEnDisco(pos)) { ob.Menurectangulo(5, 10, 70, 2, ""); std::cout << "Eliminado con exito."; }
					else { rlutil::cls(); ob.Menurectangulo(5, 10, 70, 2, ""); std::cout << "Error al eliminar."; }
				}
				else if (confirmar != 2) { rlutil::cls();
				ob.Menurectangulo(5, 10, 70, 2, "");
				std::cout << "Por favor ingrese una opción válida."; }
			}
			else { rlutil::cls(); ob.Menurectangulo(5, 10, 70, 2, ""); std::cout << "No se ha podido encontrar el producto."; }
		}
		if (c != 0) rlutil::anykey();
		            rlutil::cls();
	} while (c != 0);
}

void Producto::listarProducto() {
	int opcion, c, pos, cont;
	bool bandera = false;
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
	rlutil::cls();
	Menu ob;
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
	do
	{
		pos = 0;
		rlutil::setColor(rlutil::BLACK);
		rlutil::setBackgroundColor(rlutil::WHITE);
		ob.Menurectangulo(45, 8, 35, 3, "");
		std::cout << "Seleccion una opcion" << std::endl;
		ob.Menurectangulo(45, 11, 35, 3, "");
		std::cout << "1-Listar todos los productos" << std::endl;
		ob.Menurectangulo(45, 14, 35, 3, "");
		std::cout << "2-Listar un producto por código" << std::endl;
		ob.Menurectangulo(45, 17, 35, 3, "");
		std::cout << "0 Volver " << std::endl;
		ob.Menurectangulo(45, 20, 35, 3, "");
		std::cin >> opcion;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			mostrarTodos();
			/*cont = 0;
			while (leerDeDisco(pos++))
			{
				rlutil::locate(54, 7 + (cont * 24));
				mostrar();
				if (estado)std::cout << std::endl << std::endl;
				if (estado) cont++;
			}*/
			break;
		case 2:
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::WHITE);
			ob.Menurectangulo(45, 11, 70, 3, "");
			std::cout << "Ingrese el código del producto que quiere listar o 0 para volver: ";
			std::cin >> c;
			pos=buscarRegistro(c);
			if (pos < 0) { 
				rlutil::cls();
				rlutil::setColor(rlutil::BLACK);
				rlutil::setBackgroundColor(rlutil::WHITE);
				ob.Menurectangulo(45,8, 35, 3, "");
				std::cout << "No productos cargados"; }
				else
				{        
						leerDeDisco(pos);
						
						mostrar();
				}
			
			break;
		default:
			if (opcion != 0)
			{
				rlutil::setColor(rlutil::BLACK);
				rlutil::setBackgroundColor(rlutil::WHITE);
				ob.Menurectangulo(45, 8, 35, 3, "");
				std::cout << "Por favor ingrese una opción correcta.";
			}
			break;
		}
		bandera = false;
		if (opcion != 0)rlutil::anykey();
		rlutil::cls();
	} while (opcion != 0);
	
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
}

bool Producto::modificarEnDisco(int pos) {
	FILE* p = NULL;
	p = fopen("productos.dat", "rb+");
	if (p == NULL)return 0;
	fseek(p, pos * sizeof(Producto), 0);
	bool escribio = fwrite(this, sizeof(Producto), 1, p);
	fclose(p);
	return escribio;
}

int Producto::buscarRegistro(int c) {
	int pos = 0;
	while (leerDeDisco(pos))
	{

		if (c == getCodigo()) { return pos; }
		
		pos++;
	}

	return -1;
}

bool Producto::buscarcodigo(int codigo) 
{
	int pos = 0;
	bool encontro=false ;
	while (leerDeDisco(pos))
	{

		if (codigo == getCodigo()) { encontro=true; }

		pos++;
	}

	return encontro;

}