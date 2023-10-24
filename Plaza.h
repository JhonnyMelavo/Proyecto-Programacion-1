#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Plaza {
private:
	string Codigo;
	string Puesto;
public:
	Plaza(string, string);
	virtual ~Plaza();

	void setCodigo(string);
	void setPuesto(string);

	string getCodigo();
	string getPuesto();

	string toString();

};