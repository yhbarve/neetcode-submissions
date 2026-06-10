class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = INT_MIN;
        for (auto i : nums){
            curSum += i;
            maxSum = max(maxSum, curSum);
            if (curSum < 0) curSum = 0;
        }
        return maxSum;
    }
};
