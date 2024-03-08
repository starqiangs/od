#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>

std::vector<int> SplitString(std::string input) {
    std::vector<int> result;
    while (input.find(' ') != std::string::npos) {
        int index = input.find(' ');
        result.push_back(std::stoi(input.substr(0, index)));
        input = input.substr(index + 1);
    }
    result.push_back(std::stoi(input));
    return result;
}

int main() {
    std::string inputMessage;
    std::string consumer;
    std::getline(std::cin, inputMessage);
    std::getline(std::cin, consumer);

    std::vector<int> message = SplitString(inputMessage);
    std::vector<int> consumers = SplitString(consumer);

    std::vector<std::pair<int, int> > message_mp;
    std::vector<std::pair<int, int> > consumer_mp;

    for (int i = 0; i < message.size(); i += 2) {
        message_mp.push_back(std::pair<int, int>(message[i], message[i + 1]));
    }

    for (int i = 0; i < consumers.size(); i += 2) {
        consumer_mp.push_back(std::pair<int, int>(consumers[i], consumers[i + 1]));
    }

    std::sort(message_mp.begin(), message_mp.end());
    std::vector<std::vector<int> > result(consumer_mp.size());

    for (int i = 0; i < message_mp.size(); i++) {
        int pub_time = message_mp[i].first;
        int pub_content = message_mp[i].second;
        for (int j = consumer_mp.size() - 1; j >= 0; j--) {
            int sub_time = consumer_mp[j].first;
            int unsub_time = consumer_mp[j].second;

            if (pub_time >= sub_time && pub_time < unsub_time) {
                result[j].push_back(pub_content);
                break;
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        if (result[i].empty()) {
            std::cout << "-1" << std::endl;
        } else {
            for (int j = 0; j < result[i].size(); j++) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
