#pragma once
#include"Contrato.h"
#include"Aeronave.h"
#include"ContContrato.h"

class Empleado {
protected:
	string cedula;
	string nombre;
	int edad;
	Contrato* contrato;
public:
	Empleado(string, string, int);
	virtual ~Empleado();

	void setCedula(string);
	void setNombre(string);
	void setEdad(int);
	void setContrato(Contrato&);
	void setContratoSinBorrar(Contrato&);

	string getCedula();
	string getNombre();
	int getEdad();
	Contrato* getContrato();
	virtual Aeronave* getAeronave() = 0;
	virtual void setAeronave(Aeronave&) = 0;
	virtual int getAniosExp() = 0;
	virtual string getTelefono() = 0;
	virtual string getNacionalidad() = 0;

	string toString();
};

//Tripulacion----------------------------------------------------------------------------------------------------------------------------------

class EmpleadoTripulacion: public Empleado {
protected:
	Aeronave* nave;
public:
	EmpleadoTripulacion(string, string, int, Aeronave&);
	virtual ~EmpleadoTripulacion();

	void setAeronave(Aeronave&);

	virtual Aeronave* getAeronave();
	virtual int getAniosExp() = 0;
	virtual string getTelefono() = 0;
	virtual string getNacionalidad() = 0;

	virtual string toString() = 0;
};

class Piloto : public EmpleadoTripulacion {
private:
	int aniosExp;
public:
	Piloto(string, string, int, Aeronave&, int);
	virtual ~Piloto();

	void setAniosExp(int);

	int getAniosExp();
	string getTelefono();
	string getNacionalidad();
	
	string toString();
};

class Copiloto : public EmpleadoTripulacion {
private:
	string telefono;
public:
	Copiloto(string, string, int, Aeronave&, string);
	virtual ~Copiloto();

	void setTelefono(string);

	string getTelefono();
	int getAniosExp();
	string getNacionalidad();

	string toString();
};

class Azafata : public EmpleadoTripulacion {
private:
	string nacionalidad;
public:
	Azafata(string, string, int, Aeronave&, string);
	virtual ~Azafata();

	void setNacionalidad(string);

	string getNacionalidad();
	int getAniosExp();
	string getTelefono();
	
	string toString();
};

//Planta---------------------------------------------------------------------------------------------------------------------------------------

class EmpleadoAdmi : public Empleado {
private:
	string titulo;
public:
	EmpleadoAdmi(string, string, int, string);
	virtual ~EmpleadoAdmi();

	void setTitulo(string);

	string getTitulo();
	Aeronave* getAeronave();
	void setAeronave(Aeronave&);
	int getAniosExp();
	string getTelefono();
	string getNacionalidad();

	string toString();
};

class Miscelaneo : public Empleado {
private:
	string gradoEscolaridad;
	string areaTrabajo;
public:
	Miscelaneo(string, string, int, string, string);
	virtual ~Miscelaneo();

	void setGradoEscolaridad(string);
	void setAreaTrabajo(string);

	string getGradoEscolaridad();
	string getAreaTrabajo();
	Aeronave* getAeronave();
	void setAeronave(Aeronave&);
	int getAniosExp();
	string getTelefono();
	string getNacionalidad();

	string toString();
};