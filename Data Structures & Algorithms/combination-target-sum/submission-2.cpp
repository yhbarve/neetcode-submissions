class Solution {
public:
    void backtrack(vector<int>& nums, int target, set<vector<int>>& combinations, vector<int> currentCombination){
        if (target < 0) return;
        if (target == 0){
            combinations.insert(currentCombination);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (currentCombination.empty() || currentCombination.back() <= nums[i]){
                currentCombination.push_back(nums[i]);
                backtrack(nums, target - nums[i], combinations, currentCombination);
                currentCombination.pop_back();
            }
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        /*
            t = 0 | []
            t = 1 | [2], [5], [6], [9]
            t = 2 | [2, 2], [2, 5], [2, 6], [2, 9], [5, 2], [5, 5], [5, 6], [5, 9]...

            base case: if sum of a combination > target -> stop
            base case: if sum of a combination == target -> stop
            otherwise: pick one element from the array and add to the combination
        */
        sort(nums.begin(), nums.end());
        set<vector<int>> combinations;
        backtrack(nums, target, combinations, {});
        vector<vector<int>> combinationsVector(combinations.begin(), combinations.end());
        return combinationsVector;
    }
};
