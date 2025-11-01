#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Magazin {
private:
	float pret;
	string data;
	string numeMagazin;
	char* tipCarne;

	static int nrMagazine;

public:
	Magazin() {
		this->pret = 0;
		this->data = "";
		this->numeMagazin = "";
		this->tipCarne = nullptr;
	}

	Magazin(float pret = 0, string data = "", string numeMagazin = "", const char* tipCarne = nullptr) {
		this->pret = pret;
		this->data = data;
		this->numeMagazin = numeMagazin;
		if (tipCarne != nullptr) {

			this->tipCarne = new char[strlen(tipCarne) + 1];
			strcpy_s(this->tipCarne, strlen(tipCarne) + 1, tipCarne);

		}
		else {

			this->tipCarne = nullptr;

		}
	}

	Magazin(Magazin& copy) {
		this->pret = copy.pret;
		this->data = copy.data;
		this->numeMagazin = copy.numeMagazin;
		if (copy.tipCarne != nullptr) {

			this->tipCarne = new char[strlen(copy.tipCarne) + 1];
			strcpy_s(this->tipCarne, strlen(copy.tipCarne) + 1, copy.tipCarne);

		}
		else {

			this->tipCarne = nullptr;

		}
	}

	~Magazin() {
		if (this->tipCarne != nullptr) {
			delete[] this->tipCarne;
		}
	}

	Magazin& operator=(Magazin& copy) {
		if (this->tipCarne != nullptr) {
			delete[] this->tipCarne;
		}

		this->pret = copy.pret;
		this->data = copy.data;
		this->numeMagazin = copy.numeMagazin;
		if (copy.tipCarne != nullptr) {

			this->tipCarne = new char[strlen(copy.tipCarne) + 1];
			strcpy_s(this->tipCarne, strlen(copy.tipCarne) + 1, copy.tipCarne);

		}
		else {

			this->tipCarne = nullptr;

		}

		return *this;
	}

	float getPret() {
		return this->pret;
	}

	string getData() {
		return this->data;
	}

	string getNumeMagazin() {
		return this->numeMagazin;
	}

	char* getTipCarne() {
		return this->tipCarne;
	}

	friend ostream& operator<< (ostream& out, Magazin& copy) {

		cout << copy.pret << " " << copy.data << " " << copy.numeMagazin << " " << copy.tipCarne << " ";
		if (copy.tipCarne != nullptr) {
			out << copy.tipCarne;
		}
		return out;

	}

};

int Magazin::nrMagazine = 0;

int main() {

	Magazin m1(29.99, "01/11/2025", "Auchan", "Carne Proaspata");
	cout << "Nume magazin: " << m1.getNumeMagazin() << endl;
	cout << "Tip carne: " << m1.getTipCarne() << endl;
	cout << "Pretul: " << m1.getPret() << endl;
	cout << "Data expirare: " << m1.getData() << endl;
	cout << endl;

	Magazin m2(19.99, "25/12/2025", "Carrefour", "Carne Congelata");
	cout << "Nume magazin: " << m2.getNumeMagazin() << endl;
	cout << "Tip carne: " << m2.getTipCarne() << endl;
	cout << "Pretul: " << m2.getPret() << endl;
	cout << "Data expirare: " << m2.getData() << endl;
	cout << endl;

	float pret = 29.99;
	float pret1 = 19.99;
	pret *= 0.3;

	string nume = "Auchan";
	string nume1 = "Carrefour";

	cout << "Pretul dupa reducere este de: " << pret << " lei" << endl;


	if (pret == pret1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	if (nume == nume1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}