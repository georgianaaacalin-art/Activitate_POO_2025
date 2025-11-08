/*#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Petitie {
private:
	const int id;
	string data;
	string nume;
	int nrZile;
	bool status;
	char* descriere;

public:
	Petitie() :id(id) {
		this->data = "";
		this->nume = "";
		this->nrZile = 0;
		this->status = true;
		this->descriere = nullptr;
	}

	Petitie(string data="", string nume = "", int nrZile = 0, 
		bool status = true, const char* descriere = nullptr) :id(id) {
		this->data = data;
		this->nume = nume;
		this->nrZile = nrZile;
		this->status = status;
		if (descriere != nullptr) {
			this->descriere = new char[strlen(descriere) + 1];
			strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
		}
		else {
			this->descriere = nullptr;
		}
	}


	Petitie(Petitie&p) :id(p.id) {
		this->data = p.data;
		this->nume = p.nume;
		this->nrZile = p.nrZile;
		this->status = p.status;
		if (p.descriere != nullptr) {
			this->descriere = new char[strlen(p.descriere) + 1];
			strcpy_s(this->descriere, strlen(p.descriere) + 1, p.descriere);
		}
		else {
			this->descriere = nullptr;
		}
	}

	~Petitie() {
		if (this->descriere) {
			delete[] this->descriere;
		}
	}

	Petitie& operator= (Petitie& p) {
		if (this->descriere) {
			delete[] this->descriere;
		}

		this->data = p.data;
		this->nume = p.nume;
		this->nrZile = p.nrZile;
		this->status = p.status;
		if (p.descriere != nullptr) {
			this->descriere = new char[strlen(p.descriere) + 1];
			strcpy_s(this->descriere, strlen(p.descriere) + 1, p.descriere);
		}
		else {
			this->descriere = nullptr;
		}

		return *this;	

	}

	string getData() {
		return this->data;
	}

	string getNume() {
		return this->nume;
	}

	int getNrZile() {
		return this->nrZile;
	}

	bool getStatus() {
		return this->status;
	}

	char* getDescriere() {
		return this->descriere;
	}

	friend ostream& operator << (ostream& out, Petitie& p) {
		out << p.data << " " << p.nume << " " << p.nrZile << " "
			<< p.status << " " << p.descriere << " ";
		if (p.descriere != nullptr) {
			out << p.descriere;
		}
	}

	bool operator! () {
		if (status == 0 && nrZile > 30) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator~() {
		if (status == 0) {
			status = 1;
		}
		else {
			status = 0;
		}
	}

	int main() {
		Petitie p1("31.12.2025", "Ghita", 25, true, "descriere1");
		cout << "Nume: " << p1.getNume() << endl;
		cout << "Descriere: " << p1.getDescriere() << endl;
		cout << "Data: " << p1.getData() << endl;
		cout << "Numar zile: " << p1.getNrZile() << endl;
		cout << "Status: " << p1.getStatus() << endl;
		cout << endl;

		Petitie p2("25.10.2025", "Georgiana", 35, false, "descriere2");
		cout << "Nume: " << p2.getNume() << endl;
		cout << "Descriere: " << p2.getDescriere() << endl;
		cout << "Data: " << p2.getData() << endl;
		cout << "Numar zile: " << p2.getNrZile() << endl;
		cout << "Status: " << p2.getStatus() << endl;
		cout << endl;

		bool ok = !p1;
		cout << (p1.getNrZile() > 30 ? "expirata" : "trimisa") << endl;

		~p1;
		cout << "dupa ~ " << endl << p1 << endl;
	}
};*/