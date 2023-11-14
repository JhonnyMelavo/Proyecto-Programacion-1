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
	int getCantidadCopilotos();
	int getCantidadAzafatas();
	int getCantidadEmpleadosSinContrato();
	int getCantidadMilitares();

	Contrato* contratoCod(string);
	Aeronave* aeronavePla(string);
	Empleado* empleadoCed(string);
	Aeronave* naveN(int);
	Empleado* empleadoN(int);
	Contrato* contratoN(int);
	bool hayPiloto(Aeronave*);
	bool hayCopiloto(Aeronave*);
	bool hayAzafata(Aeronave*);
	bool EsMilitar(Aeronave*);
	string getPlacas();
	string empleadosSinContrato();
	bool PasarEmpleados(Aeronave&, Aeronave&);
	string toStringAeronavesConTripulacion(Aeronave&);
	string pilotosCarga();
	string AeronavesMas20(Fecha&);
	string ContratosServicios();
	string ContratosPlazo();
	string ContratosIndefinidos();
	string TripulacionComerciales();
	Aeronave* PuertaMasGrande();


	string toStringContratos();
	string toStringEmpleados();
	string toStringAeronaves();

	void agregarContrato(Contrato&);
	void agregarEmpleado(Empleado&);
	void agregarAeronave(Aeronave&);

	bool eliminarContrato(Contrato&);
	bool eliminarEmpleado(Empleado&);
	bool eliminarAeronaves(Aeronave&);

	void setContrato(Contrato&, int);

};