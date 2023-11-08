#include"ContEmpleado.h"

NodoEmp::NodoEmp() {
	NO = NULL;
	SN = NULL;
}
NodoEmp::NodoEmp(Empleado& no, NodoEmp* sn) {
	NO = (Empleado*)&no;
	SN = sn;
}

NodoEmp::~NodoEmp() {}

void NodoEmp::setObj(Empleado& no) {
	if (NO != NULL) {
		delete NO;
	}
	NO = (Empleado*)&no;
}
void NodoEmp::setSigNodo(NodoEmp* sn) {
	SN = sn;
}

Empleado* NodoEmp::getObj() { return NO; }
NodoEmp* NodoEmp::getSigNodo() { return SN; }

//Empleado

ContEmpleado::ContEmpleado() {
	ppio = NULL;
}
ContEmpleado::~ContEmpleado() {
	NodoEmp* pex = ppio;
	while (pex != NULL) {
		ppio = pex->getSigNodo();
		delete pex->getObj();
		delete pex;
		pex = ppio;
	}
}

void ContEmpleado::Agregar(Empleado& con) {
	NodoEmp* pex = ppio;
	NodoEmp* nn = new NodoEmp(con, NULL);
	if (pex == NULL) {
		ppio = nn;
	}
	else {
		while (pex->getSigNodo() != NULL) {
			pex = pex->getSigNodo();
		}
		pex->setSigNodo(nn);
	}
}

bool ContEmpleado::Eliminar(Empleado& con) {
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return false;
	}
	if (pex->getObj()->getCedula() == con.getCedula()) {
		ppio = pex->getSigNodo();
		delete pex->getObj();
		delete pex;
		return true;
	}
	while (pex->getSigNodo() != NULL) {
		if (pex->getSigNodo()->getObj()->getCedula() == con.getCedula()) {
			NodoEmp* Aux = pex->getSigNodo()->getSigNodo();

			delete pex->getSigNodo()->getObj();
			delete pex->getSigNodo();

			pex->setSigNodo(Aux);

			return true;
		}
		pex = pex->getSigNodo();
	}
	return false;
}

string ContEmpleado::toString() {
	stringstream s;
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return "No hay Contratos";
	}
	while (pex != NULL) {
		s << pex->getObj()->toString() << endl;
		pex = pex->getSigNodo();
	}
	return s.str();
}
Empleado* ContEmpleado::EmpleadoCed(string ced) {
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return NULL;
	}
	while (pex->getSigNodo() != NULL) {
		if (pex->getObj()->getCedula() == ced) {
			return pex->getObj();
		}
		pex = pex->getSigNodo();
	}
	return NULL;
}
int ContEmpleado::cantidad() {
	NodoEmp* pex = ppio;
	int i = 1;
	if (pex == NULL) {
		return 0;
	}
	while (pex->getSigNodo() != NULL) {
		pex = pex->getSigNodo();
		i++;
	}
	return i;
}