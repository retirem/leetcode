#include <vector>
#include <iostream>

// We can assume that every given input has exactly one solution, according to task description
#pragma clang diagnostic ignored "-Wreturn-type"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> indices;
        // Since the same element is allowed multiple times in the input, the sorting double iterator, and hash map is not an option
        for (auto i = nums.begin(); i != nums.end(); ++i){
            for (auto j = i; j != nums.end(); ++j){
                if (i != j) {
                    if (*i + *j == target) {
                        indices.push_back(distance(nums.begin(), i));
                        indices.push_back(distance(nums.begin(), j));
                        return indices;
                    }
                }
            }
        }
    }
};

int main(){
    std::vector<int> nums{ 3,3 };
    int target = 6;

    Solution s;
    std::vector<int> indices = s.twoSum(nums, target);

    std::cout << "Solution: [" << indices[0] << ", " << indices[1] << "]" << std::endl;
    return 0;
}
