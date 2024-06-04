#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "gusfield.h"
#include "brute.h"
#include "sunday.h"
#include "rabin.h"
#include "KMP.h"
#include "FSM.h"

std::string readTextFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string text = "";

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            text += line;
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }

    return text;
}

long long measureTime(void (*searchFunction)(const std::string&, const std::string&), const std::string& text, const std::string& pattern)
{
    auto start = std::chrono::high_resolution_clock::now();
    searchFunction(pattern, text);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

int main() {
    std::string text = readTextFromFile("C:\\Users\\serwis\\CLionProjects\\untitled1\\chapter.txt");
    std::string pattern = readTextFromFile("C:\\Users\\serwis\\CLionProjects\\untitled1\\pattern.txt");
    std::cout << " size brute sunday rabin gusfield kmp fsm" << std::endl;
    for (int power = 1; 9*power <= text.length(); power *= 10) {
        for (int d = 1; d < 10; d++) {
            int size = d * power;
              long long bruteForceTime = 0;
              long long sunday = 0;
              long long rabin = 0;
              long long kmp = 0;
              long long z = 0;
              long long fsm = 0;

              //string textcut = text.

              int T = 1;
              for (int t = 0; t < T; t++) {
                  //bruteForceTime += measureTime(brute_force_pattern_matching, text, pattern);
                  //sunday += measureTime(sundayAlg, text, pattern);
                  //rabin += measureTime(rabinKarp, text, pattern);
                  //kmp += measureTime(KMPAlg, text, pattern);
                  //z += measureTime(gusfieldAlg, text, pattern);
                  fsm += measureTime(FSMAlg, text, pattern);
            }
            std::cout << size << " " << bruteForceTime / T << " " << sunday / T << " " << rabin / T << " " <<z/ T<< " " <<kmp / T << " " <<fsm / T<<std::endl;

        }
    }

    return 0;
}
