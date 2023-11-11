#pragma once
#include"Aeropuerto.h"
#include"Interfaz.h"

class Control {
private:
	Aeropuerto* aeropuerto;
public:
	Control();
	virtual ~Control();

	void Control0();

	void Control1();
	void Control2();
	void Control3();
	void Control4();
	void Control5();

	void ControlErrorDat();
};
