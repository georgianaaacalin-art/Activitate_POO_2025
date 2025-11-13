#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ServiciiPrintare {
private:
	string tipMaterial;
	int nrExemplare;
	float* dimensiune;
	static int nrServicii; 

public:
	
	ServiciiPrintare() {
		this->tipMaterial = "";
		this->nrExemplare = 0;
		this->dimensiune = nullptr;
	}

	
	ServiciiPrintare(string tipMaterial = "", int nrExemplare = 0, float dimensiune = 0) {
		this->tipMaterial = tipMaterial;
		this->nrExemplare = nrExemplare;
		this->dimensiune = new float(dimensiune);
	}

	
	ServiciiPrintare(ServiciiPrintare& copie) {
		this->tipMaterial = copie.tipMaterial;
		this->nrExemplare = copie.nrExemplare;

		if (copie.dimensiune != nullptr) {
			this->dimensiune = new float(*copie.dimensiune);
		}
		else {
			this->dimensiune = nullptr;
		}
	}

	
	~ServiciiPrintare() {
		if (this->dimensiune) {
			delete[] this->dimensiune;
		}
	}

	
	ServiciiPrintare& operator=(ServiciiPrintare& copie) {
		if (this->dimensiune) {
			delete[] this->dimensiune;
		}

		this->tipMaterial = copie.tipMaterial;
		this->nrExemplare = copie.nrExemplare;

		if (copie.dimensiune != nullptr) {
			this->dimensiune = new float(*copie.dimensiune);
		}
		else {
			this->dimensiune = nullptr;
		}

		return *this;
	}

	string getTipMaterial() {
		return this->tipMaterial;
	}

	int getNrExemplare() {
		return this->nrExemplare;
	}

	float getDimensiune() const {
		if (this->dimensiune) {
			return *this->dimensiune;
		}
		return 0;

	}

	friend ostream& operator<<(ostream& out, ServiciiPrintare& copie) {
		out << copie.tipMaterial << " " << copie.nrExemplare << " " << copie.dimensiune << " ";
		if (copie.dimensiune != nullptr) {
			out << copie.dimensiune;
		}
		return out;
	}
};

int ServiciiPrintare::nrServicii = 0;

void main() {

	ServiciiPrintare sp1("Lemn", 29, 10.2f);
	cout << "Tipul material este: " << sp1.getTipMaterial() << endl;
	cout << "Numarul de exemplare este: " << sp1.getNrExemplare() << endl;
	cout << "Dimensiunea este: " << sp1.getDimensiune() << endl;
	cout << endl;

	ServiciiPrintare sp2("Sticla", 20, 5.2f);
	cout << "Tipul material este: " << sp2.getTipMaterial() << endl;
	cout << "Numarul de exemplare este: " << sp2.getNrExemplare() << endl;
	cout << "Dimensiunea este: " << sp2.getDimensiune() << endl;
	cout << endl;

	
	int nrExemplare = 29;
	int nrExemplare1 = 20;
	if (nrExemplare < nrExemplare1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

}