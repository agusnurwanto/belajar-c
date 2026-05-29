#include <iostream>
#include <vector>
using namespace std;

int GSI(vector<int> B, int x, int y) {
    return B[y] - B[x - 1];
}

int FUN(vector<int> A) {
    int N = A.size();

    vector<int> B;
    B.push_back(0);

    for (int i = 0; i < N; i++) {
        B.push_back(B[i] + A[i]);
    }

    // menampilkan isi vector B
    cout << "Isi B : ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    int out = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            out = max(out, GSI(B, i, j));
        }
    }

    return out;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};

    int hasil = FUN(A);

    cout << "Hasil FUN = " << hasil << endl;

    return 0;
}
