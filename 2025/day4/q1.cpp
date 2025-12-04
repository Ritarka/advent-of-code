#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Open the file
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open q1.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> data;
    std::string line;


    while (std::getline(inputFile, line)) {
        data.push_back(line);
    }
    
    const vector<vector<int>> dirs = {
        {1, 0},
        {1, -1},
        {1, 1},
        {-1, 0},
        {-1, -1},
        {-1, 1},
        {0, 1},
        {0, -1}
    };
    int total = 0;

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            char c = data[i][j];
            if (c != '@') continue;

            int num_adj = 0;
            for (int k = 0; k < dirs.size(); k++) {
                int dx = dirs[k][0];
                int dy = dirs[k][1];

                int nx = i + dx;
                int ny = j + dy;

                if (nx < 0 || ny < 0 || nx >= data.size() || ny >= data[0].size()) continue;

                if (data[nx][ny] == '@')
                    num_adj++;
            }
            if (num_adj < 4) {
                // printf("%d %d\n", i, j);
                total++;
            }
        }
    }

    // Output the result
    std::cout << "Result: " << total << std::endl;

    return 0;
}