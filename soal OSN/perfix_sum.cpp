#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Fungsi GSI (Get Segment Information)
 * Menghitung jumlah elemen dalam rentang tertentu menggunakan Prefix Sum.
 */
int GSI(vector<int> B, int x, int y) {
    return B[y] - B[x - 1];
}

/**
 * Fungsi FUN
 * 1. Membangun vector Prefix Sum B dari vector A.
 * 2. Mencari nilai sub-array dengan jumlah terbesar (Maximum Subarray Sum).
 */
int FUN(vector<int> A) {
    int N = A.size();

    // Membangun Vector B (Prefix Sum)
    vector<int> B;
    B.push_back(0); // Indeks ke-0 diisi 0
    for (int i = 0; i < N; i++) {
        B.push_back(B[i] + A[i]);
    }

    // Mencari nilai maksimum dari semua kemungkinan rentang (i ke j)
    int out = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            out = max(out, GSI(B, i, j));
            cout << "out=" << out << " , ketika i=" << i << " , j = " << j << endl;
        }
    }
    
    return out;
}

int main() {
    // Contoh penggunaan dengan Vector A = {1, 2, 3, 4, 5}
    vector<int> A = {1, 2, 3, 4, 5};
    
    int hasil = FUN(A);
    
    cout << "Hasil pemanggilan FUN(A) adalah: " << hasil << endl;
    
    return 0;
}