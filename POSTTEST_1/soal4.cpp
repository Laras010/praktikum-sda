#include <iostream>
using namespace std;

void tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int* pX = &x; 
    int* pY = &y; 

    cout << "Sebelum pertukaran : " << endl;
    cout << "x = " << x << ", via pointer = " << *pX << endl;
    cout << "y = " << y << ", via pointer = " << *pY << endl;

    tukar (pX, pY);

    cout << "Sesudah pertukaran : " << endl;
    cout << "x = " << x << ", via pointer = " << *pX << endl;
    cout << "y = " << y << ", via pointer = " << *pY << endl;


    int data[5] = {10, 20, 30, 40, 50};
    int* p = data; 
    cout << "\nIterasi array menggunakan pointer:\n";
    while (p < data + 5) {
        cout << "Nilai: " << *p << ", Alamat: " << p << endl;
        p++; 
    }

    return 0;

}