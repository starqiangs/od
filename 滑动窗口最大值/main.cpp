#include <iostream>

int main() {
    int N, M;
    std::cin >> N;

    int input_number;
    std::vector<int> input;
    for (int i = 0; i < N; i++) {
        std::cin >> input_number;
        input.push_back(input_number);
    }

    std::cin >> M;
    int start = 0, sum = 0, ans = 0;
    for (int end = 0; end < N; end++) {
        sum += input[end];
        if (end - start + 1 >= M) {
            ans = std::max(ans, sum);
            sum -= input[start];
            start++;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}