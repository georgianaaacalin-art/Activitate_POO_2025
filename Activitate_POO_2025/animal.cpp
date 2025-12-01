#include <iostream>

using namespace std;

class Animal {
private:
	const int idAnimal;
	static int nrAnimale;
	char* nume;
	int varsta;
	float greutate;
	string culoare;

public:
	Animal() :idAnimal(++nrAnimale) {
		this->nume = nullptr;
		this->varsta = 3;
		this->greutate = 5.5;
		this->culoare = "alb";
	}

	Animal(const char* nume, int varsta, float greutate, string culoare) :idAnimal(++nrAnimale) {
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}

		this->varsta = varsta;
		this->greutate = greutate;
		this->culoare = culoare;
	}

	Animal(Animal& copie) :idAnimal(++nrAnimale) {
		if (nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}

		this->varsta = copie.varsta;
		this->greutate = copie.greutate;
		this->culoare = copie.culoare;
	}

	~Animal() {
		if (nume != nullptr) {
			delete[] this->nume;
		}
	}

	Animal& operator=(Animal& copie) {

		this->varsta = copie.varsta;
		this->greutate = copie.greutate;
		this->culoare = copie.culoare;
		if (nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			this->nume = nullptr;

			return *this;
		}
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
		if (varsta > 0) {
			this->varsta = varsta;
		}
	}

	int getVarsta() {
		return this->varsta;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void operator+=(float valoareDeAdaugatLaGreutate) {
		this->greutate = valoareDeAdaugatLaGreutate;
	}

	string getCuloare() {
		return this->culoare;
	}

	friend ostream& operator<< (ostream& out, Animal& a) {
		out << endl;
		if (a.nume != nullptr) {
			out << "Numele animalului este: " << a.nume << ".";
		}
		else {
			out << "Nume nespecificat";
		}
		out << "Culoarea animalului este: " << a.culoare << ".";
		out << "Varsta animalului este: " << a.varsta << ".";
		out << "Greutatea animalului este: " << a.greutate << ".";

		return out;
	}


};

int Animal::nrAnimale = 0;

void main() {

	Animal a1("Azorel", 3, 2.3, "maro");
	cout << "Numele animalului este: " << a1.getNume() << endl;
	cout << "Varsta animalului este: " << a1.getVarsta() << endl;
	cout << "Greutatea animalului este: " << a1.getGreutate() << endl;
	cout << "Culoarea animalului este: " << a1.getCuloare() << endl;
	cout << endl;

	a1 += 1.5;
}