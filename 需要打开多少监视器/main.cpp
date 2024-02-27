#include <iostream>
#include <vector>
#include <string>

std::vector<int> SpiltString(std::string input) {
    std::vector<int> ans;
    while (input.find(" ") != std::string::npos) {
        int index = input.find(" ");
        ans.push_back(std::stoi(input.substr(0, index)));
        input = input.substr(index + 1);
    }
    ans.push_back(std::stoi(input));
    return ans;
}

int getResult(std::vector<std::vector<int> > matrix) {
    int ans = 0;
    std::vector<std::vector<int> > directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                ans += 1;
            } else {
                for (int k = 0; k < 4; k++) {
                    int x = i + directions[k][0];
                    int y = j + directions[k][1];
                    if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[i].size() && matrix[x][y] == 1) {
                        ans += 1;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    int m, n;
    std::cin >> m;
    std::cin >> n;

    std::vector<std::vector<int> > matrix(m, std::vector<int>(n));

    int number;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            std::cin >> number;
            matrix[i][j] = number;
        }
    }
    int ans = getResult(matrix);
    std::cout << ans << std::endl;

    return 0;
}