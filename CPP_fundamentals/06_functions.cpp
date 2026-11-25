#include<iostream>

using namespace std;

bool numberParameters(int x) {
    
    if (x <= 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int arrayCheck(int array[], int size) {
    int result = array[0];
    int maximum_ones = 0;
    unsigned int first_number = array[0];
    
    while (first_number > 0) {
        first_number &= (first_number - 1);
        maximum_ones++;
    }

    for (int i = 1; i < size; i++) {
        int current_number = array[i];
        int current_score = 0;
        unsigned int temporary = current_number;
        
        while (temporary > 0) {
            temporary &= (temporary - 1);
            current_score++;
        }
        
        if (current_score > maximum_ones) {
            maximum_ones = current_score;
            result = current_number;
        }
    }
    return result;
}

int countBitSequence(int pattern, int model) {
    if (pattern == 0 and model == 0) return 1;
    int pattern_length = 0;
    unsigned int temporary_pattern = pattern;

    while (temporary_pattern > 0) {
        temporary_pattern >>= 1;
        pattern_length++;
    }

    if (pattern_length == 0) return 0;
    int events = 0;

    for (int i = 0; i <= 32 - pattern_length; i++) {
        bool match = true;
        for (int j = 0; j < pattern_length; j++) {
            int bit_pattern = (pattern >> j) & 1;
            int bit_model = (model >> (i + j)) & 1;

            if (bit_pattern != bit_model) {
                match = false;
                break;
            }
        }
        
        if (match) events++;
    }
    
    return events;
}
    
int main () {
    int task_number;
    cin >> task_number;
    
    switch (task_number) {
        case 1 : {
            int number;
            cin >> number;
            
            if (numberParameters(number) == true) {
                cout << "TAK" << endl;
            } 
            else {
                cout << "NIE" << endl;
            }
            
        break;    
        }
        
        case 2 : {
            const int size = 10;
            int arr[size];
            
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }

            cout << arrayCheck(arr, size) << endl;
         
        break;   
        }
        
        case 3 : {
            int y, z;
            
            cin >> y >> z;
            cout << countBitSequence(y, z) << endl;
            
        break;    
        }
        
    default : {cout << "Niepoprawny numer zadania";}    
    }
    
return 0;    
}