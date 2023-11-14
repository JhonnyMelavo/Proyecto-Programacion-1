#include"Fecha.h"

Fecha::Fecha(int d, int m, int a) {
	dia = d;
	mes = m;
	anio = a;
}
Fecha::~Fecha() {}

void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }

int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

bool Fecha::mas20Anios(Fecha& act) {
	if (act.getAnio() - anio > 20) {
		return true;
	}
	else if (act.getAnio() - anio == 20 && act.getMes() > mes) {
		return true;
	}
	else if (act.getAnio() - anio == 20 && act.getMes() == mes && act.getDia() >= dia) {
		return true;
	}
	else {
		return false;
	}
}
bool Fecha::mas2Anios(Fecha& act) {
	if (act.getAnio() - anio > 2) {
		return true;
	}
	else if (act.getAnio() - anio == 2 && act.getMes() > mes) {
		return true;
	}
	else if (act.getAnio() - anio == 2 && act.getMes() == mes && act.getDia() >= dia) {
		return true;
	}
	else {
		return false;
	}
}

string Fecha::toString() {
	stringstream s;
	s << dia << "/" << mes << "/" << anio;
	return s.str();
}