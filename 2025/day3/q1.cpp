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


    int sum = 0;
    while (std::getline(inputFile, line)) {
        int size = line.size();
        int tens = -1;
        int ones = -1;
        for (int i = 0; i < size; i++) {
            int num = line[i] - '0';
            if (i != size - 1 && num > tens) {
                tens = num;
                ones = line[i+1] - '0';
            } else if (num > ones) {
                ones = num;
            }
        }
        int combine = tens * 10 + ones;
        printf("%d\n", combine);
        sum += combine;
    }

    // Output the result
    std::cout << "Result: " << sum << std::endl;

    return 0;
}