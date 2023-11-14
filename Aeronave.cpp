#include"Aeronave.h"

Aeronave::Aeronave(Fecha& fe, double dis, string pla): distaciaRecorrida(dis), placa(pla) {
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
void Aeronave::setPlaca(string pla) { placa = pla; }

Fecha* Aeronave::getFechaCreacion() { return fechaCreacion; }
double Aeronave::getDistanciaRecorrida() { return distaciaRecorrida; }
string Aeronave::getPlaca() { return placa; }
string Aeronave::toString() {
	stringstream s;
	s << "== Aeronave ==" << endl;
	if (fechaCreacion != NULL) {
		s << "Fecha de creacion: " << fechaCreacion->toString() << endl;
	}
	s << "Distancia recorrida: " << distaciaRecorrida << endl;
	s << "Numero de placa: " << placa << endl;
	return s.str();
}

//Aviacion Civil

AviacionCivil::AviacionCivil(Fecha& fe, double dis, string pla): Aeronave::Aeronave(fe, dis, pla) {}
AviacionCivil::~AviacionCivil() {}

//Comercial

Comerciales::Comerciales(Fecha& fe, double dis, string pla, int cat, bool tip) : AviacionCivil::AviacionCivil(fe, dis, pla), Categoria(cat), Tipo(tip) {}
Comerciales::~Comerciales() {}

void Comerciales::setCategoria(int cat) { Categoria = cat; }
void Comerciales::setTipo(bool tip) { Tipo = tip; }

int Comerciales::getCategoria() { return Categoria; }
bool Comerciales::getTipo() { return Tipo; }
string Comerciales::getcategoria() { 
	stringstream s;
	s << Categoria;
	return s.str();
}
bool Comerciales::esMilitar() {
	if (ServicioMilitar::Avion(getcategoria()) != "idf") { return true; }
	else { return false; }
}
bool Comerciales::esCarga() {
	if (ServicioCarga::Avion(getcategoria()) != "idf") { return true; }
	else { return false; }
}
double Comerciales::tamPuerta() {
	return 0;
}

string Comerciales::toString() {
	stringstream s;
	s << AviacionCivil::toString() << endl << "-Comercial-" << endl << "Tipo: ";
	if (Tipo) {
		s << "Pasillo unico" << endl;
	}
	else {
		s << "Pasillo doble" << endl;
	}
	s << "Categoria: " << Categoria << endl << endl << "Avion: " << ServicioComercial::Avion(Categoria) << endl 
		<< "Cantidad de pasajeros: " << ServicioComercial::Pasajeros(Categoria) << endl << "Rango: " << 
		ServicioComercial::Rango(Categoria) << "Km" << endl << "Velocidad: " << ServicioComercial::Velocidad(Categoria)
		<< "Km/h" << endl << "Precio: " << ServicioComercial::Precio(Categoria) << " Millones de dolares" << endl;
	return s.str();
}

//Carga

Carga::Carga(Fecha& fe, double dis, string pla, double alt, double anc, string cat, bool tip) : AviacionCivil::AviacionCivil(fe, dis, pla), AlturaPuerta(alt), AnchuraPuerta(anc), Categoria(cat), Tipo(tip) {}
Carga::~Carga() {}

void Carga::setAltura(double alt) { AlturaPuerta = alt; }
void Carga::setAnchura(double anc) { AnchuraPuerta = anc; }
void Carga::setCategoria(string cat) { Categoria = cat; }
void Carga::setTipo(bool tip) { Tipo = tip; }

double Carga::getAltura() { return AlturaPuerta; }
double Carga::getAnchura() { return AnchuraPuerta; }
string Carga::getcategoria() { return Categoria; }
bool Carga::getTipo() { return Tipo; }
bool Carga::esMilitar() {
	if (ServicioMilitar::Avion(getcategoria()) != "idf") { return true; }
	else { return false; }
}
bool Carga::esCarga() {
	if (ServicioCarga::Avion(getcategoria()) != "idf") { return true; }
	else { return false; }
}
double Carga::tamPuerta() {
	return AlturaPuerta * AnchuraPuerta;
}

string Carga::toString() {
	stringstream s;
	s << AviacionCivil::toString() << endl << "-Carga-" << endl << "Tipo: ";
	if (Tipo) {
		s << "Puerta Lateral" << endl;
	}
	else {
		s << "Escotilla" << endl;
	}
	s << "Altura de puerta: " << AlturaPuerta << "cm" << endl << "Anchura puerta: " << AnchuraPuerta << "cm" << endl
		<< "Categoria: " << Categoria << endl << endl << "Avion: " << ServicioCarga::Avion(Categoria) << endl << "Carga: " <<
		ServicioCarga::Carga(Categoria) << "m^3" << endl << "Cantidad de pasajeros: " << ServicioCarga::Pasajeros(Categoria) << endl <<
		"Alcance: " << ServicioCarga::Alcance(Categoria) << "Km" << endl;
	return s.str();
}

//Militar

Militar::Militar(Fecha& fe, double dis, string pla, double vel, string cat) : Aeronave::Aeronave(fe, dis, pla), VelocidadM(vel), Categoria(cat) {}
Militar::~Militar() {}

void Militar::setVelocidadM(double vel) { VelocidadM = vel; }
void Militar::setCategoria(string cat) { Categoria = cat; }

double Militar::getVelocidadM() { return VelocidadM; }
string Militar::getcategoria() { return Categoria; }
bool Militar::esMilitar() {
	if (ServicioMilitar::Avion(getcategoria()) != "idf") { return true; }
	else { return false; }
}
bool Militar::esCarga() {
	if (ServicioCarga::Avion(getcategoria()) != "idf") { return true; }
	else { return false; }
}
double Militar::tamPuerta() {
	return 0;
}

string Militar::toString() {
	stringstream s;
	s << Aeronave::toString() << endl << "-Avion Militar-" << endl << "Velocidad Maxima: " << VelocidadM
		<< "Km/h" << endl << "Categoria: " << Categoria << endl << endl << "Avion: " <<
		ServicioMilitar::Avion(Categoria) << endl << "Carga: " << ServicioMilitar::Carga(Categoria) << "m^3"
		<< endl << "Alcance: " << ServicioMilitar::Alcance(Categoria) << "m" << endl;
	return s.str();
}