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
Pseudocode:
procedure FindMin(A, n)
    min ← A[0]
    indexMin ← 0
    for i ← 1 to n - 1
        if A[i] < min
            min ← A[i]
            indexMin ← i
        end if
    end for
    return min, indexMin
end procedure

Pseudocode          Cost    Tmin    Tmax
procedure FindMin   C1      1       1
min ← A[0]          C1      1       1
indexMin = 0        C3      n       n
for i ← 1 to n-1    C4      n       n
if A[i] < min       C5      n-1     n-1
min ← A[i]          C6      0       n-1
indexMin ← i        C7      0       n-1
end if              C8      n-1     n-1
end for             C9      n       n
return min          c10     1       1
end procedure       C11     1       1
Total waktu (Tn)            O(n)    O(n)

Tmin(n) =
C1 + C2 + C3 + C4(n) + C5(n-1) + C8(n-1) + C9(n) + C10 + C11
Tmin(n) : O(n)

Tmax(n) =
C1 + C2 + C3 + C4(n) + C5(n-1)
+ C6(n-1) + C7(n-1)
+ C8(n-1) + C9(n) + C10 + C11
Tmax(n) : O(n)
*/