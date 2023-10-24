#pragma once
#include"Fecha.h"
#include"Hora.h"
#include"Plaza.h"
using namespace std;

class Contrato {
protected:
	string codigo;
	string descripcion;
	double salario;
public:
	Contrato(string, string, double);
	virtual ~Contrato();

	void setCodigo(string);
	void setDescripcion(string);
	void setSalario(double);

	string getCodigo();
	string getDescripcion();
	double getSalario();

	string virtual toString();

	virtual void setHoraEntrada(Hora&);
	virtual void setHoraSalida(Hora&);
	virtual void setTipoSerivico(string);
	virtual void setFechaInicio(Fecha&) = 0;
	virtual void  setFechaCese(Fecha&) = 0;

	virtual Hora* getHoraEntrada();
	virtual Hora* getHoraSalida();
	virtual string getTipoServicio();
	virtual Fecha* getFechaInicio() = 0;
	virtual Fecha* getFechaCese() = 0;
};


class ContratoServicios : public Contrato {
private:
	Hora* horaEntrada;
	Hora* horaSalida;
	string tipoServicio;
	Fecha* fechaInicio;
	Fecha* fechaCese;
public:
	ContratoServicios(string, string, double, Hora&, Hora&, string, Fecha&, Fecha&);
	virtual ~ContratoServicios();

	void setHoraEntrada(Hora&);
	void setHoraSalida(Hora&);
	void setTipoSerivico(string);
	void setFechaInicio(Fecha&);
	void setFechaCese(Fecha&);

	Hora* getHoraEntrada();
	Hora* getHoraSalida();
	string getTipoServicio();
	Fecha* getFechaInicio();
	Fecha* getFechaCese();

	string toString();
};


class ContratoPlazo : public Contrato {
private:
	Fecha* fechaInicio;
	Fecha* fechaCese;
public:
	ContratoPlazo(string, string, double, Fecha&, Fecha&);
	virtual ~ContratoPlazo();

	void setFechaInicio(Fecha&);
	void setFechaCese(Fecha&);

	Fecha* getFechaInicio();
	Fecha* getFechaCese();

	string toString();
};


class ContratoIndefinido : public Contrato {
private:
	Plaza* plaza;
	Fecha* fechaInicio;
	Fecha* fechaCese;
public:
	ContratoIndefinido(string, string, double,Plaza& ,Fecha&);
	virtual ~ContratoIndefinido();

	void setPlaza(Plaza&);
	void setFechaInicio(Fecha&);
	void setFechaCese(Fecha&);

	Plaza* getPlaza();
	Fecha* getFechaInicio();
	Fecha* getFechaCese();

	string toString();
};