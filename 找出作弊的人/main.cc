#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


std::pair<int, int> Spilt(std::string str) {
    int index = str.find(' ');
    int a = std::stoi(str.substr(0, index));
    int b = std::stoi(str.substr(index + 1));
    return std::pair<int, int>(a, b);
}

int main() {

    int number;
    std::cin >> number;
    std::cin.ignore();

    std::string score = "";
    std::vector<std::pair<int, int> > result;
    std::vector<std::pair<int, int> > vec;
    for (int i = 0; i < number; i++) {
        std::getline(std::cin, score);
        vec.push_back(Spilt(score));
    }
    int min = 300;
    for (int i = 1; i < vec.size(); i++) {
        min = std::min(std::abs(vec[i].second - vec[i - 1].second), min);
    }
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].second - vec[i - 1].second == min) {
            result.push_back(std::pair<int, int>(vec[i - 1].first, vec[i].first));
        }
    }
    for (auto it: result) {
        std::cout << it.first << " " << it.second << std::endl;
    }


    return 0;
}