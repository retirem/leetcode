#include <iostream>
#include <vector>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        return subMinFallingPathSum(0, grid, true);
    }

    int subMinFallingPathSum(size_t last_smallest_index, std::vector<std::vector<int>>& grid, bool is_first_row){
        if (grid.size() == 0) return 0;

        std::vector<int> first_row = grid[0];
        int smallest = first_row[0];
        size_t current_smallest_index = 0;

        for (size_t i = 0; i < first_row.size(); ++i) {
            if (is_first_row) {
                if (first_row[i] < smallest) {
                    smallest = first_row[i];
                    current_smallest_index = i;
                }
            } else {
                if (i != last_smallest_index) {
                    if (first_row[i] < smallest) {
                        smallest = first_row[i];
                        current_smallest_index = i;
                    }
                    // DOES NOT WORK? WHAT IF THERE ARE MORE SAME SIZE SMALLEST ONES???!
                }
            }
        }

        grid.erase(grid.begin());
        return smallest + subMinFallingPathSum(current_smallest_index, grid, false);
    }
};

int main(){
    std::vector<std::vector<int>> grid{ std::vector<int>{ 1,2,3 }, std::vector<int>{ 4,5,6 }, std::vector<int>{ 7,8,9 }};

    Solution s;
    std::cout << "Solution: " << s.minFallingPathSum(grid) << std::endl;
    return 0;
}
