#include <iostream>

using namespace std;

class Angajat {
private:
	static int nrAngajati;
	char* nume;
	int varsta;
	float greutate;
	string departament;

public:
	Angajat() {
		this->nume = nullptr;
		this->varsta = 25;
		this->greutate = 80.5;
		this->departament = "IT";
	}

	Angajat(const char* nume, int vasrta, float greutate, string departament) {
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}

		this->varsta = varsta;
		this->greutate = greutate;
		this->departament = departament;
	}

	Angajat(Angajat& copie) {
		if (nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}

		this->varsta = copie.varsta;
		this->greutate = copie.greutate;
		this->departament = copie.departament;
	}

	Angajat& operator=(Angajat& copie) {
		if (copie.nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			this->nume = nume;

			return *this;
		}
	}

	void operator+=(float valoareDeAdaugatLaGreutate) {
		this->greutate += valoareDeAdaugatLaGreutate;
	}

	void setNume(char* nume) {
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	char* getNume() {
		return this->nume;
	}

	void setVarsta(int varsta) {
		this->varsta = varsta;
	}

	int getVarsta() {
		return this->varsta;
	}

	void setGrreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	void setDepartament(string departament) {
		this->departament = departament;
	}


};

int Angajat::nrAngajati = 0;

void main() {

	Angajat a1("Gheorghe", 23, 82.5, "Finante");
	cout << "Numele angajatului este: " << a1.getNume() << endl;

	a1 += 3.5;
}