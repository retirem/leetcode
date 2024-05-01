#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        std::vector<int> first_row = grid[0];
        grid.erase(grid.begin());

        int smallest_sum = INT_MAX;

        for (size_t i = 0; i < first_row.size(); ++i) {
            int sum = first_row[i] + subMinFallingPathSum(i, grid);
            if (sum < smallest_sum) {
                smallest_sum = sum;
            }
        }

        return smallest_sum;
    }

    int subMinFallingPathSum(size_t last_smallest_index, std::vector<std::vector<int>> grid){
        if (grid.size() == 0) return 0;
        
        std::vector<int> first_row = grid[0];
        grid.erase(grid.begin());

        int smallest_sum = INT_MAX;

        for (size_t i = 0; i < first_row.size(); ++i) {
            if (i != last_smallest_index) {
                int sum = first_row[i] + subMinFallingPathSum(i, grid);
                if (sum < smallest_sum) {
                    smallest_sum = sum;
                }
            }
        }

        return smallest_sum;
    }
};

int main(){
    std::vector<std::vector<int>> grid{ std::vector<int>{ -2,-18,31,-10,-71,82,47,56,-14,42 }, 
        std::vector<int>{ 82,4,30,14,38 }, std::vector<int>{ -95,3,65,-7,64,75,-51,97,-66,-28 }, 
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ 36,3,-62,38,15,51,-58,-90,-23,-63 },
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ 58,-26,-42,-66,21,99,-94,-95,-90,89 },
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ 83,-66,-42,-45,43,85,51,-86,65,-39 },
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ 56,9,9,95,-56,-77,-2,20,78,17 },
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ 78,-13,-55,55,-7,43,-98,-89,38,90 },
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ 32,44,-47,81,-1,-55,-5,16,-81,17 },
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ -87,82,2,86,-88,-58,-91,-79,44,-9 },
        std::vector<int>{ -49,-3,-77,8,-19 }, std::vector<int>{ -96,-14,-52,-8,12,38,84,77,-51,52 }};

    Solution s;
    std::cout << "Solution: " << s.minFallingPathSum(grid) << std::endl;
    return 0;
}
