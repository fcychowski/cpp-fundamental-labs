#include <iostream>

using namespace std;

class Car {
private:
    char id[5];
    int power;
    float weight;
    char engine;
    
public:
    Car() {
        id[0] = '\0';
        power = 0;
        weight = 0;
        engine = 'B';
    }
    
    Car(char nr[], int p, float w, char t) {
        for (int i = 0; i < 4; ++i) {
            id[i] = nr[i];
        }
        id[4] = '\0';
        power = p;
        weight = w;
        engine = t;
    }
    
    void copyIdTo(char destination[]) const {
        for (int i = 0; i < 5; ++i) {
            destination[i] = id[i];
        }
    }
    
    int getpower() const { return power; }
};

class Brand {
private:
    Car array[6];
    int cars;
    
public:
    Brand() {
        cars = 0;
    }
    
    void add(Car newCar) {
        if (cars < 6) {
            array[cars] = newCar;
            cars++;
        }
    }
    
    void delet(int index) {
        if (index >= 0 and index < cars) {
            array[index] = array[cars - 1];
            cars--;
        }
    }
    
    void show() const {
        for (int i = 0; i < cars; ++i) {
            char tempId[5];
            array[i].copyIdTo(tempId);
            
            cout << tempId << " " << array[i].getpower();
            if (i < cars - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Brand myBrand;
    
    for (int i = 0; i < 6; ++i) {
        char id[5];
        int power = 0;
        float weight = 0.0f;
        char engine = 'B';
        
        char buf[100]; 
         
        while (true) {
            cin >> buf;
             
            int length = 0;
            while (buf[length] != '\0') {
                length++;
            }
            
            if (length == 4) {
                bool correct = true;
                for (int j = 0; j < 4; ++j) {
                    if (!((buf[j] >= 'a' and buf[j] <= 'z') or (buf[j] >= 'A' and buf[j] <= 'Z') or (buf[j] >= '0' and buf[j] <= '9'))) {
                        correct = false;
                        break;
                    }
                }
                if (correct) {
                    for(int j = 0; j < 5; ++j) id[j] = buf[j];
                    break;
                }
            }
        }
        
        while (true) {
            cin >> buf;
            bool correct = true;
            int len = 0;
            
            while (buf[len] != '\0') {
                if (buf[len] < '0' or buf[len] > '9') {
                    correct = false; 
                }
                len++;
            }
            
            if (correct and len > 0) {
                int val = 0;
                for (int j = 0; j < len; ++j) {
                    val = val * 10 + (buf[j] - '0'); 
                }
                if (val > 0) {
                    power = val;
                    break;
                }
            }
        }
        
        while (true) {
            cin >> buf;
            bool correct = true;
            int dots = 0;
            int digits = 0;
            int len = 0;
            
            while (buf[len] != '\0') {
                if (buf[len] == '.') {
                    dots++;
                } else if (buf[len] >= '0' and buf[len] <= '9') {
                    digits++;
                } else {
                    correct = false;
                }
                len++;
            }
            
            if (correct and dots <= 1 and digits > 0) {
                float val = 0.0f;
                float fraction = 0.1f;
                bool is_fraction = false;
                for (int j = 0; j < len; j++) {
                    if (buf[j] == '.') {
                        is_fraction = true;
                    } else {
                        if (!is_fraction) {
                            val = val * 10.0f + (buf[j] - '0');
                        } else {
                            val += (buf[j] - '0') * fraction;
                            fraction *= 0.1f;
                        }
                    }
                }
                if (val > 0.0f) {
                    weight = val;
                    break;
                }
            }
        }
        
        while (true) {
            cin >> buf;
            int len = 0;
            while(buf[len] != '\0') len++;
            
            if (len == 1) {
                if (buf[0] == 'B' or buf[0] == 'D' or buf[0] == 'E' or buf[0] == 'H') {
                    engine = buf[0];
                    break;
                }
            }
        }
        
        Car newCar(id, power, weight, engine);
        myBrand.add(newCar);
    }
    
    myBrand.delet(2);
    myBrand.show();
    
    return 0;
}