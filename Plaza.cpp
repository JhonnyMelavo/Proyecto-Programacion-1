#include"Plaza.h"

Plaza::Plaza(string cod, string pue) {
	Codigo = cod;
	Puesto = pue;
}
Plaza::~Plaza() {}

void Plaza::setCodigo(string cod) {
	Codigo = cod;
}
void Plaza::setPuesto(string pue) {
	Puesto = pue;
}

string Plaza::getCodigo() { return Codigo; }
string Plaza::getPuesto() { return Puesto; }

string Plaza::toString() {
	stringstream s;
	s << "--Plaza--" << endl << "Codigo: " << Codigo << endl << "Puesto: " << Puesto << endl;
	return s.str();
}
