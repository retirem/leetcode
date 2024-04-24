#include <iostream>

class Solution {
public:
    int tribonacci(int n) {
        if (n < 0 || n > 37) {
            std::cout << "Wrong input!\n";
            exit(1);
        }

        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        size_t t0 = 0;
        size_t t1 = 1, t2 = 1;

        for(size_t i = 3; i < n; ++i){
            size_t temp_t2 = t2;
            size_t temp_t1 = t1;
            t2 = t2 + t1 + t0;
            t1 = temp_t2;
            t0 = temp_t1;
        }

        return t0 + t1 + t2;
    }
};

int main(){
    int x;
    std::cin >> x;

    Solution s;
    std::cout << "Solution: " << s.tribonacci(x) << std::endl;
    return 0;
}
