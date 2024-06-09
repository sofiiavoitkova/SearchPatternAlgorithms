#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <string>
#include <algorithm>

void FSMAlg(const std::string& P, const std::string& T)
{
    unsigned int m = P.length();
    unsigned int n = T.length();

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





//#ifndef FSM_H
//#define FSM_H
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//void FSMAlg(const std::string& T, const std::string& P)
//{
//    std::cout << "Entering FSMAlg function" << std::endl;
//
//    unsigned int m = P.length();
//    unsigned int n = T.length();
//
//    int engine[m+1][256];
//
//    for (unsigned int s = 0; s <= m; s++)
//    {
//        std::cout << "Entering outer loop, s = " << s << std::endl;
//        for (int a = 0; a < 256; a++)
//        {
//            std::cout << "Entering inner loop, a = " << a << std::endl;
//            unsigned int k = std::min(m, s + 1);
//            while (k > 0 )
//            {
//                std::cout << "Entering while loop, k = " << k << std::endl;
//                if(P[k]==a){
//                    int j = k-2;
//                    while (j>=0 && P[j]==P[s+1-k+j]){
//                        std::cout << "Entering inner while loop, j = " << j << std::endl;
//                        j--;
//                    }
//                    if(j<-1){
//                        std::cout << "Inside if condition, j = " << j << std::endl;
//                    }
//                }
//                k--;
//            }
//            engine[s][a]=k;
//
//        }
//    }
//
//    int state = 0;
//    int count = 0;
//
//    for (unsigned int i = 0; i < n; i++)
//    {
//        std::cout << "Entering outer loop, i = " << i << std::endl;
//        state = engine[state][T[i]];
//        if (state == m)
//        {
//            std::cout << "Pattern found at index " << i - m + 1 << std::endl;
//            //count++;
//        }
//    }
//    std::cout << "Exiting FSMAlg function" << std::endl;
//}
//
//#endif