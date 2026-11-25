#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int wprowadzint(int min_v, int max_v = 2147483647) {
    int v;
    while (true) {
        if (cin >> v) {
            if (v >= min_v and v <= max_v) return v;
        } else {
            cin.clear();
            string smiec;
            cin >> smiec;
        }
    }
}

double wprowadzdouble() {
    double v;
    while (true) {
        if (cin >> v) return v;
        cin.clear();
        string smiec;
        cin >> smiec;
    }
}

enum Plec { K, M };

class Osoba {
private:
    string imie;
    string nazwisko;
    int wiek;
protected:
    Plec plec;
public:
    Osoba(string i, string n, int w, Plec p) : imie(i), nazwisko(n), wiek(w), plec(p) {}
    
    virtual ~Osoba() {}
    
    void wyswietl() const {
        cout << imie << " " << nazwisko;
    }
};

class Student : public Osoba {
private:
    string indeks;
    int rok;
    double* oceny;
    int ile;
public:
    Student(string i, string n, int w, Plec p, string ind, int r, double* oc, int il) : Osoba(i, n, w, p), indeks(ind), rok(r), ile(il) { 
    oceny = new double[ile];
    for (int x = 0; x < ile; ++x) {
        oceny[x] = oc[x];
        }
    }
    
    ~Student() {
        delete[] oceny;
    }
    
    double srednia() const {
        if (ile == 0) return 0.0;
        double suma = 0;
        for (int x = 0; x < ile; ++x) suma += oceny[x];
        return suma / ile;
    }
    
    string getIndeks() const { return indeks; }
    int getRok() const { return rok; }
    
    void pokaz() const {
        cout << indeks << " ";
        wyswietl();
        cout << " " << setprecision(2) << fixed << srednia();
    }
    
    bool operator > (const Student& other) const {
        return this -> srednia() > other.srednia();
    }
};

class Kierunek {
private:
    string nazwa;
    Student*** studenci;
    int limit;
    int lata;
    int* licznik;
    
public:
    Kierunek(string n, int l, int m) : nazwa(n), lata(l), limit(m) {
        studenci = new Student** [lata];
        licznik = new int[lata];
        for (int i = 0; i < lata; ++i) {
            studenci[i] = new Student* [limit];
            licznik[i] = 0;
        }
    }
    
    ~Kierunek() {
        for (int i = 0; i < lata; ++i) {
            for (int j = 0; j < licznik[i]; ++j) {
                delete studenci[i][j];
            }
            delete[] studenci[i];
        }
        delete[] studenci;
        delete[] licznik;
    }
    
    void dodaj(Student* s) {
        int r = s -> getRok() - 1;
        if (r >= 0 and r < lata and licznik[r] < limit) {
            studenci[r][licznik[r]] = s;
            licznik[r]++;
        }
    }
    
    void skresl(string ind) {
        for (int r = 0; r < lata; ++r) {
            for (int i = 0; i < licznik[r]; ++i) {
                if (studenci[r][i] -> getIndeks() == ind) {
                    delete studenci[r][i];
                    if (i != licznik[r] - 1) {
                        studenci[r][i] = studenci[r][licznik[r] - 1];
                    }
                    studenci[r][licznik[r] - 1] = nullptr;
                    licznik[r]--;
                    cout << "Student usuniety z listy\n";
                    return;
                }
            }
        }
    }
    
    void sortuj(int rok) {
        int r = rok - 1;
        if (r >= 0 and r < lata) {
            for (int i = 0; i < licznik[r] - 1; ++i) {
                for (int j = 0; j < licznik[r] - i - 1; ++j) {
                    if (*studenci [r][j + 1] > *studenci[r][j]) {
                        Student* temp = studenci[r][j];
                        studenci[r][j] = studenci[r][j + 1];
                        studenci[r][j + 1] = temp;
                    }
                }
            }
        }
    }
    
    void pokazWszystkich() const {
        for (int r = 0; r < lata; ++r) {
            if (licznik[r] > 0) {
                cout << "[ROK " << (r + 1) << "]\n";
                for (int i = 0; i < licznik[r]; ++i) {
                    cout << (i + 1) << ". ";
                    studenci[r][i] -> pokaz();
                    cout << "\n";
                }
            }
        }
    }
};
    
int main() {
    string nazwa;
    cout << "Kierunek=";
    cin >> nazwa;
    
    cout << "Ile lat studiow(1-5)=";
    int lata = wprowadzint(1, 5);
    
    cout << "Maksymalna liczba studentow na roku na kierunku=";
    int limit = wprowadzint(1);
    
    Kierunek kierunek(nazwa, lata, limit);
    
    for (int r = 1; r <= lata; ++r) {
        cout << "[ROK " << r << "] Liczba studentow na roku=";
        int ileStud = wprowadzint(0, limit);
        
        for (int s = 1; s <= ileStud; ++s) {
            cout << "[ROK " << r << "] [STUDENT #" << s << "]:\n";
            string imie, nazwisko, indeks;
            int wiek;
            char plecC;
            Plec plec;
            cout << "Imie="; cin >> imie;
            cout << "Nazwisko="; cin >> nazwisko;
            cout << "Indeks="; cin >> indeks;
            cout << "Wiek="; wiek = wprowadzint(18);
            cout << "Plec(M,K)=";
            
            while (true) {
                string wejsciePlec;
                cin >> wejsciePlec;
                if (wejsciePlec == "K" or wejsciePlec == "k") { plec = K; break; }
                else if (wejsciePlec == "M" or wejsciePlec == "m") { plec = M; break; }
            }
            
            cout << "Liczba ocen=";
            int ileOcen = wprowadzint(1);
            
            cout << "Oceny=";
            double* oceny = new double [ileOcen];
            for (int i = 0; i < ileOcen; ++i) {
                oceny[i] = wprowadzdouble();
            }
            
            Student* stud = new Student(imie, nazwisko, wiek, plec, indeks, r, oceny, ileOcen);
            kierunek.dodaj(stud);
            delete[] oceny;
        }
    }
    
    kierunek.pokazWszystkich();
    
    cout << "Po sortowaniu:\n";
    for (int r = 1; r <= lata; ++r) {
        kierunek.sortuj(r);
    }
    
    kierunek.pokazWszystkich();
    
    cout << "Podaj rok=";
    int usunRok = wprowadzint(1, lata);
    cout << "Podaj id=";
    string usunId;
    cin >> usunId;
    kierunek.skresl(usunId);
    kierunek.pokazWszystkich();
    
return 0;   
}
    