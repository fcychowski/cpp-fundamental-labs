#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    char numer;
    cin >> numer;
    switch(numer){
        case '1' : {
            double metry;
            cin >> metry;
            
            if (metry <= 20) {
                cout << "To jest kawalerka." << endl;
            }
            else if (metry>20 and metry<=40) {
                cout << "To jest male mieszkanie." << endl;
            }
            else if (metry>40 and metry<=70) {
                cout << "To jest sredniej wielkosci mieszkanie." << endl;
            }
            else if (metry>70) {
                cout << "To jest duze mieszkanie." << endl;
            }
            break;
        }
        case '2' : {
            char pakiet;
            double godziny;
            
            cin >> pakiet;
            cin >> godziny;
            if ((pakiet=='A' or pakiet=='B' or pakiet=='C') and (godziny>=0 and godziny<=744)){
            if (pakiet=='A'){
                if (godziny<=10){
                    cout << (9.95) << "$" << endl;
                }
                else if (godziny>10 and godziny<=744){
                    cout << (9.95)+((godziny-10)*2.00) << "$" <<endl;
                }
                
            }
            else if (pakiet=='B'){
                if (godziny<=20){
                    cout << (14.95) << endl;
                }
                else if (godziny>20 and godziny<=744){
                    cout << (14.95)+(godziny-20)*1.00 << "$" << endl;
                }
                
                
            }
            else if (pakiet=='C'){
                cout << (19.95) << "$" << endl;
                
            }
            }
            else {
                cout << "Niepoprawne dane wejsciowe" << endl;
            }
            
        }
        break;
        case '3' : {
            int napoj;
            
            cin >> napoj;
            switch (napoj) {
                case 1 : 
                cout << "Coca-Cola" << endl;
                break;
                case 2 :
                cout << "Woda" << endl;
                break;
                case 3 :
                cout << "Sprite" << endl;
                break;
                case 4 :
                cout << "Fanta" << endl;
                break;
                case 5 :
                cout << "Pepsi" << endl;
                break;
                default: cout << "Niepoprawne dane wejsciowe" << endl;
            }
            break;
        }
        case '4' : {
            float r1, r2;
            char znak;
            
            cin >> r1;
            cin >> r2;
            cin >> znak;
            
            switch (znak) {
                case '+' :
                cout << r1+r2 << endl;
                break;
                case '-' :
                cout << r1-r2 << endl;
                break;
                case '*' :
                cout << r1*r2 << endl;
                break;
                case '/' : {
                    if (r2==0) {
                        cout << "Niepoprawne dane wejsciowe";
                    }
                    else {
                        cout << r1/r2 << endl;
                    }
                }
                default: cout << "Niepoprawne dane wejsciowe" << endl;  
            }
        }
    default: cout << "Niepoprawne dane wejsciowe" << endl;
}
    return 0;
}