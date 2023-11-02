#include"Empleado.h"

int main(){
	//Contrato Serivico
	Fecha* fec1 = new Fecha(20, 1, 2000);
	Fecha* fec2 = new Fecha(20, 1, 2003);
	Fecha* fec3 = new Fecha(20, 1, 2001);

	Aeronave* A1 = new Comerciales(*fec1, 1300, "a123", 310, true);

	cout << A1->toString();
	delete A1;
	system("Pause");
	system("CLS");

	Aeronave* A2 = new Carga(*fec2, 120, "b123", 3.2, 4.2, "A340", false);

	cout << A2->toString();
	delete A2;
	system("Pause");
	system("CLS");

	Aeronave* A3 = new Militar(*fec3, 59, 120, "M300");

	cout << A3->toString();
	delete A3;
	system("Pause");
	system("CLS");

	return 0;
}