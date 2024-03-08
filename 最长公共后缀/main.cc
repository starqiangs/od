#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> SpiltString(std::string input) {
    std::vector<std::string> result;
    while (input.find(",") != std::string::npos) {
        int index = input.find(",");
        std::string str = input.substr(0, index);
        result.push_back(str.substr(1, str.size() - 2));
        input = input.substr(index + 1);
    }
    result.push_back(input.substr(1, input.size() - 2));
    return result;
}

std::string longestStrLast(std::string str1, std::string str2) {
    std::string result;
    int size = str1.size() < str2.size() ? str1.size() : str2.size();
    for (int i = size; i > 0; i--) {
        if (str1[str1.size() - i] == str2[str2.size() - i]) {
            result += str1[str1.size() - i];
        } else {
            break;
        }
    }
    return result;
}


std::string GetCommonLast(std::vector<std::string> vec) {
    std::string str = vec[vec.size() - 1];
    for (int i = vec.size() - 2; i >= 0; i--) {
        str = longestStrLast(str, vec[i]);
        if (str.empty()) {
            return "Zero";
        }
    }
    return str;
}

int main() {
    std::string input;
    std::cin >> input;

    input = input.substr(1, input.size() - 2);

    std::vector<std::string> inputVec = SpiltString(input);

    std::string result = GetCommonLast(inputVec);

    std::cout << result << std::endl;


    return 0;
}