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
	cout << "<<No hay empleados suficientes>>" << endl;
}
void Interfaz::ErrorInsuficientesAeronaves() {
	cout << "<<No hay aeronaves sufivientes>>" << endl;
}
void Interfaz::ErrorInsuficientesContratos() {
	cout << "<<No hay contratos suficientes>>" << endl;
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
void Interfaz::ErrorAzafataExistente() {
	cout << "<<ya hay una azafata en esa aeronave>>" << endl;
}
void Interfaz::ErrorInsuficientesEmpleadosSinContrato() {
	cout << "<<Insuficientes empleados sin contrato>>" << endl;
}
void Interfaz::ErrorContratoYaExistente() {
	cout << "<<Ese empleado ya posee contrato>>" << endl;
}
void Interfaz::ErrorAzafataEnMilitar() {
	cout << "<<Las azafatas no pueden ir en aviones Militares>>" << endl;
}
void Interfaz::NoSePudoEliminar() {
	cout << "<<No se pudo eliminar>>" << endl;
}
void Interfaz::MismaAeronaves() {
	cout << "<<La Aeronave digitada es la misma>>" << endl;
}

//Confirmaciones

void Interfaz::AgregadoExitoso() {
	cout << "<<Agregado con exito>>" << endl;
}
void Interfaz::EliminadoExitoso() {
	cout << "<<Eliminado con exito>>" << endl;
}

void Interfaz::Despedida() {
	system("CLS");
	cout << "<< Gracias >>" << endl;
}

//Menu------------------------------------------------------------------------------------------------------------------------

//Ingresar====================================================================================================================
// ===========================================================================================================================
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
			} while (  op < 1 || op > aero.getCantidadAeronaves());
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
	if (aero.getCantidadCopilotos() >= aero.getCantidadAeronaves()) {
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
		cout << "()->Digite el numero de telefono del Empleado: "; cin >> tel;
		do {
			system("CLS");
			if (hayCopiloto) { ErrorCopilotoExistente(); }
			cout << "--	Aeronaves --" << endl;
			cout << aero.toStringAeronaves();
			do {
				cout << endl << "Digite el numero de aeronave para ingresar empleado: "; cin >> aux;
				op = PasarStringAInt(aux);
			} while (op < 1 || op > aero.getCantidadAeronaves());
			hayCopiloto = aero.hayCopiloto(aero.naveN(op));
		} while (hayCopiloto);
		Aeronave* nav = (Aeronave*)aero.naveN(op);
		Empleado* emp = new Copiloto(id, nom, edad, *nav, tel);
		aero.agregarEmpleado(*emp);
		AgregadoExitoso();
	}
}
void Interfaz::IngresarAzafata(Aeropuerto& aero) {
	string id, nom, nac, aux;
	int edad, op;
	bool error = false, hayAzafata = false, esMilitar = false;
	if (aero.getCantidadAzafatas() >= (aero.getCantidadAeronaves() - aero.getCantidadMilitares())) {
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
		cout << "()->Digite la nacionalidad del Empleado: "; cin >> nac;
		do {
			system("CLS");
			if (hayAzafata) { ErrorAzafataExistente(); }
			hayAzafata = false;
			if (esMilitar) { ErrorAzafataEnMilitar(); }
			esMilitar = false;
			cout << "--	Aeronaves --" << endl;
			cout << aero.toStringAeronaves();
			do {
				cout << endl << "Digite el numero de aeronave para ingresar empleado: "; cin >> aux;
				op = PasarStringAInt(aux);
			} while (op < 1 || op > aero.getCantidadAeronaves());
			hayAzafata = aero.hayAzafata(aero.naveN(op));
			esMilitar = aero.EsMilitar(aero.naveN(op));
		} while (hayAzafata || esMilitar);
		Aeronave* nav = (Aeronave*)aero.naveN(op);
		Empleado* emp = new Azafata(id, nom, edad, *nav, nac);
		aero.agregarEmpleado(*emp);
		AgregadoExitoso();
	}
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

void Interfaz::Mantenimiento(Aeropuerto& aero) {
	system("CLS");
	string opaux; int op = 1;
	cout << "=====================================" << endl;
	cout << "==========  Mantenimiento  ==========" << endl;
	cout << "\t(1) Eliminar Contrato" << endl;
	cout << "\t(2) Eliminar Empleado" << endl;
	cout << "\t(3) Eliminar Aeronave" << endl;
	cout << "\t(4) Volver a Menu" << endl;
	cout << "=====================================" << endl;
	cout << "Digite lo que desea Eliminar: ";
	do {
		if (op < 1 || op > 4) { ErrorDato(); }
		cin >> opaux;
		op = PasarStringAInt(opaux);
	} while (op < 1 || op > 4);
	system("CLS");
	switch (op) {
	case 1: EliminarContrato(aero); break;
	case 2:	EliminarEmpleado(aero); break;
	case 3:	EliminarAeronave(aero); break;
	case 4: break;
	}
}

void Interfaz::EliminarContrato(Aeropuerto& aero) {
	string aux;
	int op;
	if (1 > aero.getCantidadContratos()) { ErrorInsuficientesContratos(); }
	else{
		cout << "==== Eliminar Contrato ====" << endl;
		cout << aero.toStringContratos();
		do {
			cout << "Digite el numero de contrato que desea eliminar: "; cin >> aux;
			op = PasarStringAInt(aux);
		} while (op < 1 || op > aero.getCantidadContratos());
		if (aero.eliminarContrato(*aero.contratoN(op))) {
			EliminadoExitoso();
		}
		else {
			NoSePudoEliminar();
		}
	}
}
void Interfaz::EliminarEmpleado(Aeropuerto& aero) {
	string aux;
	int op;
	if (1 > aero.getCantidadEmpleados()) { ErrorInsuficientesEmpleados(); }
	else {
		cout << "==== Eliminar Empleado ====" << endl;
		cout << aero.toStringEmpleados();
		do {
			cout << "Digite el numero de empleado que desea eliminar: "; cin >> aux;
			op = PasarStringAInt(aux);
		} while (op < 1 || op > aero.getCantidadEmpleados());
		if (aero.empleadoN(op)->getContrato() != NULL) {
			cout << "--Contrato:" << endl;
			if (aero.eliminarContrato(*aero.empleadoN(op)->getContrato())) {
				EliminadoExitoso();
			}
			else {
				NoSePudoEliminar();
			}
		}
		cout << "--Empleado:" << endl;
		if (aero.eliminarEmpleado(*aero.empleadoN(op))) {
			EliminadoExitoso();
		}
		else {
			NoSePudoEliminar();
		}
	}
}
void Interfaz::EliminarAeronave(Aeropuerto& aero) {
	string aux;
	int op1, op2 = -1;
	bool error = false;
	if (2 > aero.getCantidadAeronaves()) { ErrorInsuficientesAeronaves(); } 
	else {
		cout << "==== Eliminar Aeronaves ====" << endl;
		cout << aero.toStringAeronaves();
		do {
			if (error) { ErrorDato(); }
			cout << "Digite el numero de aeronave que desea eliminar: "; cin >> aux;
			op1 = PasarStringAInt(aux);
			error = true;
		} while (op1 < 1 || op1 > aero.getCantidadAeronaves());
		system("CLS");
		error = false;
		cout << "==== Eliminar Aeronaves ====" << endl;
		cout << aero.toStringAeronaves();
		do {
			if (op1 == op2) { MismaAeronaves(); }
			else if (error) { ErrorDato(); }
			cout << "Seleccione otra aeronave para ingresar a la tripulacion: "; cin >> aux;
			op2 = PasarStringAInt(aux);
			error = true;
		} while (op1 < 1 || op1 > aero.getCantidadAeronaves() || op1 == op2);

		if (aero.PasarEmpleados(*aero.naveN(op1), *aero.naveN(op2))) {
			aero.eliminarAeronaves(*aero.naveN(op1));
			EliminadoExitoso();
		}
		else {
			NoSePudoEliminar();
			cout << "La primera aeronave le falta un piloto, copiloto o azafata/La segunda aeronave ya tiene piloto, copiloto o azafata" << endl;
		}
	}
}

//Reportes====================================================================================================================
//============================================================================================================================

void Interfaz::Reportes(Aeropuerto& aero) {
	system("CLS");
	string opaux; int op = 1;
	cout << "==========================================================" << endl;
	cout << "=======================  Reportes  =======================" << endl;
	cout << "\t(1) Contrato con Empleados" << endl;
	cout << "\t(2) Aeronaves con Tripulacion" << endl;
	cout << "\t(3) Todas las Aeronaves" << endl;
	cout << "\t(4) Todos los Pilotos de carga" << endl;
	cout << "\t(5) Aeronaves con mas de 20 anios" << endl;
	cout << "\t(6) Todos los Contratos de Servicios" << endl;
	cout << "\t(7) Todos los Contratos de Plazo" << endl;
	cout << "\t(8) Todos los Contratos Indefinidos" << endl;
	cout << "\t(9) Todos los Tripulantes de Aeronaves Comerciales" << endl;
	cout << "\t(10) Contratos de Plazo que Excedieron 2 anios" << endl;
	cout << "\t(11) Aeronave de Carga con Puerta mas Grande" << endl;
	cout << "\t(12) Volver a Menu" << endl;
	cout << "==========================================================" << endl;
	cout << "Digite lo que desee Obtener Reporte: ";
	do {
		if (op < 1 || op > 12) { ErrorDato(); }
		cin >> opaux;
		op = PasarStringAInt(opaux);
	} while (op < 1 || op > 12);
	system("CLS");
	switch (op) {
	case 1: ReporteContratoYEmpleado(aero); break;
	case 2:	ReporteAeronavesConTripulacion(aero); break;
	case 3:	ReporteAeronaves(aero); break;
	case 4: ReportePilotosDeCarga(aero); break;
	case 5:	ReporteAeronavesMas20(aero); break;
	case 6:	ReporteContratosSerivicios(aero); break;
	case 7: ReporteContratosPlazo(aero); break;
	case 8:	ReporteContratosIndefinidos(aero); break;
	case 9:	ReporteTripulantesComerciales(aero); break;
	case 10: ReporteContratosPlazoFijoMas2(aero); break;
	case 11: ReportePuertaMasGrande(aero); break;
	case 12: break;
	}
}

void Interfaz::ReporteContratoYEmpleado(Aeropuerto& aero) {
	cout << "====== Contratos con Empleados ======" << endl;
	cout << aero.toStringEmpleados() << endl;
}
void Interfaz::ReporteAeronavesConTripulacion(Aeropuerto& aero) {
	cout << "====== Aeronaves con Tripulacion ======" << endl;
	for (int i = 1; i <= aero.getCantidadAeronaves(); i++) {
		if (aero.naveN(i) != NULL) {
			cout << aero.naveN(i)->toString();
			cout << aero.toStringAeronavesConTripulacion(*aero.naveN(i));
		}
	}
	cout << endl;
}

void Interfaz::ReporteAeronaves(Aeropuerto& aero) {
	cout << "====== Aeronaves ======" << endl;
	cout << aero.toStringAeronaves() << endl;
}

void Interfaz::ReportePilotosDeCarga(Aeropuerto& aero) {
	cout << "====== Pilotos de Carga ======" << endl;
	cout << aero.pilotosCarga() << endl;
}

void Interfaz::ReporteAeronavesMas20(Aeropuerto& aero) {
	int d = -1, me = -1, a = -1;
	string aux;
	cout << "== Digite la fecha actual ==" << endl;
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia actual: "; cin >> aux;
		d = PasarStringAInt(aux);
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes actual: "; cin >> aux;
		me = PasarStringAInt(aux);
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio actual: "; cin >> aux;
		a = PasarStringAInt(aux);
	} while (a < 1000 || a > 3000);
	Fecha* act = new Fecha(d, me, a);

	system("CLS");

	cout << "====== Aeronaves con mas de 20 anios de uso ======" << endl;
	cout << aero.AeronavesMas20(*act) << endl;

	if (act != NULL) {
			delete act;
	}
}

void Interfaz::ReporteContratosSerivicios(Aeropuerto& aero) {
	cout << "====== Contratos de Servicios Profesionales ======" << endl;
	cout << aero.ContratosServicios() << endl;
}
void Interfaz::ReporteContratosPlazo(Aeropuerto& aero) {
	cout << "====== Contratos de Plazo Fijo ======" << endl;
	cout << aero.ContratosPlazo() << endl;
}
void Interfaz::ReporteContratosIndefinidos(Aeropuerto& aero) {
	cout << "====== Contratos de Tiempo Indefinido ======" << endl;
	cout << aero.ContratosIndefinidos() << endl;
}

void Interfaz::ReporteTripulantesComerciales(Aeropuerto& aero) {
	cout << "====== Tripulacion de Aeronaves Comerciales ======" << endl;
	cout << aero.TripulacionComerciales(); 
}

void Interfaz::ReporteContratosPlazoFijoMas2(Aeropuerto& aero) {
	int d = -1, me = -1, a = -1;
	string aux;
	cout << "== Digite la fecha actual ==" << endl;
	do {
		if (d != -1) { ErrorDato(); }
		cout << "()->Digite el dia actual: "; cin >> aux;
		d = PasarStringAInt(aux);
	} while (d < 0 || d > 30);
	do {
		if (me != -1) { ErrorDato(); }
		cout << "()->Digite el mes actual: "; cin >> aux;
		me = PasarStringAInt(aux);
	} while (me < 0 || me > 12);
	do {
		if (a != -1) { ErrorDato(); }
		cout << "()->Digite el anio actual: "; cin >> aux;
		a = PasarStringAInt(aux);
	} while (a < 1000 || a > 3000);
	Fecha* act = new Fecha(d, me, a);

	system("CLS");
	//////////////////////////Falta



	if (act != NULL) {
		delete act;
	}
}

void Interfaz::ReportePuertaMasGrande(Aeropuerto& aero) {
	cout << "====== Puerta Mas Grande ======" << endl;
	if (aero.PuertaMasGrande() != NULL) {
		cout << aero.PuertaMasGrande()->toString();
	}
	else {
		cout << "<<No hay Aeronaves de Carga>>";
	}
}

//Consultar==================================================================================================================
//===========================================================================================================================

void Interfaz::Consultar(Aeropuerto& aero) {
	system("CLS");
	string opaux; int op = 1;
	cout << "=========================================" << endl;
	cout << "==============  Consultar  ==============" << endl;
	cout << "\t(1) Consultar Empleado por Cedula" << endl;
	cout << "\t(2) Consultar Contrato por Codigo" << endl;
	cout << "\t(3) Consultar Aeronave por Placa" << endl;
	cout << "\t(4) Volver a Menu" << endl;
	cout << "=========================================" << endl;
	cout << "Digite lo que desea Consultar: ";
	do {
		if (op < 1 || op > 4) { ErrorDato(); }
		cin >> opaux;
		op = PasarStringAInt(opaux);
	} while (op < 1 || op > 4);

	system("CLS");
	switch (op) {
	case 1: ConsultarEmpleadoCed(aero); break;
	case 2:	ConsultarContratoCod(aero); break;
	case 3:	ConsultarAeronavePlaca(aero); break;
	case 4: break;
	}
}

void Interfaz::ConsultarEmpleadoCed(Aeropuerto& aero) {
	string ced;
	if (aero.getCantidadEmpleados() < 1) {
		ErrorInsuficientesEmpleados();
	}
	else {
		cout << "()->Digite la cedula: "; cin >> ced;
		if (aero.empleadoCed(ced) != NULL) {
			cout << aero.empleadoCed(ced)->toString() << endl;
			if (aero.empleadoCed(ced)->getAeronave() != NULL) {
				cout << aero.empleadoCed(ced)->getAeronave()->toString() << endl;
			}
		}	
		else {
			cout << "No existe empleado con esa cedula" << endl;
		}
	}
}
void Interfaz::ConsultarContratoCod(Aeropuerto& aero) {
	string cod;
	if (aero.getCantidadContratos() < 1) {
		ErrorInsuficientesContratos();
	}
	else {
		cout << "()->Digite la cedula: "; cin >> cod;
		if (aero.contratoCod(cod) != NULL) {
			cout << aero.contratoCod(cod)->toString();
		}
		else {
			cout << "No existe contrato con ese codigo" << endl;
		}
	}
}
void Interfaz::ConsultarAeronavePlaca(Aeropuerto& aero) {
	string pla;
	if (aero.getCantidadAeronaves() < 1) {
		ErrorInsuficientesAeronaves();
	}
	else {
		cout << "()->Digite la placa: "; cin >> pla;
		if (aero.aeronavePla(pla) != NULL) {
			cout << aero.aeronavePla(pla)->toString();
		}
		else {
			cout << "No existe aeronave con esa placa" << endl;
		}
	}
}
