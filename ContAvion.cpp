#include"ContAvion.h"

NodoAvi::NodoAvi() {
	NO = NULL; 
	SN = NULL;
}
NodoAvi::NodoAvi(Aeronave& no, NodoAvi* sn) {
	NO = (Aeronave*)&no;
	SN = sn;
}

NodoAvi::~NodoAvi() {}

void NodoAvi::setObj(Aeronave& no) {
	if (NO != NULL) {
		delete NO;
	}
	NO = (Aeronave*)&no;
}
void NodoAvi::setSigNodo(NodoAvi* sn) {
	SN = sn;
}

Aeronave* NodoAvi::getObj() { return NO; }
NodoAvi* NodoAvi::getSigNodo() { return SN; }

//Aeronave

ContAvion::ContAvion() {
	ppio = NULL;
}
ContAvion::~ContAvion() {
	NodoAvi* pex = ppio;
	while (pex != NULL) {
		ppio = pex->getSigNodo();
		delete pex->getObj();
		delete pex;
		pex = ppio;
	}
}

void ContAvion::Agregar(Aeronave& avi) {
	NodoAvi* pex = ppio;
	NodoAvi* nn = new NodoAvi(avi, NULL);
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

bool ContAvion::Eliminar(Aeronave& aviborra) {
	NodoAvi* pex = ppio;
	if (pex == NULL) {
		return false;
	}
	if (pex->getObj()->getPlaca() == aviborra.getPlaca()) {
		ppio = pex->getSigNodo();
		delete pex->getObj();
		delete pex;
		return true;
	}
	while (pex->getSigNodo() != NULL) {
		if (pex->getSigNodo()->getObj()->getPlaca() == aviborra.getPlaca()) {
			NodoAvi* Aux = pex->getSigNodo()->getSigNodo();

			delete pex->getSigNodo()->getObj();
			delete pex->getSigNodo();

			pex->setSigNodo(Aux);

			return true;
		}
		pex = pex->getSigNodo();
	}
	return false;
}

string ContAvion::toString() {
	stringstream s;
	NodoAvi* pex = ppio;
	int i = 1;
	if (pex == NULL) {
		return "No hay Aeronaves";
	}
	while (pex != NULL) {
		s << i << ") " << pex->getObj()->toString() << endl;
		pex = pex->getSigNodo(); i++;
	}
	return s.str();
}

Aeronave* ContAvion::AeronavePlaca(string placa){
	NodoAvi* pex = ppio;
	if (pex == NULL) {
		return NULL;
	}
	while (pex != NULL) {
		if (pex->getObj()->getPlaca() == placa) {
			return pex->getObj();
		}
		pex = pex->getSigNodo();
	}
	return NULL;
}

Aeronave* ContAvion::naveN(int n) {
	NodoAvi* pex = ppio; int i = 0;
	if (pex == NULL) {
		return NULL;
	}
	while (pex->getSigNodo() != NULL && i < n) {
		pex = pex->getSigNodo();
		i++;
	}
	return pex->getObj();
}

string ContAvion::Placas() {
	stringstream s;
	NodoAvi* pex = ppio;
	if (pex == NULL) {
		return "No hay Aeronaves";
	}
	while (pex != NULL) {
		s << pex->getObj()->getPlaca() << endl;
		pex = pex->getSigNodo();
	}
	return s.str();
}

int ContAvion::cantidad() {
	NodoAvi* pex = ppio;
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