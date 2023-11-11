#pragma once
#include"ContContrato.h"
#include"ContEmpleado.h"
#include"ContAvion.h"

class Aeropuerto {
private:
	string Cedula;
	string Nombre;
	string Telefono;
	ContContrato* Contratos;
	ContEmpleado* Empleados;
	ContAvion* Aeronaves;
public:
	Aeropuerto(string, string, string);
	~Aeropuerto();

	void setNombre(string);
	void setCedula(string);
	void setTelefono(string);

	string getNombre();
	string getCedula();
	string getTelefono();

	int getCantidadContratos();
	int getCantidadEmpleados();
	int getCantidadAeronaves();
	int getCantidadPilotos();
	int getCantidadEmpleadosSinContrato();

	Contrato* contratoCod(string);
	Aeronave* aeronavePla(string);
	Empleado* empleadoCed(string);
	Aeronave* naveN(int);
	Empleado* empleadoN(int);
	Contrato* contratoN(int);
	bool hayPiloto(Aeronave*);
	bool hayCopiloto(Aeronave*);
	string getPlacas();
	string empleadosSinContrato();

	string toStringContratos();
	string toStringEmpleados();
	string toStringAeronaves();

	void agregarContrato(Contrato&);
	void agregarEmpleado(Empleado&);
	void agregarAeronave(Aeronave&);

	void setContrato(Contrato&, int);

};