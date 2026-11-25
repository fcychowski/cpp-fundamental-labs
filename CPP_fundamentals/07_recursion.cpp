#include <iostream>

using namespace std;

void even(unsigned int n) {
    if (n < 2) {
        return;
    }

    if (n % 2 != 0) {
        even(n - 1);
    } 
    else {
        even(n - 2);
        cout << n << " ";
    }
}

double tab(double tab1[], int size) {
    if (size <= 0) {
        return 1.0;
    }
    else {
        return tab1[size - 1] * tab(tab1, size - 1);
    }
}

int tab(int tab2[], int size1) {
    if (size1 <= 0) {
        return 1.0;
    }
    else {
        return tab2[size1 - 1] * tab(tab2, size1 - 1);
    }
}

double strin(int y) {
    
    if (y == 1) {
        return 1.0;
    }
    if (y == 2) {
        return 0.5;
    }
    if (y != 1 and y != 2) {
        return -2.0 * strin(y-1);
    }
    else {
        return 0;
    }
}

void ATM(int p) {
    int j = 0;
    
    if (p == 0) {
        return;
    }
    
    if ((p/500) >= 1) {
        j = 500;
    }
    else if ((p/200) >= 1) {
        j = 200;
    }
    else if ((p/100) >= 1) {
        j = 100;
    }
    else if ((p/50) >= 1) {
        j = 50;
    }
    else if ((p/20) >= 1) {
        j = 20;
    }
    else if ((p/10) >= 1) {
        j = 10;
    }
    
    cout << j;
    
    if (p - j > 0) {
        cout << "+";
        ATM(p - j);
    }
}

int main () {
    int task;
    cin >> task;
    
    switch (task) {
        case 1: {
            unsigned int N;
            cin >> N;
            even(N);
            break;    
        }
        
        case 2: {
            const int size = 6;
            double arr[size];
            
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            
            cout << tab(arr, size) << endl;
            break;
        }
        
        case 3 : {
            const int size = 6;
            int arr[size];
            
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            
            cout << tab(arr, size) << endl;
            break;
        }
        
        case 4 : {
            int x;
            cin >> x;
            
            if (x <= 0) {
                cout << "Niepoprawne dane wejsciowe" << endl;
            } 
            else {
                cout << strin(x) << endl;
            }
        break;    
        }
        
        case 5 : {
            int cash;
            cin >> cash;
            
            if (cash < 10) {
                cout << "Niepoprawne dane wejsciowe";
            }
            else {
                 ATM(cash);
            }
        break;    
        }
        
        default : {cout << "Niepoprawny numer zadania";}
    }
    
    return 0;    
}