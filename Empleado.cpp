#include"Empleado.h"

Empleado::Empleado(string ce, string no, int ed): cedula(ce), nombre(no), edad(ed) {
	contrato = NULL;
}
Empleado::~Empleado() {}

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

EmpleadoTripulacion::EmpleadoTripulacion(string ce, string no, int ed, Aeronave& aero): Empleado::Empleado(ce,no,ed) {
	nave = (Aeronave*)&aero;
}
EmpleadoTripulacion::~EmpleadoTripulacion() {}

void EmpleadoTripulacion::setAeronave(Aeronave& aero) {
	nave = (Aeronave*)&aero;
}

Aeronave* EmpleadoTripulacion::getAeronave() { return nave; }

//Tripulacion: Piloto

Piloto::Piloto(string ce, string no, int ed, Aeronave& aero, int a) : EmpleadoTripulacion::EmpleadoTripulacion(ce, no, ed, aero), aniosExp(a) {}
Piloto::~Piloto() {}

void Piloto::setAniosExp(int a) { aniosExp = a; }

int Piloto::getAniosExp() { return aniosExp; }
string Piloto::getTelefono() { return " "; }
string Piloto::getNacionalidad() { return " "; }

string Piloto::toString() {
	stringstream s;
	s << Empleado::toString() << "-Piloto-" << endl << "Años de experiencia: " << aniosExp << endl;
	return s.str();
}

//Tripulacion: Copiloto

Copiloto::Copiloto(string ce, string no, int ed, Aeronave& aero, string tel) : EmpleadoTripulacion::EmpleadoTripulacion(ce, no, ed, aero), telefono(tel) {}
Copiloto::~Copiloto() {}

void Copiloto::setTelefono(string tel) { telefono = tel; }

int Copiloto::getAniosExp() { return -1; }
string Copiloto::getTelefono() { return telefono; }
string Copiloto::getNacionalidad() { return " "; }

string Copiloto::toString() {
	stringstream s;
	s << Empleado::toString() << "-Copiloto-" << endl << "Numero de telefono: " << telefono << endl;
	return s.str();
}

//Tripulacion Azafata

Azafata::Azafata(string ce, string no, int ed, Aeronave& aero, string nac) : EmpleadoTripulacion::EmpleadoTripulacion(ce, no, ed, aero), nacionalidad(nac) {}
Azafata::~Azafata() {}

void Azafata::setNacionalidad(string nac) { nacionalidad = nac; }

string Azafata::getNacionalidad() { return nacionalidad; }
int Azafata::getAniosExp() { return -1; }
string Azafata::getTelefono() { return " "; }

string Azafata::toString() {
	stringstream s;
	s << Empleado::toString() << "-Azafata-" << endl << "Nacionalidad: " << nacionalidad << endl;
	return s.str();
}

//Planta---------------------------------------------------------------------------------------------------------------------------------------

//Administrativo

EmpleadoAdmi::EmpleadoAdmi(string ce, string no, int ed, string tit) : Empleado::Empleado(ce, no, ed), titulo(tit) {}
EmpleadoAdmi::~EmpleadoAdmi() {}

void EmpleadoAdmi::setTitulo(string tit) { titulo = tit; }

string EmpleadoAdmi::getTitulo() { return titulo; }
Aeronave* EmpleadoAdmi::getAeronave() { return NULL; }
void EmpleadoAdmi::setAeronave(Aeronave& aero) {}
int EmpleadoAdmi::getAniosExp() { return -1; }
string EmpleadoAdmi::getTelefono() { return " "; }
string EmpleadoAdmi::getNacionalidad() { return " "; }

string EmpleadoAdmi::toString() {
	stringstream s;
	s << Empleado::toString() << "-Administrativo-" << endl << "Titulo: " << titulo << endl;
	return s.str();
}

//Miscelaneo

Miscelaneo::Miscelaneo(string ce, string no, int ed, string gra, string are) : Empleado::Empleado(ce, no, ed), gradoEscolaridad(gra), areaTrabajo(are) {}
Miscelaneo::~Miscelaneo() {}

void Miscelaneo::setGradoEscolaridad(string gra) { gradoEscolaridad = gra; }
void Miscelaneo::setAreaTrabajo(string are) { areaTrabajo = are; }

string Miscelaneo::getGradoEscolaridad() { return gradoEscolaridad; }
string Miscelaneo::getAreaTrabajo() { return areaTrabajo; }
Aeronave* Miscelaneo::getAeronave() { return NULL; }
void Miscelaneo::setAeronave(Aeronave& aero) {}
int Miscelaneo::getAniosExp() { return -1; }
string Miscelaneo::getTelefono() { return " "; }
string Miscelaneo::getNacionalidad() { return " "; }

string Miscelaneo::toString() {
	stringstream s;
	s << Empleado::toString() << "-Miscelaneo-" << endl << "Grado de escolaridad: " << gradoEscolaridad << endl << "Area de trabajo: " << areaTrabajo << endl;
	return s.str();
}