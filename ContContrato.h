#pragma once
#include"Contrato.h"

class NodoCon {
private:
	Contrato* NO;
	NodoCon* SN;
public:
	NodoCon();
	NodoCon(Contrato&, NodoCon*);

	virtual ~NodoCon();

	void setObj(Contrato&);
	void setSigNodo(NodoCon*);

	Contrato* getObj();
	NodoCon* getSigNodo();
};

class ContContrato {
private:
	NodoCon* ppio;
public:
	ContContrato();
	virtual ~ContContrato();
	
	void Agregar(Contrato&);

	bool Eliminar(Contrato&);

	string toString();
	Contrato* ContratoCod(string);
	Contrato* ContratoN(int);

	string ContratosSerivicios();
	string ContratosPlazo();
	string ContratosIndefinido();
	string ContratosMas2(Fecha&);
	int cantidadContratosMas2(Fecha&);

	int cantidad();
};