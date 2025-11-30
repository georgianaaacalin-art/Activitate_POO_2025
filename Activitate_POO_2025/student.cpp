#include <iostream>

using namespace std;

class Student {
private:
	char* nume;
	int nota;
	char* materie;
	int numarMatricol; //cum diferentiez doi studenti cu acelasi nume
	float medie;  //atribut pt aflarea mediei studentului

public:
	Student() {
		this->nume = nullptr;
		this->nota = 10;
		this->materie = nullptr;
		this->numarMatricol = 5;
		this->medie = 9.5;
	}

	Student(const char* nume, int nota, const char* materie, int numarMatricol, float medie) {
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		this->nota = nota;
		if (materie != nullptr) {
			this->materie = new char[strlen(materie) + 1];
			strcpy_s(this->materie, strlen(materie) + 1, materie);
		}

		this->numarMatricol = numarMatricol;
		this->medie = medie;

	}

	Student(const Student& copie) {
		if (copie.nume != nullptr) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}

		this->nota = copie.nota;

		if (copie.materie != nullptr) {
			this->materie = new char[strlen(copie.materie) + 1];
			strcpy_s(this->materie, strlen(copie.materie) + 1, copie.materie);
		}

		this->numarMatricol = copie.numarMatricol;
		this->medie = copie.medie;
	}

	~Student() {
		if (this->materie != nullptr) {
			delete[] this->materie;
		}
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
	}

	void setNume(char* nume) {

		if (this->nume != nullptr) {
			delete[] this->nume;
		}
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume), nume);
		}

	}

	char* getNume() {
		return this->nume;
	}

	void setNota(int nota) {
		if (nota > 0 && nota <= 10) {
			this->nota = nota;
		}
	}

	int getNota() {
		return this->nota;
	}

	void setMaterie(char* materie) {
		if (this->materie != nullptr) {
			delete[] this->materie;
		}
		if (materie != nullptr) {
			this->materie = new char[strlen(materie) + 1];
			strcpy_s(this->materie, strlen(materie) + 1, materie);
		}
	}
	char* getMaterie() {
		return this->materie;
	}

	void setNumarMatricol(int numarMatricol) {
		if (numarMatricol > 0) {
			this->numarMatricol = numarMatricol;
		}
	}

	int getNumarMatricol() {
		return this->numarMatricol;
	}

	void setMedie(float medie) {
		if (medie <= 10 && medie <= 5) {
			this->medie = medie;
		}
	}
	float  getMedie() {
		return this->medie;
	}

	Student& operator=(Student& copie) {
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
		if (copie.nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}

		this->nota = copie.nota;

		if (this->materie != nullptr) {
			delete[] this->materie;
		}
		if (copie.materie != nullptr) {
			this->materie = new char[strlen(copie.materie) + 1];
			strcpy_s(this->materie, strlen(copie.materie), copie.materie);
		}

		this->numarMatricol = copie.numarMatricol;
		this->medie = copie.medie;

		return *this;
	}

	void afisare() {
		cout << this->nume << endl;

	}
};

void main() {
	Student s1("Rares", 10, "POO", 12345, 9.5);
	Student s2Default;

	cout << "Numele studentului este " << s1.getNume() << endl;
	cout << "Nota este: " << s1.getNota() << endl;
	cout << "Materia este: " << s1.getMaterie() << endl;
	cout << "Numarul matricol: " << s1.getNumarMatricol() << endl;
	cout << "Media este: " << s1.getMedie() << endl;
	cout << endl;

	//am creat un obiect folosindu-ma de operatorul de atribuire
	Student s3 = s1;
	s3.setNumarMatricol(1231010);
	cout << "Noul numar matricol al studentului s3 este: " << s3.getNumarMatricol() << endl;
	//am creat un creat un obiect folosindu-ma de constructorul de copiere
	Student s4(s3);

}