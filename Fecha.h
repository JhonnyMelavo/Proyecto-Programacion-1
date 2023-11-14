#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int, int ,int);
	virtual ~Fecha();

	void setDia(int);
	void setMes(int);
	void setAnio(int);

	int getDia();
	int getMes();
	int getAnio();

	bool mas20Anios(Fecha&);
	bool mas2Anios(Fecha&);

	string toString();
};