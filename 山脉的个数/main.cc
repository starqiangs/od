#include <iostream>

int GetResult(std::vector<int> vec) {
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (i - 1 < 0) {
            if (vec[i + 1] < vec[i]) {
                ans += 1;
            }
        } else if (i + 1 >= vec.size()) {
            if (vec[i - 1] < vec[i]) {
                ans += 1;
            }
        } else {
            if (vec[i] > vec[i + 1] && vec[i] > vec[i - 1]) {
                ans += 1;
            }
        }
    }
    return ans;
}

std::vector<int> SpiltString(std::string input) {
    std::vector<int> result;
    while (input.find(' ') != std::string::npos) {
        int index = input.find(' ');
        result.push_back(std::stoi(input.substr(0, index)));
        input = input.substr(index + 1);
    }
    result.push_back(std::stoi(input));
    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> vec = SpiltString(input);
    std::cout << GetResult(vec) << std::endl;


    return 0;
}