#include"Aeronave.h"

Aeronave::Aeronave(Fecha& fe, double dis): distaciaRecorrida(dis) {
	fechaCreacion = (Fecha*)&fe;
}
Aeronave::~Aeronave() {
	if (fechaCreacion != NULL) {
		delete fechaCreacion;
	}
}

void Aeronave::setFechaCreacion(Fecha& fe) {
	if (fechaCreacion != NULL) {
		delete fechaCreacion;
	}
	fechaCreacion = (Fecha*)&fe;
}
void Aeronave::setDistaciaRecorrida(double dis) { distaciaRecorrida = dis; }

Fecha* Aeronave::getFechaCreacion() { return fechaCreacion; }
double Aeronave::getDistanciaRecorrida() { return distaciaRecorrida; }

string Aeronave::toString() {
	stringstream s;
	s << "== Aeronave ==" << endl;
	if (fechaCreacion != NULL) {
		s << "Fecha de creacion: " << fechaCreacion->toString() << endl;
	}
	s << "Distancia recorrida: " << distaciaRecorrida << endl;
	return s.str();
}

