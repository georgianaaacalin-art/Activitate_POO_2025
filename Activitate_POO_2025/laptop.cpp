#include <iostream>

using namespace std;

class Laptop {
private:
	const int idLaptop;
	char* nume;
	string culoare;
	int lunaLansare;
	float greutate;

public:
	Laptop() :idLaptop() {
		this->nume = nullptr;
		this->culoare = "roz";
		this->lunaLansare = 06;
		this->greutate = 3.4;
	}

	Laptop(const char* nume, string culoare, int lunaLansare, float greutate) :idLaptop() {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->culoare = culoare;
		this->lunaLansare = lunaLansare;
		this->greutate = greutate;
	}

	Laptop(Laptop& copie) :idLaptop() {
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			this->nume = nullptr;
		}
		this->culoare = copie.culoare;
		this->lunaLansare = copie.lunaLansare;
		this->greutate = copie.greutate;
	}

	~Laptop() {
		if (nume != nullptr) {
			delete[] this->nume;
		}
	}

	Laptop& operator=(Laptop& copie) {
		this->culoare = copie.culoare;
		this->lunaLansare = copie.lunaLansare;
		this->greutate = copie.greutate;

		if (nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, nume);
		}
		else {
			this->nume = nullptr;

			return *this;
		}


	}

	friend ostream& operator<<(ostream& out, Laptop l) {
		if (l.nume != nullptr) {
			out << "Nume laptop: " << l.nume;

		}
		else {
			out << "Nume nespecificat";
		}

		out << "Culoarea este: " << l.culoare;
		out << "Luna lansarii este: " << l.lunaLansare;
		out << "Greutatea este: " << l.greutate;

		return out;
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

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	string getCuloare() {
		return this->culoare;
	}

	void setLunaLansare(int lunaLansare) {
		this->lunaLansare = lunaLansare;
	}

	int getLunaLansare() {
		return this->lunaLansare;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	//supraincarcarea op=+
	void operator+=(float valoareDeAdaugatLaGreutate) {
		this->greutate += valoareDeAdaugatLaGreutate;
	}
};

void main() {

	Laptop l1("HP", "roz", 05, 3.5);
	cout << "Numele laptopului este: " << l1.getNume() << endl;
	cout << "Culoarea laptopului este: " << l1.getCuloare() << endl;
	cout << "Luna lansarii este: " << l1.getLunaLansare() << endl;
	cout << "Greutatea este: " << l1.getGreutate() << endl;
	cout << endl;

	Laptop l2("Asus", "gri", 04, 4.5);
	cout << "Numele laptopului este: " << l2.getNume() << endl;
	cout << "Culoarea laptopului este: " << l2.getCuloare() << endl;
	cout << "Luna lansarii este: " << l2.getLunaLansare() << endl;
	cout << "Greutatea este: " << l2.getGreutate() << endl;
	cout << endl;

	Laptop laptop2 = l1;
	cout << "Numele laptopului 2 este: " << laptop2.getNume() << endl;

	l1 += 2;

}
