#include "Persona.h"
#include"Menu.h"

void Persona::cargar() {
	
	Menu o;
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::GREEN);
	std::string palabra;
	estado = true;
	system("cls");
	
	o.Menurectangulo(49, 4, 25, 3, "Completar ");
	
	o.Menurectangulo(49, 7, 25, 3, "");
	
		
		std::cout << "Nombre: ";
		std::cin.ignore();
		std::getline(std::cin, palabra);
		setNombre(palabra);
		o.Menurectangulo(49, 10, 25, 3, "");
		std::cout << "Apellido: ";
		std::getline(std::cin, palabra);
		setApellido(palabra);
		o.Menurectangulo(49, 13, 25, 3, "");
		std::cout << "DNI: ";
		std::cin >> dni;
		o.Menurectangulo(49, 16, 25, 3, "");
		std::cout << "Fecha de nacimiento: \n";
		fechaDeNacimiento.cargarFecha();

		rlutil::setColor(rlutil::WHITE);
		rlutil::setBackgroundColor(rlutil::GREEN);
	
	//domicilio.cargar();
}
void Persona::cargar(int _dni) {
	std::string palabra;
	estado = true;
	std::cout << "Nombre: ";
	std::cin.ignore();
	std::getline(std::cin,palabra);
	setNombre(palabra);
	std::cout << "Apellido: ";
	std::getline(std::cin,palabra);
	setApellido(palabra);
	dni = _dni;
	std::cout << "Fecha de nacimiento: \n";
	fechaDeNacimiento.cargarFecha();
	//domicilio.cargar();
}
void Persona::mostrar() {
	std::cout << "Nombre y apellido: ";
	std::cout << nombre << " "<< apellido ;
	std::cout << "  DNI:    ";
	std::cout << dni;
	std::cout << "  \nFecha de nacimiento: \n";
	fechaDeNacimiento.mostrarFecha();
	
	//domicilio.mostrar();	
}


std::string Persona::getApellido() 
{
	std::string apellido = this->apellido;
    return apellido;
}

void Persona::setApellido(std::string apellido)
{
    strcpy(this->apellido,apellido.c_str());
}

std::string Persona::getNombre() 
{
	std::string nombre = this->nombre;
    return nombre;
}

void Persona::setNombre(std::string nombre)
{
    strcpy(this->nombre, nombre.c_str());
}

int Persona::getDni() const
{
    return dni;
}

void Persona::setDni(int dni)
{
    this->dni = dni;
}

FechaHora Persona::getFechaDeNacimiento() 
{
    return fechaDeNacimiento;
}

void Persona::setFechaDeNacimiento(FechaHora fechaDeNacimiento)
{
    this->fechaDeNacimiento = fechaDeNacimiento;
}

bool Persona::getEstado()
{
	return estado;
}

void Persona::setEstado(bool estado)
{
	this->estado = estado;
}