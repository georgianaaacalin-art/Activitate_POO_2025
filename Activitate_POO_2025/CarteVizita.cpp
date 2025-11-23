#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CarteVizita {
private:
	const int IdCarteVizita;
	string tipMaterial;
	int nrExemplare;
	float dimensiune;
	char* categorie;

public:
	CarteVizita() :IdCarteVizita() {
		this->tipMaterial = "";
		this->nrExemplare = 0;
		this->dimensiune = 0.0;
		this->categorie = nullptr;

	}

	CarteVizita(string tipMaterial = " ", int nrExemplare = 0, float dimensiune = 0.0, const char* categorie = nullptr) :IdCarteVizita() {
		this->tipMaterial = tipMaterial;
		this->nrExemplare = nrExemplare;
		this->dimensiune = dimensiune;

		if (categorie != nullptr) {
			this->categorie = new char[strlen(categorie) + 1];
			strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
		}
		else {
			this->categorie = nullptr;
		}
	}

	CarteVizita(CarteVizita& copie) : IdCarteVizita() {
		this->tipMaterial = copie.tipMaterial;
		this->nrExemplare = copie.nrExemplare;
		this->dimensiune = copie.dimensiune;

		if (copie.categorie != nullptr) {
			this->categorie = new char[strlen(copie.categorie) + 1];
			strcpy_s(this->categorie, strlen(copie.categorie) + 1, copie.categorie);
		}
		else {
			this->categorie = nullptr;
		}
	}

	~CarteVizita() {
		if (this->categorie != nullptr) {
			delete[] this->categorie;
		}
	}

	CarteVizita& operator=(CarteVizita& copie) {
		if (this->categorie != nullptr) {
			delete[] this->categorie;
		}

		this->tipMaterial = copie.tipMaterial;
		this->nrExemplare = copie.nrExemplare;
		this->dimensiune = copie.dimensiune;

		if (copie.categorie != nullptr) {
			this->categorie = new char[strlen(copie.categorie) + 1];
			strcpy_s(this->categorie, strlen(copie.categorie) + 1, copie.categorie);
		}
		else {
			this->categorie = nullptr;
		}

		return *this;
	}

	string getTipMaterial() {
		return this->tipMaterial;
	}

	int getNrExemplare() {
		return this->nrExemplare;
	}

	float getDimensiune() {
		return this->dimensiune;
	}

	char* getCategorie() {
		return this->categorie;
	}

	friend ostream& operator <<(ostream& out, CarteVizita copie) {
		out << copie.tipMaterial << " " << copie.nrExemplare << " "
			<< copie.dimensiune << " " << copie.categorie << " ";

		if (copie.categorie != nullptr) {
			out << copie.categorie;
		}
	}

	CarteVizita operator+=(const CarteVizita& copie) {
		this->tipMaterial += copie.tipMaterial;
		this->nrExemplare += copie.nrExemplare;
		this->dimensiune += copie.dimensiune;

		if (copie.categorie != nullptr) {
			this->categorie = new char[strlen(copie.categorie) + 1];
			strcpy_s(this->categorie, strlen(copie.categorie) + 1, copie.categorie);
		}
		else {
			this->categorie = nullptr;
		}

	}

	//operator postincrementare
	CarteVizita operator++(int i) {
		CarteVizita copie = *this;
		this->nrExemplare++;

		return copie;
	}

	//operator preincrementare
	CarteVizita operator++() {
		CarteVizita copie2 = *this;
		this->nrExemplare++;

		return copie2;
	}
};

void main() {

	CarteVizita CV1("Carton", 5, 5.5, "1");
	cout << "Tipul materialului: " << CV1.getTipMaterial() << endl;
	cout << "Numarul de exemplare este: " << CV1.getNrExemplare() << endl;
	cout << "Dimensiunea este: " << CV1.getDimensiune() << endl;
	cout << "Categoria este: " << CV1.getCategorie() << endl;
	cout << endl;

	CarteVizita CV2("Plastic", 4, 7.3, "2");
	cout << "Tipul materialului: " << CV2.getTipMaterial() << endl;
	cout << "Numarul de exemplare este: " << CV2.getNrExemplare() << endl;
	cout << "Dimensiunea este: " << CV2.getDimensiune() << endl;
	cout << "Categoria este: " << CV2.getCategorie() << endl;
	cout << endl;

	int nrExemplare = 5;
	nrExemplare += 4;
	cout << "Nr de exemplare pt prima carte de vizita este: " << nrExemplare << endl;

	cout << "Dimensiunea primei carti de vizita este: " << CV1.getDimensiune() << endl;
	CV1++;
	cout << "Dimensiunea primei carti de vizita este: " << CV1.getDimensiune() << endl;
	CV1++;
	cout << "Dimensiunea primei carti de vizita este: " << CV1.getDimensiune() << endl;
	CV1++;

	cout << "Dimensiunea primei carti de vizita dupa modificare este: " << CV1.getDimensiune() << endl;
	++CV1;
	cout << "Dimensiunea primei carti de vizita dupa modificare este: " << CV1.getDimensiune() << endl;
	++CV1;
	cout << "Dimensiunea primei carti de vizita dupa modificare este: " << CV1.getDimensiune() << endl;
	++CV1;

	float dimensiune = 5.5;
	float dimensiune2 = 4.5;
	if (dimensiune >= dimensiune2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

}