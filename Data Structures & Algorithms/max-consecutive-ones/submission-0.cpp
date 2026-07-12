class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sol = 0;
        int cur = 0;
        for (auto i : nums){
            if (i == 1) cur++;
            else {
                sol = max(sol, cur);
                cur = 0;
            }
        }
        return max(sol, cur);
    }
};