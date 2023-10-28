#pragma once
#include"Fecha.h"

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

	string toString();
};

