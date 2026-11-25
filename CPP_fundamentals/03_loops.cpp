#include<iostream>

using namespace std;

int main () {
    char task_number;
    cin >> task_number;
    switch (task_number){
    
    case '1' : {
        int high;
        
        cin >> high;
        if (high>20 or high<=1) {
            cout << "Niepoprawne dane wejsciowe";
        }
        else {
          for (int i = 0; i < high; i++) {
              for (int j = 0; j < high; j++) {
                  if (j < i) {
                      cout << "o";
                  }
                  else {
                      cout << "x";
                  }
              }
              cout << endl;
          }  
          
        }
    break;
    }
    
    case '2' : {
        int n, number, even = 0, divisible3 = 0, negative = 0;
    
        if (!(cin >> n)) {
            break; 
        }
        for (int i = 0; i < n; i++) {
            cin >> number;
                if (number % 2 == 0) {
                    even++;
                }
                if (number % 3 == 0) {
                    divisible3++;
                }
                if (number < 0) {
                    negative++;
                }
            }
        cout << even << " " << divisible3 << " " << negative << endl;
    break; 
    }
    
    case '3' : {
        int N;
        do {
            cin >> N;
        } while (N <= 0 or N > 10);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << i * j;
                if (j < N) {
                    cout << " ";
                }
            }
        cout << endl;
        }
    break;
    }
    
    case '4' : {
        int high;
        if (!(cin >> high) or high <= 1 or high > 20) {
            cout << "Niepoprawne dane wejsciowe" << endl;
            return 0;
        }
        for (int i = 1; i <= high; i++) {
            for (int j = 1; j <= high - i; j++) {
                cout << " ";
            }
            for (int j = 1; j <= 2 * i - 1; j++) {
                cout << "*";
            }
            cout << endl;
        }
        for (int i = 1; i < high; i++) {
            cout << " ";
        }
        cout << "#" << endl;
    break;
    }
    default: cout << "Niepoprawny numer zadania" << endl;
    }
return 0;
}