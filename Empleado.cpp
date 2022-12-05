#include "Empleado.h"
#include "Menu.h"

int Empleado::getID()
{
    return ID;
}

void Empleado::setID(int ID)
{
    this->ID = ID;
}

int Empleado::getCategoria()
{
    return categoria;
}

void Empleado::setCategoria(int categoria)
{
    this->categoria = categoria;
}

char Empleado::getTurno()
{
    return turno;
}

void Empleado::setTurno(char turno)
{
    this->turno = turno;
}

FechaHora Empleado::getFechaDeIngreso()
{
    return fechaDeIngreso;
}

void Empleado::setFechaDeIngreso(FechaHora fechaDeIngreso)
{
    this->fechaDeIngreso = fechaDeIngreso;
}

char Empleado::getTipoJornada()
{
    return tipoJornada;
}

void Empleado::setTipoJornada(char tipoJornada)
{
    this->tipoJornada = tipoJornada;
}

float Empleado::getSueldo()
{
    return sueldo;
}

void Empleado::setSueldo(float sueldo)
{
    this->sueldo = sueldo;
}


void Empleado::cargar() {
	
	
	system("cls");
	Menu o;
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
	system("cls");
	o.Menurectangulo(49, 1, 30, 3, "Pulsa'0' Salir | '1' No Salir >>");
	int ingreso;
	int pos;
	std::cin >> ingreso;
	while (ingreso!=0 && buscarRegistro(ingreso) == -1)
	{   

		pos = buscarRegistro(ingreso);
		if (pos == -1) { pos += 1; }
		if (pos < 0) {
			std::cout << "Error para agregar Productos.";
			rlutil::anykey();
			ingreso = 0;

		}
		else {
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::WHITE);


			Persona::cargar();
			do
			{

				o.Menurectangulo(49, 22, 25, 3, "");
				std::cout << "Categoria" << std::endl;
				o.Menurectangulo(49, 25, 70, 3, "");
				std::cout << "1-Gerente\t2-Cajero/a\t3-Vendedor/a\t4-Auxiliar de Limpieza" << std::endl;
				o.Menurectangulo(65, 22, 0, 3, "");
				std::cout << ">";
				std::cin >> categoria;
				if (categoria < 1 || categoria>4)
				{
					rlutil::cls();
					std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
					rlutil::anykey();
					rlutil::cls();
				}
			} while (categoria < 1 || categoria>4);
			o.Menurectangulo(49, 28, 25, 3, "");
			std::cout << "Fecha de ingreso:\n";
			fechaDeIngreso.cargarFecha();
			do
			{
				o.Menurectangulo(49, 31, 58, 3, "");
				std::cout << "Tipo de jornada(f-Full-time/p-Part-time): ";
				std::cin >> tipoJornada;
				if (tolower(tipoJornada) != 'f' && tolower(tipoJornada) != 'p')
				{
					rlutil::cls();
					std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
					rlutil::anykey();
					rlutil::cls();
				}
			} while (tolower(tipoJornada) != 'f' && tolower(tipoJornada) != 'p');
			do {
				o.Menurectangulo(49, 34, 50, 3, "");
				std::cout << "Turno (M-Mañana/T-Tarde/N-Noche): ";
				std::cin >> turno;
				if (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n')
				{
					rlutil::cls();
					std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
					rlutil::anykey();
					rlutil::cls();
				}
			} while (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n');
			do {
				o.Menurectangulo(49, 37, 25, 3, "");
				std::cout << "Sueldo: $";
				std::cin >> sueldo;
				if (sueldo <= 0)
				{
					rlutil::cls();
					std::cout << "Error. Por favor ingrese un sueldo válido." << std::endl;
					rlutil::anykey();
					rlutil::cls();
				}
			} while (sueldo <= 0);
			ID = contRegistros() + 1;
			if (grabarEnDisco())
			{
				system("cls");
				o.Menurectangulo(49, 15, 28, 3, "");
				std::cout << "Empleado guardado con exito." << std::endl;
				system("pause");
				system("cls");
			}
			o.Menurectangulo(49, 4, 25, 3, "Pulsa'0' Salir | '1' No Salir ");
			std::cin >> ingreso;
		}

		ingreso = 0;


	}
	if (buscarRegistro(ingreso) == false) {
		//system("cls");
		
		std::cout << "empleado existente" << std::endl;
		rlutil::anykey();
	}
	rlutil::cls();
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
}


void Empleado::mostrar() {
    if (estado)
	{
		rlutil::cls();
		Menu ob;
		int y = 10;
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
		ob.Menurectangulo(45, y, 35, 3, "");
        std::cout << "ID: " << ID << std::endl;

		ob.Menurectangulo(45, y += 3, 35, 3, "");
		std::cout<<"Apellido y Nombre: "<< Persona::getApellido()<<" "<< getNombre();
        //Persona::mostrar();
		ob.Menurectangulo(45, y += 3, 35, 3, "");
        std::cout << "Categoria: ";
		switch (categoria)
		{
		case 1:
			std::cout << "1-Gerente" << std::endl;
			break;
		case 2:
			std::cout << "2-Cajero/a" << std::endl;
			break;
		case 3:
			std::cout << "3-Vendedor/a" << std::endl;
			break;
		default:
			std::cout << "4-Auxiliar de Limpieza" << std::endl;
			break;
		}
		ob.Menurectangulo(45, y += 3, 35, 3, "");
        std::cout << "Fecha de ingreso:\n";
		ob.Menurectangulo(66,19,15, 3, "");
        fechaDeIngreso.mostrarFecha();

		ob.Menurectangulo(45, y += 3, 35, 3, "");
        std::cout<< "Tipo de jornada: ";
        if (tolower(tipoJornada) == 'p')
        {
            std::cout << "Part-time";
        }
        else
        {
            std::cout << "Full-time";
        }

		ob.Menurectangulo(45, y += 3, 35, 3, "");

        std::cout<< "Turno: ";
        switch (tolower(turno))
        {
        case 'm':
            std::cout << "Mañana";
            break;
        case 't':
            std::cout << "Tarde";
            break;
        default:
            std::cout << "Noche";
            break;
        }
		ob.Menurectangulo(45, y += 3, 35, 3, "");
        std::cout << "Sueldo: $" << sueldo << std::endl;
    }
}


void Empleado::mostrarTodos() {
	int y = 0, pos = 0;
	Menu ob;
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
	while (leerDeDisco(pos))
	{
		if (estado) {
			y += 10;
			ob.Menurectangulo(45, y, 35, 3, "");
			std::cout << "ID: " << ID << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Apellido y Nombre: " << Persona::getApellido() << " " << getNombre();
			//Persona::mostrar();
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Categoria: " << getCategoria();
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Fecha de ingreso:\n";
			ob.Menurectangulo(66, 19, 15, 3, "");
			fechaDeIngreso.mostrarFecha();
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Tipo de jornada: " << getTipoJornada();
			///////////////////////////

		}
		pos++;
	}
}

bool Empleado::grabarEnDisco() {
	FILE* p = NULL;
	p = fopen("empleados.dat", "ab");
	if (p == NULL)
	{
		std::cout << "Error al guardar.\n";
		system("pause");
		return 0;
	}
	fwrite(this, sizeof(Empleado), 1, p);
	fclose(p);
	return 1;
}

bool Empleado::leerDeDisco(int n) {
    FILE* p = NULL;
    p = fopen("empleados.dat", "rb");
    if (p == NULL)
    {
        std::cout << "No hay registros.";
		rlutil::anykey();
        return false;
    }
    fseek(p, n * sizeof(Empleado), 0);
    int leyo=fread(this, sizeof(Empleado), 1, p);
    fclose(p);
    return leyo;
}

int Empleado::contRegistros()
{
	FILE* p = fopen("empleados.dat", "rb");
	if (p == NULL) {
		return 0; ///cantidad de registros cero 0
	}
	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Empleado);
	return cant_reg;
}

void Empleado::modificarEmpleado() {
	Menu o;
	int opcion, ingreso, id, nReg=0;
	bool ingresoCorrecto = true;
	FechaHora nuevaFecha;
	std::string palabra;
	bool bandera = false;
	do {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
		system("cls");
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
		o.Menurectangulo(25,5, 70, 3, "");
		std::cout << "Ingrese el ID del empleado a modificar o 0 para volver: ";
		std::cin >> id;
		
		nReg = buscarRegistro(id);
		if (nReg >= 0 && getEstado()==true)
		{
			do
			{
				system("cls");
				mostrar();
				std::cout << std::endl << std::endl;
				o.Menurectangulo(5, 1,25, 16, "EMPLEADO");
				rlutil::locate(5, 3);
				std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
				rlutil::locate(5, 4);
				std::cout << "1-DNI" << std::endl;
				rlutil::locate(5, 5);
				std::cout << "2-Fecha de nacimiento" << std::endl;
				rlutil::locate(5, 6);
				std::cout << "3-Nombre" << std::endl;
				rlutil::locate(5, 7);
				std::cout << "4-Apellido" << std::endl;
				rlutil::locate(5, 8);
				std::cout << "5-Categoría" << std::endl;
				rlutil::locate(5, 9);
				std::cout << "6-Tipo de jornada" << std::endl;
				rlutil::locate(5, 10);
				std::cout << "7-Turno" << std::endl;
				rlutil::locate(5, 11);
				std::cout << "8-Sueldo" << std::endl;
				rlutil::locate(5, 12);
				std::cout << "-------------------" << std::endl;
				rlutil::locate(5, 13);
				std::cout << "------------------" << std::endl;
				rlutil::locate(5, 14);
				std::cout << "0-Volver" << std::endl << std::endl;
				rlutil::locate(5, 15);
				std::cout << "Ingrese una opción: ";
				std::cin >> opcion;
				rlutil::cls();
				switch (opcion)
				{
				case 1:
					std::cout << "Ingrese un nuevo DNI: ";
					std::cin >> dni;
					break;
				case 2:
					std::cout << "Ingrese nueva fecha de nacimiento:" << std::endl;
					nuevaFecha.cargarFecha();
					setFechaDeNacimiento(nuevaFecha);
					break;
				case 3:
					std::cout << "Ingrese el nombre nuevo: ";
					std::cin.ignore();
					
					setNombre(palabra);
					break;
				case 4:
					std::cout << "Ingrese el apellido nuevo: ";
					std::cin.ignore();
					
					setApellido(palabra);
					break;
				case 5:
					do
					{
						std::cout << "Ingrese la categoría nueva: " << std::endl;
						std::cout << "Categoria\t\t1-Gerente\t2-Cajero/a\t3-Vendedor/a\t4-Auxiliar de Limpieza" << std::endl << '>';
						std::cin >> categoria;
						if (categoria < 1 || categoria>4) {
							rlutil::cls();
							std::cout << std::endl << std::endl << "Por favor ingrese una opción válida.";
							rlutil::anykey();
						}
						rlutil::cls();
					} while (categoria < 1 || categoria>4);
					break;
				case 6:
					do {
						std::cout << "Ingrese el nuevo tipo de jornada (p-Part time/f-Full time): " << std::endl;
						std::cin >> tipoJornada;
						rlutil::cls();
						if (tolower(tipoJornada) != 'p' && tolower(tipoJornada) != 'f')
						{
							std::cout << "Por favor ingrese una opción válida.";
							rlutil::anykey();
							rlutil::cls();
						}
					} while (tolower(tipoJornada) != 'p' && tolower(tipoJornada) != 'f');
					break;
				case 7:
					do
					{
						std::cout << "Ingrese el nuevo turno (m-Mañana/t-Tarde/n-Noche): " << std::endl;
						std::cin >> turno;
						rlutil::cls();
						if (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n')
						{
							std::cout << "Por favor ingrese una opción válida.";
							rlutil::anykey();
							rlutil::cls();
						}
					} while (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n');
					break;
				case 8:
					std::cout << "Ingrese el nuevo sueldo: " << std::endl;
					std::cin >> sueldo;
					break;
				default:
					if (opcion != 0)
					{
						std::cout << "Por favor ingrese una opción correcta.";
						rlutil::anykey();
					}
					break;
				}
				if (opcion != 0) {
					if (modificarEnDisco(nReg )) std::cout << "Modificación realizada con éxito.";
					else std::cout << "Error al modificar.";
					rlutil::anykey();
				}
				rlutil::cls();
			} while (opcion != 0);
		}
		else if (id != 0)
		{
			std::cout << "Error. No se ha encontrado el empleado.";
			rlutil::anykey();
		}
		rlutil::cls();

		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
	} while (id != 0);
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
}

void Empleado::eliminarEmpleado() {
	int c, confirmar, pos;
	Menu ob;
	do {
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
		ob.Menurectangulo(5, 10, 70, 2, "");
		std::cout << "Ingrese el ID del empleado a eliminar o 0 para volver: ";
		ob.Menurectangulo(5, 12, 70, 2, "");
		std::cin >> c;
		pos = buscarRegistro(c);
		rlutil::cls();

		if (pos < 0) {
			rlutil::setBackgroundColor(rlutil::WHITE);
			rlutil::setColor(rlutil::GREEN);
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
					setEstado ( false);
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
		if (c != 0) rlutil::anykey();
		rlutil::cls();
	} while (c != 0);
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);






	/*FILE* p;
	int escribio = 0;
	int id;
	bool bandera = false;
	p = fopen("empleados.dat", "rb+");
	if (p == NULL)
	{
		std::cout << "Error de archivo";
		return escribio;
	}
	std::cout << "Ingrese el ID del empleado a eliminar o presione 0 para volver atras: ";
	std::cin >> id;
	if (id != 0) {
		while (fread(this, sizeof(Empleado), 1, p))
		{
			if (id == getID())
			{
				setEstado(false);
				// se cambia el valor del campo estado
				fseek(p, ftell(p) - sizeof(Empleado), 0);
				//desplazamiento de part un registro hacia atrás
				escribio = fwrite(this, sizeof(Empleado), 1, p);
				// escritura del registro modificado
				fclose(p);
				return escribio;

			}
		}
		fclose(p);
		
	}
	
	else { std::cout << "Error. No se ha podido encontrar al empleado."; }
	*/
}


void Empleado::listarEmpleado() {
	int opcion, d, pos, numeroReg;
	
		bool bandera = false;
		Menu ob;
		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
		if (contRegistros() > 0) {
		do
		{
			pos = 0;
			rlutil::setColor(rlutil::WHITE);
			rlutil::setBackgroundColor(rlutil::GREEN);
			ob.Menurectangulo(45, 8, 35, 3, "");
			std::cout << "Seleccion una opcion" << std::endl;
			ob.Menurectangulo(45, 11, 35, 3, "");
			std::cout << "1-Listar todos los Empleados" << std::endl;
			ob.Menurectangulo(45, 14, 35, 3, "");
			std::cout << "2-Listar un Empleado por ID" << std::endl;
			ob.Menurectangulo(45, 17, 35, 3, "");
			std::cout << "0 Volver " << std::endl;
			ob.Menurectangulo(45, 20, 35, 3, "");
			std::cin >> opcion;
			rlutil::cls();
			switch (opcion)
			{
			case 1:
				mostrarTodos();
				break;
			case 2:
				std::cout << "Ingrese el número de venta que quiere listar o 0 para volver: ";
				std::cin >> d;
				if (d != 0) {
					rlutil::cls();
					if (buscarRegistro(d) < 0) std::cout << "No se ha podido encontrar el empleado.";
					else
					{
						if (estado) {
							bandera = true;
							mostrar();
						}
						else std::cout << "No se ha podido encontrar el empleado.";
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
		} while (opcion != 0);
	}
	else {
		rlutil::cls;
		ob.Menurectangulo(45, 8,20, 3, "NO HAY REGISTROS");
		rlutil::anykey();
	}

	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
}

bool Empleado::modificarEnDisco(int pos) {
	FILE* p = NULL;
	p = fopen("empleados.dat", "rb+");
	if (p == NULL)return 0;
	fseek(p, pos * sizeof(Empleado), 0);
	bool escribio=fwrite(this, sizeof(Empleado), 1, p);
	fclose(p);
	return escribio;
}

int Empleado::buscarRegistro(int id) {
	int pos = 0;
	while (leerDeDisco(pos))
	{

		if (id == getID()) return pos;
		pos++;
	}

	return -1;
}
