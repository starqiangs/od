#include <iostream>
#include <vector>
#include <string>

std::string findLongestCommonPrefix(std::string str1, std::string str2) {
    std::string ans;
    int size = std::max(str1.size(), str2.size());
    for (int i = 0; i < size; i++) {
        if (str1[i] == str2[i]) {
            ans += str1[i];
        } else {
            break;
        }
    }
    return ans;
}

std::string longestCommonPrefix(std::vector <std::string> &strs) {
    std::string str = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        str = findLongestCommonPrefix(str, strs[i]);
        if (str.empty()) {
            return "Zero";
        }
    }
    return str;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    input = input.substr(1, input.size() - 2);

    std::vector <std::string> vec;
    std::string temp;
    for (char ch : input) {
        if (ch == ',') {
            vec.push_back(temp);
            temp = "";
        } else if (ch != '\"')
        {
            temp += ch;
        }
    }
    vec.push_back(temp);
    std::string ans = longestCommonPrefix(vec);
    std::cout << ans << std::endl;

    return 0;
}