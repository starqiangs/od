#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<std::vector<int> > direction = {{1,  0},
                                            {-1, 0},
                                            {0,  1},
                                            {0,  -1}};

int dfs(int max_value, int x, int y, std::vector<std::vector<int> > matrix) {
    if (matrix[x][y] == 0) return max_value;

    max_value += matrix[x][y];
    matrix[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int new_x = x + direction[i][0];
        int new_y = y + direction[i][1];
        if (new_x >= 0 && new_x < matrix.size() && new_y >= 0 && new_y < matrix[0].size() && matrix[new_x][new_y] > 0) {
            max_value = dfs(max_value, new_x, new_y, matrix);
        }
    }

    return max_value;
}

int main() {

    std::vector<std::vector<int> > matrix;
    std::string input;

    while (getline(std::cin, input)) {
        std::vector<int> vec;
        for (int i = 0; i < input.size(); i++) {
            vec.push_back(input[i] - '0');
        }
        if (vec.size() == 0) {
            break;
        }
        matrix.push_back(vec);
    }

    int result = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            result = std::max(result, dfs(0, i, j, matrix)); // 시작점
        }
    }
    std::cout << result << std::endl;

    return 0;
}