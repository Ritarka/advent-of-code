#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Open the file
    std::ifstream inputFile("q1.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open q1.txt" << std::endl;
        return 1;
    }

    std::string line;

    unsigned long long sum = 0;
    while (std::getline(inputFile, line)) {
        int size = line.size();
        // printf("size: %d\n", size);
        vector<int> pos;
        for (int i = size - 12; i < size; i++) {
            pos.push_back(i);
            // printf("%2d ", i);
        }
        // printf("\n");

        unsigned long long run = 0;

        for (int i = 0; i < 12; i++) {
            int largest_num = -1;
            int largest_pos = -1;
            int end = 0;
            if (i != 0) {
                end = pos[i-1] + 1;
            }
            // printf("i: %d begin: %d end: %d\n", i, pos[i], end);
            for (int j = pos[i]; j >= end; j--) {
                int val = line[j] - '0';
                if (val >= largest_num) {
                    largest_num = val;
                    largest_pos = j;
                }
            }
            pos[i] = largest_pos;
            run = run * 10 + largest_num;
            // printf("Largest num: %d, run: %llu\n", largest_num, run);
        }
        printf("%llu\n", run);
        sum += run;

    }

    // Output the result
    std::cout << "Result: " << sum << std::endl;

    return 0;
}