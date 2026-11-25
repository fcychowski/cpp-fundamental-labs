#include<iostream>

using namespace std;

//functions//
void fit (string tab[11][10], const int s1, const int s2, string word, int M) {
        int result = 0;
        
        for (int i = 0; i < word.length(); i++){
            char p = word [i];
            int ascii = p;
            
            int op = 1;
            int power = word.length() - i - 1;
            for (int j = 0; j < power; j++){
                op = op * 128;
            }
            
            result = (result + (ascii * op) % M) % M;
        }
        
        int row = result % M;
        
        for (int column = 0; column < s2; column++) {
            if (tab[row][column] == "_"){
                tab[row][column] = word;
                
            break;    
            }
        }
}

void fit2 (string tab[], const int size, string word, int M) {
        int ascii = 0;
        
        for(int i = 0; i < word.length(); i++) {
            ascii = ascii + word[i];
        }
        
        int index = ascii % M;
        
        int counter = 0;
        while (tab[index] != "_" and tab[index] != "" and counter < size) {
            index = (index + 1) % size;
            counter++;
        }
        
        if (counter < size) {
            tab[index] = word;
        }
}

int searching (string tab[], int size, string word, int M) {
    int ascii = 0;
    int counter = 0;
    
    for (int i = 0; i < word.length(); i++) {
        ascii = ascii + word[i];
    }
    
    int index = ascii % M;
    
    while (size > counter) {
        if (tab[index] == "_") {
            return -1;
        }
        
        if (tab[index] == word) {
            return index;
        }
        
        index = (index + 1) % size;
        counter++;
    }
    
return -1;    
} 


//code//

int main () {
    int task;
    cin >> task;
    switch (task) {
        
        case 1 : {
            const int h = 11, l = 10;
            string arr[h][l];
            int M = 11;
            
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < l; j++) {
                    arr[i][j] = "_";
                }
            }
            
            for (int i = 0; i < 15; i++) {
                string term;
                cin >> term;
                fit (arr, h, l, term, M);
            }
            
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < l; j++) {
                    cout << arr[i][j];
                    
                    if (j < l - 1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            
        break;    
        }
        
        case 2 : {
            const int size = 31; 
            string arr[size];
            int M = 31;
            
            for (int i = 0; i < size; i++) {
                arr[i] = "_";
            }
            
            for (int i = 0; i < 20; i++) {
                string term;
                cin >> term;
                fit2 (arr, size, term, M);
            }
            
            for (int i = 0; i < size; i++) {
                cout << arr[i];
                
                if (i < size - 1) {
                    cout << " ";
                }
            }
            
        break;     
        }
        
        case 3 : {
            const int size = 31;
            string arr[size];
            int M = 31, result[10];
            
            for (int i = 0; i < size; i++) {
                arr[i] = "_";
            }
            
            for (int i = 0; i < 20; i++) {
                string term;
                cin >> term;
                fit2 (arr, size, term, M);
            }
            
            for (int i = 0; i < 10; i++) {
                string word;
                cin >> word;
                
                result[i] = searching(arr, size, word, M);
            }
            
            for (int i = 0; i < 10; i++) {
                cout << result[i];
                
                if (i < 9) {
                    cout << " ";
                }
                
            }
            
        break;   
        }
        
        default : {cout << "Niepoprawny numer zadania";}
    }
    
return 0;    
}