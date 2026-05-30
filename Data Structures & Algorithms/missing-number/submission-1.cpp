class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sum = 0;
        // int expectedSum = (n * (n+1)) / 2;
        // for (auto n : nums){
        //     sum += n;
        // }
        // return expectedSum - sum;

        int x = 0;
        for (int i = 1; i <= nums.size(); i++){
            x ^= i;
        }

        for (auto n : nums){
            x ^= n;
        }

        return x;
    }
};
