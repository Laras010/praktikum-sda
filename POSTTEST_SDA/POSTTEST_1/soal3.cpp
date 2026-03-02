#include <iostream>
using namespace std;

// Fungsi membalik array pakai pointer
void reverseArray(int* arr, int n) {
    int* start = arr;        
    int* end = arr + n - 1;  

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;  
        end--;    
    }
}

int main() {

    int prim[] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    int* p; 

    cout << "Array sebelum dibalik: ";
    for (p = prim; p < prim + n; p++) {
        cout << *p << " ";
    }
    cout << endl;
    cout << "Alamat memori tiap elemen: ";
    for (p = prim; p < prim + n; p++) {
        cout << p << " ";
    }
    cout << endl << endl;
    reverseArray(prim, n);
    cout << "Array setelah dibalik: ";
    for (p = prim; p < prim + n; p++) {
        cout << *p << " ";
    }
    cout << endl;
    cout << "Alamat memori tiap elemen: ";
    for (p = prim; p < prim + n; p++) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}