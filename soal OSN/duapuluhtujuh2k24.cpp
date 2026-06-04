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
    int cnt = 0;

    for (char a = 'A'; a <= 'Z'; a++) {
        for (char b = 'A'; b <= 'Z'; b++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                string s = "";
                s += a;
                s += b;
                s += c;

                if (cek(s))
                    cnt++;
            }
        }
    }

    cout << cnt << endl;
}