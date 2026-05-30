class Solution {
public:
    void backtrack(vector<int>& nums, int target, int i, int sum, vector<int> curSet, set<vector<int>>& solSet){
        if (i >= nums.size()) return;
        int newSum = sum + nums[i];
        if (newSum > target) return;
        curSet.push_back(nums[i]);
        if (newSum == target){
            sort(curSet.begin(), curSet.end());
            solSet.insert(curSet);
            return;
        }
        for (int j = i; j < nums.size(); j++){
            backtrack(nums, target, j, newSum, curSet, solSet);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> solSet;
        for (int i = 0; i < nums.size(); i++){
            backtrack(nums, target, i, 0, {}, solSet);
        }
        vector<vector<int>> sol(solSet.begin(), solSet.end());
        return sol;
    }
};
