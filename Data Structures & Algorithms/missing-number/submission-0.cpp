class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int expectedSum = (n * (n+1)) / 2;
        for (auto n : nums){
            sum += n;
        }
        return expectedSum - sum;
    }
};
