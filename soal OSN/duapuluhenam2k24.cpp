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

int main() {
    cout << cek("BEGINI") << endl;
    cout << cek("BEGITU") << endl;
    cout << cek("BERAPA") << endl;
    cout << cek("BERUPA") << endl;
    cout << cek("BETAPA") << endl;

    return 0;
}