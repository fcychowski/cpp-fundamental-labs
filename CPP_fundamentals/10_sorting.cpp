#include<iostream>
using namespace std;

//functions

void coctailSort(int arr[], int n) {
    bool change = true;
    int start = 0;
    int stop = n - 1;
    
    while (change) {
        change = false;
    
    for (int i = start; i < stop; i++) {
        if (arr[i] < arr[i + 1]) {
            int storage = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = storage;
            
            change = true;
            
            for (int j = 0; j < n; j++) {
                cout << arr[j] << " ";
            }
            
        cout << endl;
        }
    }
    
    if (!change) {
        break;
    }
    
    stop--;
    change = false;
    
    for (int i = stop - 1; i >= start; i--) {
        if (arr[i] < arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            
            change = true;
            
            for (int j = 0; j < n; j++) {
                cout << arr[j] << " ";
            }
            
        cout << endl;
        }
    }
    
    start++;
    }
}

void selectionSort (char arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        
        if (min != i) {
            char storage = arr[min];
            arr[min] = arr[i];
            arr[i] = storage;
        
            for (int x = 0; x < n; x++) {
                cout << arr[x] << " ";
            }
            
        cout << endl;
        }
    }
}

void setWord (string tab[], int n) {
    int size = 0;
    
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
    
        int index = 0;
    
        while (index < size and word.length() >= tab[index].length()) {
            index++;
        }
    
        for(int j = size; j > index; j--) {
            tab[j] = tab[j - 1];
        }
    
        tab[index] = word;
        size++;
    
        for (int j = 0; j < size; j++) {
            cout << tab[j] << " ";
        }   
    
    cout << endl;    
    }
}


//code

int main () {
    int task;
    cin >> task;
    
    switch (task) {
        
        case 1 : {
            int n;
            cin >> n;
            
            if (n < 1 or n > 20) {
                cout << "Niepoprawne dane wejsciowe";
            break;
            }
            
            int tab[20];
            
            for (int i = 0; i < n; i++) {
                cin >> tab[i];
            }
            
            coctailSort (tab, n);
            
            
        break;    
        }
        
        case 2 : {
            int n;
            cin >> n;
            
            if (n < 1 or n > 20) {
                cout << "Niepoprawne dane wejsciowe";
            break;
            }
            
            char tab[20];
            
            for (int i = 0; i < n; i++) {
                cin >> tab[i];
            }
            
            selectionSort (tab, n);
            
        break;    
        }
        
        case 3 : {
            int n;
            cin >> n;
            
            if (n < 1 or n > 20) {
                cout << "Niepoprawne dane wejsciowe";
            break;
            }
            
            string tab[20];
            
            setWord (tab, n);
            
        break;    
        }
        
    default : {cout << "Niepoprawny numer zadania";}
    }

return 0;    
}