#include <iostream>
#include <stack>


std::string Reverse(std::string input) {
    std::stack <std::string> st;
    std::string str;
    for (int i = 0; i < input.size(); i++) {
        if (input.at(i) == '(') {
            st.push(str);
            str = "";
        } else if (input.at(i) == ')') {
            std::reverse(str.begin(), str.end());
            str = st.top() + str;
            st.pop();
        } else {
            str += input[i];
        }
    }
    return str;
}

int main() {
    std::string inputStr;
    std::cin >> inputStr;

    inputStr = inputStr.substr(1, inputStr.length() - 2);

    std::string str = Reverse(inputStr);
    std::cout << str << std::endl;

    return 0;
}