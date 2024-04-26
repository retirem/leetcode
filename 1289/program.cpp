#include <iostream>
#include <vector>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int sum = 0;

        for (auto element = grid.begin(); element != grid.end(); ++element){
            int current_sum = subMinFallingPathSum(grid, element);
            if (current_sum < sum) sum = current_sum;
        }

        /**
         * @brief IDEA: to do recursion, by selection each element in a row, and compare sums at each recursion return
         * 
         */

    }

    int subMinFallingPathSum(std::vector<std::vector<int>>& grid, std::vector<int>::iterator element){

    }
};

int main(){
    std::vector<std::vector<int>> grid{ std::vector<int>{ 1,2,3 }, std::vector<int>{ 4,5,6 }, std::vector<int>{ 7,8,9 }};

    Solution s;
    std::cout << "Solution: " << s.minFallingPathSum(grid) << std::endl;
    return 0;
}
