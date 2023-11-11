#include"Aeropuerto.h"

Aeropuerto::Aeropuerto(string ce, string no, string te): Cedula(ce), Nombre(no), Telefono(te) {
	Contratos = new ContContrato();
	Empleados = new ContEmpleado();
	Aeronaves = new ContAvion();
}
Aeropuerto::~Aeropuerto() {
	if (Contratos != NULL) {
		delete Contratos;
	}
	if (Empleados != NULL) {
		delete Empleados;
	}
	if (Aeronaves != NULL) {
		delete Aeronaves;
	}
}

void Aeropuerto::setNombre(string no) { Nombre = no; }
void Aeropuerto::setCedula(string ce) { Cedula = ce; }
void Aeropuerto::setTelefono(string tel) { Telefono = tel; }

string Aeropuerto::getNombre() { return Nombre; }
string Aeropuerto::getCedula() { return Cedula; }
string Aeropuerto::getTelefono() { return Telefono; }

int Aeropuerto::getCantidadContratos() {
	return Contratos->cantidad();
}
int Aeropuerto::getCantidadEmpleados() {
	return Empleados->cantidad();
}
int Aeropuerto::getCantidadAeronaves() {
	return Aeronaves->cantidad();
}
int Aeropuerto::getCantidadPilotos() {
	return Empleados->cantidadPilotos();
}
int Aeropuerto::getCantidadEmpleadosSinContrato() {
	return Empleados->cantidadSinContrato();
}

Contrato* Aeropuerto::contratoCod(string cod) {
	return Contratos->ContratoCod(cod);
}
Empleado* Aeropuerto::empleadoCed(string id) {
	return Empleados->EmpleadoCed(id);
}
Aeronave* Aeropuerto::aeronavePla(string pla) {
	return Aeronaves->AeronavePlaca(pla);
}
Aeronave* Aeropuerto::naveN(int n) {
	return Aeronaves->naveN(n);
}
Empleado* Aeropuerto::empleadoN(int n) {
	return Empleados->EmpleadoN(n);
}
Contrato* Aeropuerto::contratoN(int n) {
	return Contratos->ContratoN(n);
}
bool Aeropuerto::hayPiloto(Aeronave* aero) {
	return Empleados->hayPiloto(aero);
}
bool Aeropuerto::hayCopiloto(Aeronave* aero) {
	return Empleados->hayCopiloto(aero);
}
string Aeropuerto::getPlacas() {
	return Aeronaves->Placas();
}
string Aeropuerto::empleadosSinContrato() {
	return Empleados->empleadosSinContrato();
}

string Aeropuerto::toStringContratos() {
	return Contratos->toString();
}
string Aeropuerto::toStringEmpleados() {
	return Empleados->toString();
}
string Aeropuerto::toStringAeronaves() {
	return Aeronaves->toString();
}

void Aeropuerto::agregarContrato(Contrato& con) {
	Contratos->Agregar(con);
}
void Aeropuerto::agregarEmpleado(Empleado& emp) {
	Empleados->Agregar(emp);
}
void Aeropuerto::agregarAeronave(Aeronave& nave) {
	Aeronaves->Agregar(nave);
}

void Aeropuerto::setContrato(Contrato& con, int n) {
	Empleados->setContrato(con, n);
}