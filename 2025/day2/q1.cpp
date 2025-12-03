#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Open the file
    std::ifstream inputFile("test.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open q1.txt" << std::endl;
        return 1;
    }

    std::vector<std::vector<char>> data;
    std::string line;

    while (std::getline(inputFile, line)) {
    }

    // Output the result
    std::cout << "Result: " << password << std::endl;

    return 0;
}