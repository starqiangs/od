#include <iostream>
#include <queue>
#include <string>


int main() {
    std::string input;
    std::cin >> input;

    bool contains_number = false;
    bool contains_upper = false;
    bool contains_lower = false;
    bool contains_special = false;

    std::string result = "";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<') {
            result = result.substr(0, result.size() - 1);
        } else {
            result += input[i];
            if (std::isdigit(input[i])) {
                contains_number = true;
            } else if (std::isupper(input[i])) {
                contains_upper = true;
            } else if (std::islower(input[i])) {
                contains_lower = true;
            } else if (!isupper(input[i]) && !islower(input[i]) && !isdigit(input[i]) && input[i] != ' ') {
                contains_special = true;
            }
        }
    }

    bool is_palindrome = (contains_special && contains_upper && contains_number && contains_lower);
    if (is_palindrome) {
        std::cout << result << "," << "true" << std::endl;
    } else {
        std::cout << result << "," << "false" << std::endl;
    }

    return 0;
}