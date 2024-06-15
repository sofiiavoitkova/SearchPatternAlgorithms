
#ifndef BRUTE_H
#define BRUTE_H
#include <iostream>
#include <cstring>

using namespace std;
void brute_force_pattern_matching(const string& pattern, const string& text){
    unsigned int n = text.length();
    unsigned int m = pattern.length();
    if (m > n) return;
    int count = 0;
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if(j == m){
                count++;
            }
        }
    }
#endif // BRUTE_H

