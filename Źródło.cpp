/**
 ** @file     ¯ród³o.cpp
 ** @brief     Main
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "Funkcje.h"

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Uzycie: " << argv[0] << " -i plik_wejsciowy -o plik_wyjsciowy" << std::endl;
        return 1;
    }

    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string inputFileName, outputFileName;

    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-i") {
            inputFileName = argv[i + 1];
        }
        else if (std::string(argv[i]) == "-o") {
            outputFileName = argv[i + 1];
        }
    }

    inputFile.open(inputFileName);
    outputFile.open(outputFileName);

    std::vector<Edge> edges;

    std::string line;
    while (std::getline(inputFile, line)) { 
        std::stringstream ss(line);
        std::string token;
        while (getline(ss, token, '(')) {
            if (token.empty()) continue;
            token = token.substr(0, token.size() - 2);
            std::stringstream edge(token);
            int x, y;
            double w;
            edge >> x >> token >> y >> token >> w;
            edges.push_back({ x, y, w });
        }
    }
    std::vector<int> parents(edges.size()+1);

    std::vector<std::pair<double, std::pair<int, int>>> result = kruskal(parents, edges);

    int it = 0;
	
    for (auto s : result) {
        outputFile << "(" << s.second.first << ", " << s.second.second << ", " << s.first << ")";
        it++;
        if (it < result.size()) outputFile << ", ";
    }
    outputFile << std::endl;

    return 0;
}



    