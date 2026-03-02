#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    Mahasiswa data[5] = {
        {"laras", "010", 3.5},
        {"syifa", "059", 2.6},
        {"patan", "026", 3.0},
        {"manda", "011", 3.4},
        {"sinta", "070", 3.3},
    };

    float maxIpk = data[0].ipk;
    int indexMax = 0;

    for (int i = 1; i < 5; i++) {
        if (data[i].ipk > maxIpk) {
            maxIpk = data[i].ipk;
            indexMax = i;
        }
    }

    cout << " MAHASISWA DENGAN IPK TERTINGGI : " << endl;
    cout << "Nama : " << data[indexMax].nama << endl;
    cout << "Nim  : " << data[indexMax].nim << endl;
    cout << "IPK  : " << data[indexMax].ipk << endl;

    return 0;
}
