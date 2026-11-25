#include<iostream>
#include<iomanip>

using namespace std;
int main() {
    long long x = 1000000000;
    float y = 3.14;
    unsigned int q = 500;
    signed char z = 'Z';
    string producent, miasto1, miasto2, miasto3;
    int ilosc, cena, jablka, pojemnosc;
    float ocena1, ocena2, waga1, waga2, cenan, masa;
    double r;
    
    
    //1
    cout << x << " " << y << " " << q << " " << z << endl;
    cout << sizeof(x) << " " << sizeof(y) << " " << sizeof(q) << " " << sizeof(z) << endl;
    
    //2
    cout << "Podaj nazwe producenta: ";
    cin.ignore();
    getline(cin, producent);
    cout << "Producent: " << producent << endl;
    
    //3
    cout << "Podaj ilosc i cene: ";
    cin >> ilosc;
    cin >> cena;
    cout << ilosc << " szt. * " << cena << " PLN = " << ilosc*cena << " PLN" << endl;

    //4
    cout << "Podaj liczbe przedmiotow i pojemnosc opakowania: ";
    cin >> jablka;
    cin >> pojemnosc;
    cout << jablka << " / " << pojemnosc << " = " << jablka/pojemnosc << " r " << jablka%pojemnosc << endl;
    
    //5
    cout << "Podaj dwie oceny i ich wagi: ";
    cin >> ocena1;
    cin >> ocena2;
    cin >> waga1;
    cin >> waga2;
    cout << "Srednia: " << (ocena1*waga1 + ocena2*waga2) / (waga1+waga2) << endl;
    
    //6
    cout << "Podaj cene netto: ";
    cin >> cenan;
    cout << "Cena brutto: " << fixed << setprecision(2) << cenan*1.23 << endl;
    
    //7
    cout << "Podaj mase: ";
    cin >> masa;
    cout << scientific << setprecision(2) << masa << endl;
    
    //8
    cout << "Podaj promien r: ";
    cin >> r;
    cout << "Obwod wynosi: " << defaultfloat << setprecision(6) << 2*3.14159*r << endl;
    
    //9
    cout << "Podaj trzy miasta: ";
    cin >> miasto1;
    cin >> miasto2;
    cin >> miasto3;
    cout << setw(15) << miasto1 << endl;
    cout << setw(15) << miasto2 << endl;
    cout << setw(15) << miasto3 << endl;

    
    return 0;
}