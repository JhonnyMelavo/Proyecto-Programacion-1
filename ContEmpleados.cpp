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
	int i = 1;
	if (pex == NULL) {
		return "No hay Empleados";
	}
	while (pex != NULL) {
		s << i << ") " << pex->getObj()->toString() << endl;
		pex = pex->getSigNodo(); i++;
	}
	return s.str();
}
Empleado* ContEmpleado::EmpleadoCed(string ced) {
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return NULL;
	}
	while (pex != NULL) {
		if (pex->getObj()->getCedula() == ced) {
			return pex->getObj();
		}
		pex = pex->getSigNodo();
	}
	return NULL;
}

string ContEmpleado::empleadosSinContrato() {
	stringstream s;
	int i = 1;
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return "No hay Empleados";
	}
	while (pex != NULL) {
		if (pex->getObj()->getContrato() == NULL) {
			s << "--Empleados Numero: " << i << " --" << endl;
			s << pex->getObj()->toString() << endl;
		}
		pex = pex->getSigNodo(); i++;
	}
	return s.str();
}

bool ContEmpleado::hayPiloto(Aeronave* nave) {
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return false;
	}
	while (pex != NULL) {
		if (pex->getObj()->getAeronave() == nave) {
			if (pex->getObj()->getAniosExp() != -1) { return true; }
		}
		pex = pex->getSigNodo();
	}
	return false;
}

bool ContEmpleado::hayCopiloto(Aeronave* nave) {
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return false;
	}
	while (pex != NULL) {
		if (pex->getObj()->getAeronave() == nave) {
			if (pex->getObj()->getTelefono() != " ") { return true; }
		}
		pex = pex->getSigNodo();
	}
	return false;
}
bool ContEmpleado::hayAzafata(Aeronave* nave) {
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return false;
	}
	while (pex != NULL) {
		if (pex->getObj()->getAeronave() == nave) {
			if (pex->getObj()->getNacionalidad() != " ") { return true; }
		}
		pex = pex->getSigNodo();
	}
	return false;
}

Empleado* ContEmpleado::EmpleadoN(int n) {
	NodoEmp* pex = ppio; int i = 1;
	if (pex == NULL) {
		return NULL;
	}
	while (pex->getSigNodo() != NULL && i < n) {
		pex = pex->getSigNodo();
		i++;
	}
	return pex->getObj();
}

bool ContEmpleado::pasarEmpleados(Aeronave& nav1, Aeronave& nav2) {
	NodoEmp* pex = ppio;
	bool pil = hayPiloto((Aeronave*)&nav2);
	bool cop = hayCopiloto((Aeronave*)&nav2);
	bool aza = hayAzafata((Aeronave*)&nav2);
	bool piloto = false, copiloto = false, azafata = false;
	if (pex == NULL) {
		return false;
	}
	while (pex != NULL) {
		if (pex->getObj()->getAeronave() != NULL) {
			if (pex->getObj()->getAeronave()->getPlaca() == nav1.getPlaca()) {
				if (pex->getObj()->getAniosExp() != -1 && !pil) {
					piloto = true;
				}
				else if (pex->getObj()->getTelefono() != " " && !cop) {
					copiloto = true;
				}
				else if (pex->getObj()->getNacionalidad() != " " && !aza && !nav2.esMilitar()) {
					azafata = true;
				}
			}
		}
		pex = pex->getSigNodo();
	}
	if (piloto && copiloto && azafata) {
		pex = ppio;
		if (pex == NULL) {
			return false;
		}
		while (pex != NULL) {
			if (pex->getObj()->getAeronave() != NULL) {
				if (pex->getObj()->getAeronave()->getPlaca() == nav1.getPlaca()) {
					if (pex->getObj()->getAniosExp() != -1 && piloto) {
						pex->getObj()->setAeronave(nav2);
					}
					else if (pex->getObj()->getTelefono() != " " && copiloto) {
						pex->getObj()->setAeronave(nav2);
					}
					else if (pex->getObj()->getNacionalidad() != " " && azafata) {
						pex->getObj()->setAeronave(nav2);
					}
				}
			}
			pex = pex->getSigNodo();
		}
		return true;
	}
	return false;
}

string ContEmpleado::toStringEmpleadosEnAeronave(Aeronave& nave) {
	NodoEmp* pex = ppio;
	stringstream s;
	if (pex == NULL) {
		return "No hay Empleados";
	}
	while (pex != NULL) {
		if (pex->getObj()->getAeronave() != NULL) {
			if (pex->getObj()->getAeronave()->getPlaca() == nave.getPlaca()) {
				s << pex->getObj()->toString();
			}
		}
		pex = pex->getSigNodo();
	}
	return s.str();;
}

string ContEmpleado::pilotosCarga() {
	NodoEmp* pex = ppio;
	stringstream s;
	if (pex == NULL) {
		return "No hay Empleados";
	}
	while (pex != NULL) {
		if (pex->getObj()->getAeronave() != NULL) {
			if (pex->getObj()->getAeronave()->esCarga() && pex->getObj()->getAniosExp() != -1) {
				s << pex->getObj()->toString();
			}
		}
		pex = pex->getSigNodo();
	}
	return s.str();
}

Empleado* ContEmpleado::EmpleadoConContrato(Contrato& con) {
	NodoEmp* pex = ppio;
	stringstream s;
	if (pex == NULL) {
		return NULL;
	}
	while (pex != NULL) {
		if (pex->getObj()->getContrato() != NULL) {
			if (pex->getObj()->getContrato()->getCodigo() == con.getCodigo()) {
				return pex->getObj();
			}
		}
		pex = pex->getSigNodo();
	}
	return NULL;
}

int ContEmpleado::cantidadEmpleadosPlazoMas2(Fecha& fe) {
	NodoEmp* pex = ppio;
	stringstream s;
	int i = 0;
	if (pex == NULL) {
		return NULL;
	}
	while (pex != NULL) {
		if (pex->getObj()->getContrato() != NULL) {
			if (pex->getObj()->getContrato()->esPlazo() && pex->getObj()->getContrato()->getFechaInicio()->mas2Anios(fe)) {
				i++;
			}
		}
		pex = pex->getSigNodo();
	}
	return i;
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

int ContEmpleado::cantidadPilotos() {
	NodoEmp* pex = ppio;
	int i = 0;
	if (pex == NULL) {
		return 0;
	}
	while (pex != NULL) {
		if (pex->getObj()->getAniosExp() != -1) { i++; }
		pex = pex->getSigNodo();
	}
	return i;
}

int ContEmpleado::cantidadCopilotos() {
	NodoEmp* pex = ppio;
	int i = 0;
	if (pex == NULL) {
		return 0;
	}
	while (pex != NULL) {
		if (pex->getObj()->getTelefono() != " ") { i++; }
		pex = pex->getSigNodo();
	}
	return i;
}

int ContEmpleado::cantidadAzafatas() {
	NodoEmp* pex = ppio;
	int i = 0;
	if (pex == NULL) {
		return 0;
	}
	while (pex != NULL) {
		if (pex->getObj()->getNacionalidad() != " ") { i++; }
		pex = pex->getSigNodo();
	}
	return i;
}

int ContEmpleado::cantidadSinContrato() {
	int i = 0;
	NodoEmp* pex = ppio;
	if (pex == NULL) {
		return 0;
	}
	while (pex != NULL) {
		if (pex->getObj()->getContrato() == NULL) {
			i++;
		}
		pex = pex->getSigNodo();
	}
	return i;
}

void ContEmpleado::setContrato(Contrato& con, int n) {
	EmpleadoN(n)->setContrato(con);
}