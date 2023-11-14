#include"Contrato.h"

Contrato::Contrato(string cod, string des, double sal) {
	codigo = cod;
	descripcion = des;
	salario = sal;
}
Contrato::~Contrato() {}

void Contrato::setCodigo(string cod) { codigo = cod; }
void Contrato::setDescripcion(string des) { descripcion = des; }
void Contrato::setSalario(double sal) { salario = sal; }

string Contrato::getCodigo() { return codigo; }
string Contrato::getDescripcion() { return descripcion; }
double Contrato::getSalario() { return salario; }

string Contrato::toString() {
	stringstream s;
	s << "----Contrato----" << endl << "Codigo: " << codigo << endl << "Descripcion de puesto: " << descripcion << endl << "Salario: " << salario << endl;
	return s.str();
}

void Contrato::setHoraEntrada(Hora&) {}
void Contrato::setHoraSalida(Hora&) {}
void Contrato::setTipoSerivico(string) {}

Hora* Contrato::getHoraEntrada() { return NULL; }
Hora* Contrato::getHoraSalida() { return NULL; }
string Contrato::getTipoServicio() { return ""; }

//Contrato Servicios

ContratoServicios::ContratoServicios(string cod, string des, double sal, Hora& HE, Hora& HS, string tip, Fecha& feI, Fecha& feC) :Contrato(cod, des, sal) {
	horaEntrada = (Hora*)&HE;
	horaSalida = (Hora*)&HS;
	tipoServicio = tip;
	fechaInicio = (Fecha*)&feI;
	fechaCese = (Fecha*)&feC;
}
ContratoServicios::~ContratoServicios() {
	if (horaEntrada != NULL) {
		delete horaEntrada;
	}
	if (horaSalida != NULL) {
		delete horaSalida;
	}
	if (fechaInicio != NULL) {
		delete fechaInicio;
	}
	if (fechaCese != NULL) {
		delete fechaCese;
	}
}

void ContratoServicios::setHoraEntrada(Hora& HE) { horaEntrada = (Hora*)&HE; }
void ContratoServicios::setHoraSalida(Hora& HS) { horaSalida = (Hora*)&HS; }
void ContratoServicios::setTipoSerivico(string tip) { tipoServicio = tip; }
void ContratoServicios::setFechaInicio(Fecha& feI) { fechaInicio = (Fecha*)&feI; }
void ContratoServicios::setFechaCese(Fecha& feC) { fechaCese = (Fecha*)&feC; }

Hora* ContratoServicios::getHoraEntrada() { return horaEntrada; }
Hora* ContratoServicios::getHoraSalida() { return horaSalida; }
string ContratoServicios::getTipoServicio() { return tipoServicio; }
Fecha* ContratoServicios::getFechaInicio() { return fechaInicio; }
Fecha* ContratoServicios::getFechaCese() { return fechaCese; }

bool ContratoServicios::esServicio() { return true; }
bool ContratoServicios::esPlazo() { return false; }
bool ContratoServicios::esIndefinido() { return false; }

string ContratoServicios::toString() {
	stringstream s;
	s << Contrato::toString() << endl << "Tipo de servicio: " << tipoServicio << endl
		<< "Hora Entrada: " << horaEntrada->toString() << endl
		<< "Hora Salida: " << horaSalida->toString() << endl
		<< "Periodo de servicio: " << fechaInicio->toString() << " - " << fechaCese->toString() << endl;
	return s.str();
}

//Contrato Plazo

ContratoPlazo::ContratoPlazo(string cod, string des, double sal, Fecha& feI, Fecha& feC) : Contrato(cod, des, sal) {
	fechaInicio = (Fecha*)&feI;
	fechaCese = (Fecha*)&feC;
}
ContratoPlazo::~ContratoPlazo() {
	if (fechaInicio != NULL) {
		delete fechaInicio;
	}
	if (fechaCese != NULL) {
		delete fechaCese;
	}
}

void ContratoPlazo::setFechaInicio(Fecha& feI) { fechaInicio = (Fecha*)&feI; }
void ContratoPlazo::setFechaCese(Fecha& feC) { fechaCese = (Fecha*)&feC; }

Fecha* ContratoPlazo::getFechaInicio() { return fechaInicio; }
Fecha* ContratoPlazo::getFechaCese() { return fechaCese; }

bool ContratoPlazo::esServicio() { return false; }
bool ContratoPlazo::esPlazo() { return true; }
bool ContratoPlazo::esIndefinido() { return false; }

string ContratoPlazo::toString() {
	stringstream s;
	s << Contrato::toString() << endl << "Periodo de servicio: " << fechaInicio->toString() << " - " << fechaCese->toString() << endl;
	return s.str();
}

//Contrato Tiempo Indefinido

ContratoIndefinido::ContratoIndefinido(string cod, string des, double sal, Plaza& plaz, Fecha& feI) : Contrato(cod, des, sal) {
	plaza = (Plaza*)&plaz;
	fechaInicio = (Fecha*)&feI;
	fechaCese = NULL;
}
ContratoIndefinido::~ContratoIndefinido(){
	if (fechaInicio != NULL) {
		delete fechaInicio;
	}
	if (fechaCese != NULL) {
		delete fechaCese;
	}
	if (plaza != NULL) {
		delete plaza;
	}
}

void ContratoIndefinido::setPlaza(Plaza& pla) { plaza = (Plaza*)&pla; }
void ContratoIndefinido::setFechaInicio(Fecha& feI) { fechaInicio = (Fecha*)&feI; }
void ContratoIndefinido::setFechaCese(Fecha& feC) { fechaCese = (Fecha*)&feC; }

Plaza* ContratoIndefinido::getPlaza() { return plaza; }
Fecha* ContratoIndefinido::getFechaInicio() { return fechaInicio; }
Fecha* ContratoIndefinido::getFechaCese() {	return fechaCese; }

bool ContratoIndefinido::esServicio() { return false; }
bool ContratoIndefinido::esPlazo() { return false; }
bool ContratoIndefinido::esIndefinido() { return true; }

string ContratoIndefinido::toString() {
	stringstream s;
	s << Contrato::toString() << endl << plaza->toString() << "Fecha de inicio: " << fechaInicio->toString() << endl;
	if (fechaCese != NULL) {
		s << "Fecha de cese: " << fechaCese->toString() << endl;
	}
	return s.str();
}