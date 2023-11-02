#include"Servicio.h"

//Comercial

string ServicioComercial::Avion(int cat) {
	switch (cat){
	case 310: return "Airbus A310"; break;
	case 747: return "Boeing 747"; break;
	case 767: return "Boeing 767"; break;
	case 777: return "Boeing 777"; break;
	case 130: return "Concorde"; break;
	case 850: return "DC-8-50"; break;
	default: return "indf"; break;
	}
}
double ServicioComercial::Pasajeros(int cat) {
	switch (cat) {
	case 310: return 250; break;
	case 747: return 470; break;
	case 767: return 250; break;
	case 777: return 375; break;
	case 130: return 130; break;
	case 850: return 145; break;
	default: return 0; break;
	}
}
double ServicioComercial::Rango(int cat) {
	switch (cat) {
	case 310: return 8300; break;
	case 747: return 6700; break;
	case 767: return 12300; break;
	case 777: return 7450; break;
	case 130: return 6400; break;
	case 850: return 14000; break;
	default: return 0; break;
	}
}
double ServicioComercial::Velocidad(int cat) {
	switch (cat) {
	case 310: return 895; break;
	case 747: return 980; break;
	case 767: return 885; break;
	case 777: return 980; break;
	case 130: return 2200; break;
	case 850: return 875; break;
	default: return 0; break;
	}
}
double ServicioComercial::Precio(int cat) {
	switch (cat) {
	case 310: return 120; break;
	case 747: return 200; break;
	case 767: return 120; break;
	case 777: return 180; break;
	case 130: return 350; break;
	case 850: return 80; break;
	default: return 0; break;
	}
}

//Carga

string ServicioCarga::Avion(string cat) {
	if (cat == "A319") {
		return "AIRBUS 319";
	}
	if (cat == "A320") {
		return "AIRBUS 320";
	}
	if (cat == "A321") {
		return "AIRBUS 321";
	}
	if (cat == "A330") {
		return "AIRBUS 330";
	}
	if (cat == "A340") {
		return "AIRBUS 340";
	}
	if (cat == "B737") {
		return "BOEING 737";
	}
	if (cat == "B777") {
		return "BOEING 777";
	}
	return "idf";
}
string ServicioCarga::Carga(string cat) {
	if (cat == "A319") {
		return "27,7";
	}
	if (cat == "A320") {
		return "37,40";
	}
	if (cat == "A321") {
		return "51,70";
	}
	if (cat == "A330") {
		return "132,4-158,4";
	}
	if (cat == "A340") {
		return "162,8-207,6";
	}
	if (cat == "B737") {
		return "52,5";
	}
	if (cat == "B777") {
		return "162-653";
	}
	return "idf";
}
string ServicioCarga::Pasajeros(string cat) {
	if (cat == "A319") {
		return "156";
	}
	if (cat == "A320") {
		return "220";
	}
	if (cat == "A321") {
		return "220";
	}
	if (cat == "A330") {
		return "293-335";
	}
	if (cat == "A340") {
		return "261-419";
	}
	if (cat == "B737") {
		return "215";
	}
	if (cat == "B777") {
		return "550";
	}
	return "idf";
}
string ServicioCarga::Alcance(string cat) {
	if (cat == "A319") {
		return "7200";
	}
	if (cat == "A320") {
		return "3100-1200";
	}
	if (cat == "A321") {
		return "5600";
	}
	if (cat == "A330") {
		return "7400-13450";
	}
	if (cat == "A340") {
		return "14630";
	}
	if (cat == "B737") {
		return "9955";
	}
	if (cat == "B777") {
		return "17370";
	}
	return "idf";
}

//Militar

string ServicioMilitar::Avion(string cat) {
	if (cat == "M300") {
		return "AIRBUS 300-600";
	}
	if (cat == "M130") {
		return "ANTONOV";
	}
	return "idf";
}
double ServicioMilitar::Carga(string cat) {
	if (cat == "M300") {
		return 1400;
	}
	if (cat == "M130") {
		return 1300;
	}
	return 0;
}
double ServicioMilitar::Alcance(string cat) {
	if (cat == "M300") {
		return 4630;
	}
	if (cat == "M130") {
		return 4000;
	}
	return 0;
}