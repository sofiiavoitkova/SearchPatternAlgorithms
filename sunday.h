#ifndef SUNDAY_H
#define SUNDAY_H

#include <iostream>
using namespace std;

void sundayAlg(const std::string& P, const std::string& T) {
    int count = 0;
    unsigned int n = T.length();
    unsigned int m = P.length();

    unsigned int skip[256];

    for (int k = 0; k < 256; k++) {
        skip[k] = m + 1;
    }

    for (int k = 0; k < m; k++) {
        skip[P[k]] = m - k;
    }

    unsigned int i = 0;
    while (i <= n - m) {

        int j = 0;
        while (j < m && P[j] == T[i + j]) {
            j++;
        }
        if (j == m) {
            count++;
            //cout << "pattern found at index " << i << endl;
        }

        if (i + m < n) {
            i += skip[  (unsigned char)  T[i + m]  ];
        } else {
            break;
        }
    }
}

#endif //SUNDAY_H
