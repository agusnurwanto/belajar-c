#include <iostream>
#include <string>
using namespace std;

bool cek(string S) {
    int n = S.length();

    for (int i = 0; i < n - 1; i++) {
        if (S[i] > S[i + 1])
            return false;
    }

    return true;
}

bool ricek(string S) {
    int n = S.length();

    for (int i = 0; i < n - 1; i++) {
        if (S[i] <= S[i + 1])
            return true;
    }

    return false;
}

int main() {
    string S = "BAC";

    cout << "cek(S)   = " << cek(S) << endl;
    cout << "ricek(S) = " << ricek(S) << endl;

    return 0;
}
