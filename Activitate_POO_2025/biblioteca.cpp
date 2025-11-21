#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Biblioteca {
protected:
	const int idCarte;
private:
	char* numeCititor;
	string CNP;
	int nrExemplar;
	static int nrCarti;

public:
	Biblioteca() :idCarte(++nrCarti) {
		this->numeCititor = nullptr;
		this->CNP = "";
		this->nrExemplar = 0;
	}

	Biblioteca(const char* numeCititor = nullptr, string CNP = " ", int nrExemplar = 0) :idCarte(++nrCarti) {
		if (numeCititor != nullptr) {
			this->numeCititor = new char[strlen(numeCititor) + 1];
			strcpy_s(this->numeCititor, strlen(numeCititor) + 1, numeCititor);
		}
		else {
			this->numeCititor = nullptr;
		}

		this->CNP = CNP;
		this->nrExemplar = nrExemplar;
	}

	Biblioteca(Biblioteca& copie) :idCarte(++nrCarti) {
		if (copie.numeCititor != nullptr) {
			this->numeCititor = new char[strlen(copie.numeCititor) + 1];
			strcpy_s(this->numeCititor, strlen(copie.numeCititor) + 1, copie.numeCititor);
		}
		else {
			this->numeCititor = nullptr;
		}

		this->CNP = copie.CNP;
		this->nrExemplar = copie.nrExemplar;
	}

	~Biblioteca() {
		if (this->numeCititor != nullptr) {
			delete[] this->numeCititor;
		}
	}

	Biblioteca& operator=(Biblioteca& copie) {
		if (this->numeCititor != nullptr) {
			delete[] this->numeCititor;
		}

		if (copie.numeCititor != nullptr) {
			this->numeCititor = new char[strlen(copie.numeCititor) + 1];
			strcpy_s(this->numeCititor, strlen(copie.numeCititor) + 1, copie.numeCititor);
		}
		else {
			this->numeCititor = nullptr;

		}
		return *this;

		this->CNP = copie.CNP;
		this->nrExemplar = copie.nrExemplar;
	}

	char* getNumeCititor() {
		return this->numeCititor;
	}

	string getCNP() {
		return this->CNP;
	}

	int getNrExemplar() {
		return this->nrExemplar;
	}

	//operatorul de afisare
	friend ostream& operator<<(ostream& out, Biblioteca copie) {
		out << copie.numeCititor << " " << copie.CNP << " " << copie.nrExemplar << " ";
		if (copie.numeCititor != nullptr) {
			out << copie.numeCititor;
		}
		return out;
	}

	Biblioteca operator+=(const Biblioteca& copie) {
		this->numeCititor = new char[strlen(numeCititor) + 1];
		strcpy_s(this->numeCititor, strlen(numeCititor) + 1, numeCititor);

		this->CNP += copie.CNP;
		this->nrExemplar += copie.nrExemplar;

		if (this->numeCititor != nullptr) {
			delete[] this->numeCititor;
		}
		return *this;
	}

};

int Biblioteca::nrCarti = 0;

void main() {
	Biblioteca b1("Gheorghita", "18906788934", 5);
	cout << "Numele cititorului: " << b1.getNumeCititor() << endl;
	cout << "CNP este: " << b1.getCNP() << endl;
	cout << "Numar exemplare: " << b1.getNrExemplar() << endl;
	cout << endl;

	Biblioteca b2("Ana", "25906788934", 7);
	cout << "Numele cititorului: " << b2.getNumeCititor() << endl;
	cout << "CNP este: " << b2.getCNP() << endl;
	cout << "Numar exemplare: " << b2.getNrExemplar() << endl;
	cout << endl;

	int numarEx = 5;
	numarEx += 3;
	cout << "Numarul de exemplare pt prima carte este: " << numarEx << endl;

	string CNP1 = "18906788934";
	string CNP2 = "25906788934";

	if (CNP1 == CNP2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
}