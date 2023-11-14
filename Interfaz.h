#pragma once
#include<iostream>
#include<sstream>
#include"Controladora.h"
using namespace std;

class Interfaz {
public:
	static int PasarStringAInt(string);

	static int Menu(string);

	static void CrearAeropuerto(string&, string&, string&);

	//Errores
	static void ErrorDato();
	static void ErrorInsuficientesEmpleados();
	static void ErrorInsuficientesAeronaves();
	static void ErrorInsuficientesContratos();
	static void ErrorCodigoExistente();
	static void ErrorPlacaExistente();
	static void ErrorCategoriaNoExistente();
	static void ErrorCedulaExistente();	
	static void ErrorPilotoExistente();
	static void ErrorCopilotoExistente();
	static void ErrorInsuficientesEmpleadosSinContrato();
	static void ErrorContratoYaExistente();
	static void ErrorAzafataExistente();
	static void ErrorAzafataEnMilitar();
	static void NoSePudoEliminar();
	static void MismaAeronaves();

	//Confirmaciones
	static void AgregadoExitoso();
	static void EliminadoExitoso();

	//Despedida
	static void Despedida();

	//Ingresar
	static void Ingresar(Aeropuerto&);
	
	static void IngresarContrato(Aeropuerto&);
	static void IngresarServicio(Aeropuerto&);
	static void IngresarPlazo(Aeropuerto&);
	static void IngresarIndefinido(Aeropuerto&);

	static void IngresarEmpleado(Aeropuerto&);
	static void IngresarTripulante(Aeropuerto&);
	static void IngresarPiloto(Aeropuerto&);
	static void IngresarCopiloto(Aeropuerto&);
	static void IngresarAzafata(Aeropuerto&);

	static void IngresarPlanta(Aeropuerto&);
	static void IngresarAdministrativo(Aeropuerto&);
	static void IngresarMiscelaneo(Aeropuerto&);

	static void IngresarAeronave(Aeropuerto&);
	static void IngresarComercial(Aeropuerto&);
	static void IngresarCarga(Aeropuerto&);
	static void IngresarMilitar(Aeropuerto&);

	//Mantenimiento

	static void Mantenimiento(Aeropuerto&);

	static void EliminarContrato(Aeropuerto&);
	static void EliminarEmpleado(Aeropuerto&);
	static void EliminarAeronave(Aeropuerto&);

	//Reportes

	static void Reportes(Aeropuerto&);

	static void ReporteContratoYEmpleado(Aeropuerto&);
	static void ReporteAeronavesConTripulacion(Aeropuerto&);
	static void ReportePilotosDeCarga(Aeropuerto&);
	static void ReporteAeronaves(Aeropuerto&);
	static void ReporteAeronavesMas20(Aeropuerto&);
	static void ReporteContratosSerivicios(Aeropuerto&);
	static void ReporteContratosPlazo(Aeropuerto&);
	static void ReporteContratosIndefinidos(Aeropuerto&);
	static void ReporteTripulantesComerciales(Aeropuerto&);
	static void ReporteContratosPlazoFijoMas2(Aeropuerto&);
	static void ReportePuertaMasGrande(Aeropuerto&);

	//Consultar

	static void Consultar(Aeropuerto&);

	static void ConsultarEmpleadoCed(Aeropuerto&);
	static void ConsultarContratoCod(Aeropuerto&);
	static void ConsultarAeronavePlaca(Aeropuerto&);
};