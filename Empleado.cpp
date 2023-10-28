#include"Empleado.h"

Empleado::Empleado(string ce, string no, int ed, Contrato& con): cedula(ce), nombre(no), edad(ed) {
	contrato = (Contrato*)&con;
}
Empleado::~Empleado() {
	if (contrato != NULL) {
		delete contrato;
	}
}

void Empleado::setCedula(string ce) { cedula = ce; }
void Empleado::setNombre(string no) { nombre = no; }
void Empleado::setEdad(int ed) { edad = ed; }
void Empleado::setContrato(Contrato& con) {
	if (contrato != NULL) {
		delete contrato;
	}
	contrato = (Contrato*)&con;
}

string Empleado::getCedula() { return cedula; }
string Empleado::getNombre() { return nombre; }
int Empleado::getEdad() { return edad; }
Contrato* Empleado::getContrato() { return contrato; }

string Empleado::toString() {
	stringstream s;
	s << "== Empleado ==" << endl << "Cedula: " << cedula << endl << "Nombre: " << nombre << endl << "Edad: " << edad << endl;
	if (contrato != NULL) {
		s << contrato->toString();
	}
	return s.str();
}

//Tripulacion----------------------------------------------------------------------------------------------------------------------------------

EmpleadoTripulacion::EmpleadoTripulacion(string ce, string no, int ed, Contrato& con, Aeronave& aero): Empleado::Empleado(ce,no,ed,con) {
	nave = (Aeronave*)&aero;
}
EmpleadoTripulacion::~EmpleadoTripulacion() {}

void EmpleadoTripulacion::setAeronave(Aeronave& aero) {
	nave = (Aeronave*)&aero;
}

Aeronave* EmpleadoTripulacion::getAeronave() { return nave; }

//Tripulacion: Piloto

Piloto::Piloto(string ce, string no, int ed, Contrato& con, Aeronave& aero, int a) : EmpleadoTripulacion::EmpleadoTripulacion(ce, no, ed, con, aero), aniosExp(a) {}
Piloto::~Piloto() {}

void Piloto::setAniosExp(int a) { aniosExp = a; }

int Piloto::getAniosExp() { return aniosExp; }

string Piloto::toString() {
	stringstream s;
	s << Empleado::toString() << "-Piloto-" << endl << "Años de experiencia: " << aniosExp << endl;
	return s.str();
}

//Tripulacion: Copiloto

Copiloto::Copiloto(string ce, string no, int ed, Contrato& con, Aeronave& aero, string tel) : EmpleadoTripulacion::EmpleadoTripulacion(ce, no, ed, con, aero), telefono(tel) {}
Copiloto::~Copiloto() {}

void Copiloto::setTelefono(string tel) { telefono = tel; }

string Copiloto::getTelefono() { return telefono; }

string Copiloto::toString() {
	stringstream s;
	s << Empleado::toString() << "-Copiloto-" << endl << "Numero de telefono: " << telefono << endl;
	return s.str();
}

//Tripulacion Azafata

Azafata::Azafata(string ce, string no, int ed, Contrato& con, Aeronave& aero, string nac) : EmpleadoTripulacion::EmpleadoTripulacion(ce, no, ed, con, aero), nacionalidad(nac) {}
Azafata::~Azafata() {}

void Azafata::setNacionalidad(string nac) { nacionalidad = nac; }

string Azafata::getNacionalidad() { return nacionalidad; }

string Azafata::toString() {
	stringstream s;
	s << Empleado::toString() << "-Azafata-" << endl << "Nacionalidad: " << nacionalidad << endl;
	return s.str();
}

//Planta---------------------------------------------------------------------------------------------------------------------------------------

//Administrativo

EmpleadoAdmi::EmpleadoAdmi(string ce, string no, int ed, Contrato& con, string tit) : Empleado::Empleado(ce, no, ed, con), titulo(tit) {}
EmpleadoAdmi::~EmpleadoAdmi() {}

void EmpleadoAdmi::setTitulo(string tit) { titulo = tit; }

string EmpleadoAdmi::getTitulo() { return titulo; }

string EmpleadoAdmi::toString() {
	stringstream s;
	s << Empleado::toString() << "-Administrativo-" << endl << "Titulo: " << titulo << endl;
	return s.str();
}

//Miscelaneo

Miscelaneo::Miscelaneo(string ce, string no, int ed, Contrato& con, string gra, string are) : Empleado::Empleado(ce, no, ed, con), gradoEscolaridad(gra), areaTrabajo(are) {}
Miscelaneo::~Miscelaneo() {}

void Miscelaneo::setGradoEscolaridad(string gra) { gradoEscolaridad = gra; }
void Miscelaneo::setAreaTrabajo(string are) { areaTrabajo = are; }

string Miscelaneo::getGradoEscolaridad() { return gradoEscolaridad; }
string Miscelaneo::getAreaTrabajo() { return areaTrabajo; }

string Miscelaneo::toString() {
	stringstream s;
	s << Empleado::toString() << "-Miscelaneo-" << endl << "Grado de escolaridad: " << gradoEscolaridad << endl << "Area de trabajo: " << areaTrabajo << endl;
	return s.str();
}