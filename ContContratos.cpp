#include"ContContrato.h"

NodoCon::NodoCon() {
	NO = NULL;
	SN = NULL;
}
NodoCon::NodoCon(Contrato& no, NodoCon* sn) {
	NO = (Contrato*)&no;
	SN = sn;
}

NodoCon::~NodoCon() {}

void NodoCon::setObj(Contrato& no) {
	if (NO != NULL) {
		delete NO;
	}
	NO = (Contrato*)&no;
}
void NodoCon::setSigNodo(NodoCon* sn) {
	SN = sn;
}

Contrato* NodoCon::getObj() { return NO; }
NodoCon* NodoCon::getSigNodo() { return SN; }

//Contrato

ContContrato::ContContrato() {
	ppio = NULL;
}
ContContrato::~ContContrato() {
	NodoCon* pex = ppio;
	while (pex != NULL) {
		ppio = pex->getSigNodo();
		delete pex->getObj();
		delete pex;
		pex = ppio;
	}
}

void ContContrato::Agregar(Contrato& con) {
	NodoCon* pex = ppio;
	NodoCon* nn = new NodoCon(con, NULL);
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

bool ContContrato::Eliminar(Contrato& con) {
	NodoCon* pex = ppio;
	if (pex == NULL) {
		return false;
	}
	if (pex->getObj()->getCodigo() == con.getCodigo()) {
		ppio = pex->getSigNodo();
		delete pex->getObj();
		delete pex;
		return true;
	}
	while (pex->getSigNodo() != NULL) {
		if (pex->getSigNodo()->getObj()->getCodigo() == con.getCodigo()) {
			NodoCon* Aux = pex->getSigNodo()->getSigNodo();

			delete pex->getSigNodo()->getObj();
			delete pex->getSigNodo();

			pex->setSigNodo(Aux);

			return true;
		}
		pex = pex->getSigNodo();
	}
	return false;
}

string ContContrato::toString() {
	stringstream s;
	NodoCon* pex = ppio;
	if (pex == NULL) {
		return "No hay Contratos";
	}
	while (pex != NULL) {
		s << pex->getObj()->toString() << endl;
		pex = pex->getSigNodo();
	}
	return s.str();
}
Contrato* ContContrato::ContratoCod(string cod) {
	NodoCon* pex = ppio;
	if (pex == NULL) {
		return NULL;
	}
	while (pex->getSigNodo() != NULL) {
		if (pex->getObj()->getCodigo() == cod) {
			return pex->getObj();
		}
		pex = pex->getSigNodo();
	}
	return NULL;
}
int ContContrato::cantidad() {
	NodoCon* pex = ppio;
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