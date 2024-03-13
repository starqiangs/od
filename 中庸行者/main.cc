#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

bool isValidMove(int x, int y, std::vector<std::vector<int> > nums, std::unordered_set<int> &st, int val, int prev) {
    if (x < 0 || x >= nums.size() || y < 0 || y >= nums[0].size()) {
        return false;
    }
    if (st.count(x * nums[0].size() + y) > 0) {
        return false;
    }
    if (nums[x][y] == val) {
        return false;
    }
    if ((prev != -1 && (prev == 1 && nums[x][y] > val)) || (prev != -1 && (prev == 0 && nums[x][y] < val))) {
        return false;
    }
    return true;
}

int dfs(std::vector<std::vector<int> > &nums, std::unordered_set<int> &st, int x, int y, int status) {
    std::vector<std::vector<int> > direction(4, std::vector<int>(2));
    // 初始化 direction
    direction[0][0] = 0;
    direction[0][1] = 1;
    direction[1][0] = 0;
    direction[1][1] = -1;
    direction[2][0] = 1;
    direction[2][1] = 0;
    direction[3][0] = -1;
    direction[3][1] = 0;

    int maxMoves = 0;

    for (int i = 0; i < 4; i++) {
        int new_x = x + direction[i][0];
        int new_y = y + direction[i][1];
        if (isValidMove(new_x, new_y, nums, st, nums[x][y], status)) {
            st.insert(x * nums[0].size() + y);
            status = nums[new_x][new_y] > nums[x][y] ? 1 : 0;
            maxMoves = std::max(maxMoves, dfs(nums, st, new_x, new_y, status) + 1);
            st.erase(x * nums[0].size() + y);
        }
    }

    return maxMoves;
}

int maxMoves(std::vector<std::vector<int> > &nums) {
    int maxMoves = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            std::unordered_set<int> st;
            int InitStatus = -1;
            maxMoves = std::max(maxMoves, dfs(nums, st, i, j, InitStatus));
        }
    }
    return maxMoves;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    std::vector<std::vector<int> > nums(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> nums[i][j];
        }
    }

    std::cout << maxMoves(nums) << std::endl;

    return 0;
}