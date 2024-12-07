#include <iostream>
#include <map>
#include <string>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::map<char, int> wordMap;

        for (char letter : word) {
            wordMap.insert_or_assign(letter, wordMap.contains(letter) ? wordMap.at(letter) + 1 : 1);
        }

        int result = 0;
        int button = 2;
        int cycle = 1;
        
        for (int i = 0; i < wordMap.size(); i++) {
            auto maxElemPair = std::ranges::max_element(wordMap,
                [](const std::pair<char, int>& p1, const std::pair<char, int>& p2) {
                    if (p1.second < p2.second) {
                        return true;
                    }

                    return false;
                });

            result += maxElemPair->second * cycle;
            wordMap.erase(maxElemPair);

            if (button == 9) {
                button = 2;
                cycle++;
            } else {
                button++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.minimumPushes("word");
}
