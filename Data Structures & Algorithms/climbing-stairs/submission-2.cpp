class Solution {
public:
    int climbStairs(int n) {
        int x1 = 1;
        int x2 = 1;
        int x3;
        for (int i = 2; i <= n; i++){
            x3 = x2 + x1;
            x1 = x2;
            x2 = x3;
        }
        return x2;
    }
};
