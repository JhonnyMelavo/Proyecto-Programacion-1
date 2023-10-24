#include"Hora.h"

Hora::Hora(int h, int m) {
	H = h;
	M = m;
}
Hora::~Hora() {}

void Hora::setHora(int h) { H = h; }
void Hora::setMinutos(int m) { M = m; }
int Hora::getHora() { return H; }
int Hora::getMinutos() { return M; }

string Hora::toString() {
	stringstream s;
	s << setfill('0') << setw(2) << H << ":" << setw(2) << M;
	return s.str();
}