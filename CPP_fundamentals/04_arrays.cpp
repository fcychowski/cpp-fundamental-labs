#include<iostream>

using namespace std;

int main() {
    char task_number;
    cin >> task_number;
    
    switch(task_number){
        case '1' : {
            const int size = 10;
            double array [size];
            int counter = 0;
            
            for (int i = 0; i < size; i++){
                cin >> array[i];
            }
            
            int max_number = array[0];            
            
            for (int i = 0; i < 10; i++){
                if (array[i] > max_number){
                    max_number = array[i];
                    counter = 1;
                }
                else if (array[i] == max_number){
                    counter++;
                }
            }
            cout << max_number << " " << counter << endl;
        break;
        }
        
        case '2' : {
            const int size = 10;
            double array [size];
            double min_number1, min_number2;
            bool found = false;
            
            for (int i = 0; i < size; i++){
                cin >> array[i];
            }
            
            min_number1 = array[0];           
            
            for (int i = 1; i < size; i++){
                if (array[i] < min_number1){
                    min_number1 = array[i];
                }
            }
            
            for (int i = 0; i < size; i++){
                if (array[i] > min_number1){
                    if (!found or array[i] < min_number2){
                        min_number2 = array[i];
                        found = true;
                    }
                }
            }
            
            if (found){
                cout << min_number2 << endl;
            }
            else{
                cout << "Brak" << endl;
            }
            
        break;
        }
        
        case '3' : {
            string pattern, rule;
            int counter = 0;
            cin >> rule >> pattern;             
            int p = pattern.length();
            int l = rule.length();
            
            for (int i = 0; i <= l - p; i++){
                bool check = true;
                
                for (int j = 0; j < p; j++){
                    if (rule[i + j] != pattern[j]){
                        check = false;
                    break;    
                    }
                }
                if (check){
                counter++;
                }
            }
            
            cout << counter << endl;
            
        break;  
        }
        
        case '4' : {
            int high, counter = 1;
            cin >> high;
            if (high < 1 or high > 15){
                cout << "Niepoprawne dane wejsciowe" << endl;
            }
            else {
                int pascal_triangle[15][15];
                for (int i = 0; i < high; i++){
                    for (int j = 0; j <= i; j++){
                        if (j == 0 or j == i){
                            pascal_triangle[i][j] = 1;
                        }
                        else {
                            pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
                        }
                    cout << pascal_triangle[i][j] << " ";
                    }
                cout << endl;
                }
               
            }
        break;         
        }
    default : {cout << "Niepoprawny numer zadania";}
    }
    
    return 0;
}