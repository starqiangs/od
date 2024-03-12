#include <iostream>
#include <vector>
#include <string>

std::vector<int> Spilt(std::string str) {
    std::vector<int> result;
    while (str.find(' ') != std::string::npos) {
        int index = str.find(' ');
        result.push_back(std::stoi(str.substr(0, index)));
        str = str.substr(index + 1);
    }
    result.push_back(std::stoi(str));
    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> vec = Spilt(input);
    int size = vec.size();

    std::vector<int> nums(size * 2, 0);
    for (int i = 0; i < size; i++) {
        nums[i] = vec[i];
        nums[i + size] = vec[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[i]) {
                vec[i] = nums[i] + nums[j];
                break;
            }
        }
    }

    for (auto it: vec) {
        std::cout << it << " ";
    }
    std::cout << std::endl;


    return 0;
}