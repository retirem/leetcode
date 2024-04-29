#include <iostream>
#include <vector>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        std::vector<int> first_row = grid[0];
        int smallest = first_row[0];
        size_t smallest_index = 0;

        for (size_t i = 0; i < first_row.size(); ++i) {
            if (first_row[i] < smallest) {
                smallest = first_row[i];
                smallest_index = i;
            }
        }

        return smallest + subMinFallingPathSum(smallest_index, grid);
    }

    int subMinFallingPathSum(size_t currently_taken_index, std::vector<std::vector<int>>& grid){
        std::vector<int> first_row = grid[0];
        int smallest = first_row[0];
        size_t new_index = 0;

        for (size_t i = 0; i < first_row.size(); ++i) {
            if (i != currently_taken_index) {
                if (first_row[i] < smallest) {
                    smallest = first_row[i];
                    new_index = i;
                }
            }
        }

        if (grid.size() == 1) return smallest;

        std::vector<std::vector<int>>& new_grid = grid;
        new_grid.erase(new_grid.begin());

        return smallest + subMinFallingPathSum(new_index, new_grid);
    }
};

int main(){
    std::vector<std::vector<int>> grid{ std::vector<int>{ 1,2,3 }, std::vector<int>{ 4,5,6 }, std::vector<int>{ 7,8,9 }};

    Solution s;
    std::cout << "Solution: " << s.minFallingPathSum(grid) << std::endl;
    return 0;
}
