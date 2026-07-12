class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> sol(nums.size()*2, 0);
        for (int i = 0; i < nums.size(); i++){
            sol[i] = nums[i];
            sol[i + nums.size()] = nums[i];
        }
        return sol;
    }
};