#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <string>
#include <algorithm>

void FSMAlg(const std::string& P, const std::string& T)
{
    unsigned int m = P.length();
    unsigned int n = T.length();

    if (m > n) return;

    int** engine = new int*[m + 1];
    for (unsigned int i = 0; i <= m; ++i) {
        engine[i] = new int[256];
    }

    for (unsigned int s = 0; s <= m; s++)
    {
        for (int a = 0; a < 256; a++)
        {
            unsigned int k = std::min(m, s + 1);
            while (k > 0 )
            {
                if( ( (unsigned char)   P[k-1]) ==a){
                    int j = k-2;
                    while (j>=0 && P[j]==P[s+1-k+j]){
                        j--;
                    }
                    if(j==-1){
                        break;
                    }
                }
                k--;
            }
            engine[s][a]=k;
        }
    }

    int state = 0;
    int count = 0;

    for (unsigned int i = 0; i < n; i++)
    {
        state = engine[state][ (unsigned char) T[i]];
        if (state == m)
        {
            count++;
        }
    }

    for (unsigned int i = 0; i <= m; ++i) {
        delete[] engine[i];
    }
    delete[] engine;

}

#endif

