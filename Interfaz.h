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
	static void ErrorCodigoExistente();
	static void ErrorPlacaExistente();
	static void ErrorCategoriaNoExistente();
	static void ErrorCedulaExistente();	
	static void ErrorPilotoExistente();
	static void ErrorCopilotoExistente();
	static void ErrorInsuficientesEmpleadosSinContrato();
	static void ErrorContratoYaExistente();

	//Confirmaciones
	static void AgregadoExitoso();

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


};