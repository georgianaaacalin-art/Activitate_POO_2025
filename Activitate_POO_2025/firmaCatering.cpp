#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FirmaCatering {
private:
	string data;
	int cantitate;
	float pret;
	char* numeClient;

public:
	FirmaCatering() {
		this->data = " ";
		this->cantitate = 0;
		this->pret = 0.0;
		this->numeClient = nullptr;
	}

	FirmaCatering(string data = "", int cantitate = 0, float pret = 0.0, const char* numeClient = nullptr) {
		this->data = data;
		this->cantitate = cantitate;
		this->pret = pret;

		if (numeClient != nullptr) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
		}
		else {
			this->numeClient = nullptr;
		}
	}

	FirmaCatering(FirmaCatering& copie) {
		this->data = copie.data;
		this->cantitate = copie.cantitate;
		this->pret = copie.pret;

		if (copie.numeClient != nullptr) {
			this->numeClient = new char[strlen(copie.numeClient) + 1];
			strcpy_s(this->numeClient, strlen(copie.numeClient) + 1, copie.numeClient);
		}
		else {
			this->numeClient = nullptr;
		}
	}

	~FirmaCatering() {
		if (this->numeClient) {
			delete[] this->numeClient;
		}
	}

	FirmaCatering& operator=(FirmaCatering& copie) {
		if (this->numeClient) {
			delete[] this->numeClient;
		}

		this->data = copie.data;
		this->cantitate = copie.cantitate;
		this->pret = copie.pret;

		if (copie.numeClient != nullptr) {
			this->numeClient = new char[strlen(copie.numeClient) + 1];
			strcpy_s(this->numeClient, strlen(copie.numeClient) + 1, copie.numeClient);
		}
		else {
			this->numeClient = nullptr;
		}

		return *this;
	}

	string getData() {
		return this->data;
	}

	int getCantitate() {
		return this->cantitate;
	}

	float getPret() {
		return this->pret;
	}

	char* getNumeClient() {
		return this->numeClient;
	}

	//operatorul de afisare
	friend ostream& operator<<(ostream& out, FirmaCatering copie) {
		out << copie.data << " " << copie.cantitate << " " << copie.pret << " " << copie.numeClient << " ";
		if (copie.numeClient != nullptr) {
			out << copie.numeClient;
		}
		return out;
	}

	//operator++ postincrementare
	FirmaCatering operator++(int i) {
		FirmaCatering copie = *this;
		this->pret++;

		return copie;
	}

	//operator++ preincrementare
	FirmaCatering operator++() {
		FirmaCatering copie2 = *this;
		this->pret++;

		return copie2;
	}

	//operator de comparatie <
	bool operator<(FirmaCatering c) {
		return this->cantitate != c.getCantitate();
	}
};

void main() {
	FirmaCatering f1("12.03.2025", 20, 500.2, "Gheorghita");
	cout << "Nume client: " << f1.getNumeClient() << endl;
	cout << "Data este: " << f1.getData() << endl;
	cout << "Pretul este: " << f1.getPret() << endl;
	cout << "Cantitatea este: " << f1.getCantitate() << endl;
	cout << endl;

	FirmaCatering f2("20.05.2025", 30, 450.2, "Victoras");
	cout << "Nume client: " << f2.getNumeClient() << endl;
	cout << "Data este: " << f2.getData() << endl;
	cout << "Pretul este: " << f2.getPret() << endl;
	cout << "Cantitatea este: " << f2.getCantitate() << endl;
	cout << endl;

	//apelam operatorul postincrementare
	cout << "Pretul primei firme este: " << f1.getPret() << endl;
	f1++;
	cout << "Pretul primei firme este: " << f1.getPret() << endl;
	f1++;
	cout << "Pretul primei firme este: " << f1.getPret() << endl;
	f1++;
	cout << endl;

	//apelam operatorul preincrementare
	cout << "Pretul primei firme este: " << f2.getPret() << endl;
	++f2;
	cout << "Pretul primei firme este: " << f2.getPret() << endl;
	++f2;
	cout << "Pretul primei firme este: " << f2.getPret() << endl;
	++f2;
	cout << endl;

	//apelam operatorul de comparatie
	int cantitate = 20;
	int cantitate1 = 30;

	if (cantitate < cantitate1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

}