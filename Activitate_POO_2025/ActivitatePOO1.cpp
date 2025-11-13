#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//companie, client, produs

class Companie {
private:
	const int id;
	int nrAngajati;
	float buget;
	char* numeCompanie;
	static int nrCompanii;

public:
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

	void setNrAngajati(int nrAngajati) {
		this->nrAngajati = nrAngajati;
	}

	float getBuget() {
		return this->buget;
	}

	void setBuget(float buget) {
		this->buget = buget;
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

class Produs;

class Client {
private:
	string numeClient;
	int varstaClient;
	char* mail;

public:
	Client() {
		this->numeClient = "";
		this->varstaClient = 0;
		this->mail = nullptr;
	}

	Client(string numeClient = "", int varstaClient = 0, const char* mail = nullptr) {
		this->numeClient = numeClient;
		this->varstaClient = varstaClient;
		if (mail != nullptr) {
			this->mail = new char[strlen(mail) + 1];
			strcpy_s(this->mail, strlen(mail) + 1, mail);
		}
		else {
			this->mail = nullptr;
		}
	}

	Client(Client& copy1) {
		this->numeClient = copy1.numeClient;
		this->varstaClient = copy1.varstaClient;
		if (copy1.mail != nullptr) {
			this->mail = new char[strlen(copy1.mail) + 1];
			strcpy_s(this->mail, strlen(copy1.mail) + 1, copy1.mail);
		}
		else {
			this->mail = nullptr;
		}
	}

	~Client() {
		if (this->mail != nullptr) {
			delete[] this->mail;
		}
	}

	Client& operator=(Client& copy1) {
		if (this->mail != nullptr) {
			delete[] this->mail;
		}

		this->numeClient = copy1.numeClient;
		this->varstaClient = copy1.varstaClient;
		if (copy1.mail != nullptr) {
			this->mail = new char[strlen(copy1.mail) + 1];
			strcpy_s(this->mail, strlen(copy1.mail) + 1, copy1.mail);
		}
		else {
			this->mail = nullptr;
		}

		return *this;
	}

	string getNumeClient() {
		return this->numeClient;
	}

	int getVarsta() {
		return this->varstaClient;
	}

	char* getMail() {
		return this->mail;
	}

	friend ostream& operator<< (ostream& out, Client& copy1) {
		cout << copy1.numeClient << " " << copy1.varstaClient << " " << copy1.mail << " ";
		if (copy1.mail != nullptr) {
			out << copy1.mail;
		}

		return out;
	}

};

class Produs {

private:
	const int idProdus;
	string numeProdus;
	float pret;
	char* descriere;
	static int nrProduse;

public:
	Produs() : idProdus(idProdus) {

		this->numeProdus = "";
		this->pret = 0;
		if (descriere != nullptr) {

			this->descriere = new char[strlen(descriere) + 1];
			strcpy_s(this->descriere, strlen(descriere) + 1, descriere);

		}
		else {

			this->descriere = nullptr;

		}

	}

	Produs(string numeProdus = "", float pret = 0, const char* descriere = nullptr) : idProdus(idProdus) {

		this->numeProdus = numeProdus;
		this->pret = pret;
		if (descriere != nullptr) {

			this->descriere = new char[strlen(descriere) + 1];
			strcpy_s(this->descriere, strlen(descriere) + 1, descriere);

		}
		else {

			this->descriere = nullptr;

		}

	}

	Produs(const Produs& copie3) : idProdus(idProdus) {

		this->numeProdus = copie3.numeProdus;
		this->pret = copie3.pret;
		if (copie3.descriere != nullptr) {

			this->descriere = new char[strlen(copie3.descriere) + 1];
			strcpy_s(this->descriere, strlen(copie3.descriere) + 1, copie3.descriere);

		}
		else {

			this->descriere = nullptr;

		}

	}

	~Produs() {

		if (this->descriere != nullptr) {

			delete[] this->descriere;

		}

	}

	Produs operator=(const Produs& copie3) {

		if (this->descriere != nullptr) {

			delete[] this->descriere;

		}

		this->numeProdus = copie3.numeProdus;
		this->pret = copie3.pret;
		if (copie3.descriere != nullptr) {

			this->descriere = new char[strlen(copie3.descriere) + 1];
			strcpy_s(this->descriere, strlen(copie3.descriere) + 1, copie3.descriere);

		}
		else {

			this->descriere = nullptr;

		}

		return *this;

	}

	string setNumeProdus(string np) {

		this->numeProdus = np;

	}
	string getNumeProdus() {

		return this->numeProdus;

	}

	float setPret(float p) {

		this->pret = p;

	}
	float getPret() {

		return this->pret;

	}

	char* getDescriere() {

		return this->descriere;

	}

	friend ostream& operator<<(ostream& out, Produs copie3) {

		out << copie3.numeProdus << " " << copie3.pret << " " << copie3.descriere << " ";
		if (copie3.descriere != nullptr) {

			out << copie3.descriere;

		}
		return out;
	}
};

//functia pt atributul static
int Produs::nrProduse = 0; 

void verificaVarsta(Client& copy1, Produs& copie3) {
	if (copy1.getVarsta() >= 18) {
		cout << copy1.getNumeClient() << " Poate cumpara produsul " << copie3.getNumeProdus() << "." << endl;
	}
	else {
		cout << copy1.getNumeClient() << " Nu poate cumpara produsul " << copie3.getNumeProdus() << "(minor)." << endl;
	}
}

void estimareValoareCompanie(Companie& c) {
	const int salariuMediu = 5000;
	int valoare = c.getNrAngajati();
	cout << "Estimare valoare companie: " << c.getNumeCompanie() << valoare << " lei" << endl;
}

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

	Client cl1("Ionescu", 35, "ionescu@google.com");
	cout << "Nume client: " << cl1.getNumeClient() << endl;
	cout << "Varsta client: " << cl1.getVarsta() << endl;
	cout << "Mail client: " << cl1.getMail() << endl;
	cout << endl;

	Client cl2("Popescu", 25, "popescu@microsoft.com");
	cout << "Nume client: " << cl2.getNumeClient() << endl;
	cout << "Varsta client: " << cl2.getVarsta() << endl;
	cout << "Mail client: " << cl2.getMail() << endl;
	cout << endl;

	Produs p1("Telefon", 1599.99, "Drescriere1");
	cout << "Nume produs: " << p1.getNumeProdus() << endl;
	cout << "Pret: " << p1.getPret() << " lei" << endl;
	cout << "Descriere: " << p1.getDescriere() << endl;
	cout << endl;

	Produs p2("Laptop", 4799.99, "Drescriere2");
	cout << "Nume produs: " << p2.getNumeProdus() << endl;
	cout << "Pret: " << p2.getPret() << " lei" << endl;
	cout << "Descriere: " << p2.getDescriere() << endl;
	cout << endl;

	estimareValoareCompanie(c1);
	estimareValoareCompanie(c2);

	verificaVarsta(cl1, p1);
	verificaVarsta(cl2, p2);


}


