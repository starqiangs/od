#include <iostream>

std::vector<std::vector<int> > mergeVec(std::vector<std::vector<int> > nums) {
    std::vector<std::vector<int> > result;
    int start = nums[0][0];
    int end = nums[0][1];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i][0] > end) {
            std::vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            result.push_back(temp);
            start = nums[i][0];
            end = nums[i][1];
        } else {
            end = nums[i][1];
        }
    }
    std::vector<int> temp;
    temp.push_back(start);
    temp.push_back(end);
    result.push_back(temp);
    return result;
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
    std::sort(matrix.begin(), matrix.end());

    auto vec = mergeVec(matrix);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i][0] << " " << vec[i][1] << std::endl;
    }


    return 0;
}