#pragma once
#include"Aeronave.h"

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
	Aeronave* AeronaveCivilPlaca(string);

	int cantidad();
};