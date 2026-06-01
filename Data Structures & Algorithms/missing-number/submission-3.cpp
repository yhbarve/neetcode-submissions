class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++){
            x ^= nums[i];
        }
        
        for (int i = 0; i <= n; i++){
            x ^= i;
        }

        return x;
    }
};
