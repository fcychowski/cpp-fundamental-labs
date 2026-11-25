#include<iostream>
using namespace std;

//functions

bool sortCheck (int tab[], const int size = 10) {
    for (int i = 0; i < size - 1; i++) {
        if (tab[i] > tab[i+1]){
            return false;
        }
    }
    
    return true;
}

int binarySearching(int tab[], int size, int x){
    int right = size - 1;
    int left = 0;
    int index = -1;
    int counter = 0;
    
    while(left < right){
        counter++;
        int mid = (right + left) / 2;
        
        if (tab[mid] == x){
            index = mid;
            
        break;
        }
        else if (tab[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
        
    while ((index > 0) and (tab[index - 1]) == x){
        counter++;
        index--;
    }
        
    cout << counter << endl;
    return index;
}

bool binarySearching2(int tab[], int left, int right, int x) {
  
    if (right < left){ 
      return false;
    }
    int mid = left + (right - left) / 2;
  
    if (tab[mid] > x){ 
    return binarySearching2(tab, left, mid - 1, x);
    }
  
    if (tab[mid] == x){ 
      return true;
    }
  
    return binarySearching2(tab, mid + 1, right, x);
    
}

bool interpolation(int A[], int size, int value){
    int right = size -1;
    int left = 0;
    int counter = 0;
    
    while (left <= right and value <= A[right] and value >= A[left]) {
        counter++;
        int mid = left + (right  - left) * (value - A[left]) / (A[right] - A[left]);
        
        if(A[mid] == value){
            cout << counter << endl;
            return true;
        }
        else if(A[mid] < value){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << counter << endl;
    return false;
}



//code

int main () {
    int task;
    cin >> task;
    
    switch (task) {
        case 1 : {
            const int size = 10;
            int arr[size], n;
            cin >> n;
            
            for (int i = 0; i < 10; i++) {
                cin >> arr[i];
            }
            if (sortCheck(arr, size) == false){
                cout << "Elementy tablicy nie sa posortowane";
            }
            else {
            cout << binarySearching(arr, size, n) << endl;
            }
        break;
        }
        
        case 2 : {
            const int size = 10;
            int arr[size], n;
            cin >> n;
            
            for (int i = 0; i < 10; i++) {
                cin >> arr[i];
            }
            
            if (sortCheck(arr, size) == false){
                cout << "Elementy tablicy nie sa posortowane";
            }
            else {
            cout << binarySearching2(arr, 0, size - 1, n);
            }
            
        break;    
        }
        
        case 3 : {  
            const int size = 10;
            int arr[size], n;
            cin >> n;
            
            for (int i = 0; i < 10; i++) {
                cin >> arr[i];
            }
            
            if (sortCheck(arr, size) == false){
                cout << "Elementy tablicy nie sa posortowane";
            }
            else {
            cout << interpolation(arr, size, n) << endl;
            }
            
        break;    
        }
        
    default : {cout << "Niepoprawny numer zadania";}    
    }

return 0;    
}