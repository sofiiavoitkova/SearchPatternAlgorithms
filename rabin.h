#ifndef RABIN_H
#define RABIN_H

#include <iostream>

void rabinKarp(const std::string& P, const std::string& T) {
    unsigned int n = T.length();
    unsigned int m = P.length();


    if (m > n) return;

    int S = 128;
    int L = 997;

    int hP = 0;
    int h = 0;
    int Sm1 = 1;
    int count = 0;

    for (int j = 1; j < m; j++) {
        Sm1 = (Sm1 * S) % L;
    }

    for (int j = 0; j < m; j++) {
        hP = ((hP * S) + P[j]) % L;
        h = ((h * S) + T[j]) % L;
    }

    if (h == hP) {
        int j = 0;
        while (j < m && T[j] == P[j]) {
            j++;
        }
        if (j == m) {
            count++;
        }
    }

    for (int i = 0; i <= n - m; i++) {
        if (h == hP) {
            int j = 0;
            while (j < m && T[j + i] == P[j]) {
                j++;
            }
            if (j == m) {
                count++;
            }
        }

        if (i < n - m) {
            h = ((h - T[i] * Sm1) * S + T[i + m]) % L;
            if (h < 0) {
                h += L;
            }
        }
    }
}

#endif // RABIN_H
