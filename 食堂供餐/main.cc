#include <iostream>
#include <vector>
#include <string>

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

bool check(int mid, int total, std::vector<int> vec) {
    bool result = true;
    for (int i = 0; i < vec.size(); i++) {
        total -= vec[i];
        if (total < 0) {
            result = false;
            break;
        } else {
            total += mid;
        }
    }
    return result;
}

int main() {
    int N, M;
    std::cin >> N;
    std::cin >> M;

    int number;
    std::vector<int> vec;
    int total = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> number;
        vec.push_back(number);
        total += number;
    }

    int min = 0;
    int max = total - M;
    while (min < max) {
        int mid = (max + min) / 2;
        if (check(mid, M, vec)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    std::cout << min << std::endl;

    return 0;
}