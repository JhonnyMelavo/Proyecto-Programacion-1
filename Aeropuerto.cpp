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
int Aeropuerto::getCantidadCopilotos() {
	return Empleados->cantidadCopilotos();
}
int Aeropuerto::getCantidadAzafatas() {
	return Empleados->cantidadAzafatas();
}
int Aeropuerto::getCantidadEmpleadosSinContrato() {
	return Empleados->cantidadSinContrato();
}
int Aeropuerto::getCantidadMilitares() {
	return Aeronaves->cantidadMilitares();
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
bool Aeropuerto::hayAzafata(Aeronave* aero) {
	return Empleados->hayAzafata(aero);
}
bool Aeropuerto::EsMilitar(Aeronave* aero) {
	return Aeronaves->EsMilitar(aero);
}
string Aeropuerto::getPlacas() {
	return Aeronaves->Placas();
}
string Aeropuerto::empleadosSinContrato() {
	return Empleados->empleadosSinContrato();
}
bool Aeropuerto::PasarEmpleados(Aeronave& nav1, Aeronave& nav2) {
	return Empleados->pasarEmpleados(nav1, nav2);
}
string Aeropuerto::toStringAeronavesConTripulacion(Aeronave& nave) {
	return Empleados->toStringEmpleadosEnAeronave(nave);
}
string Aeropuerto::pilotosCarga() {
	return Empleados->pilotosCarga();
}
string Aeropuerto::AeronavesMas20(Fecha& act) {
	return Aeronaves->AeronavesMas20(act);
}
string Aeropuerto::ContratosServicios() {
	return Contratos->ContratosSerivicios();
}
string Aeropuerto::ContratosPlazo() {
	return Contratos->ContratosPlazo();
}
string Aeropuerto::ContratosIndefinidos() {
	return Contratos->ContratosIndefinido();
}
string Aeropuerto::TripulacionComerciales() {
	return Aeronaves->TripulacionComerciales(*Empleados);
}
Aeronave* Aeropuerto::PuertaMasGrande() {
	return Aeronaves->PuertaMasGrande();
}
string Aeropuerto::ContratosPlazoMas2(Fecha& fe) {
	return Contratos->ContratosMas2(fe);
}
int Aeropuerto::cantidadContratosPlazoMas2(Fecha& fe) {
	return Contratos->cantidadContratosMas2(fe);
}
Empleado* Aeropuerto::EmpleadoConContrato(Contrato& con) {
	return Empleados->EmpleadoConContrato(con);
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

bool Aeropuerto::eliminarContrato(Contrato& con) {
	return Contratos->Eliminar(con);
}
bool Aeropuerto::eliminarEmpleado(Empleado& emp) {
	return Empleados->Eliminar(emp);
}
bool Aeropuerto::eliminarAeronaves(Aeronave& nave) {
	return Aeronaves->Eliminar(nave);
}

void Aeropuerto::setContrato(Contrato& con, int n) {
	Empleados->setContrato(con, n);
}