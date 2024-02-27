#include <iostream>
#include <string>
#include <vector>

std::vector<int> spiltResult(std::string input) {
    std::vector<int> result;
    while (input.find(",") != std::string::npos) {
        int index = input.find(",");
        result.push_back(std::stoi(input.substr(0, index)));
        input = input.substr(index + 1);
    }
    result.push_back(std::stoi(input));
    return result;
}

int BackIndex(std::vector<int> vec, int sum) {
    int total = 0;
    for (int i = 0; i < vec.size(); i++) {
        if(total * 2 + vec[i] == sum) {
            return i;
        }
        total += vec[i];
    }
    return -1;

}

int main() {
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::vector<int> vec = spiltResult(inputLine);
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    int ans = BackIndex(vec, sum);
    std::cout << ans << std::endl;
    return 0;
}