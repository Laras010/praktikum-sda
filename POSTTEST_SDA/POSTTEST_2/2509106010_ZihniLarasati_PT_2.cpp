//GENAP
//2509106010

#include <iostream>
#include <string>
using namespace std;

struct Kereta {
    int nomorKereta;
    string namaKereta;
    string asal;
    string tujuan;
    int harga;
};

void swap(Kereta *a, Kereta*b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "===============" << endl;
    cout << "| Data Kereta |" << endl;
    cout << "===============" << endl;
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->nomorKereta << endl;
        cout << (arr + i)->namaKereta << endl;
        cout << (arr + i)->asal << endl;
        cout << (arr + i)->tujuan << endl;
        cout << (arr + i)->harga << endl;
        cout << endl;
    }
}

void tambah(Kereta*& arr, int& n) {
    Kereta* temp = new Kereta[n + 1];

    for (int i = 0; i < n; i++) {
        *(temp + i) = *(arr + i);
    }

    cout << "No Kereta : ";     cin >> temp[n].nomorKereta;
    cout << "Nama Kereta : ";   cin >> temp[n].namaKereta;
    cout << "Asal : ";          cin >> temp[n].asal;
    cout << "Tujuan : ";        cin >> temp[n].tujuan;
    cout << "Harga : ";         cin >> temp[n].harga;

    delete[] arr;
    arr = temp;
    n++;
}

void linearsearch(Kereta* arr, int n) {
    string asal, tujuan;
    cout << "Asal : ";   cin >> asal;
    cout << "Tujuan : "; cin >> tujuan;

    for (int i = 0; i < n; i++) {
        cout << "cek data ke-" << i << endl;
        
        if ((arr + i)-> asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan : " << (arr + i)->namaKereta << endl;
        }
    }
}

int jumpsearch(Kereta* arr, int n, int key) {
    int step = 2;
    int prev = 0;
    int batas;

    if (step < n)
        batas = step;
    else
        batas = n;

    while ((arr + batas - 1)->nomorKereta < key){
        prev = step;
        step += 2;

        if (prev >= n) return -1;
        if (step < n)
        batas = step;
        else
        batas = n;
    }

    for (int i = prev; i < batas; i++){
        if ((arr + i)->nomorKereta == key)
            return i;
    }
    return -1;
}

void merge(Kereta* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i); 

    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if ((L + i)->namaKereta <= (R + j)->namaKereta) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    while (i < n1) {
        *(arr + k) = *(L + i);
        i++; k++;
    }
    while (j < n2){
        *(arr + k) = *(R + j);
        j++; k++;
    }
    delete[] L;
    delete[] R;
    }   

    void mergesort(Kereta* arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergesort(arr, left, mid);
            mergesort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void selectionsort(Kereta* arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            int min = i;

            for (int j = i + 1; j < n; j++) {
                if ((arr + j)->harga < (arr + min)->harga) {
                    min = j;
                }
            }
            swap((arr + i), (arr + min));
        }
    }

    int main() {
        int n = 5;

        Kereta* arr = new Kereta[n]{
            {101, "Argo Bromo Anggrek", "Gambir", "Surabaya", 100000},
            {102, "Brantas", "Pasarsenen", "Blitar", 50000},
            {103, "Jayabaya", "Pasarsenen", "Malang", 120000},
            {104, "Whoosh", "Jakarta", "Bandung", 200000},
            {105, "Kertajaya", "Surabaya", "Ngrombo", 75000}
        };

    int pilih;

    do {
        cout << "===============" << endl;
        cout << "|     Menu    |" << endl;
        cout << "===============" << endl;
        cout << "1. Tampil Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Jump Search" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Selection Sort" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1)
        tampil(arr, n);

        else if (pilih == 2)
        tambah(arr, n);

        else if (pilih == 3)
        linearsearch(arr, n);

        else if (pilih == 4) {
            int key;
            cout << "Masukan Nomor Kereta: ";
            cin >> key;

            int hasil = jumpsearch(arr, n, key);

            if (hasil != -1)
                cout << "Ditemukan: " << (arr + hasil)->namaKereta << endl;
            else 
                cout << "Tidak ditemukan." << endl;
        }
        else if (pilih == 5){
            mergesort(arr, 0, n - 1);
            cout << "Data diurutkan berdasarkan nama" << endl;
        }
        else if (pilih == 6){
            selectionsort(arr, n);
            cout << "Data diurutkan berdasarkan harga" << endl;
        }
    } while (pilih != 0);

    delete[] arr;
    return 0;
}