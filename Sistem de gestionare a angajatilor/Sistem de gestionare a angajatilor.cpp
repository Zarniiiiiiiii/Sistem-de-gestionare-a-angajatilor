#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Angajat {
private:
    string nume;
    string pozitie;
    int salariu;

public:
    Angajat(string nume, string pozitie, int salariu) {
        this->nume = nume;
        this->pozitie = pozitie;
        this->salariu = salariu;
    }

    /*~Angajat() {
        cout << "Angajatul " << nume << " a fost concediat." << endl;
    }*/

    string getNume() const {
        return nume;
    }

    void afisareInformatii() const {
        cout << "Nume: " << nume << endl;
        cout << "Pozitie: " << pozitie << endl;
        cout << "Salariu: " << salariu << " RON" << endl;
        cout << endl;
    }

    void actualizareSalariu(int noulSalariu) {
        salariu = noulSalariu;
        cout << "Salariul pentru angajatul " << nume << " a fost actualizat la " << salariu << " RON." << endl;
    }
};

int main() {
    vector<Angajat> listaAngajati;

    while (true) {
        cout << "Meniu:" << endl;
        cout << "1. Adauga angajat" << endl;
        cout << "2. Concediaza angajat" << endl;
        cout << "3. Schimba salariul angajatului" << endl;
        cout << "4. Afiseaza lista de angajati" << endl;
        cout << "5. Iesire din program" << endl;
        cout << "Alegeti optiunea: ";

        int optiune;
        cin >> optiune;

        switch (optiune) {
        case 1: {
            string nume, pozitie;
            int salariu;
            cout << "Introduceti numele noului angajat: ";
            cin >> nume;
            cout << "Introduceti pozitia noului angajat: ";
            cin >> pozitie;
            cout << "Introduceti salariul noului angajat: ";
            cin >> salariu;
            Angajat nouAngajat(nume, pozitie, salariu);
            listaAngajati.push_back(nouAngajat);
            cout << "Angajat adaugat cu succes." << endl;
            break;
        }
        case 2: {
            if (!listaAngajati.empty()) {
                cout << "Introduceti numele angajatului de concediat: ";
                string numeAngajat;
                cin >> numeAngajat;
                bool gasit = false;
                for (auto it = listaAngajati.begin(); it != listaAngajati.end(); ++it) {
                    if (it->getNume() == numeAngajat) {
                        it = listaAngajati.erase(it);
                        cout << "Angajatul " << numeAngajat << " a fost concediat cu succes." << endl;
                        gasit = true;
                        break;
                    }
                }
                if (!gasit) {
                    cout << "Angajatul " << numeAngajat << " nu a fost gasit in lista." << endl;
                }
            }
            else {
                cout << "Lista de angajati este goala." << endl;
            }
            break;
        }
        case 3: {
            if (!listaAngajati.empty()) {
                cout << "Introduceti numele angajatului pentru a-i schimba salariul: ";
                string numeAngajat;
                cin >> numeAngajat;
                bool gasit = false;
                for (auto& angajat : listaAngajati) {
                    if (angajat.getNume() == numeAngajat) {
                        int nouSalariu;
                        cout << "Introduceti noul salariu pentru angajatul " << numeAngajat << ": ";
                        cin >> nouSalariu;
                        angajat.actualizareSalariu(nouSalariu);
                        gasit = true;
                        break;
                    }
                }
                if (!gasit) {
                    cout << "Angajatul " << numeAngajat << " nu a fost gasit in lista." << endl;
                }
            }
            else {
                cout << "Lista de angajati este goala." << endl;
            }
            break;
        }
        case 4: {
            if (!listaAngajati.empty()) {
                cout << "Lista de angajati:" << endl;
                for (const auto& angajat : listaAngajati) {
                    angajat.afisareInformatii();
                }
            }
            else {
                cout << "Lista de angajati este goala." << endl;
            }
            break;
        }
        case 5: {
            cout << "Programul s-a incheiat." << endl;
            return 0;
        }
        default: {
            cout << "Optiune invalida. Va rugam sa alegeti din nou." << endl;
            break;
        }
        }
    }

    return 0;
}
