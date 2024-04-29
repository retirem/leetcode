#include <iostream>
#include <vector>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        return subMinFallingPathSum(0, grid, true);
    }

    int subMinFallingPathSum(size_t last_smallest_index, std::vector<std::vector<int>> grid, bool is_first_row){
        if (grid.size() == 0) return 0;
        
        std::vector<int> first_row = grid[0];
        grid.erase(grid.begin());

        int smallest_sum = INT_MAX;

        for (size_t i = 0; i < first_row.size(); ++i) {
            if (is_first_row) {
                int sum = first_row[i] + subMinFallingPathSum(i, grid, false);
                if (sum < smallest_sum) {
                    smallest_sum = sum;
                }
            }else {
                if (i != last_smallest_index) {
                    int sum = first_row[i] + subMinFallingPathSum(i, grid, false);
                    if (sum < smallest_sum) {
                        smallest_sum = sum;
                    }
                }
            }
        }

        return smallest_sum;
    }
};

int main(){
    std::vector<std::vector<int>> grid{ std::vector<int>{ -37,51,-36,34,-22 }, std::vector<int>{ 82,4,30,14,38 }, std::vector<int>{ -68,-52,-92,65,-85 }, std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ -60,-71,-21,-62,-73 }};

    Solution s;
    std::cout << "Solution: " << s.minFallingPathSum(grid) << std::endl;
    return 0;
}
