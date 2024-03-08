#include <iostream>
#include <string>
#include <vector>


std::vector<int> SpiltString(std::string str) {
    std::vector<int> result;
    while (str.find(',') != std::string::npos) {
        int index = str.find(',');
        result.push_back(std::stoi(str.substr(0, index)));
        str = str.substr(index + 1);
    }
    result.push_back(std::stoi(str));
    return result;
}

int main() {
    std::string input;
    int target;
    std::getline(std::cin, input);
    std::cin >> target;

    std::vector<int> vec = SpiltString(input);

    int left = 0;
    int right = 0;
    int curSum = 0;
    int result = 0;
    for (; right < vec.size(); right++) {
        curSum += vec[right];

        while (curSum > target) {
            left++;
            curSum -= vec[left - 1];
        }

        if (curSum == target) {
            result = std::max(result, right - left + 1);
        }
    }

    if (result > 0) {
        std::cout << result << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}