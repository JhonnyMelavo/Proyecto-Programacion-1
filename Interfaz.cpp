#include"Interfaz.h"

int Interfaz::PasarStringAInt(string n) {
	int m = 0;
	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '1') {
			m += 1; m *= 10;
		}
		else if (n[i] == '2') {
			m += 2; m *= 10;
		}
		else if (n[i] == '3') {
			m += 3; m *= 10;
		}
		else if (n[i] == '4') {
			m += 4; m *= 10;
		}
		else if (n[i] == '5') {
			m += 5; m *= 10;
		}
		else if (n[i] == '6') {
			m += 6; m *= 10;
		}
		else if (n[i] == '7') {
			m += 7; m *= 10;
		}
		else if (n[i] == '8') {
			m += 8; m *= 10;
		}
		else if (n[i] == '9') {
			m += 9; m *= 10;
		}
		else if (n[i] == '0') {
			m *= 10;
		}
	}
	m /= 10;
	return m;
}

int Interfaz::Menu(string n) {
	string opaux;
	system("CLS");
	cout << "- - - - - - - - - - - - - - - - -" << endl;
	cout << "==================================" << endl;
	cout << "    Aeropuerto " << n << endl;
	cout << "|\t (1) Ingresar\t\t|" << endl;
	cout << "|\t (2) Mantenimiento\t|" << endl;
	cout << "|\t (3) Reportes\t\t|" << endl;
	cout << "|\t (4) Consultar\t\t|" << endl;
	cout << "|\t (5) Salir\t\t|" << endl;
	cout << "==================================" << endl;
	cout << "Digite una opcion valida: ";
	cin >> opaux;
	int op = PasarStringAInt(opaux);
	return op;
}

void Interfaz::CrearAeropuerto(string& ce, string& no, string& te) {
	cout << "*----Ingresando datos del aeropuerto-----*" << endl;
	cout << "()->Digite la cedula del aeropuerto: \t"; cin >> ce;
	cout << "()->Digite el nombre del aeropuerto: \t"; cin >> no;
	cout << "()->Digite el telefono del aeropuerto: \t"; cin >> te;
	system("CLS");
}

//Errores

void Interfaz::ErrorDato() {
	cout << "<<Error al ingresar datos>>" << endl;
}
void Interfaz::ErrorInsuficientesEmpleados() {
	cout << "<<No hay empleados a los que asignarles contratos>>" << endl;
}
void Interfaz::ErrorInsuficientesAeronaves() {
	cout << "<<No hay aeronaves a los que asignarles empleados>>" << endl;
}
void Interfaz::ErrorCodigoExistente() {
	cout << "<<Codigo ya existente>>" << endl;
}
void Interfaz::ErrorPlacaExistente() {
	cout << "<<Placa ya existente>>" << endl;
}
void Interfaz::ErrorCategoriaNoExistente() {
	cout << "<<Categoria no existente>>" << endl;
}
void Interfaz::ErrorCedulaExistente() {
	cout << "<<Cedula ya existente>>" << endl;
}
void Interfaz::ErrorPilotoExistente() {
	cout << "<<Ya hay un piloto en esa aeronave>>" << endl;
}
void Interfaz::ErrorCopilotoExistente() {
	cout << "<<Ya hay un copiloto en esa aeronave>>" << endl;
}
void Interfaz::ErrorInsuficientesEmpleadosSinContrato() {
	cout << "<<Insuficientes empleados sin contrato>>" << endl;
}
void Interfaz::ErrorContratoYaExistente() {
	cout << "<<Ese empleado ya posee contrato>>" << endl;
}

//Confirmaciones

void Interfaz::AgregadoExitoso() {
	cout << "<<Agregado con exito>>" << endl;
}

//Menu------------------------------------------------------------------------------------------------------------------------

void Interfaz::Ingresar(Aeropuerto& aero) {
		system("CLS");
		string opaux; int op = 1;
		cout << "==================================" << endl;
		cout << "===========  Ingresar  ===========" << endl;
		cout << "\t(1) Ingresar Contrato" << endl;
		cout << "\t(2) Ingresar Empleado" << endl;
		cout << "\t(3) Ingresar Aeronave" << endl;
		cout << "\t(4) Volver a Menu" << endl;
		cout << "==================================" << endl;
		cout << "Digite lo que desea Ingresar: ";
		do {
			if (op < 1 || op > 4) { ErrorDato(); }
			cin >> opaux;
			op = PasarStringAInt(opaux);
		} while (op < 1 || op > 4);
		system("CLS");
		switch (op){
		case 1: IngresarContrato(aero); break;
		case 2:	IngresarEmpleado(aero); break;
		case 3:	IngresarAeronave(aero); break;
		case 4: break;
		}
}

//Ingresar====================================================================================================================
// ===========================================================================================================================
//Contratos-------------------------------------------------------------------------------------------------------------------

void Interfaz::IngresarContrato(Aeropuerto& aero) {
	if (aero.getCantidadEmpleados() == 0) {
		ErrorInsuficientesEmpleados();
	} else {
		if (aero.getCantidadEmpleadosSinContrato() < 1) { ErrorInsuficientesEmpleadosSinContrato(); }
		else{
			string opaux; int op = 1;
			cout << "====================================================" << endl;
			cout << "====================  Contrato  ====================" << endl;
			cout << "   (1) Ingresar Contrato por Servicios Profesionales" << endl;
			cout << "   (2) Ingresar Contrato de Plazo Fijo" << endl;
			cout << "   (3) Ingresar Contrato de Tiempo Indefinido" << endl;
			cout << "   (4) Volver a Menu" << endl;
			cout << "====================================================" << endl;
			cout << "Digite el tipo de contrato que desea Ingresar: ";
			do {
				if (op < 1 || op > 4) { ErrorDato(); }
				cin >> opaux;
				op = PasarStringAInt(opaux);
			} while (op < 1 || op > 4);

			system("CLS");
			switch (op) {
			case 1: IngresarServicio(aero); break;
			case 2:	IngresarPlazo(aero); break;
			case 3:	IngresarIndefinido(aero); break;
			case 4: break;
			}
		}
	}
}
void Interfaz::IngresarServicio(Aeropuerto& aero) {
	string cod = "idf", des, tipo, aux;
	double sal;
	int h = -1 , mi = -1, d = -1, me = -1, a = -1;
	int op;
	do {
		if (cod != "idf") { ErrorCodigoExistente(); }
		cout << "()->Digite el codigo del contrato: "; cin >> cod;
	} while (aero.contratoCod(cod) != NULL);
	cout << "()->Digite la descripcion del contrato: "; cin >> des;
	cout << "()->Digite el salario: "; cin >> aux;
	sal = PasarStringAInt(aux);
	cout << "()->Digite el tipo de servicio: "; cin >> tipo;
	//Hora
	do {
		if (h != -1) { ErrorDato(); }
		cout << "()->Digite la hora de entrada: "; cin >> aux;
		h = PasarStringAInt(aux);
	} while (h < 0 || h > 24);
	do {
		if (mi != -1) { ErrorDato(); }
		cout << "()->Digite el minuto de entrada: "; cin >> aux;
		mi = PasarStringAInt(aux);
	} while (mi < 0 || mi > 60);
	Hora* hora1 = new Hora(h, mi);
	//Hora
	h = -1, mi = -1;
	do {
		if (h != -1) { ErrorDato(); }
		cout << "()->Digite la hora de Salida: "; cin >> aux;
		h = PasarStringAInt(aux);
	} while (h < 0 || h > 24);
	do {
		if (mi != -1) { ErrorDato(); }
		cout << "()->Digite el minuto de Salida: "; cin >> aux;
		mi = PasarStringAInt(aux);
	} while (mi < 0 || mi > 60);
	Hora* hora2 = new Hora(h, mi);
	//Fecha
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de inicio: "; cin >> aux;
		d = PasarStringAInt(aux);
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de inicio: "; cin >> aux;
		me = PasarStringAInt(aux);
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de inicio: "; cin >> aux;
		a = PasarStringAInt(aux);
	} while (a < 1000 || a > 3000);
	Fecha* fecha1 = new Fecha(d, me, a);
	//Fecha
	d = -1, me = -1, a = -1;
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de cese: "; cin >> aux;
		d = PasarStringAInt(aux);
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de cese: "; cin >> aux;
		me = PasarStringAInt(aux);
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de cese: "; cin >> aux;
		a = PasarStringAInt(aux);
	} while (a < 1000 || a > 3000);
	Fecha* fecha2 = new Fecha(d, me, a);
	//Contrato
	bool error = false;
	Contrato* con = new ContratoServicios(cod, des, sal, *hora1, *hora2, tipo, *fecha1, *fecha2);
	aero.agregarContrato(*con);
	do {
		system("CLS");
		if (error) { ErrorDato(); }
		cout << "--Empleados sin Contrato--" << endl;
		cout << aero.empleadosSinContrato();
		cout << endl << "Digite el numero de empleado para agregar contrato: "; cin >> aux;
		op = PasarStringAInt(aux);
		error = true;
	} while (op < 1 || op > aero.getCantidadEmpleados() || aero.empleadoN(op)->getContrato() != NULL);
	aero.setContrato(*con, op);
	AgregadoExitoso();
}
void Interfaz::IngresarPlazo(Aeropuerto& aero) {
	string cod = "idf", des, aux;
	double sal;
	int d = -1, me = -1, a = -1;
	int op;
	do {
		if (cod != "idf") { ErrorCodigoExistente(); }
		cout << "()->Digite el codigo del contrato: "; cin >> cod;
	} while (aero.contratoCod(cod) != NULL);
	cout << "()->Digite la descripcion del contrato: "; cin >> des;
	cout << "()->Digite el salario: "; cin >> aux;
	sal = PasarStringAInt(aux);
	//Fecha
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de inicio: "; cin >> aux;
		d = PasarStringAInt(aux);
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de inicio: "; cin >> aux;
		me = PasarStringAInt(aux);
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de inicio: "; cin >> aux;
		a = PasarStringAInt(aux);
	} while (a < 1000 || a > 3000);
	Fecha* fecha1 = new Fecha(d, me, a);
	//Fecha
	d = -1, me = -1, a = -1;
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de cese: "; cin >> aux;
		d = PasarStringAInt(aux);
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de cese: "; cin >> aux;
		me = PasarStringAInt(aux);
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de cese: "; cin >> aux;
		a = PasarStringAInt(aux);
	} while (a < 1000 || a > 3000);
	Fecha* fecha2 = new Fecha(d, me, a);
	//Contrato
	bool error = false;
	Contrato* con = new ContratoPlazo(cod, des, sal, *fecha1, *fecha2);
	aero.agregarContrato(*con);
	do {
		system("CLS");
		if (error) { ErrorDato(); }
		cout << "--Empleados sin Contrato--" << endl;
		cout << aero.empleadosSinContrato();
		cout << endl << "Digite el numero de empleado para agregar contrato: "; cin >> aux;
		op = PasarStringAInt(aux);
		error = true;
	} while (op < 1 || op > aero.getCantidadEmpleados() || aero.empleadoN(op)->getContrato() != NULL);
	aero.setContrato(*con, op);
	AgregadoExitoso();
}
void Interfaz::IngresarIndefinido(Aeropuerto& aero) {
	string cod = "idf", des, codp, puesto,aux;
	double sal;
	int d = -1, me = -1, a = -1;
	int op;
	do {
		if (cod != "idf") { ErrorCodigoExistente(); }
		cout << "()->Digite el codigo del contrato: "; cin >> cod;
	} while (aero.contratoCod(cod) != NULL);
	cout << "()->Digite la descripcion del contrato: "; cin >> des;
	cout << "()->Digite el salario: "; cin >> aux;
	sal = PasarStringAInt(aux);
	//Fecha
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de inicio: "; cin >> aux;
		d = PasarStringAInt(aux);
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de inicio: "; cin >> aux;
		me = PasarStringAInt(aux);
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de inicio: "; cin >> aux;
		a = PasarStringAInt(aux);
	} while (a < 1000 || a > 3000);
	Fecha* fecha1 = new Fecha(d, me, a);
	//Plaza
	cout << "()->Digite el codigo de la plaza: "; cin >> codp;
	cout << "()->Digite el puesto de la plaza: "; cin >> puesto;
	Plaza* plaza = new Plaza(codp, puesto);
	//Contrato
	bool error = false;
	Contrato* con = new ContratoIndefinido(cod, des, sal, *plaza ,*fecha1);
	aero.agregarContrato(*con);
	do {
		system("CLS");
		if (error) { ErrorDato(); }
		cout << "--Empleados sin Contrato--" << endl;
		cout << aero.empleadosSinContrato();
		cout << endl << "Digite el numero de empleado para agregar contrato: "; cin >> aux;
		op = PasarStringAInt(aux);
		error = true;
	} while (op < 1 || op > aero.getCantidadEmpleados() || aero.empleadoN(op)->getContrato() != NULL);
	aero.setContrato(*con, op);
	AgregadoExitoso();
}

//Empleados-------------------------------------------------------------------------------------------------------------------

void Interfaz::IngresarEmpleado(Aeropuerto& aero) {
	string opaux; int op = 1;
	cout << "=============================================" << endl;
	cout << "================= Empleados =================" << endl;
	cout << "   (1) Ingresar Empleado Tripulante" << endl;
	cout << "   (2) Ingresar Empleado Planta" << endl;
	cout << "   (3) Volver a Menu" << endl;
	cout << "=============================================" << endl;
	cout << "Digite el tipo de empleado que desea Ingresar: ";
	do {
		if (op < 1 || op > 3) { ErrorDato(); }
		cin >> opaux;
		op = PasarStringAInt(opaux);
	} while (op < 1 || op > 3);

	system("CLS");
	switch (op) {
	case 1: IngresarTripulante(aero); break;
	case 2:	IngresarPlanta(aero); break;
	case 3: break;
	}
}

void Interfaz::IngresarTripulante(Aeropuerto& aero) {
	string opaux; int op = 1;
	if (aero.getCantidadAeronaves() == 0) { ErrorInsuficientesAeronaves(); }
	else {
		cout << "========================================" << endl;
		cout << "============== Tripulante ==============" << endl;
		cout << "   (1) Ingresar Piloto" << endl;
		cout << "   (2) Ingresar Copiloto" << endl;
		cout << "   (3) Ingresar Azafata" << endl;
		cout << "   (4) Volver a Menu" << endl;
		cout << "========================================" << endl;
		do {
			if (op < 1 || op > 4) { ErrorDato(); }
			cin >> opaux;
			op = PasarStringAInt(opaux);
		} while (op < 1 || op > 4);

		system("CLS");
		switch (op) {
		case 1: IngresarPiloto(aero); break;
		case 2:	IngresarCopiloto(aero); break;
		case 3: IngresarAzafata(aero); break;
		case 4: break;
		}
	}
}
void Interfaz::IngresarPiloto(Aeropuerto& aero) {
	string id, nom, aux;
	int edad, xp, op;
	bool error = false, hayPiloto = false;
	if (aero.getCantidadPilotos() >= aero.getCantidadAeronaves()) {
		ErrorInsuficientesAeronaves();
	}
	else {
		do {
			if (error) { ErrorCedulaExistente(); }
			cout << "()->Digite la cedula del Empleado: "; cin >> id;
			error = true;
		} while (aero.empleadoCed(id) != NULL);
		cout << "()->Digite el nombre del Empleado: "; cin >> nom;
		cout << "()->Digite la edad del Empleado: "; cin >> aux;
		edad = PasarStringAInt(aux);
		cout << "()->Digite los anios de experiencia del Empleado: "; cin >> aux;
		xp = PasarStringAInt(aux);
		do {
			system("CLS");
			if (hayPiloto) { ErrorPilotoExistente(); }
			cout << "--	Aeronaves --" << endl;
			cout << aero.toStringAeronaves();
			do {
				cout << endl << "Digite el numero de aeronave para ingresar empleado: "; cin >> aux;
				op = PasarStringAInt(aux);
			} while (  op <= 0 || op > aero.getCantidadAeronaves());
			hayPiloto = aero.hayPiloto(aero.naveN(op));
		} while ( hayPiloto );
		Aeronave* nav = (Aeronave*)aero.naveN(op);
		Empleado* emp = new Piloto(id, nom, edad, *nav, xp);
		aero.agregarEmpleado(*emp);
		AgregadoExitoso();
	}
}
void Interfaz::IngresarCopiloto(Aeropuerto& aero) {
	string id, nom, tel, aux;
	int edad, op;
	bool error = false, hayCopiloto = false;
	do {
		if (error) { ErrorCedulaExistente(); }
		cout << "()->Digite la cedula del Empleado: "; cin >> id;
		error = true;
	} while (aero.empleadoCed(id) != NULL);
	cout << "()->Digite el nombre del Empleado: "; cin >> nom;
	cout << "()->Digite la edad del Empleado: "; cin >> aux;
	edad = PasarStringAInt(aux);
	cout << "()->Digite el numero de telefono del Empleado: "; cin >> tel;
	do {
		system("CLS");
		if (hayCopiloto) { ErrorCopilotoExistente(); }
		cout << "--	Aeronaves --" << endl;
		cout << aero.toStringAeronaves();
		do {
			cout << endl << "Digite el numero de aeronave para ingresar empleado: "; cin >> aux;
			op = PasarStringAInt(aux);
		} while (op <= 0 || op > aero.getCantidadAeronaves());
		hayCopiloto = aero.hayCopiloto(aero.naveN(op));
	} while (hayCopiloto);
	Aeronave* nav = (Aeronave*)aero.naveN(op);
	Empleado* emp = new Copiloto(id, nom, edad, *nav, tel);
	aero.agregarEmpleado(*emp);
	AgregadoExitoso();
}
void Interfaz::IngresarAzafata(Aeropuerto& aero) {
	string id, nom, nac, aux;
	int edad, op;
	bool error = false;
	do {
		if (error) { ErrorCedulaExistente(); }
		cout << "()->Digite la cedula del Empleado: "; cin >> id;
		error = true;
	} while (aero.empleadoCed(id) != NULL);
	cout << "()->Digite el nombre del Empleado: "; cin >> nom;
	cout << "()->Digite la edad del Empleado: "; cin >> aux;
	edad = PasarStringAInt(aux);
	cout << "()->Digite la nacionalida del Empleado: "; cin >> nac;
	system("CLS");
	cout << "--	Aeronaves --" << endl;
	cout << aero.toStringAeronaves();
	do {
		cout << endl << "Digite el numero de aeronave para ingresar empleado: "; cin >> aux;
		op = PasarStringAInt(aux);
	} while (op <= 0 || op > aero.getCantidadAeronaves());
	Aeronave* nav = (Aeronave*)aero.naveN(op);
	Empleado* emp = new Azafata(id, nom, edad, *nav, nac);
	aero.agregarEmpleado(*emp);
	AgregadoExitoso();
}

void Interfaz::IngresarPlanta(Aeropuerto& aero) {
	string opaux; int op = 1;
	cout << "==========================================" << endl;
	cout << "================= Planta =================" << endl;
	cout << "   (1) Ingresar Empleado Administrativo" << endl;
	cout << "   (2) Ingresar Miscelaneo" << endl;
	cout << "   (3) Volver a Menu" << endl;
	cout << "==========================================" << endl;
	do {
		if (op < 1 || op > 3) { ErrorDato(); }
		cin >> opaux;
		op = PasarStringAInt(opaux);
	} while (op < 1 || op > 3);

	system("CLS");
	switch (op) {
	case 1: IngresarAdministrativo(aero); break;
	case 2:	IngresarMiscelaneo(aero); break;
	case 4: break;
	}
}
void Interfaz::IngresarAdministrativo(Aeropuerto& aero) {
	string id, nom, aux, tit;
	int edad;
	bool error = false;
	do {
		if (error) { ErrorCedulaExistente(); }
		cout << "()->Digite la cedula del Empleado: "; cin >> id;
		error = true;
	} while (aero.empleadoCed(id) != NULL);
	cout << "()->Digite el nombre del Empleado: "; cin >> nom;
	cout << "()->Digite la edad del Empleado: "; cin >> aux;
	edad = PasarStringAInt(aux);
	cout << "()->Digite el titulo academico: "; cin >> tit;
	Empleado* emp = new EmpleadoAdmi(id, nom, edad, tit);
	aero.agregarEmpleado(*emp);
	AgregadoExitoso();
}
void Interfaz::IngresarMiscelaneo(Aeropuerto& aero) {
	string id, nom, aux, gra, area;
	int edad;
	bool error = false;
	do {
		if (error) { ErrorCedulaExistente(); }
		cout << "()->Digite la cedula del Empleado: "; cin >> id;
		error = true;
	} while (aero.empleadoCed(id) != NULL);
	cout << "()->Digite el nombre del Empleado: "; cin >> nom;
	cout << "()->Digite la edad del Empleado: "; cin >> aux;
	edad = PasarStringAInt(aux);
	cout << "()->Digite el grado de escolaridad: "; cin >> gra;
	cout << "()->Digite el area de trabajo: "; cin >> area;
	Empleado* emp = new Miscelaneo(id, nom, edad, gra, area);
	aero.agregarEmpleado(*emp);
	AgregadoExitoso();
}

//Aeronaves---------------------------------------------------------------------------------------------------------------------

void Interfaz::IngresarAeronave(Aeropuerto& aero) {
	string opaux; int op = 1;
	cout << "=============================================" << endl;
	cout << "================= Aeronaves =================" << endl;
	cout << "   (1) Ingresar Aeronave Comercial" << endl;
	cout << "   (2) Ingresar Aeronave de Carga" << endl;
	cout << "   (3) Ingresar Aeronave Militar" << endl;
	cout << "   (4) Volver a Menu" << endl;
	cout << "=============================================" << endl;
	cout << "Digite el tipo de aeronave que desea Ingresar: ";
	do {
		if (op < 1 || op > 4) { ErrorDato(); }
		cin >> opaux;
		op = PasarStringAInt(opaux);
	} while (op < 1 || op > 4);

	system("CLS");
	switch (op) {
	case 1: IngresarComercial(aero); break;
	case 2:	IngresarCarga(aero); break;
	case 3:	IngresarMilitar(aero); break;
	case 4: break;
	}
}

void Interfaz::IngresarComercial(Aeropuerto& aero) {
	string pla = "idf";
	string aux;
	double dis;
	int d = -1, me = -1, a = -1, cat = -1;
	bool tip;
	//Fecha
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de creacion: "; cin >> d;
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de creacion: "; cin >> me;
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de creacion: "; cin >> a;
	} while (a < 1000 || a > 3000);
	Fecha* fecha1 = new Fecha(d, me, a);
	//
	cout << "()->Digite la distancia recorrida de la Aeronave(metros): ";
		cin >> aux;
		dis = PasarStringAInt(aux);
	do {
		if (pla != "idf") { ErrorPlacaExistente(); }
		cout << "()->Digite a placa de la Aeronave: "; cin >> pla;
	} while (aero.aeronavePla(pla) != NULL);
	//categoria
	system("CLS");
	cout << "=Categorias de Aeronaves Comerciales=" << endl;
	cout << "310 - 747 - 676 - 777 - 130 - 850" << endl;
	do {
		if (cat != -1) { ErrorCategoriaNoExistente(); }
		cout << "()->Digite a categoria de la Aeronave: "; cin >> aux;
		cat = PasarStringAInt(aux);
	} while (ServicioComercial::Avion(cat) == "idf");
	//categoria
	cout << "1. Pasillo Unico" << endl << "2. Pasillo Doble" << endl;
	cout << "()->Digite el tipo de pasillo: "; cin >> aux;
	if (PasarStringAInt(aux) < 2) { tip = false; }
	else { tip = true; }
	Aeronave* nave = new Comerciales(*fecha1, dis, pla, cat, tip);
	aero.agregarAeronave(*nave);
	AgregadoExitoso();
}
void Interfaz::IngresarCarga(Aeropuerto& aero) {
	string pla = "idf";
	string aux;
	double dis, alt, anc;
	string cat = "";
	int d = -1, me = -1, a = -1;
	bool tip, error = false;
	//Fecha
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de creacion: "; cin >> d;
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de creacion: "; cin >> me;
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de creacion: "; cin >> a;
	} while (a < 1000 || a > 3000);
	Fecha* fecha1 = new Fecha(d, me, a);
	//
	cout << "()->Digite la distancia recorrida de la Aeronave(metros): ";cin >> aux;
	dis = PasarStringAInt(aux);
	do {
		if (pla != "idf") { ErrorPlacaExistente(); }
		cout << "()->Digite a placa de la Aeronave: "; cin >> pla;
	} while (aero.aeronavePla(pla) != NULL);
	cout << "()->Digite la altura de la puerta de la Aeronave(centimetros): "; cin >> aux;
	alt = PasarStringAInt(aux);
	cout << "()->Digite la anchura de la puerta de la Aeronave(centimetros): "; cin >> aux;
	anc = PasarStringAInt(aux);
	//categoria
	system("CLS");
	cout << "=======Categorias de Aeronaves de Carga========" << endl;
	cout << "A319 - A320 - A321 - A330 - A340 - B737 - B777" << endl;
	do {
		if (error) { ErrorCategoriaNoExistente(); }
		cout << "()->Digite a categoria de la Aeronave: "; cin >> cat;
		error = true;
	} while (ServicioCarga::Avion(cat) == "idf");
	//tipo
	cout << "1. Escotilla" << endl << "2. Lateral" << endl;
	cout << "()->Digite el tipo de puerta: "; cin >> aux;
	if (PasarStringAInt(aux) < 2) { tip = false; }
	else { tip = true; }
	Aeronave* nave = new Carga(*fecha1, dis, pla, alt, anc, cat, tip);
	aero.agregarAeronave(*nave);
	AgregadoExitoso();
}
void Interfaz::IngresarMilitar(Aeropuerto& aero) {
	string pla = "idf";
	string aux;
	double dis, vel;
	string cat = "";
	int d = -1, me = -1, a = -1;
	bool error = false;
	//Fecha
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia de creacion: "; cin >> d;
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes de creacion: "; cin >> me;
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio de creacion: "; cin >> a;
	} while (a < 1000 || a > 3000);
	Fecha* fecha1 = new Fecha(d, me, a);
	//
	cout << "()->Digite la distancia recorrida de la Aeronave(metros): "; cin >> aux;
	dis = PasarStringAInt(aux);
	do {
		if (error) { ErrorPlacaExistente(); }
		cout << "()->Digite a placa de la Aeronave: "; cin >> pla;
		error = true;
	} while (aero.aeronavePla(pla) != NULL);
	cout << "()->Digite velocidad maxima de la Aeronave(Km/h): "; cin >> aux;
	vel = PasarStringAInt(aux);
	//categoria
	system("CLS");
	cout << "=Categorias de Aeronaves Militares=" << endl;
	cout << "  - - - - - M300 - M130 - - - - -  " << endl;
	do {
		if (cat == "idf") { ErrorCategoriaNoExistente(); }
		cout << "()->Digite a categoria de la Aeronave: "; cin >> cat;
	} while (ServicioMilitar::Avion(cat) == "idf");
	Aeronave* nave = new Militar(*fecha1, dis, pla, vel, cat);
	aero.agregarAeronave(*nave);
	AgregadoExitoso();
}

//Mantenimiento===============================================================================================================
//============================================================================================================================
