#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Open the file
    std::ifstream inputFile("q1.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open q1.txt" << std::endl;
        return 1;
    }

    std::vector<std::vector<char>> data;
    std::string line;


    int password = 0;
    int pos = 50;
    int mod = 100;
    while (std::getline(inputFile, line)) {
        int dir = line[0] == 'R' ? 1 : -1;
        int mag = stoi(line.substr(1));

        int move = dir * mag;
        pos += move;
        pos = (pos + mod) % mod;

        // printf("%d %d\n", pos, move);

        if (pos == 0) {
            password++;
        }
    }

    // Output the result
    std::cout << "Result: " << password << std::endl;

    return 0;
}