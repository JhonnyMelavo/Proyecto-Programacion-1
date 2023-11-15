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
	string empleadosSinContrato();
	bool hayPiloto(Aeronave*);
	bool hayCopiloto(Aeronave*);
	bool hayAzafata(Aeronave*);
	Empleado* EmpleadoN(int);
	bool pasarEmpleados(Aeronave&, Aeronave&);
	string toStringEmpleadosEnAeronave(Aeronave&);
	string pilotosCarga();
	Empleado* EmpleadoConContrato(Contrato&);
	int cantidadEmpleadosPlazoMas2(Fecha&);

	int cantidad();
	int cantidadPilotos();
	int cantidadCopilotos();
	int cantidadAzafatas();
	int cantidadSinContrato();

	void setContrato(Contrato&, int);
};