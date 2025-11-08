#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Casa {
private:
	bool cuEtaj;
	float* amprentaSol;
	int deschidereLaDrum;
	string adresa;

public:
	Casa() {
		this->cuEtaj = true;
		this->amprentaSol = nullptr;
		this->deschidereLaDrum = 0;
		this->adresa = "";
	}

	Casa(bool cuEtaj = true, float amprentaSolVal = 0, int deschidereLaDrum = 0, string adresa = "") {
		this->cuEtaj = cuEtaj;
		this->deschidereLaDrum = deschidereLaDrum;
		this->adresa = adresa;
		this->amprentaSol = new float(amprentaSolVal);


	}

	Casa(Casa& copie) {
		this->cuEtaj = copie.cuEtaj;
		this->deschidereLaDrum = copie.deschidereLaDrum;
		this->adresa = copie.adresa;

		if (copie.amprentaSol != nullptr) {
			this->amprentaSol = new float(*copie.amprentaSol);
		}
		else {
			this->amprentaSol = nullptr;
		}
	}

	~Casa() {
		if (this->amprentaSol) {
			delete[] this->amprentaSol;
		}
	}

	Casa& operator=(Casa& copie) {
		if (this->amprentaSol) {
			delete[] this->amprentaSol;
		}

		this->cuEtaj = copie.cuEtaj;
		this->deschidereLaDrum = copie.deschidereLaDrum;
		this->adresa = copie.adresa;

		if (copie.amprentaSol != nullptr) {
			this->amprentaSol = new float(*copie.amprentaSol);
		}
		else {
			this->amprentaSol = nullptr;
		}

		return *this;
	}

	bool getCuEtaj() {
		return this->cuEtaj;
	}

	float getAmprentaSol() const {
		if (this->amprentaSol) {
			return *this->amprentaSol;
		}
		return 0;
	}

	int getDeschidereLaDrum() {
		return this->deschidereLaDrum;
	}

	string getAdresa() {
		return this->adresa;
	}

	friend ostream& operator<<(ostream& out, Casa& copie) {
		out << copie.getCuEtaj() << " " << copie.getAmprentaSol() << " " << copie.getDeschidereLaDrum() << " " << copie.getAdresa() << " ";
		if (copie.amprentaSol != nullptr) {
			out << copie.amprentaSol;
		}
		return out;
	}
};



int main() {

	Casa c1(true, 1.2f, 5, "adresa1");
	cout << "Cu etaj: " << c1.getCuEtaj() << endl;
	cout << "Amprenta sol: " << c1.getAmprentaSol() << endl;
	cout << "Deschidere la drum: " << c1.getDeschidereLaDrum() << endl;
	cout << "Adresa: " << c1.getAdresa() << endl;
	cout << endl;

	Casa c2(false, 2.3f, 4, "adresa2");
	cout << "Cu etaj: " << c2.getCuEtaj() << endl;
	cout << "Amprenta sol: " << c2.getAmprentaSol() << endl;
	cout << "Deschidere la drum: " << c2.getDeschidereLaDrum() << endl;
	cout << "Adresa: " << c2.getAdresa() << endl;
	cout << endl;

	return 0;
}

