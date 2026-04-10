// GENAP
// 2509106010

#include <iostream>
#include <string>
using namespace std;

#define MAX 5

struct Kereta {
    int nomorKereta;
    string namaKereta;
    string asal;
    string tujuan;
    int harga;
};

struct Tiket {
    string nama;
    int rute;
};

int akar(int n) {
    int i = 1;
    while (i * i <= n) i++;
    return i - 1;
}

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    return s;
}

void swap(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "=== DATA KERETA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->nomorKereta << endl;
        cout << (arr + i)->namaKereta << endl;
        cout << (arr + i)->asal << endl;
        cout << (arr + i)->tujuan << endl;
        cout << (arr + i)->harga << endl << endl;
    }
}

void tambah(Kereta*& arr, int& n) {
    Kereta* temp = new Kereta[n + 1];
    
    for (int i = 0; i < n; i++)
        *(temp +i) = *(arr + i);

    cout << "No Kereta: ";
    cin >> temp[n].nomorKereta;

    for (int i = 0; i < n; i++) {
        if ((arr + i)->nomorKereta == temp[n].nomorKereta) {
            cout << "Nomor sudah ada!" << endl;
            delete[] temp;
            return;
        }
    }

    cin.ignore();
    cout << "Nama Kereta: ";
    getline(cin, temp[n].namaKereta);

    cout << "Asal: ";
    getline(cin, temp[n].asal);

    cout << "Tujuan: ";
    getline(cin, temp[n].tujuan);

    cout << "Harga: ";
    cin >> temp[n].harga;

    if (temp[n].harga <= 0) {
        cout << "Harga tidak valid!" << endl;
        delete[] temp;
        return;
    }

    delete[] arr;
    arr = temp;
    n++;

    cout << "Data berhasil ditambahkan!" << endl;
}

void linearsearch(Kereta* arr, int n) {
    string asal, tujuan;

    cout << "Asal: "; cin >> asal;
    cout << "Tujuan: "; cin >> tujuan;

    asal = toLower(asal);
    tujuan = toLower(tujuan);

    for (int i = 0; i < n; i++) {
        cout << "Cek data ke-" << i << endl;

        if (toLower((arr + i)->asal) == asal &&
            toLower((arr + i)->tujuan) == tujuan) {
                cout << "Ditemukan: " << (arr + i)->namaKereta << endl;
            }
    }
}

void selectionsort(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->nomorKereta < (arr + min)->nomorKereta)
                min = j;
        }
        swap((arr + i), (arr + min));
    }
}

int jumpsearch(Kereta* arr, int n, int key) {
    int step = akar(n);
    int prev = 0;

    cout << "Proses Jump Search: " << endl;

    while ((arr + (step < n ? step : n) - 1)->nomorKereta < key) {
        cout << "Loncat ke index " << (step < n? step : n) - 1 << endl;

        prev = step;
        step += akar(n);

        if (prev >= n)
            return -1;
    }

    cout << "Linear search dari " << prev << " ke " << (step < n ? step : n) << endl;

    for (int i = prev; i < (step < n ? step : n); i++) {
        cout << "Cek index " << i << endl;

        if ((arr + i)->nomorKereta == key)
        return i;
    }
    return -1;
}

struct Queue {
    Tiket data[MAX];
    int  front, rear;
};

void initQueue(Queue *q) {
     q->front = q->rear = -1;
}

bool isFullQueue(Queue *q) {
    return q->rear == MAX - 1;
}

bool isEmptyQueue(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, Tiket t) {
    if (isFullQueue(q)) {
        cout << "Queue overflow" << endl;
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->rear++;
    *(q->data + q->rear) = t;

}

Tiket dequeue(Queue *q) {
    Tiket t;

    if (isEmptyQueue(q)) {
        cout << "Queue underflow" << endl;
        return t;
    }

    t = *(q->data + q->front);

    for (int i = q->front; i < q->rear; i++)
        *(q->data + i) = *(q->data + i + 1);

    q->rear--;

    if (q->rear < q->front)
        q->front = q->rear = -1;

    return t;
}

struct Stack {
    Tiket data[MAX];
    int top;
};

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmptyStack(Stack *s) {
    return s->top == -1;
}

bool isFullStack(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Tiket t) {
    if (isFullStack(s)) {
        cout << "Stack overflow" << endl;
        return;
    }

    s->top++;
    *(s->data + s->top) = t;
}

void pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Stack underflow" << endl;
        return;
    }

    cout << "Hapus: " << (*(s->data + s->top)).nama << endl;
    s->top--;
}

void peek(Queue *q, Stack *s) {
    if (!isEmptyQueue(q))
        cout << "Antrian depan: " << (*(q->data + q->front)).nama << endl;
    else
        cout << "Antrian kosong " << endl;

    if (!isEmptyStack(s))
        cout << "Riwayat terakhir: " << (*(s->data + s->top)).nama << endl;
    else
        cout << "Riwayat kosong" << endl;
}

int main() {
    int n = 5;

    Kereta* arr = new Kereta[n]{
        {101, "Argo", "Gambir", "Surabaya", 100000},
        {102, "Brantas", "Pasarsenen", "Blitar", 50000},
        {103, "Jayabaya", "Pasarsenen", "Malang", 120000},
        {104, "Whoosh", "Jakarta", "Bandung", 200000},
        {105, "Kertajaya", "Surabaya", "Ngrombo", 75000}
    };

    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih;

    do {
        cout << "============" << endl;
        cout << "|   MENU   |" << endl;
        cout << "============" << endl;
        cout << "1. Tampil Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Jump Search" << endl;
        cout << "5. Enqueue Tiket" << endl;
        cout << "6. Dequeue Tiket" << endl;
        cout << "7. Pop Riwayat" << endl;
        cout << "8. Peek" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: " << endl;
        cin >> pilih;

        if (pilih == 1) tampil(arr, n);
        else if (pilih == 2) tambah(arr, n);
        else if (pilih == 3) linearsearch(arr, n);

        else if (pilih == 4) {
            int key;
            cout << "Nomor Kereta: ";
            cin >> key;

            selectionsort(arr, n); 
            int hasil = jumpsearch(arr, n, key);

            if (hasil != -1)
                cout << "Ditemukan: " << (arr + hasil)->namaKereta << endl;
            else
                cout << "Tidak ditemukan " << endl;
        }
        else if (pilih == 5) {
            Tiket t;
            cout << "Nama: "; cin >> t.nama;
            cout << "Rute: "; cin >> t.rute;
            enqueue(&q, t);
        }

        else if (pilih == 6) {
            Tiket t = dequeue(&q);
            if (t.nama != "") {
                cout << "Diproses: " << t.nama << endl;
                push(&s, t);
            }
        }
        
        else if (pilih == 7) pop(&s);
        else if (pilih == 8) peek(&q, &s);

    } while (pilih != 0);

    delete[] arr;
    return 0;
}