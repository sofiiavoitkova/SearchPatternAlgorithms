#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <string>

void computeLPSArray(const std::string& P, int m, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPAlg(const std::string& P, const std::string& T) {
    int m = P.length();
    int n = T.length();
    int lps[m];

    computeLPSArray(P, m, lps);

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n) {
        if (P[j] == T[i]) {
            j++;
            i++;
        }

        if (j == m) {
            std::cout << "Found pattern at index " << i - j << std::endl;
            //count++;
            j = lps[j - 1];
        } else if (i < n && P[j] != T[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

#endif
