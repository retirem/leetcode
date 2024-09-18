#include <iostream>
#include <unordered_set>

class Solution {
public:
    std::unordered_set<char> distinctCharacters(std::string word) {
        std::unordered_set<char> chars;

        for (int i = 0; i < word.size(); ++i) {
            chars.insert(word[i]);
        }

        return chars;
    }

    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        int consistentCount = 0;

        for (std::string word : words) {
            std::unordered_set<char> wordChars = distinctCharacters(word);

            bool consistent = true;
            for (char character : wordChars) {
                if (allowed.find(character) == std::string::npos) consistent = false;
            }

            if (consistent) consistentCount++;
        }

        return consistentCount;
    }
};

int main(){
    std::string allowed = "ab";
    std::vector<std::string> words = {
        "ad","bd","aaab","baa","badab"
    };

    Solution s;
    std::cout << "Solution: " << s.countConsistentStrings(allowed, words) << std::endl;
    return 0;
}
