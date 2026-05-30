class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp; // {num, index}
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(target - nums[i]) != mp.end()){
                vector<int> sol = {mp[target - nums[i]], i};
                sort(sol.begin(), sol.end());
                return sol;
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
