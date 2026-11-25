#include<iostream>

using namespace std;

int main () {
    char task_number;
    cin >> task_number;
    switch (task_number) {
        
        case '1' : {
            int integer;
            cin >> integer;
            int move = 0;
            
            if (integer == 0) {
                cout << 0;
            }
            
            for (int i = 31; i >= 0; i--) {
                int bit = (integer >> i) & 1;
                if(bit == 1){
                    move = 1;
                }
                
                if(move == 1){
                    cout << bit;
                    if (i % 4 == 0){
                        cout << " ";
                    }
                }
            } 

        break;    
        }
        
        case '2' : {
            int integer;
            cin >> integer;
            int LSB = integer & 1;
            
            if (LSB == 0){
                cout << "TAK" << endl;
            }
            else {
                cout << "NIE" << endl;
            }
            
        break;    
        }
        
        case '3' : {
            
            int integer; 
            cin >> integer;
            int minimum = 0;
            int maximum = 31;
            int zero = 0;
            
            while (minimum <= 31 and ((integer >> minimum) & 1) == 0) {
                minimum++;
            }

            while (maximum >= 0 and ((integer >> maximum) & 1) == 0) {
                maximum--;
            }
            
            if (maximum > minimum) {
                for (int i = minimum + 1; i < maximum; i++) {
                    if (((integer >> i) & 1) == 0) {
                        zero++;
                    }
                }
            }
            cout << zero;

        break;    
        }
        
        case '4' : {
            string word;
            cin >> word;

            for (char &sign : word) {
                if ((sign >= 65 and sign <= 90) or (sign >= 97 and sign <= 122)) {
                sign = sign ^ (1 << 5);
                }
            }
            
            cout << word << endl;
                        
        break;
        }
        
        case '5' : {
            int integer;
            cin >> integer;

            if (integer > 0 and (integer & (integer - 1)) == 0) {
                cout << "TAK" << endl;
            }
            else {
                cout << "NIE" << endl;
            }
            
        break;    
        }
        
        case '6' : {
            unsigned int data;
            cin >> data;
            int year = data & 4095;
            int month = (data >> 12) & 15;
            int day = (data >> 16) & 31;
            
            if (day < 10) { 
                cout << "0";
            }
            
            cout << day << "/";
            
            if (month < 10) {
                cout << "0";
            }
            
            cout << month << "/";
            cout << year << endl;

        break;
        }
    
    default: {cout << "Niepoprawny numer zadania" << endl;}    
    }
    
    return 0;
}