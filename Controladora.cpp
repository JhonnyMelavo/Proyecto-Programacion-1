#include"Controladora.h"

Control::Control() {
	string ce, no, tel;
	Interfaz::CrearAeropuerto(ce, no, tel);
	aeropuerto = new Aeropuerto(ce, no, tel);
}
Control::~Control() {
	if (aeropuerto != NULL) {
		delete aeropuerto;
	}
}

void Control::Control0() {
	int op;
	do {
		op = Interfaz::Menu(aeropuerto->getNombre());
		switch (op){
		case 1: Control1(); break;
		case 2: Control2(); break;
		case 3: Control3(); break;
		case 4: Control4(); break;
		case 5: Control5(); break;
		default: ControlErrorDat(); break;
		}
		system("Pause");
	} while (op != 5);
}

void Control::Control1() {
	Interfaz::Ingresar(*aeropuerto);
}

void Control::Control2() {

}

void Control::Control3() {

}

void Control::Control4() {

}

void Control::Control5() {
	
}

void Control::ControlErrorDat() {
	Interfaz::ErrorDato();
}