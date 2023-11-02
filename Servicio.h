#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class ServicioComercial {
public:
	static string Avion(int);
	static double Pasajeros(int);
	static double Rango(int);
	static double Velocidad(int);
	static double Precio(int);
};

class ServicioCarga {
public:
	static string Avion(string);
	static string Carga(string);
	static string Pasajeros(string);
	static string Alcance(string);
};

class ServicioMilitar {
public:
	static string Avion(string);
	static double Carga(string);
	static double Alcance(string);
};