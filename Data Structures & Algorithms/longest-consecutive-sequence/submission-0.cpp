class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        map<int, int> mp;
        for (auto n : nums){
            mp[n] = 1;
        }

        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i] - 1) == mp.end()){
                int size = 1;
                int start = nums[i] + 1;
                while (mp.find(start) != mp.end()){
                    start++;
                    size++;
                }
                maxLen = max(maxLen, size);
            }
        }
        return maxLen;
    }
};
