#pragma once
#include"Fecha.h"
#include"Servicio.h"

class Aeronave {
protected:
	Fecha* fechaCreacion;
	double distaciaRecorrida;
public:
	Aeronave(Fecha&, double);
	virtual ~Aeronave();

	void setFechaCreacion(Fecha&);
	void setDistaciaRecorrida(double);

	Fecha* getFechaCreacion();
	double getDistanciaRecorrida();

	virtual string toString();
};

class AviacionCivil : public Aeronave {
protected:
	string Placa;
public:
	AviacionCivil(Fecha&, double, string);
	virtual ~AviacionCivil();

	void setPlaca(string);

	string getPlaca();

	virtual string toString();
};

class Comerciales : public AviacionCivil {
private:
	int Categoria;
	bool Tipo; // false = PasilloUnico || true = DoblePasillo
public:
	Comerciales(Fecha&, double, string, int, bool);
	virtual ~Comerciales();

	void setCategoria(int);
	void setTipo(bool);

	int getCategoria();
	bool getTipo();

	string toString();
};

class Carga : public AviacionCivil {
private:
	double AlturaPuerta;
	double AnchuraPuerta;
	string Categoria;
	bool Tipo; // false = Escotilla || true = Lateral
public:
	Carga(Fecha&, double, string, double, double, string, bool);
	virtual ~Carga();

	void setAltura(double);
	void setAnchura(double);
	void setCategoria(string);
	void setTipo(bool);

	double getAltura();
	double getAnchura();
	string getCategoria();
	bool getTipo();

	string toString();
};

class Militar : public Aeronave {
private:
	double VelocidadM;
	string Categoria;
public:
	Militar(Fecha&, double, double, string);
	virtual ~Militar();

	void setVelocidadM(double);
	void setCategoria(string);

	double getVelocidadM();
	string getCategoria();

	string toString();
};