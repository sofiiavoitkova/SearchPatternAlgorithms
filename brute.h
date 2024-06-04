
#ifndef BRUTE_H
#define BRUTE_H
#include <iostream>
#include <cstring>

using namespace std;
void brute_force_pattern_matching(const string& pattern, const string& text){
    unsigned int n = text.length();
    unsigned int m = pattern.length();

        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            int count = 0;
            if(j == m){
                cout << "Pattern found at index: "<< i << endl;
                //count++;
            }
        }
    }
#endif // BRUTE_H

