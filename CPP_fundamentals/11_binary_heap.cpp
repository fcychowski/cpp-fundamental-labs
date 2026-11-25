#include<iostream>

using namespace std;

//functions

const int heapSize = 32;
double heap[heapSize];
int startSize = 0;

void heapInsert (double n) {
    if (startSize >= heapSize) {
        
    return;
    }
    
    int x = startSize;
    heap[x] = n;
    startSize++;
    
    while (heap[(x - 1) / 2] < heap[x] and x != 0) {
        double storage = heap[x];
        heap[x] = heap[(x - 1) / 2];
        heap[(x - 1) / 2] = storage;
        x = ((x - 1) / 2);
    }
}

void stripper (double tab[], int n, int x) {
    int small = x;
    int right = (2 * x + 2);
    int left = (2 * x + 1);
    
    if (left < n and tab[left] < tab[small]) {
        small = left;
    }
    
    if (right < n and tab[right] < tab[small]) {
        small = right;
    }
    
    if (small != x) {
        double storage = tab[x];
        tab[x] = tab[small];
        tab[small] = storage;
        
        stripper(tab, n, small);
    }
    
}

void heapSort (double tab[], int y) {
    for ( int i = y / 2 - 1; i >= 0; --i){
        stripper(tab, y, i);
    }
    
    for (int i = y - 1; i >= 0; --i) {
        double storage = tab[0];
        tab[0] = tab[i];
        tab[i] = storage;
        
        stripper(tab, i, 0);
    }
}

bool checker(int x) {
    int left = 2 * x + 1;
    int right = 2 * x + 2;
    
    if ((int)heap[x] % 2 != 0) {
        return false;
    }
    
    if (left >= startSize) {
        
    return true;    
    }
    
    bool leftEnd = false;
    bool rightEnd = false;
    
    if (left < startSize) {
        leftEnd = checker(left);
    }
    
    if (leftEnd) {
        
    return true;    
    }
    
    if (right < startSize) {
        rightEnd = checker(right);
    }
    
    return rightEnd;
}


//code

int main () {
    int task;
    cin >> task;
    
    switch (task) {
        
        case 1 : {
            double value;
            
            for (int i = 0; i < 8; ++i) {
                cin >> value;
                heapInsert(value);
            }
            
            for (int i = 0; i < startSize; ++i) {
                cout << heap[i] << " ";
            }
            
        break;    
        }
        
        case 2 : {
            double arr[20];
            
            for (int i = 0; i < 20; ++i) {
                cin >> arr[i];
            }
            
            heapSort(arr, 20);
            
            for (int i = 0; i < 20; ++i) {
                cout << arr[i] << " ";
            }
            
        break;
        }
        
        case 3 : {
            for (int i = 0; i < 20; ++i) {
                double x;
                cin >> x;
                heapInsert(x);
            }
            
            if (startSize > 0 and checker(0)) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            
        break;    
        }
        
        default : {cout << "Niepoprawny numer zadania";}
    }

return 0;    
}