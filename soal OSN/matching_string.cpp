#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Fungsi DUA
 * Menghitung berapa kali kebalikan dari string T muncul di dalam string S.
 */
int DUA(string S, string T) {
    int N = S.length();
    int M = T.length();

    int P = 0;
    // Loop luar: Menggeser jendela pencarian di string S
    for (int i = 0; i <= N - M; i++) {
        int Q = 1;
        // Loop dalam: Membandingkan S dengan T yang dibalik (reverse)
        for (int j = 0; j < M; j++) {
            // T[M - 1 - j] mengakses karakter T dari belakang
            if (S[i + j] != T[M - 1 - j]) {
                Q = 0; // Tidak cocok
            }
        }
        P += Q; // Jika cocok (Q tetap 1), tambahkan ke total P
    }
    return P;
}

int main() {
    // String S dari soal
    string S = "BBABAABBAAABBABBAAABBBAAABBABBA";
    
    // String T (Contoh "ABB" yang kebalikannya "BBA" muncul 5 kali)
    string T = "ABB";

    int hasil = DUA(S, T);

    cout << "String S: " << S << endl;
    cout << "String T: " << T << " (kebalikannya adalah BBA)" << endl;
    cout << "Hasil pemanggilan DUA(S, T) adalah: " << hasil << endl;

    return 0;
}