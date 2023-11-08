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

//Aviacion Civil

AviacionCivil::AviacionCivil(Fecha& fe, double dis, string pla): Aeronave::Aeronave(fe, dis), Placa(pla) {}
AviacionCivil::~AviacionCivil() {}

void AviacionCivil::setPlaca(string pla) { Placa = pla; }

string AviacionCivil::getPlaca() { return Placa; }

string AviacionCivil::toString() {
	stringstream s;
	s << Aeronave::toString() << endl << "--Aviacion Civil--" << endl << "Numero de placa: " << Placa << endl;
	return s.str();
}


//Comercial

Comerciales::Comerciales(Fecha& fe, double dis, string pla, int cat, bool tip) : AviacionCivil::AviacionCivil(fe, dis, pla), Categoria(cat), Tipo(tip) {}
Comerciales::~Comerciales() {}

void Comerciales::setCategoria(int cat) { Categoria = cat; }
void Comerciales::setTipo(bool tip) { Tipo = tip; }

int Comerciales::getCategoria() { return Categoria; }
bool Comerciales::getTipo() { return Tipo; }

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
string Carga::getCategoria() { return Categoria; }
bool Carga::getTipo() { return Tipo; }

string Carga::toString() {
	stringstream s;
	s << AviacionCivil::toString() << endl << "-Carga-" << endl << "Tipo: ";
	if (Tipo) {
		s << "Puerta Lateral" << endl;
	}
	else {
		s << "Escotilla" << endl;
	}
	s << "Altura de puerta: " << AlturaPuerta << "m" << endl << "Anchura puerta: " << AnchuraPuerta << "m" << endl
		<< "Categoria: " << Categoria << endl << endl << "Avion: " << ServicioCarga::Avion(Categoria) << endl << "Carga: " <<
		ServicioCarga::Carga(Categoria) << "m^3" << endl << "Cantidad de pasajeros: " << ServicioCarga::Pasajeros(Categoria) << endl <<
		"Alcance: " << ServicioCarga::Alcance(Categoria) << "Km" << endl;
	return s.str();
}

//Militar

Militar::Militar(Fecha& fe, double dis, double vel, string cat) : Aeronave::Aeronave(fe, dis), VelocidadM(vel), Categoria(cat) {}
Militar::~Militar() {}

void Militar::setVelocidadM(double vel) { VelocidadM = vel; }
void Militar::setCategoria(string cat) { Categoria = cat; }

double Militar::getVelocidadM() { return VelocidadM; }
string Militar::getCategoria() { return Categoria; }
string Militar::getPlaca() { return ""; }

string Militar::toString() {
	stringstream s;
	s << Aeronave::toString() << endl << "-Avion Militar-" << endl << "Velocidad Maxima: " << VelocidadM
		<< "Km/h" << endl << "Categoria: " << Categoria << endl << endl << "Avion: " <<
		ServicioMilitar::Avion(Categoria) << endl << "Carga: " << ServicioMilitar::Carga(Categoria) << "m^3"
		<< endl << "Alcance: " << ServicioMilitar::Alcance(Categoria) << "m" << endl;
	return s.str();
}