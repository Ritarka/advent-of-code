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


    int password = 0;
    int pos = 50;
    int mod = 100;
    while (std::getline(inputFile, line)) {
        int dir = line[0] == 'R' ? 1 : -1;
        int mag = stoi(line.substr(1));

        int move = dir * mag;
        int move_modded = move % mod;
        int rotations = abs(move / mod);

        int old_pos = pos;

        password += rotations;
        pos += move_modded;
        printf("move: %d pos: %d pass: %d\n", move_modded, pos, password);

        if (pos <= 0 || pos >= mod) {
            pos = (pos + mod) % mod;
            if (old_pos != 0) {
                password++;
            }
        }
        printf("%2d %2d %2d\n\n", pos, rotations, password);
        // printf("%d %d %d %d\n", pos, move_modded, rotations, password);
    }

    // Output the result
    std::cout << "Result: " << password << std::endl;

    return 0;
}