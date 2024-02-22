#include <iostream>
#include <vector>
#include<string>

std::vector<int> SpiltString(std::string input) {
    std::vector<int> vec;
    while (input.find(' ') != std::string::npos) {
        int index = input.find(' ');
        vec.push_back(std::stoi(input.substr(0, index)));
        input = input.substr(index + 1);
    }
    vec.push_back(std::stoi(input));
    return vec;
}

int check(std::vector<int> vec, int k) {
    int day = 0;
    for (int i = 0; i < vec.size(); i++) {
        day += vec[i] / k + (vec[i] % k == 0 ? 0 : 1);
    }
    return day;
}

int getResult(std::vector<int> vec, int h) {
    int min_k = 1;
    int max_k = 0;
    for (int i = 0; i < vec.size(); i++) {
        max_k = std::max(vec[i], max_k);
    }

    while (min_k < max_k) {
        int mid = (max_k + min_k) / 2;
        if (check(vec, mid) > h) {
            min_k = mid + 1;
        } else {
            max_k = mid;
        }
    }
    return min_k;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> vec = SpiltString(input);
    int h = vec[vec.size() - 1];
    vec.pop_back();

    int min_k = getResult(vec, h);
    std::cout << min_k << std::endl;
    return 0;
}
