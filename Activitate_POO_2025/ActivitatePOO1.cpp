#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//companie, client, produs

class Companie {
private:
	const int id;
public:
	int nrAngajati;
	float buget;
	char* numeCompanie;
	static int nrCompanii;

	Companie() :id(id) {
		this->nrAngajati = 0;
		this->buget = 0;
		this->numeCompanie = nullptr;
	}

	Companie(int nrAngajati = 0, float buget = 0, const char* numeCompanie = nullptr) :id(id){
		this->nrAngajati = nrAngajati;
		this->buget = buget;
		if (numeCompanie != nullptr) {
			this->numeCompanie = new char[strlen(numeCompanie) + 1];
			strcpy_s(this->numeCompanie, strlen(numeCompanie) + 1, numeCompanie);

		}else {
			this->numeCompanie = nullptr;
		}
	}

	Companie(const Companie & c) :id(c.id) {
		this->nrAngajati = c.nrAngajati;
		this->buget = c.buget;
		if (c.numeCompanie != nullptr) {
			this->numeCompanie = new char[strlen(c.numeCompanie) + 1];
			strcpy_s(this->numeCompanie, strlen(c.numeCompanie) + 1, c.numeCompanie);

		}
		else {
			this->numeCompanie = nullptr;
		}
	}


	~Companie()
	{
		if (this->numeCompanie != nullptr) {
			delete[] this->numeCompanie;
		}
	}

	Companie& operator= (const Companie& c) {
		if (this->numeCompanie != nullptr) {
			delete[] this->numeCompanie;
		}


		this->nrAngajati = c.nrAngajati;
		this->buget = c.buget;
		if (c.numeCompanie != nullptr) {
			this->numeCompanie = new char[strlen(c.numeCompanie) + 1];
			strcpy_s(this->numeCompanie, strlen(c.numeCompanie) + 1, c.numeCompanie);

		}
		else {
			this->numeCompanie = nullptr;
		}

		return *this;

	}

	int getNrAngajati() {
		return this->nrAngajati;
	}


	float getBuget() {
		return this->buget;
	}

	char* getNumeCompanie() {
		return this->numeCompanie;
	}


	friend ostream & operator << (ostream & out, Companie & c) {
		out << c.nrAngajati << " " << c.buget << " " << c.numeCompanie << " ";
		if (c.numeCompanie != nullptr) {
			out << c.numeCompanie;
		}

		return out;
	}


};

int main() {

	Companie c1(20, 1099.50, "Microsoft");
	cout << "Nume Companie: " << c1.getNumeCompanie() << endl;
	cout << "Nr Angajati : " << c1.getNrAngajati() << endl;
	cout << "Buget: " << c1.getBuget() << endl;
	cout << endl;

	Companie c2(30, 2099.50, "Google");
	cout << "Nume Companie: " << c2.getNumeCompanie() << endl;
	cout << "Nr Angajati : " << c2.getNrAngajati() << endl;
	cout << "Buget: " << c2.getBuget() << endl;
	cout << endl;

}
