#include <iostream>
#include <queue>
#include <vector>

std::vector<std::string> spiltString(std::string input) {
    std::vector<std::string> ans;
    while (input.find(" ") != std::string::npos) {
        int index = input.find(" ");
        ans.push_back(input.substr(0, index));
        input = input.substr(index + 1);
    }
    ans.push_back(input);
    return ans;
}

int main() {
    std::vector<std::vector<std::string> > input;
    std::string inputLine;

    while (std::getline(std::cin, inputLine)) {
        if (inputLine.size() == 0) {
            break;
        } else {
            std::vector<std::string> vec = spiltString(inputLine);
            input.push_back(vec);
        }
    }

    std::queue<std::pair<int, int> > que;

    //输入YES的坐标进入que
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == "YES") {
                que.push(std::make_pair(i, j));
            }
        }
    }

    int ans = -1;

    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            std::pair<int, int> it = que.front();
            if (it.first - 1 > 0 && input[it.first - 1][it.second] == "NO") {
                input[it.first - 1][it.second] = "YES";
                que.push(std::make_pair(it.first - 1, it.second));
            }
            if (it.second - 1 > 0 && input[it.first][it.second - 1] == "NO") {
                input[it.first][it.second - 1] = "YES";
                que.push(std::make_pair(it.first, it.second - 1));
            }
            if (it.first + 1 < input.size() && input[it.first + 1][it.second] == "NO") {
                input[it.first + 1][it.second] = "YES";
                que.push(std::make_pair(it.first + 1, it.second));
            }
            if (it.second + 1 < input[0].size() && input[it.first][it.second + 1] == "NO") {
                input[it.first][it.second + 1] = "YES";
                que.push(std::make_pair(it.first, it.second + 1));
            }
            que.pop();
        }
        ans += 1;
    }

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == "NA") {
                ans = -1;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
