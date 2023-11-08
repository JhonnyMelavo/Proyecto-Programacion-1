#pragma once
#include"ContContrato.h";
#include"ContEmpleado.h";
#include"ContAvion.h";

class Aeropuerto {
private:
	string Nombre;
	string Cedula;
	string Telefono;
	ContContrato* Contratos;
	ContEmpleado* Empleados;
	ContAvion* Aviones;
public:
	Aeropuerto(string, string, string);
	~Aeropuerto();

	void setNombre(string);
	void setCedula(string);
	void setTelefono(string);

	string getNombre();
	string getCedula();
	string getTelefono();


};