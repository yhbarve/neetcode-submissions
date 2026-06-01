class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size(), 1);
        int prod = 1;
        for (int i = 0; i < nums.size(); i++){
            sol[i] *= prod;
            prod *= nums[i];
        }

        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            sol[i] *= prod;
            prod *= nums[i];
        }

        return sol;
    }
};
