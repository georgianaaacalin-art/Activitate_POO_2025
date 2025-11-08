#include <iostream>
#include <fstream>

using namespace std;

class SejurVacanta {
private:
    const int id;
protected:
    string destinatia;
    string dataInceput;
    string dataSfarsit;
    int nrPersoane;
    string tipMese;
    bool insotitori;
    char* tipCamera;
public:
    static int nrSejururi;

    SejurVacanta() : id(++nrSejururi) {
        this->destinatia = "";
        this->dataInceput = "";
        this->dataSfarsit = "";
        this->nrPersoane = 0;
        this->tipMese = "";
        this->insotitori = true;
        this->tipCamera = nullptr;
    }

    SejurVacanta(string destinatia = "", string dataInceput = "", string dataSfarsit = "",
        int nrPersoane = 0, string tipMese = "", bool insotitori = true,
        const char* tipCamera = nullptr) : id(++nrSejururi) {
        this->destinatia = destinatia;
        this->dataInceput = dataInceput;
        this->dataSfarsit = dataSfarsit;
        this->nrPersoane = nrPersoane;
        this->tipMese = tipMese;
        this->insotitori = insotitori;
        if (tipCamera != nullptr) {
            this->tipCamera = new char[strlen(tipCamera) + 1];
            strcpy_s(this->tipCamera, strlen(tipCamera) + 1, tipCamera);
        }
        else {
            this->tipCamera = nullptr;
        }
    }

    SejurVacanta(const SejurVacanta& sv) : id(sv.id) {
        this->destinatia = sv.destinatia;
        this->dataInceput = sv.dataInceput;
        this->dataSfarsit = sv.dataSfarsit;
        this->nrPersoane = sv.nrPersoane;
        this->tipMese = sv.tipMese;
        this->insotitori = sv.insotitori;
        if (sv.tipCamera != nullptr) {
            this->tipCamera = new char[strlen(sv.tipCamera) + 1];
            strcpy_s(this->tipCamera, strlen(sv.tipCamera) + 1, sv.tipCamera);
        }
        else {
            this->tipCamera = nullptr;
        }
    }

    ~SejurVacanta() {
        if (this->tipCamera != nullptr) {
            delete[] this->tipCamera;
        }
    }

    SejurVacanta& operator=(const SejurVacanta& sv) {
        if (this->tipCamera != nullptr) {
            delete[] this->tipCamera;
        }

        this->destinatia = sv.destinatia;
        this->dataInceput = sv.dataInceput;
        this->dataSfarsit = sv.dataSfarsit;
        this->nrPersoane = sv.nrPersoane;
        this->tipMese = sv.tipMese;
        this->insotitori = sv.insotitori;
        if (sv.tipCamera != nullptr) {
            this->tipCamera = new char[strlen(sv.tipCamera) + 1];
            strcpy_s(this->tipCamera, strlen(sv.tipCamera) + 1, sv.tipCamera);
        }
        else {
            this->tipCamera = nullptr;
        }

        return *this;
    }

    void setDestinatia(string d) {
        this->destinatia = d;
    }
    string getDestinatia() {
        return this->destinatia;
    }

    void setDataInceput(string di) {
        this->dataInceput = di;
    }
    string getDataInceput() {
        return this->dataInceput;
    }

    void setDataSfarsit(string df) {
        this->dataSfarsit = df;
    }
    string getDataSfarsit() {
        return this->dataSfarsit;
    }

    void setNrPersoane(int nr) {
        this->nrPersoane = nr;
    }
    int getNrPersoane() {
        return this->nrPersoane;
    }

    void setTipMese(string tm) {
        this->tipMese = tm;
    }
    string getTipMese() {
        return this->tipMese;
    }

    void setInsotitori(bool i) {
        this->insotitori = i;
    }
    bool getInsotitori() {
        return this->insotitori;
    }

    void setTipCamera(char* tc) {
        this->tipCamera = tc;
    }
    char* getTipCamera() {
        return this->tipCamera;
    }

    friend ostream& operator<<(ostream& out, SejurVacanta sv) {
        out << sv.destinatia << " " << sv.dataInceput << " " << sv.dataSfarsit << " "
            << sv.nrPersoane << " " << sv.tipMese << " " << sv.insotitori << " " << sv.tipCamera << " ";
        if (sv.tipCamera != nullptr) {
            out << sv.tipCamera;
        }
        return out;
    }

    SejurVacanta operator+(const SejurVacanta& sv) const {
        SejurVacanta aux = *this;
        aux.nrPersoane = this->nrPersoane + sv.nrPersoane;
        if (aux.tipCamera != NULL) {
            delete[]aux.tipCamera;
        }
        aux.tipCamera = new char[aux.nrPersoane];
        for (int i = 0; i < this->nrPersoane; i++) {
            aux.tipCamera[i] = this->tipCamera[i];
        }
        for (int i = this->nrPersoane; i < aux.nrPersoane; i++) {
            aux.tipCamera[i] = sv.tipCamera[i - this->nrPersoane];
        }
        return aux;
    }

};

int SejurVacanta::nrSejururi = 0;

int main() {
    SejurVacanta s1("Tokyo", "12.09.2021", "30.09.2021", 4, "All-Inclusive", true, "Tripla");
    cout << "Destinatie: " << s1.getDestinatia() << endl;
    cout << "Data inceput: " << s1.getDataInceput() << endl;
    cout << "Data sfarsit: " << s1.getDataSfarsit() << endl;
    cout << "Tip masa: " << s1.getTipMese() << endl;
    cout << "Insotitor: " << s1.getInsotitori() << endl;
    cout << "Tip camera: " << s1.getTipCamera() << endl;
    cout << endl;

    SejurVacanta s2("Seoul", "10.05.2022", "10.06.2022", 2, "Mic ejun inclus", false, "Double");
    cout << "Destinatie: " << s2.getDestinatia() << endl;
    cout << "Data inceput: " << s2.getDataInceput() << endl;
    cout << "Data sfarsit: " << s2.getDataSfarsit() << endl;
    cout << "Tip masa: " << s2.getTipMese() << endl;
    cout << "Insotitor: " << s2.getInsotitori() << endl;
    cout << "Tip camera: " << s2.getTipCamera() << endl;
    cout << endl;

    SejurVacanta s3 = s1;

    s3 = s1 + s2;
    cout << s3 << endl;

    int nrPersoane[10];
    for (int i = 0; i < 10; i++) {
        nrPersoane[i] = i++;
    }
    cout << nrPersoane[10] << endl;
    cout << 10[nrPersoane] << endl;
    return 1;

}