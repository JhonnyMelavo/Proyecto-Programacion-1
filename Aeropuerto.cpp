#include"Aeropuerto.h"

Aeropuerto::Aeropuerto(string no, string ce, string te): Nombre(no), Cedula(ce), Telefono(te) {
	Contratos = new ContContrato();
	Empleados = new ContEmpleado();
	Aviones = new ContAvion();
}
Aeropuerto::~Aeropuerto() {
	if (Contratos != NULL) {
		delete Contratos;
	}
	if (Empleados != NULL) {
		delete Empleados;
	}
	if (Aviones != NULL) {
		delete Aviones;
	}
}

void Aeropuerto::setNombre(string no) { Nombre = no; }
void Aeropuerto::setCedula(string ce) { Cedula = ce; }
void Aeropuerto::setTelefono(string tel) { Telefono = tel; }

string Aeropuerto::getNombre() { return Nombre; }
string Aeropuerto::getCedula() { return Cedula; }
string Aeropuerto::getTelefono() { return Telefono; }


