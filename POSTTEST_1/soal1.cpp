#include <iostream>
using namespace std;

int FindMin(int A[], int n) {
    int min = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

int main() {
    int numbers[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    int min = numbers[0];
    int indexMin = 0;

    for (int i = 0; i < n; i++) {
        if (numbers[i] < min){
            min = numbers[i];
            indexMin = i;
        }
    }
    cout << "nilai minimum: " << min << endl;
    cout << "indeks minimum: " << indexMin << endl;

    return 0;
}


/*
procedure FindMax(A : array of n elements)
min ← A[0]
for i ← 1 to n − 1 do
if A[i] > min then
min ← A[i]
end if
end for
return min
end procedure

Pseudocode          Cost    Tmin    Tmax
procedure FindMax   C1      1       1
max ← A[0]          C2      1       1
for i ← 1 to n − 1  C3      n       n
if A[i] > max       C4      n-1     n-1
max ← A[i]          C5      0       n-1
end if              C6      n-1     n-1
end for             C7      n       n
return max          C8      1       1
end procedure       C9      1       1
Total waktu (Tn)            O(n)    O(n)

*/