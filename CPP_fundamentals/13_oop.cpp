#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Pracownik {
private:
    string imie;
    string nazwisko;
    double pensja;

public:
    Pracownik(string imie, string nazwisko, double pensja) : imie(imie), nazwisko(nazwisko), pensja(pensja) {}

    double getPensja() const {
        return pensja;
    }

    friend ostream& operator << (ostream& os, const Pracownik& p) {
        os << "|" << p.imie << " " << p.nazwisko << ": " << fixed << setprecision(2) << p.pensja << " PLN|";
        return os;
    }
};

class Dzial {
private:
    Pracownik** tab;
    string nazwa;
    int maks;
    int ile;

public:
    Dzial(string nazwa, int maks) : nazwa(nazwa), maks(maks), ile(0) {
        tab = new Pracownik*[maks];
    }

    Dzial(const Dzial& inny) : nazwa(inny.nazwa), maks(inny.maks), ile(inny.ile) {
        tab = new Pracownik*[maks];
        for (int i = 0; i < ile; ++i) {
            tab[i] = new Pracownik(*(inny.tab[i]));
        }
    }

    Dzial& operator = (const Dzial& inny) {
        if (this != &inny) {
            for (int i = 0; i < ile; ++i) {
                delete tab[i];
            }
            delete[] tab;

            nazwa = inny.nazwa;
            maks = inny.maks;
            ile = inny.ile;
            tab = new Pracownik*[maks];
            
            for (int i = 0; i < ile; ++i) {
                tab[i] = new Pracownik(*(inny.tab[i]));
            }
        }
        return *this;
    }

    ~Dzial() {
        for (int i = 0; i < ile; ++i) {
            delete tab[i];
        }
        delete[] tab;
    }

    Dzial& operator += (Pracownik* p) {
        if (ile < maks and p != nullptr) {
            tab[ile] = p;
            ile++;
        }
        return *this;
    }

    Dzial& operator -= (Pracownik* p) {
        for (int i = 0; i < ile; ++i) {
            if (tab[i] == p) {
                delete tab[i]; 
                
                for (int j = i; j < ile - 1; ++j) {
                    tab[j] = tab[j + 1];
                }
                
                tab[ile - 1] = nullptr;
                ile--;
                break;
            }
        }
        return *this;
    }

    Pracownik* operator[](int i) {
        if (i >= 0 and i < ile) {
            return tab[i];
        }
        return 0;
    }

    double sumaPensji() const {
        double suma = 0;
        for (int i = 0; i < ile; ++i) {
            suma += tab[i] -> getPensja();
        }
        return suma;
    }

    friend ostream& operator << (ostream& os, const Dzial& d) {
        os << "Dzial: " << d.nazwa << "\nPracownicy: ";
        for (int i = 0; i < d.ile; ++i) {
            os << *(d.tab[i]) << " ";
        }
        os << "\nSuma pensji: " << fixed << setprecision(2) << d.sumaPensji() << " PLN";
        return os;
    }
};

int main() {
    int n;
    string dzial;

    cout << "Liczba pracownikow: ";
    cin >> n;
    cout << "Nazwa dzialu: ";
    cin >> dzial;

    Dzial oryginal(dzial, n);

    for (int i = 0; i < n; ++i) {
        string imie, nazwisko;
        double pensja;
        cout << "Podaj imie, nazwisko i pensje: ";
        cin >> imie >> nazwisko >> pensja;
        oryginal += new Pracownik(imie, nazwisko, pensja);
    }

    cout << "Kopia dzialu (konstruktor kopiujacy):\n";
    Dzial kopia(oryginal);
    cout << kopia << "\n";

    cout << "Dzial po przypisaniu (operator przypisania):\n";
    Dzial drugi("Tymczasowy", 10);
    drugi = oryginal;
    cout << drugi << "\n\n";

    cout << "Po usunieciu pracownika z oryginalnego dzialu:\n";
    
    Pracownik* cel = oryginal[n / 2];
    oryginal -= cel;

    cout << "Oryginalny dzial:\n";
    cout << oryginal << "\n";

    cout << "Kopia dzialu (konstruktor kopiujacy):\n";
    cout << kopia << "\n";

    cout << "Dzial po przypisaniu (operator przypisania):\n";
    cout << drugi << "\n";

    return 0;
}