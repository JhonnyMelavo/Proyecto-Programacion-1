#pragma once
#include"Fecha.h"
#include"Servicio.h"

class Aeronave {
protected:
	Fecha* fechaCreacion;
	double distaciaRecorrida;
	string placa;
public:
	Aeronave(Fecha&, double, string);
	virtual ~Aeronave();

	void setFechaCreacion(Fecha&);
	void setDistaciaRecorrida(double);
	void setPlaca(string);

	Fecha* getFechaCreacion();
	double getDistanciaRecorrida();
	virtual string getPlaca();
	virtual string getcategoria() = 0;
	virtual bool esMilitar() = 0;
	virtual bool esCarga() = 0;
	virtual double tamPuerta() = 0;

	virtual string toString();
};

class AviacionCivil : public Aeronave {
public:
	AviacionCivil(Fecha&, double, string);
	virtual ~AviacionCivil();
	virtual string getcategoria() = 0;
	virtual bool esMilitar() = 0;
	virtual bool esCarga() = 0;
	virtual double tamPuerta() = 0;
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
	string getcategoria();
	bool esMilitar();
	bool esCarga();
	virtual double tamPuerta();

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
	string getcategoria();
	bool getTipo();	
	bool esMilitar();
	bool esCarga();
	double tamPuerta();

	string toString();
};

class Militar : public Aeronave {
private:
	double VelocidadM;
	string Categoria;
public:
	Militar(Fecha&, double, string, double, string);
	virtual ~Militar();

	void setVelocidadM(double);
	void setCategoria(string);

	double getVelocidadM();
	string getcategoria();
	bool esMilitar();
	bool esCarga();
	double tamPuerta();

	string toString();
};