#pragma once
#include"Empleado.h"

class NodoEmp {
private:
	Empleado* NO;
	NodoEmp* SN;
public:
	NodoEmp();
	NodoEmp(Empleado&, NodoEmp*);

	virtual ~NodoEmp();

	void setObj(Empleado&);
	void setSigNodo(NodoEmp*);

	Empleado* getObj();
	NodoEmp* getSigNodo();
};

class ContEmpleado {
private:
	NodoEmp* ppio;
public:
	ContEmpleado();
	virtual ~ContEmpleado();

	void Agregar(Empleado&);

	bool Eliminar(Empleado&);

	string toString();
	Empleado* EmpleadoCed(string);

	int cantidad();
};