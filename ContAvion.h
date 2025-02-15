#pragma once
#include"Aeronave.h"
#include"ContEmpleado.h"

class NodoAvi {
private:
	Aeronave* NO;
	NodoAvi* SN;
public:
	NodoAvi();
	NodoAvi(Aeronave&, NodoAvi*);

	virtual ~NodoAvi();

	void setObj(Aeronave&);
	void setSigNodo(NodoAvi*);

	Aeronave* getObj();
	NodoAvi* getSigNodo();
};

class ContAvion {
private:
	NodoAvi* ppio;
public:
	ContAvion();
	virtual ~ContAvion();

	void Agregar(Aeronave&);

	bool Eliminar(Aeronave&);

	string toString();
	Aeronave* AeronavePlaca(string);
	Aeronave* naveN(int);
	string Placas();
	bool EsMilitar(Aeronave*);
	string AeronavesMas20(Fecha&);
	string TripulacionComerciales(ContEmpleado&);
	Aeronave* PuertaMasGrande();

	int cantidad();
	int cantidadMilitares();
};