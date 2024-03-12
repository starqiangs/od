#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> SpiltString(std::string input) {
    std::vector<std::string> result;
    while (input.find(',') != std::string::npos) {
        int index = input.find(',');
        result.push_back(input.substr(0, index));
        input = input.substr(index + 1);
    }
    result.push_back(input);
    return result;
}

std::string GetResult(std::vector<std::string> &vec, int index) {
    std::string result = "";
    std::string input = vec[index];
    int preIndex = input.find('<');
    int lastIndex = input.find('>');
    if (preIndex == -1 && lastIndex == -1) {
        result = input;
    } else if ((preIndex == -1 || lastIndex == -1) || (preIndex > lastIndex || lastIndex - preIndex != 2)) {
        result = "-1";
    } else {
        //获取当前的自字符
        char ch = input.substr(preIndex + 1, lastIndex)[0];
        if (!(ch >= 'A' && ch <= 'Z')) {
            result = "-1";
        }
        //获取当前的字符替换的位置
        int i = ch - 'A';
        if (i == index) {
            result = "-1";
        }
        result = input.substr(0, preIndex) + vec[i] + input.substr(lastIndex + 1);
    }
    return result;
}

int main() {
    std::string input;
    std::cin >> input;
    std::vector<std::string> vec = SpiltString(input);
    for (int i = 0; i < vec.size(); i++) {
        std::string temp = GetResult(vec, i);
        if (temp == "-1") {
            std::cout << "-1";
            return 0;
        } else {
            vec[i] = temp;
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << ",";
        }
    }

    std::cout << std::endl;

    return 0;
}